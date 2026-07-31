/*
 * firmware/main.c
 * Basic firmware skeleton for STM32F103C8T6
 * - TIM1 generates PWM for H-bridge (CH1/CH2)
 * - GPIO controls TX/RX switching
 * - TIM2 input capture reads comparator edges
 * - ADC reads current sense resistor
 * - UART for debug
 * Note: This is a simplified skeleton; CubeMX generated HAL init code (SystemClock_Config, MX_GPIO_Init etc) is expected.
 */

#include "main.h"
#include "stm32f1xx_hal.h"
#include <string.h>

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart1;

volatile uint32_t last_capture = 0;
volatile uint8_t capture_flag = 0;
char uart_buf[128];

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_ADC1_Init(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_TIM1_Init();
    MX_TIM2_Init();
    MX_USART1_UART_Init();
    MX_ADC1_Init();

    // Initial state: RX enabled
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); // TX_ENABLE
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);   // RX_SWITCH

    while (1)
    {
        // 1) Start TX
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET); // route coil to H-bridge
        HAL_Delay(1);

        // Enable H-bridge PWM (TIM1 channels)
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
        HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);

        HAL_Delay(50); // TX duration (ms) - adjust per test

        // Stop TX
        HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
        HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);

        HAL_Delay(1);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET); // route coil to RX

        // Dead time for ringing to decay
        HAL_Delay(2);

        // Start RX capture
        HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);

        // Wait for capture or timeout
        HAL_Delay(100);

        HAL_TIM_IC_Stop_IT(&htim2, TIM_CHANNEL_1);

        if (capture_flag) {
            int len = snprintf(uart_buf, sizeof(uart_buf), "RX edge dt=%lu us\r\n", last_capture);
            HAL_UART_Transmit(&huart1, (uint8_t*)uart_buf, len, HAL_MAX_DELAY);
            capture_flag = 0;
        } else {
            const char *s = "No response\r\n";
            HAL_UART_Transmit(&huart1, (uint8_t*)s, strlen(s), HAL_MAX_DELAY);
        }

        HAL_Delay(200);
    }
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2) {
        uint32_t cap = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
        static uint32_t prev = 0;
        if (prev == 0) prev = cap;
        uint32_t delta = (cap >= prev) ? (cap - prev) : (0xFFFF - prev + cap + 1);
        prev = cap;
        last_capture = delta;
        capture_flag = 1;
    }
}

// Stub initializers - to be generated/filled by CubeMX
static void MX_TIM1_Init(void)
{
    // TIM1 configured to generate PWM at ~134.2 kHz - to be implemented
}
static void MX_TIM2_Init(void)
{
    // TIM2 configured as input capture with 1us tick - to be implemented
}
static void MX_USART1_UART_Init(void)
{
    // UART init at 115200
}
static void MX_ADC1_Init(void)
{
}
static void MX_GPIO_Init(void)
{
    // configure PB0 PB1 etc
}

