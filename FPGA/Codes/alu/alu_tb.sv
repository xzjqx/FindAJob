`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/08 10:05:40
// Design Name: 
// Module Name: alu_tb
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

module alu_tb();

    // input
    logic [3:0] A, B, aluop;
    
    // output
    logic [3:0] y0, y1;
    logic [1:0] ov;
    
    alu alu0(.A(A), .B(B), .aluop(aluop), .y0(y0), .y1(y1), .ov(ov));
    
    logic [15:0] result;
    initial begin
        result = 16'd0;
        A = 4'b0101; B = 4'b1000; aluop = 4'b0000; #50; // AND      y0 = 4'b0000
        if(y0 != 4'b0000) begin
            $display("Case 1: AND is wrong");
        end else begin
            result[0] = 1;
        end
        A = 4'b0101; B = 4'b1000; aluop = 4'b0001; #50; // OR       y0 = 4'b1101
        if(y0 != 4'b1101) begin
            $display("Case 2: OR is wrong");
        end else begin
            result[1] = 1;
        end
        A = 4'b0101; B = 4'b1000; aluop = 4'b0010; #50; // XOR      y0 = 4'b1101
        if(y0 != 4'b1101) begin
            $display("Case 3: XOR is wrong");
        end else begin
            result[2] = 1;
        end
        A = 4'b0101; B = 4'b1000; aluop = 4'b0011; #50; // NAND     y0 = 4'b1111
        if(y0 != 4'b1111) begin
            $display("Case 4: NAND is wrong");
        end else begin
            result[3] = 1;
        end
        A = 4'b0101; B = 4'b1000; aluop = 4'b0100; #50; // NOR      y0 = 4'b0010
        if(y0 != 4'b0010) begin
            $display("Case 5: NOR is wrong");
        end else begin
            result[4] = 1;
        end
        A = 4'b0101; B = 4'b1000; aluop = 4'b0101; #50; // NXOR     y0 = 4'b0010
        if(y0 != 4'b0010) begin
            $display("Case 5: NXOR is wrong");
        end else begin
            result[5] = 1;
        end
        A = 4'b0101; B = 4'b0011; aluop = 4'b0110; #50; // SLL      y0 = 4'b1000
        if(y0 != 4'b1000) begin
            $display("Case 6: SLL is wrong");
        end else begin
            result[6] = 1;
        end
        A = 4'b1101; B = 4'b0010; aluop = 4'b0111; #50; // SRL      y0 = 4'b0011
        if(y0 != 4'b0011) begin
            $display("Case 8: SRL is wrong");
        end else begin
            result[7] = 1;
        end
        A = 4'b1101; B = 4'b0001; aluop = 4'b1000; #50; // SRA      y0 = 4'b1110
        if(y0 != 4'b1110) begin
            $display("Case 9: SRA is wrong");
        end else begin
            result[8] = 1;
        end
        A = 4'b0101; B = 4'b1000; aluop = 4'b1001; #50; // MULTU    y0 = 4'b1000 y1 = 4'b0010
        if(y0 != 4'b1000 || y1 != 4'b0010) begin
            $display("Case 10: MULTU is wrong");
        end else begin
            result[9] = 1;
        end
        A = 4'b0101; B = 4'b1001; aluop = 4'b1010; #50; // MULT     y0 = 4'b1101 y1 = 4'b1101
        if(y0 != 4'b1101 || y1 != 4'b1101) begin
            $display("Case 11: MULT is wrong");
        end else begin
            result[10] = 1;
        end
        A = 4'b0101; B = 4'b1000; aluop = 4'b1011; #50; // ADD      y0 = 4'b1101 ov = 2'b00
        if(y0 != 4'b1101 || ov != 2'b00) begin
            $display("Case 12: ADD is wrong");
        end else begin
            result[11] = 1;
        end
        A = 4'b1101; B = 4'b1000; aluop = 4'b1011; #50; // ADD      y0 = 4'b0101 ov = 2'b11
        if(y0 != 4'b0101 || ov != 2'b11) begin
            $display("Case 13: ADD is wrong");
        end else begin
            result[12] = 1;
        end
        A = 4'b0111; B = 4'b0100; aluop = 4'b1011; #50; // ADD      y0 = 4'b1011 ov = 2'b10
        if(y0 != 4'b1011 || ov != 2'b10) begin
            $display("Case 14: ADD is wrong");
        end else begin
            result[13] = 1;
        end
        A = 4'b1101; B = 4'b1001; aluop = 4'b1100; #50; // SUB      y0 = 4'b0100 ov = 2'b01
        if(y0 != 4'b0100 || ov != 2'b01) begin
            $display("Case 15: SUB is wrong");
        end else begin
            result[14] = 1;
        end
        A = 4'b0101; B = 4'b0111; aluop = 4'b1101; #50; // SLT      y0 = 4'b0001
        if(y0 != 4'b0001) begin
            $display("Case 16: SLT is wrong");
        end else begin
            result[15] = 1;
        end
        if(|(~result)) begin
            $display("Some cases don't pass.");
        end else begin
            $display("All cases pass.");
        end
    end

endmodule
