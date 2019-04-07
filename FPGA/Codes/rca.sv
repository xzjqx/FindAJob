module rca(
    input logic [3:0] A, B,
    output logic [3:0] S,
    output logic C
);

    logic [3:0] carry;
    assign carry[0] = 0;

    fulladder U1(.A(A[0]), .B(B[0]), .Cin(carry[0]), .S(S[0]), .Cout(carry[1]));
    fulladder U2(.A(A[1]), .B(B[1]), .Cin(carry[1]), .S(S[1]), .Cout(carry[2]));
    fulladder U3(.A(A[2]), .B(B[2]), .Cin(carry[2]), .S(S[2]), .Cout(carry[3]));
    fulladder U4(.A(A[3]), .B(B[3]), .Cin(carry[3]), .S(S[3]), .Cout(C));

endmodule