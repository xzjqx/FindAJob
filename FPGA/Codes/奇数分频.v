module clk_div_odd #(
    parameter M = 5, N = 2, WIDTH = 7
)(
    input wire clk_in,
    input wire rst,
    output wire clk_out
);

    reg [WIDTH-1:0] counter;
    always@(posedge clk) begin
        if(rst)
            counter <= 0;
        else begin
            if(counter == (N << 1))
                counter <= 0;
            else
                counter <= counter + 1;
        end
    end

    reg clk_out1;
    always@(posedge clk) begin
        if(rst)
            clk_out1 <= 0;
        else if(counter == (N - 1))
            clk_out1 <= !clk_out1;
        else if(counter == (N << 1))
            clk_out1 <= !clk_out1;
    end

    reg clk_out2;
    always@(negedge clk) begin
        if(rst)
            clk_out2 <= 0;
        else if(counter == (N - 1))
            clk_out2 <= !clk_out2;
        else if(counter == (N << 1))
            clk_out2 <= !clk_out2;
    end

    assign clk_out = clk_out1 & clk_out2;

endmodule