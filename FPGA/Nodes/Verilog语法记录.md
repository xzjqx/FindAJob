### generate
生成语句可以动态的生成verilog代码，当对矢量中的多个位进行重复操作时，或者当进行多个模块的实例引用的重复操作时，或者根据参数的定义来确定程序中是否应该包含某段Verilog代码的时候，使用生成语句能大大简化程序的编写过程。
#### generate-for
1. 必须有genvar关键字定义for语句的变量。
2. for语句的内容必须加begin和end（即使就一句）。
3. for语句必须有个名字。

```
module test(bin,gray);
    parameter SIZE=8;
    output [SIZE-1:0] bin;
    input [SIZE-1:0] gray;
    genvar i; //genvar i;也可以定义到generate语句里面
    generate
        for(i=0;i<SIZE;i=i+1)
        begin:bit
            assign bin[i]=^gray[SIZE-1:i];
        end
    endgenerate
endmodule
```

### 常用操作符