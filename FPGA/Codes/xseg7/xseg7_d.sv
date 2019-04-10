module xseg7_d (
    input logic aclk, aresetn,
    input logic [3:0] Y0, Y1,
    output logic [6:0] a_to_g,
    output logic [1:0] an
);

logic [31:0] num_data;
always @(posedge aclk)
begin
    if(!aresetn) begin
        num_data <= 32'h0;
    end
    else begin
        num_data <= {24'b0, Y1, Y0};
    end
end

logic [19:0] count;
always @(posedge aclk)
begin
    if(!aresetn) begin
        count <= 20'd0;
    end
    else begin
        count <= count + 1'b1;
    end
end
//scan data
logic [3:0] scan_data;
always @ ( posedge aclk )  
begin
    if ( !aresetn )
    begin
        scan_data <= 32'd0;  
        an   <= 8'b1111_1111;
    end
    else
    begin
        case(count[19:17])
            3'b110 : scan_data <= num_data[7 : 4];
            3'b111 : scan_data <= num_data[3 : 0];
        endcase

        case(count[19:17])
            3'b110 : an <= 2'b01;
            3'b111 : an <= 2'b10;
        endcase
    end
end

always @(posedge aclk)
begin
    if ( !aresetn )
    begin
        a_to_g <= 7'b0000000;
    end
    else
    begin
        case ( scan_data )
            4'd0 : a_to_g <= 7'b1111110;   //0
            4'd1 : a_to_g <= 7'b0110000;   //1
            4'd2 : a_to_g <= 7'b1101101;   //2
            4'd3 : a_to_g <= 7'b1111001;   //3
            4'd4 : a_to_g <= 7'b0110011;   //4
            4'd5 : a_to_g <= 7'b1011011;   //5
            4'd6 : a_to_g <= 7'b1011111;   //6
            4'd7 : a_to_g <= 7'b1110000;   //7
            4'd8 : a_to_g <= 7'b1111111;   //8
            4'd9 : a_to_g <= 7'b1111011;   //9
            4'd10: a_to_g <= 7'b1110111;   //a
            4'd11: a_to_g <= 7'b0011111;   //b
            4'd12: a_to_g <= 7'b1001110;   //c
            4'd13: a_to_g <= 7'b0111101;   //d
            4'd14: a_to_g <= 7'b1001111;   //e
            4'd15: a_to_g <= 7'b1000111;   //f
        endcase
    end
end

endmodule