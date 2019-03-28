module clk_div_even #(
    parameter M = 4, N = 2, WIDTH = 7
)(
    input wire clk_in,
    input wire rst,
    output wire clk_out
);

    reg [WIDTH-1:0] counter;
    always @(posedge clk_in) begin
        if(rst) begin
            counter <= 7'b0;
        end
        else begin
            if(counter == (N - 1)) begin
                counter <= 0;
            end
            else begin
                counter <= counter + 1;
            end
        end
    end

    always @(posedge clk_in) begin
        if(rst) begin
            clk_out <= 1'b0;
        end
        else begin
            if(counter == N-1) begin
                clk_out <= !clk_out;
            end
        end
    end

endmodule