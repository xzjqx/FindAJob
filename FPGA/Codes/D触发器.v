module d_flip_flop(
    input clk, rstn, d,
    output reg q
);

always @(posedge clk) begin
    if(rstn) q <= 0;
    else q <= d;
end

endmodule