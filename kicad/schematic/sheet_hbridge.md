SHEET: H-Bridge & Gate Driver (textual schematic)

This sheet describes connection details for gate drivers and MOSFETs.

Nets used:
- VBOOST_12V, VCC_3V3, GND, HBR_OUT_A, HBR_OUT_B

Components & connections:
- U_DRV_A (half bridge driver): VCC = VBOOST_12V for gate drive supply or bootstrap scheme according to driver
  - IN = HBR_DRV_IN_A (from PA8 via level shifter/driver input)
  - HO -> Gate of Q1 (High side A) through Rg
  - LO -> Gate of Q2 (Low side A) through Rg
  - VS -> HBR_OUT_A (switch node) -> connect to coil node via layout short

- U_DRV_B same for HBR_OUT_B, controlled by PA8 complementary PWM or TIM1 complementary

- MOSFETs Q1..Q4 arranged as full bridge. Place low Rdson, Vds >= 40V recommended.

- Current shunt Rshunt placed either in low side return of H-bridge or in VBOOST feed depending on sensing strategy. Route shunt sense to MCU ADC via differential amp if needed.

Layout notes:
- Place gate driver close to MOSFETs, keep gate traces short
- Place bootstrap caps near drivers
- Use Kelvin connection for sense resistor

