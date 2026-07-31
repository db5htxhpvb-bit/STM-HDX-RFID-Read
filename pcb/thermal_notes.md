PCB thermal and power routing notes

1) Thermal vias under MOSFET pads
- Use an array of thermal vias (0.3 mm drill, tented if possible) under the MOSFET drain pad, at least 8-12 vias depending on pad size. Plating and via stitching to internal copper plane is essential for heat spreading.

2) Power trace widths
- For 1 oz copper, to carry ~10 A continuous current with acceptable temperature rise, aim for trace width >= 10 mm or use multiple parallel traces and plating. Since board width is limited, prefer plane/pour for current return (inner layer as 12V plane). Use many vias to stitch plane to surface pads.

3) Via placement
- Place vias near current entry/exit points, avoid placing vias in high-frequency switching loops that would increase inductance unnecessarily. Keep switching loop area small by placing MOSFETs, bootstrap caps, and inductor close together.

4) Grounding
- Use solid ground plane (inner1) and route analog grounds carefully. Use star connection for sensitive ADC and comparator grounds near the shunt sense amplifier.

5) Thermal relief for through-hole screws
- Use generous annular rings and consider adding thermal relief for mounting holes if heat conduction is needed.

6) Manufacturer notes
- If possible choose PCB option with 2 oz copper for power layer; if not possible, ensure sufficient via stitching and plane usage. Communicate with PCB manufacturer to ensure via thermal capacity meets power dissipation.

