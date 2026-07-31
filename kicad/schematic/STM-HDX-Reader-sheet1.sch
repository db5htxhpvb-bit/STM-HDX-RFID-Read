(Placeholder) KiCad schematic sheet file - full schematic will be created in KiCad.

File: kicad/schematic/STM-HDX-Reader-sheet1.sch

This is a textual placeholder representing the full schematic to be created. It includes the following blocks and netlisting which will be converted into KiCad .sch files:

- POWER & BOOST: VIN->LDO 3.3V, TPS61088-based synchronous boost to 12V, input/output caps and filters, Rshunt current sense (0.05Ω), F1 PTC, sensing amplifier.
- MCU: STM32F103C8T6 (LQFP48) connected to PA8(TIM1_CH1), PA0(TIM2_CH1), PA9/PA10 UART, ADC pins for shunt.
- H-BRIDGE: Q1..Q4 MOSFETs with gate drivers U_DRV_A/U_DRV_B, gate resistors, bootstrap caps, gate zeners, outputs HBR_OUT_A/HBR_OUT_B routed to COIL node.
- TX/RX SWITCH: FET-based RX/TX switching network, driven by MCU PB0/PB1.
- RX FRONTEND: matching network, envelope detector (BAT54), LMV358 preamp, LMV7231 comparator to MCU.
- CONNECTORS: JST PH-2 coil connector, SWD 6-pin, UART 4-pin header, mounting holes near coil connector.

Notes:
- This file is a placeholder; the actual KiCad schematic sheets (.sch) and symbol links will be generated and committed in the next update after layout progression.
