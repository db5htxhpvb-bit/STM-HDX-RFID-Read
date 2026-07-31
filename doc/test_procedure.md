Testing and commissioning procedure

Safety first:
- Use a current-limited bench PSU for initial bring-up. Set limit to 1 A initially.
- Keep a thermal camera or IR thermometer handy to watch MOSFET and inductor heating.

Step-by-step:
1. Without coil connected, power board at 5V to verify 3.3V regulator and 12V boost power rails. Verify 3.3V and 12V rails are present and stable.
2. Short the coil connector with a resistor approximating expected coil DCR to verify H-bridge switching and current sensing and test overcurrent protection.
3. Connect coil. With conservative PWM duty, send short TX pulses (10-50 ms), monitor coil node on oscilloscope, observe amplitude and check for clipping or unexpected ringing.
4. Stop TX and measure ring-down time. Adjust dead-time in firmware to be 1-3 ms initially.
5. Enable RX capture and verify comparator toggles capture and that timing of edges is captured by TIM2.
6. Gradually increase duty and TX duration to reach target average power; watch current and temperature.

Measurements to record:
- Coil DCR (ohms)
- Resonant frequency (Hz)
- Peak coil voltage (Vpp)
- Boost IC temperature at load
- MOSFET case temperature

