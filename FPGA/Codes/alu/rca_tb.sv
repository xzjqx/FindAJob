`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/07 21:27:32
// Design Name: 
// Module Name: rca_tb
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


module rca_tb();
    
    // input
    logic [3:0] A, B;
    // output 
    logic [3:0] S;
    logic C;
    
    rca rca0(.A(A), .B(B), .S(S), .C(C));
    
    initial begin
        A = 0; B = 0; #50;
        A = 1; B = 1; #50;
        A = 1; B = 2; #50;
        A = 3; B = 2; #50;
        A = 15; B = 1; #50;
        A = 4'ha; B = 4'hb; #50;
    end
    
endmodule
