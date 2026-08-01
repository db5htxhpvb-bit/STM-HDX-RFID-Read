JLCPCB Order Package README

This directory contains the files needed to place an online assembly/order with JLCPCB.
Files included:
- gerbers.zip (placeholder) -- will contain Gerber RS-274X files and drill file when PCB layout is finished.
- jlc_bom_for_assembly.csv -- BOM formatted for JLCPCB SMT assembly (Reference,Value,Package,Quantity,Comment)
- centroid.csv -- pick-and-place XY centroid file (reference,footprint,x_mm,y_mm,rotation)
- dfm_notes.txt -- DFM notes and selected JLCPCB order options

Usage:
1) When PCB layout is complete, replace gerbers.zip with the actual Gerber ZIP exported from KiCad.
2) Upload gerbers.zip to JLCPCB PCB order page.
3) Upload jlc_bom_for_assembly.csv and centroid.csv to JLCPCB SMT assembly page.
4) Review dfm_notes.txt for recommended options (board thickness, finish, via tenting, panelization, etc.).

Current status: gerbers.zip is a placeholder. The BOM and centroid are populated from the working BOM and assembly placement files in the repository. When I finish PCB layout I will update gerbers.zip with the real Gerber files and finalize the package.
