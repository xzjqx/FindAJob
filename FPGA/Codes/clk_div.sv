`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/30 22:51:24
// Design Name: 
// Module Name: clk_div
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module clk_div(
    input logic clk_in, rstn,
    input logic [31:0] N,
    output logic clk_out
);

    logic [31:0] count;
    always @(posedge clk_in, posedge rstn) begin
        if(rstn) begin
            clk_out <= 1'b1;
            count <= 0;
        end else if(count == ((N>>1)-1)) begin
            clk_out <= ~clk_out;
            count <= 0;
        end else begin
            count <= count + 1'b1;
        end
    end
endmodule
