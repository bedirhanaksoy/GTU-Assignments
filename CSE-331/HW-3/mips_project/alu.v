module alu(output [31:0]alu_result, 
				output zero_bit, 
				input [31:0]alu_src1, 
				input [31:0]alu_src2, 
				input [2:0]alu_ctr);
	
	wire lt,sign,carry_out_sum;
	wire [31:0]R_and, R_or, R_lt, R_xor, R_nor, R_add, R_sub, R_move;
	wire [31:0] alu_result_;
	
	my_and myand1(R_and[31:0], alu_src1[31:0], alu_src2[31:0]);
	my_or myor1(R_or[31:0], alu_src1[31:0], alu_src2[31:0]);
	is_less_than lt_1(R_lt[0], alu_src1[31:0], alu_src2[31:0]);
	my_xor myxor1(R_xor[31:0], alu_src1[31:0], alu_src2[31:0]);
	my_nor mynor1(R_nor[31:0], alu_src1[31:0], alu_src2[31:0]);
	thirty_two_bit_adder adder1(carry_out_sum, R_add[31:0], alu_src1[31:0], alu_src2[31:0], 1'b0);
	thirty_two_bit_subtractor sub1(R_sub[31:0], sign, alu_src1[31:0], alu_src2[31:0]);
	move move1(R_move[31:0], alu_src1[31:0]);
	
	_8x1Mux mux0 (alu_result[0], R_and[0], R_or[0], R_xor[0], R_nor[0], R_lt[0], R_add[0], R_sub[0], R_move[0], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux1 (alu_result[1], R_and[1], R_or[1], R_xor[1], R_nor[1], R_lt[1], R_add[1], R_sub[1], R_move[1], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux2 (alu_result[2], R_and[2], R_or[2], R_xor[2], R_nor[2], R_lt[2], R_add[2], R_sub[2], R_move[2], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux3 (alu_result[3], R_and[3], R_or[3], R_xor[3], R_nor[3], R_lt[3], R_add[3], R_sub[3], R_move[3], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux4 (alu_result[4], R_and[4], R_or[4], R_xor[4], R_nor[4], R_lt[4], R_add[4], R_sub[4], R_move[4], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux5 (alu_result[5], R_and[5], R_or[5], R_xor[5], R_nor[5], R_lt[5], R_add[5], R_sub[5], R_move[5], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux6 (alu_result[6], R_and[6], R_or[6], R_xor[6], R_nor[6], R_lt[6], R_add[6], R_sub[6], R_move[6], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux7 (alu_result[7], R_and[7], R_or[7], R_xor[7], R_nor[7], R_lt[7], R_add[7], R_sub[7], R_move[7], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux8 (alu_result[8], R_and[8], R_or[8], R_xor[8], R_nor[8], R_lt[8], R_add[8], R_sub[8], R_move[8], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux9 (alu_result[9], R_and[9], R_or[9], R_xor[9], R_nor[9], R_lt[9], R_add[9], R_sub[9], R_move[9], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux10 (alu_result[10], R_and[10], R_or[10], R_xor[10], R_nor[10], R_lt[10], R_add[10], R_sub[10], R_move[10], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux11 (alu_result[11], R_and[11], R_or[11], R_xor[11], R_nor[11], R_lt[11], R_add[11], R_sub[11], R_move[11], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux12 (alu_result[12], R_and[12], R_or[12], R_xor[12], R_nor[12], R_lt[12], R_add[12], R_sub[12], R_move[12], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux13 (alu_result[13], R_and[13], R_or[13], R_xor[13], R_nor[13], R_lt[13], R_add[13], R_sub[13], R_move[13], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux14 (alu_result[14], R_and[14], R_or[14], R_xor[14], R_nor[14], R_lt[14], R_add[14], R_sub[14], R_move[14], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux15 (alu_result[15], R_and[15], R_or[15], R_xor[15], R_nor[15], R_lt[15], R_add[15], R_sub[15], R_move[15], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux16 (alu_result[16], R_and[16], R_or[16], R_xor[16], R_nor[16], R_lt[16], R_add[16], R_sub[16], R_move[16], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux17 (alu_result[17], R_and[17], R_or[17], R_xor[17], R_nor[17], R_lt[17], R_add[17], R_sub[17], R_move[17], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux18 (alu_result[18], R_and[18], R_or[18], R_xor[18], R_nor[18], R_lt[18], R_add[18], R_sub[18], R_move[18], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux19 (alu_result[19], R_and[19], R_or[19], R_xor[19], R_nor[19], R_lt[19], R_add[19], R_sub[19], R_move[19], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux20 (alu_result[20], R_and[20], R_or[20], R_xor[20], R_nor[20], R_lt[20], R_add[20], R_sub[20], R_move[20], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux21 (alu_result[21], R_and[21], R_or[21], R_xor[21], R_nor[21], R_lt[21], R_add[21], R_sub[21], R_move[21], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux22 (alu_result[22], R_and[22], R_or[22], R_xor[22], R_nor[22], R_lt[22], R_add[22], R_sub[22], R_move[22], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux23 (alu_result[23], R_and[23], R_or[23], R_xor[23], R_nor[23], R_lt[23], R_add[23], R_sub[23], R_move[23], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux24 (alu_result[24], R_and[24], R_or[24], R_xor[24], R_nor[24], R_lt[24], R_add[24], R_sub[24], R_move[24], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux25 (alu_result[25], R_and[25], R_or[25], R_xor[25], R_nor[25], R_lt[25], R_add[25], R_sub[25], R_move[25], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux26 (alu_result[26], R_and[26], R_or[26], R_xor[26], R_nor[26], R_lt[26], R_add[26], R_sub[26], R_move[26], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux27 (alu_result[27], R_and[27], R_or[27], R_xor[27], R_nor[27], R_lt[27], R_add[27], R_sub[27], R_move[27], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux28 (alu_result[28], R_and[28], R_or[28], R_xor[28], R_nor[28], R_lt[28], R_add[28], R_sub[28], R_move[28], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux29 (alu_result[29], R_and[29], R_or[29], R_xor[29], R_nor[29], R_lt[29], R_add[29], R_sub[29], R_move[29], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux30 (alu_result[30], R_and[30], R_or[30], R_xor[30], R_nor[30], R_lt[30], R_add[30], R_sub[30], R_move[30], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	_8x1Mux mux31 (alu_result[31], R_and[31], R_or[31], R_xor[31], R_nor[31], R_lt[31], R_add[31], R_sub[31], R_move[31], alu_ctr[0], alu_ctr[1], alu_ctr[2]);
	
	

  not not1(alu_result_[31], alu_result[31]);
  not not2(alu_result_[30], alu_result[30]);
  not not3(alu_result_[29], alu_result[29]);
  not not4(alu_result_[28], alu_result[28]);
  not not5(alu_result_[27], alu_result[27]);
  not not6(alu_result_[26], alu_result[26]);
  not not7(alu_result_[25], alu_result[25]);
  not not8(alu_result_[24], alu_result[24]);
  not not9(alu_result_[23], alu_result[23]);
  not not10(alu_result_[22], alu_result[22]);
  not not11(alu_result_[21], alu_result[21]);
  not not12(alu_result_[20], alu_result[20]);
  not not13(alu_result_[19], alu_result[19]);
  not not14(alu_result_[18], alu_result[18]);
  not not15(alu_result_[17], alu_result[17]);
  not not16(alu_result_[16], alu_result[16]);
  not not17(alu_result_[15], alu_result[15]);
  not not18(alu_result_[14], alu_result[14]);
  not not19(alu_result_[13], alu_result[13]);
  not not20(alu_result_[12], alu_result[12]);
  not not21(alu_result_[11], alu_result[11]);
  not not22(alu_result_[10], alu_result[10]);
  not not23(alu_result_[9], alu_result[9]);
  not not24(alu_result_[8], alu_result[8]);
  not not25(alu_result_[7], alu_result[7]);
  not not26(alu_result_[6], alu_result[6]);
  not not27(alu_result_[5], alu_result[5]);
  not not28(alu_result_[4], alu_result[4]);
  not not29(alu_result_[3], alu_result[3]);
  not not30(alu_result_[2], alu_result[2]);
  not not31(alu_result_[1], alu_result[1]);
  not not32(alu_result_[0], alu_result[0]);

  and and1(zero_bit, alu_result_[31], alu_result_[30], alu_result_[29], alu_result_[28], alu_result_[27], alu_result_[26], alu_result_[25], alu_result_[24], alu_result_[23], alu_result_[22], alu_result_[21], alu_result_[20], alu_result_[19], alu_result_[18], alu_result_[17], alu_result_[16], alu_result_[15], alu_result_[14], alu_result_[13], alu_result_[12], alu_result_[11], alu_result_[10], alu_result_[9], alu_result_[8], alu_result_[7], alu_result_[6], alu_result_[5], alu_result_[4], alu_result_[3], alu_result_[2], alu_result_[1], alu_result_[0]);
 
	
endmodule
