PCB layout v1 plan

Board: 100 mm x 40 mm, 4 layers (Top / Inner1 GND / Inner2 12V / Bottom), 1 oz copper
Manufacturing target: JLCPCB standard 4-layer service

Layer stack recommendation (for JLCPCB):
- Top (signal, components)
- Inner1 (GND plane) - 1 oz copper
- Inner2 (12V plane) - 1 oz copper
- Bottom (signal)

Key placement & routing constraints:
- Place COIL connector and mounting holes along short edge (x≈5 mm from top edge). H-bridge components (Q1..Q4, U_DRV) directly adjacent to minimize high current path length. Place boost converter and bulk caps close to H-bridge but keep inductor and switch nodes arranged to minimize loop area.
- RX front-end placed at opposite short edge (~x≈95 mm) to maximize separation. Keep RX sensitive traces on top layer with guard traces tied to ground and short connections to op-amp inputs; route critical traces to inner ground plane via single via when needed.
- Use large pour for 12V inner plane; stitch top pads with many vias (min 10 per large pad) to distribute heat into plane.
- Rshunt placed in low-side or in supply feed as per schematic; include Kelvin pads and short sense traces to differential amp.
- Thermal vias: min 10 under each MOSFET exposed pad. Via diameter 0.3 mm drill, tented recommended by manufacturer.

Design for JLCPCB constraints:
- Min track width 6 mil, min clearance 6 mil supported by JLCPCB. For high current traces use pours and plane - do not rely on single 6 mil trace for power.
- Min via diameter 0.3mm, via annular ring per JLC spec.
- Keep soldermask between pads per JLC defaults; avoid very small SMD pads < 0.3 mm in narrow pitch areas.

DFM notes to include in Gerber README for JLCPCB:
- Suggest 1.6mm board thickness, HASL/ENIG as per assembly requirements (ENIG preferred for SMD reliability)
- Recommend selecting 1 oz default but consider 2 oz upgrade for production if budget allows
- Provide BOM and centroid file for JLC assembly if you plan to use their SMT service

