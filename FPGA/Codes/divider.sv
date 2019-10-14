`timescale 1ns / 1ps

module divider (
    input logic rst,
    input logic clk,
    input logic [31:0] n,
    output logic clkout
    );

    logic[31:0] q;
    
    always_ff @(posedge clk, posedge rst) begin
        if (rst)
            q <= 0;
        else if (q >= n - 1)
            q <= 0;
        else
            q <= q + 1'b1;
    end
    
    assign clkout = (q < (n>>1));

endmodule
