module FSM(
    input wire clk,
    input wire rst
);

    localparam S0 = 2'b00;
    localparam S1 = 2'b01;
    localparam S2 = 2'b10;
    localparam S3 = 2'b11;

    /*---------------一段式---------------*/
    reg [1:0] stage;
    always @(posedge clk) begin
        if(rst) begin
            out0;
            stage <= S0;
        end
        else begin
            case(stage)
                S0: begin
                    out0;
                    if(...) stage <= S1;
                end
                S1: begin
                    out1;
                    if(...) stage <= S2;
                end
                ...
                default: begin
                    stage <= S0;
                end
            endcase
        end
    end
    /*---------------一段式---------------*/

    /*---------------二段式---------------*/
    reg [1:0] current_stage, next_stage;
    always @(posedge clk) begin
        if(rst)
            current_stage <= S0;
        else
            current_stage <= next_stage;
    end

    always @(*) begin
        next_stage = S0;
        case(current_stage)
            S0: begin
                out0;
                if(...) next_stage = S1;
            end
            S1: begin
                out1;
                if(...) next_stage = S2;
            end
            ...
            default: begin
                next_stage = S0;
            end
        endcase
    end
    /*---------------二段式---------------*/

    /*---------------三段式---------------*/
    reg [1:0] current_stage, next_stage;
    always @(posedge clk) begin
        if(rst)
            current_stage <= S0;
        else
            current_stage <= next_stage;
    end

    always @(current_stage) begin
        next_stage = S0;
        case(current_stage)
            S0: begin
                if(...) next_stage = S1;
            end
            S1: begin
                if(...) next_stage = S2;
            end
            ...
            default: begin
                next_stage = S0;
            end
        endcase
    end

    always @(posedge clk) begin
        if(rst) begin
            out0;
        end
        else begin
            case(next_stage)
                S0: out0; ...
                S1: out1; ...
                ...
                default: out0; ...
            endcase
        end
    end
    /*---------------三段式---------------*/

endmodule