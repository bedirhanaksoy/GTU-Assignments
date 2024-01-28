module my_twos_complement(output [31:0] T, input [31:0] A);
	 
	 wire [31:0]R;
	 wire overflow;
	 
    not not1(R[0], A[0]);
    not not2(R[1], A[1]);
    not not3(R[2], A[2]);
    not not4(R[3], A[3]);
    not not5(R[4], A[4]);
    not not6(R[5], A[5]);
    not not7(R[6], A[6]);
    not not8(R[7], A[7]);
    not not9(R[8], A[8]);
    not not10(R[9], A[9]);
    not not11(R[10], A[10]);
    not not12(R[11], A[11]);
    not not13(R[12], A[12]);
    not not14(R[13], A[13]);
    not not15(R[14], A[14]);
    not not16(R[15], A[15]);
    not not17(R[16], A[16]);
    not not18(R[17], A[17]);
    not not19(R[18], A[18]);
    not not20(R[19], A[19]);
    not not21(R[20], A[20]);
    not not22(R[21], A[21]);
    not not23(R[22], A[22]);
    not not24(R[23], A[23]);
    not not25(R[24], A[24]);
    not not26(R[25], A[25]);
    not not27(R[26], A[26]);
    not not28(R[27], A[27]);
    not not29(R[28], A[28]);
    not not30(R[29], A[29]);
    not not31(R[30], A[30]);
    not not32(R[31], A[31]);
	 
	 thirty_two_bit_adder adder1(overflow, T[31:0], R[31:0], 32'b00000000000000000000000000000001, 1'b0);
endmodule
