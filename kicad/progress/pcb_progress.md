PCB 布局进度记录

状态：已确认“默认（JLC 优先采购）”，现在开始进入 PCB 布线阶段并准备最终 JLC 下单包。

当前动作（我已启动）：
- 在 kicad-hdx-reader 分支继续进行 PCB 布线与器件放置，布局会遵循 JLCPCB 的常见 DFM 约束（1.6 mm 厚度、1 oz 铜、最小线宽/间距 6 mil、最小孔径 0.3 mm）。
- 在 BOM 中将通用小件标注为“JLC优先采购”，难找/大件保留为“客户自备”，并在装配清单里注明。你已选择“默认（JLC优先采购）”。

下一步交付物与预计时间线：
- 原理图 PDF（高分辨率）与更新后的最终 BOM（LCSC 主优先 + JLC 采购标注）：12 小时内。路径示例： kicad/STM-HDX-Reader_schematic.pdf ， bom/final_bom_lcsc_jlc.csv
- 完整 PCB (.kicad_pcb) 与 Gerber 压缩包（gerbers.zip），以及 JLC 下单包（gerbers.zip + jlc_bom_for_assembly.csv + centroid.csv + dfm_notes.txt）：48–72 小时内。

注意事项：
- 我会在 Gerber README 中附上 JLC 下单建议（ENIG 推荐，若预算允许建议升级为 2 oz 铜），并生成 JLC 所需的 BOM/centroid 格式文件。
- 首次样板测试请务必遵守上电限流与短脉冲测试流程（见 doc/test_procedure.md）。

如果在我完成原理图 PDF 或 PCB 布局前你想插入最后的改动（例如改 MOSFET 型号偏好或修改装配方式），请在接下来的 6 小时内告知；否则我将按当前规格继续并把成果放到分支供你下载。
