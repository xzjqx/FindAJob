`timescale 1ns / 1ps


module testbench;

logic clk = 1;

initial
begin
    forever #(5)  clk=~clk;
end



endmodule
