module thirty_two_bit_subtractor(output [31:0] R, output sign, input [31:0] A, input [31:0] B);
	
	wire [31:0] B_TC;
	
	my_twos_complement tws1(B_TC[31:0], B[31:0]);
	
	thirty_two_bit_adder adder1(sign, R[31:0], A[31:0], B_TC[31:0], 0);
	
endmodule
