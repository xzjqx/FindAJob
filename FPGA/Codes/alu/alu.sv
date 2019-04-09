`define AND     4'b0000
`define OR      4'b0001
`define XOR     4'b0010
`define NAND    4'b0011
`define NOR     4'b0100
`define NXOR    4'b0101
`define SLL     4'b0110
`define SRL     4'b0111
`define SRA     4'b1000
`define MULTU   4'b1001
`define MULT    4'b1010
`define ADD     4'b1011
`define SUB     4'b1100
`define SLT     4'b1101

module alu(
    input logic [3:0] A, B, aluop,
    output logic [3:0] y0, y1,
    output logic [1:0] ov
);

    // mult
    logic [7:0] mulres_sign, mulres_unsign;
    assign mulres_sign   = ($signed(A) * $signed(B));
    assign mulres_unsign = ($unsigned({1'b0,A}) * $unsigned({1'b0,B}));

    // add / sub
    logic [3:0] B0, S;
    logic C;
    assign B0 = (aluop == `SUB  ) ? ((~B) + 1) : B;
    rca rca0(.A(A), .B(B0), .S(S), .C(C));
    assign ov[1] = (~A[3] & ~B0[3] & S[3]) + (A[3] & B0[3] & ~S[3]);
    assign ov[0] = C;

    assign y0 = (aluop == `AND  ) ? A & B : 
                (aluop == `OR   ) ? A | B : 
                (aluop == `XOR  ) ? A ^ B : 
                (aluop == `NAND ) ? ~(A & B) : 
                (aluop == `NOR  ) ? ~(A | B) : 
                (aluop == `NXOR ) ? ~(A ^ B) : 
                (aluop == `SLL  ) ? A << B[1:0] : 
                (aluop == `SRL  ) ? A >> B[1:0] : 
                (aluop == `SRA  ) ? (({4{A[3]}} << (3'd4-{1'b0, B[1:0]})) | A >> B[1:0]) : 
                (aluop == `MULTU) ? mulres_unsign[3:0] : 
                (aluop == `MULT ) ? mulres_sign[3:0] : 
                (aluop == `ADD  ) ? S : 
                (aluop == `SUB  ) ? S : 
                (aluop == `SLT  ) ? (($signed(A) < $signed(B)) ? 4'h1 : 4'h0) : 4'b0000; 
    
    assign y1 = (aluop == `MULTU) ? mulres_unsign[7:4] : 
                (aluop == `MULT ) ? mulres_sign[7:4] : 4'b0000; 

endmodule