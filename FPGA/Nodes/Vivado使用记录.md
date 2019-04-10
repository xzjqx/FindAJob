## 使用技巧

### edif文件的使用
edif是Vivado下的网表文件，可在设计中创建低层次网表文件，以实现自底向上的综合设计流程

edif文件的生成流程：
1. 创建一个工程，将要生成的模块设置为top module
2. 在综合设置窗口的Options下面最后一项 More Options一栏写入“-no_iobuf”
3. 综合后Open Synthesized Design
4. 在TCL console中输入`write_edif /path/xx.edif`生成edif文件

edif文件的使用：
1. 接上生成流程，在TCL console中输入`write_verilog -mode synth_stub /path/xx_stub.sv`生成stub文件
2. 在上层工程中导入xx.edif和xx_stub.sv文件，其中stub文件是网表文件的端口描述，可用于新工程中该网表的实例化
3. 在上层工程中按照stub文件中的端口描述实例化网表模块即可

## 问题信息

### 文件路径过长
使用Vivado时，可能会出现下述错误：
> ERROR: [Common 17-143] Path length exceeds 260-Byte maximum allowed by Windows: <LongPathtoFileName>

这个错误是由于Windows操作系统的限制。Windows对路径的最大长度有260个字符的限制。由于这个限制，如果路径长度超过260个字符，Vivado Design Suite及其辅助工具可能会失败。

有时报错信息不是上述容易理解的情况，可能如下所示：

> [Common 17-101] Failed to write attributes to C:/Users/xzjqx/Desktop/Work/DLC/ALU_4bits/ALU_4bits.runs/impl_1/.Xil/Vivado-12644-LAPTOP-GDGGKCGC/dcp5/ALU_4bits.xn.

可以看出该错误信息中文件的路径长度也过长。

针对这一文件最简单的方法就是移动Vivado工程目录到路径较短的位置。