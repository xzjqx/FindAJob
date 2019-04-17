module d_latch (
    input clk, d,
    output reg q
);

always @(clk, d) begin
    if(clk)
        q <= d;
end

endmodule