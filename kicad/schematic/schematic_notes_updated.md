Updated schematic notes for high-current 10W design

Summary of high-current changes (based on coil DCR = 0.2 ohm -> ~7.07 A RMS, ~10 A peak)

1) MOSFET selection and layout
- Select MOSFETs with the following target specs:
  - Vds >= 40V (to provide margin for transients)
  - Rds(on) <= 20 mOhm (lower is better)
  - Id pulse rating >= 40 A
  - SMD package with large thermal pad (PowerSO-8 / LFPAK / DPAK variants if available in SMD)
- Use multiple thermal vias under MOSFET drains/sources to inner copper planes. Place MOSFETs close to coil connector to minimize high-current trace length.
- Add gate resistors (10-22 ohm) and gate-to-source zener diodes if required for overvoltage protection.

2) H-bridge and gate drivers
- Use robust half-bridge drivers capable of driving high gate charge quickly (low switching losses). Consider drivers with adjustable dead-time or external dead-time control.
- Place bootstrap capacitors close to driver ICs. If using high-side drivers requiring floating supply, ensure bootstrap refresh conditions at PWM frequency.

3) Current sensing
- Rshunt: 0.05 ohm, 3-5 W (use 2512 or similar). Place with Kelvin sense pads. Route sense traces to ADC via differential amplifier or dedicated current-sense amplifier (INA family) to improve noise immunity.
- The MCU ADC will sample shunt voltage; include filtering (RC) before ADC to avoid aliasing.

4) Boost converter
- Target boost converter output: 12V, capable of at least 3 A continuous. Use synchronous buck/boost topology ICs rated for required current. Provide large low-ESR output capacitor (22uF-47uF) and layout per datasheet.
- Include input bypassing and a bulk capacitor for transient loads during TX pulses.

5) PCB power routing & copper
- Although board copper is 1 oz, use multiple vias to connect top and inner 12V plane. Use wide traces (e.g., >6 mm) or multiple parallel traces for high current paths. Place several vias (>=12) for MOSFET thermal/power pads.
- Consider using internal plane for 12V (inner layer) and pour generous copper for heat spreading.

6) Shunt dissipation
- With Rshunt=0.05 ohm and I_rms~7.07 A, expected P_shunt~2.5 W. Provide good thermal pad and allow airflow/heat sinking; consider using lower shunt value (0.02 ohm) if measurement dynamic range allows, to reduce dissipation.

7) Protection
- Place TVS at coil node and at 12V rail. Use PTC or fuse on boost output. Include MOSFET shoot-through protection via dead-time in gate driver/firmware.

8) RX front-end protection and switching
- Use high-voltage tolerant FETs or analog switches for TX/RX switching. Add series resistor and clamp diodes to protect the op-amp input.

These notes will be used to finalize schematic symbols, footprints, and PCB layout.