SHEET: RX Frontend (textual schematic)

This sheet details the receive (RX) analogue path from coil to MCU comparator.

Signal flow:
COIL node -> Rs_series (10-100 ohm) -> L/C matching (tunable) -> Envelope detector (BAT54 diode + cap to ground) -> RC smoothing (R=10k, C=2.2nF) -> OpAmp (LMV358) gain stage -> Comparator (LMV7231) -> MCU (TIM2) input capture

Recommended components initial values:
- Rs_series = 22 ohm (start) - adjust based on measured ring-down
- Envelope C = 10nF (low ESR)
- RC time constant = 10k * 2.2nF = 22 us (tune per signal)
- OpAmp gain: start with 20 dB (10x) and adjust as needed
- Comparator threshold: adjustable with 10k trimmer between VREF and GND

Protection:
- TVS at COIL node
- Series resistor before op-amp
- Input clamp diodes to prevent overdrive

