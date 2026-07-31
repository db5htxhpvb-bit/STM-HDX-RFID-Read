# KiCad schematic notes

此文件为 KiCad 原理图各模块说明与符号/封装建议，便于后续在 KiCad 中绘制原理图。

模块划分（SHEET）
- MCU: STM32F103C8T6 （LQFP48）
  - 引脚重要映射：
    - PA8 TIM1_CH1 -> H-bridge gate driver (用于 PWM 输出)
    - PA9 UART1_TX (调试)
    - PA10 UART1_RX
    - PA0 TIM2_CH1 -> RX 比较器输出（输入捕获）
    - PB0/PB1 控制 TX/RX 切换 MOSFET
    - PA4/PA5/PA6 等用于 ADC 读取电流感测
    - SWD: PA13/PA14 为 SWDIO/SWCLK
- Power: 3.3V LDO, 3.3V decoupling network, 5V/USB input connector
- Boost (3.3V -> 12V): 同步升压 IC（建议 footprint: TPS61088 或等效），包含：L_inductor, Schottky / synchronous MOSFET 内置, 输出电容, 反馈电阻
- H-Bridge: 四颗功率 MOSFET (SMD)，高侧驱动器 (half-bridge driver) x2 或 集成四桥 driver
  - Gate resistors, gate-driver bypass caps, bootstrap diodes/caps（若使用 bootstrap）
  - Current sense resistor (Rshunt), differential amplifier or ADC front-end
- TX/RX switching: 使用功率 MOSFET 做 SPDT 切换或专用模拟开关
- RX front-end: Coil -> Rsense(series) -> bandpass/LC -> envelope (BAT54) -> RC -> op-amp (LMV358) gain stage -> comparator (LMV7231) -> MCU input capture
- Protection: TVS at COIL node, TVS at 12V output, series fuses / PTC, gate zeners if needed
- Connectors: JST 2-pin coil input, SWD 6-pin (2x3), UART 4-pin header, power input pads

封装建议
- MCU: LQFP48 (手工贴片或机器贴片皆可)
- MOSFET: SMD large pad (SO‑8, PowerSO8 或 LFPAK) 取决于所选元件
- Boost IC: SOT‑23‑6 或适当封装
- Coil JST: JST PH2.0 2-pin or Molex equivalent

命名与网名
- COIL_P / COIL_N 用于线圈两端
- VBOOST_12V 输出 net 名称
- SHUNT_P / SHUNT_N for current sense
- HBRIDGE_OUTA / HBRIDGE_OUTB -> 连接到 COIL node（依 H-bridge 配置）

参考：请按这些 notes 在 KiCad 中绘制 Schematic sheet，并在元件库中选择合适 footprint。