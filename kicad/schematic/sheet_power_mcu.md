KiCad schematic (textual) - Sheet 1: Power & MCU

This file documents the full schematic connectivity in a text form so it can be translated into KiCad sheets.

SHEET: POWER & MCU

Nets:
- VCC_3V3: main 3.3V rail
- VBUS_5V: USB/5V input
- VBOOST_12V: boosted 12V rail for H-bridge
- GND: common ground

Parts & Connectivity:

1) Power input & 3.3V regulator
- CONN_POWER: 2-pin screw or header: VIN (5V) and GND
- TVS_D1: TVS between VIN and GND (protect against surge)
- LDO_U1: 3.3V LDO (e.g., MCP1700-33 or LD1117-3.3 for higher current) VIN=VBUS_5V -> VCC_3V3
- Decoupling: 10uF + 0.1uF at VIN and VOUT

2) Boost converter (3.3->12V)
- U_BOOST: TPS61088 (or equivalent) with synchronous output configured for 12V
- L_BOOST: 10uH low DCR power inductor between SW and VIN pin as per datasheet
- COUT_BOOST: 22uF-47uF low-ESR cap on VBOOST_12V to GND
- RFB divider for 12V feedback (Rtop, Rbot values per datasheet)
- FUSE/RESET: PTC or fuse on VBOOST output (F1)
- SHUNT: Rshunt (0.05R) in series with VBOOST output ground return or in series with H-bridge supply for current sense
- SENSE_AMP: differential amplifier or ADC divider to read shunt voltage into MCU ADC (PA4/PA5)

3) MCU: STM32F103C8T6 (LQFP48)
- VDD pins -> VCC_3V3
- VSS pins -> GND
- PA8 -> TIM1_CH1 -> H-bridge gate driver input (HBR_DRV_IN_A)
- PA9 -> USART1_TX (debug)
- PA10 -> USART1_RX
- PA0 -> TIM2_CH1 (RX comparator input)
- PB0 / PB1 -> GPIO -> controls TX/RX switch FETs or analog switch enables
- ADC pins (PA4/PA5) read current sense and optional VBOOST monitor
- SWD: PA13 (SWDIO), PA14 (SWCLK) -> SWD header (6-pin)

4) H-bridge gate drivers & MOSFETs
- U_DRV_A, U_DRV_B: half-bridge gate drivers (e.g., IR2104 or pair of modern drivers)
- MOSFETs Q1/Q2 (High/Low for half A) and Q3/Q4 (High/Low for half B): chosen low Rds_on, SMD package with large thermal pad
- Gate resistors Rg (10-22 ohm) for each MOSFET, gate-to-source zener if desired
- Bootstrap diodes/caps if drivers require

5) TX/RX switching
- Q_SW_RX series FET to connect COIL node to RX front-end when in RX mode; off during TX
- Q_SW_TX optional to isolate coil from H-bridge when not TXing (depends on topology)
- Control signals from MCU (PB0/PB1) with level shifting if needed

6) Coil connector
- JST PH-2 2-pin: pins COIL_P, COIL_N mapped to coil external connector
- Mechanical mounting holes near coil connector (4x) for coil fixture

7) RX front-end
- COIL node -> series R (Rsense_serial 10-47 ohm) -> band-pass matching network -> envelope detector (BAT54) -> RC (R=10k, C=2.2nF) -> op-amp UA (LMV358) -> comparator (LMV7231)
- Comparator output -> MCU PA0 (TIM2 input capture)
- RC and comparator thresholds adjustable via trimmer pot
- TVS at COIL node for large transients

8) Protection & indicators
- Status LED with series resistor on VCC_3V3
- Thermistor footprint optional for MOSFET temperature monitoring (if desired)

Notes:
- All decoupling caps as close to IC pins as possible
- Place star ground near the DC input/boost converter and use inner plane GND for return
- H-bridge current carrying traces must be thick and short, with thermal vias to inner copper planes

