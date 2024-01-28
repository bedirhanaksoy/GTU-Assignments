module thirty_two_bit_adder(output cout, output [31:0] R, input [31:0] A, input [31:0] B, input cin);

	wire [7:0]P;
	wire [7:0]G;
	
	wire [8:1]c;

	four_bit_CLA CLA1(R[3:0], P[0], G[0], A[3:0], B[3:0], cin);
	four_bit_CLA CLA2(R[7:4], P[1], G[1], A[7:4], B[7:4], c[1]);
	four_bit_CLA CLA3(R[11:8], P[2], G[2], A[11:8], B[11:8], c[2]);
	four_bit_CLA CLA4(R[15:12], P[3], G[3], A[15:12], B[15:12], c[3]);
	four_bit_CLA CLA5(R[19:16], P[4], G[4], A[19:16], B[19:16], c[4]);
	four_bit_CLA CLA6(R[23:20], P[5], G[5], A[23:20], B[23:20], c[5]);
	four_bit_CLA CLA7(R[27:24], P[6], G[6], A[27:24], B[27:24], c[6]);
	four_bit_CLA CLA8(R[31:28], P[7], G[7], A[31:28], B[31:28], c[7]);
	

	second_level_CLL CLL1(c[8:1], P[7:0], G[7:0], cin);
	
	and and1(cout, c[8], 1);
	
endmodule