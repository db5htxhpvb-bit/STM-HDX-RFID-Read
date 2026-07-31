# STM-HDX-RFID-Read

Reference design for an HDX (134.2 kHz) RFID reader based on STM32F103C8T6.

This repository will contain:
- KiCad schematic and PCB layout for the reader (SMD-preferred, mixed components).
- Gerber files, BOM (CSV) with LCSC/Mouser/DigiKey links.
- Firmware skeleton (HAL) for TIM1 PWM TX, TX/RX switching, TIM2 input-capture RX.
- Documentation: coil winding instructions, tuning procedure, test procedure.

Branching and contributions:
- I will create a branch `kicad-hdx-reader` containing the KiCad project, BOM, gerbers, and PDFs.

User-provided parameters used:
- MCU: STM32F103C8T6
- Power: 3.3V primary, with an on-board boost/step-up for the transmit driver (user requested 3.3V then boost)
- Coil: user-specified circular coil, diameter 180 mm, inductance ~170 µH, 200 turns (multi-strand winding)
- Preferred components: mixed, SMD prioritized

Next steps:
1. Create branch `kicad-hdx-reader` and upload KiCad project files, BOM, gerbers, and documentation.
2. Provide downloadable files and a PDF preview.

(Initial commit)
