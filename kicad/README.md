# KiCad project: STM-HDX-RFID-Read (placeholder)

This branch will contain the KiCad project, PCB layout, Gerbers, BOM and documentation for the STM32F103C8T6-based HDX (134.2 kHz) RFID reader designed to deliver ~10 W average transmit power with ~>30 cm read range.

Current contents (first iteration):
- /doc/design_spec.md  — detailed design decisions and electrical requirements
- /doc/initial_schematic_notes.md — important schematic notes and per-block details
- /bom/bom.csv — initial BOM (component roles, suggested footprints, quantities). Links and exact vendor part numbers will be added in the next iteration.
- /kicad/README.md — KiCad project plan and file list; actual .kicad_pro and schematic/pcb files will be added after component footprints are finalised.

Next steps (what I will commit next):
1. Full KiCad schematic (SHEET1.sch) with the following blocks: MCU, power (3.3V & boost to 12V), boost converter, H-bridge MOSFET gate drivers, coil TX/RX switching, RX front-end (BP filter, envelope detector, op‑amp, comparator), protection (TVS, fuses), JST coil connector, programming headers.
2. PCB layout (mixed SMD, large copper zones for power MOSFETs), Gerbers, and BOM with procurement links (LCSC/Mouser/DigiKey).
3. Firmware skeleton (HAL) and test procedure documents.

If you need any particular footprint conventions, file naming, or licensing headers (SPDX), tell me now. Otherwise I will use standard KiCad footprints (SMD preferred), and place the KiCad project in /kicad/ once schematics are complete.
