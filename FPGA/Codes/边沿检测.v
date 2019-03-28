module posedge_detection (
    input  clk,
    input  rst_n,
    input  i_data_in,
    output o_rising_edge,
    output o_downing_edge
);

reg r_data_in0;
reg r_data_in1;

assign o_rising_edge = ~r_data_in0 & r_data_in1;
assign o_downing_edge = r_data_in0 & ~r_data_in1;

always@(posedge clk, negedge rst_n) begin
    if (!rst_n) begin
        r_data_in0 <= 0;
        r_data_in1 <= 0;
    end
    else begin
        r_data_in0 <= r_data_in1;
        r_data_in1 <= i_data_in;
    end
end

endmodule