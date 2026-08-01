Full schematic netlist and mapping (textual)

This file documents the detailed netlist and component-footprint mapping that I will implement into KiCad schematic sheets. It includes specific net names, component references, suggested footprints, and placement grouping for PCB layout.

Nets:
- VCC_3V3
- VBUS_5V
- VBOOST_12V
- GND
- COIL_P, COIL_N
- HBR_OUT_A, HBR_OUT_B
- SHUNT_P, SHUNT_N
- SENSE_ADC
- RX_EN, TX_EN

Component mapping and suggested footprints:
- U1: STM32F103C8T6 - LQFP48 - footprint: LQFP-48_7x7mm_P0.8mm
- U2: Synchronous boost IC (TPS61088 or equivalent) - SOT23-6 footprint
- L_BOOST: 10uH, high-current - 1210 footprint (or 3216 if needed)
- C_BOOST: 22uF X7R low-ESR - 0805/1210 depending on value
- Q1..Q4: Power MOSFETs - PowerSO-8 or LFPAK footprint (large exposed pad)
- U_DRV_A / U_DRV_B: Half-bridge gate drivers - SOIC-8 (or SOT-23-6 if space constrained)
- R_SHUNT: 0.05R, 2512 power resistor footprint with Kelvin pads
- U_SENSE: INA differential amplifier (if chosen) - SOIC-8
- U_RX_OP: LMV358 or OPA2333 - SOIC-8
- U_COMP: LMV7231 - SOT23-5
- D_ENV: BAT54 - SOT-23
- TVS_COIL: SMBJ12CA - SMA footprint
- J_COIL: JST-PH-2 - JST-PH-2.0 footprint
- J_SWD: 2x3 standard 2.54mm header footprint
- J_UART: 4-pin 2.54mm header
- F1: PTC resettable fuse footprint - 1206
- Mounting holes: 4x 3.2mm plated thru-holes near COIL connector

Placement grouping (for PCB layout):
1) Power/boost cluster: U2, L_BOOST, C_BOOST, input capacitors, F1, large bulk capacitor - placed together near board edge opposite RX front-end.
2) H-bridge cluster: Q1..Q4, U_DRV_A/B, bootstrap caps, gate resistors, Rshunt placement - placed close to COIL connector to minimize loop area.
3) Coil connector & mounting: J_COIL and 4 mounting holes on short edge; H-bridge directly adjacent.
4) RX front-end cluster: matching network, D_ENV, U_RX_OP, U_COMP, placed at opposite short edge of PCB, physically separated from H-bridge by GND plane partition and distance.
5) MCU cluster: U1 centered between clusters with SWD and UART headers accessible; ADC traces from Rshunt routed carefully with Kelvin sense to minimize noise.

I will implement these mappings into KiCad schematic sheets and create a first-pass placement in the PCB editor consistent with these groupings.
