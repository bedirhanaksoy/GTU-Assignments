module ALU(input [31:0]A, input [31:0]B, input [2:0]select, output [31:0]R, input clk, input rst);
	
	wire lt,sign,carry_out_sum;
	wire [31:0]R_and, R_or, R_lt, R_xor, R_nor, R_add, R_sub, R_mod;
	
	my_and myand1(R_and[31:0], A[31:0], B[31:0]);
	my_or myor1(R_or[31:0], A[31:0], B[31:0]);
	is_less_than lt_1(R_lt[0], A[31:0], B[31:0]);
	my_xor myxor1(R_xor[31:0], A[31:0], B[31:0]);
	my_nor mynor1(R_nor[31:0], A[31:0], B[31:0]);
	thirty_two_bit_adder adder1(carry_out_sum, R_add[31:0], A[31:0], B[31:0], 1'b0);
	thirty_two_bit_subtractor sub1(R_sub[31:0], sign, A[31:0], B[31:0]);
	mod mod1(A[31:0], B[31:0], rst, clk, R_mod[31:0]);
	
	_8x1Mux mux0 (R[0], R_and[0], R_or[0], R_xor[0], R_nor[0], R_lt[0], R_add[0], R_sub[0], R_mod[0], select[0], select[1], select[2]);
	_8x1Mux mux1 (R[1], R_and[1], R_or[1], R_xor[1], R_nor[1], R_lt[1], R_add[1], R_sub[1], R_mod[1], select[0], select[1], select[2]);
	_8x1Mux mux2 (R[2], R_and[2], R_or[2], R_xor[2], R_nor[2], R_lt[2], R_add[2], R_sub[2], R_mod[2], select[0], select[1], select[2]);
	_8x1Mux mux3 (R[3], R_and[3], R_or[3], R_xor[3], R_nor[3], R_lt[3], R_add[3], R_sub[3], R_mod[3], select[0], select[1], select[2]);
	_8x1Mux mux4 (R[4], R_and[4], R_or[4], R_xor[4], R_nor[4], R_lt[4], R_add[4], R_sub[4], R_mod[4], select[0], select[1], select[2]);
	_8x1Mux mux5 (R[5], R_and[5], R_or[5], R_xor[5], R_nor[5], R_lt[5], R_add[5], R_sub[5], R_mod[5], select[0], select[1], select[2]);
	_8x1Mux mux6 (R[6], R_and[6], R_or[6], R_xor[6], R_nor[6], R_lt[6], R_add[6], R_sub[6], R_mod[6], select[0], select[1], select[2]);
	_8x1Mux mux7 (R[7], R_and[7], R_or[7], R_xor[7], R_nor[7], R_lt[7], R_add[7], R_sub[7], R_mod[7], select[0], select[1], select[2]);
	_8x1Mux mux8 (R[8], R_and[8], R_or[8], R_xor[8], R_nor[8], R_lt[8], R_add[8], R_sub[8], R_mod[8], select[0], select[1], select[2]);
	_8x1Mux mux9 (R[9], R_and[9], R_or[9], R_xor[9], R_nor[9], R_lt[9], R_add[9], R_sub[9], R_mod[9], select[0], select[1], select[2]);
	_8x1Mux mux10 (R[10], R_and[10], R_or[10], R_xor[10], R_nor[10], R_lt[10], R_add[10], R_sub[10], R_mod[10], select[0], select[1], select[2]);
	_8x1Mux mux11 (R[11], R_and[11], R_or[11], R_xor[11], R_nor[11], R_lt[11], R_add[11], R_sub[11], R_mod[11], select[0], select[1], select[2]);
	_8x1Mux mux12 (R[12], R_and[12], R_or[12], R_xor[12], R_nor[12], R_lt[12], R_add[12], R_sub[12], R_mod[12], select[0], select[1], select[2]);
	_8x1Mux mux13 (R[13], R_and[13], R_or[13], R_xor[13], R_nor[13], R_lt[13], R_add[13], R_sub[13], R_mod[13], select[0], select[1], select[2]);
	_8x1Mux mux14 (R[14], R_and[14], R_or[14], R_xor[14], R_nor[14], R_lt[14], R_add[14], R_sub[14], R_mod[14], select[0], select[1], select[2]);
	_8x1Mux mux15 (R[15], R_and[15], R_or[15], R_xor[15], R_nor[15], R_lt[15], R_add[15], R_sub[15], R_mod[15], select[0], select[1], select[2]);
	_8x1Mux mux16 (R[16], R_and[16], R_or[16], R_xor[16], R_nor[16], R_lt[16], R_add[16], R_sub[16], R_mod[16], select[0], select[1], select[2]);
	_8x1Mux mux17 (R[17], R_and[17], R_or[17], R_xor[17], R_nor[17], R_lt[17], R_add[17], R_sub[17], R_mod[17], select[0], select[1], select[2]);
	_8x1Mux mux18 (R[18], R_and[18], R_or[18], R_xor[18], R_nor[18], R_lt[18], R_add[18], R_sub[18], R_mod[18], select[0], select[1], select[2]);
	_8x1Mux mux19 (R[19], R_and[19], R_or[19], R_xor[19], R_nor[19], R_lt[19], R_add[19], R_sub[19], R_mod[19], select[0], select[1], select[2]);
	_8x1Mux mux20 (R[20], R_and[20], R_or[20], R_xor[20], R_nor[20], R_lt[20], R_add[20], R_sub[20], R_mod[20], select[0], select[1], select[2]);
	_8x1Mux mux21 (R[21], R_and[21], R_or[21], R_xor[21], R_nor[21], R_lt[21], R_add[21], R_sub[21], R_mod[21], select[0], select[1], select[2]);
	_8x1Mux mux22 (R[22], R_and[22], R_or[22], R_xor[22], R_nor[22], R_lt[22], R_add[22], R_sub[22], R_mod[22], select[0], select[1], select[2]);
	_8x1Mux mux23 (R[23], R_and[23], R_or[23], R_xor[23], R_nor[23], R_lt[23], R_add[23], R_sub[23], R_mod[23], select[0], select[1], select[2]);
	_8x1Mux mux24 (R[24], R_and[24], R_or[24], R_xor[24], R_nor[24], R_lt[24], R_add[24], R_sub[24], R_mod[24], select[0], select[1], select[2]);
	_8x1Mux mux25 (R[25], R_and[25], R_or[25], R_xor[25], R_nor[25], R_lt[25], R_add[25], R_sub[25], R_mod[25], select[0], select[1], select[2]);
	_8x1Mux mux26 (R[26], R_and[26], R_or[26], R_xor[26], R_nor[26], R_lt[26], R_add[26], R_sub[26], R_mod[26], select[0], select[1], select[2]);
	_8x1Mux mux27 (R[27], R_and[27], R_or[27], R_xor[27], R_nor[27], R_lt[27], R_add[27], R_sub[27], R_mod[27], select[0], select[1], select[2]);
	_8x1Mux mux28 (R[28], R_and[28], R_or[28], R_xor[28], R_nor[28], R_lt[28], R_add[28], R_sub[28], R_mod[28], select[0], select[1], select[2]);
	_8x1Mux mux29 (R[29], R_and[29], R_or[29], R_xor[29], R_nor[29], R_lt[29], R_add[29], R_sub[29], R_mod[29], select[0], select[1], select[2]);
	_8x1Mux mux30 (R[30], R_and[30], R_or[30], R_xor[30], R_nor[30], R_lt[30], R_add[30], R_sub[30], R_mod[30], select[0], select[1], select[2]);
	_8x1Mux mux31 (R[31], R_and[31], R_or[31], R_xor[31], R_nor[31], R_lt[31], R_add[31], R_sub[31], R_mod[31], select[0], select[1], select[2]);

endmodule
