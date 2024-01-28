module is_less_than(output lt, input [31:0] A, input [31:0] B);
	
	wire sign;
	wire [31:0]res;
	
	thirty_two_bit_subtractor sub(res, sign, A[31:0], B[31:0]);
	
	not not1(lt, sign);
	
endmodule