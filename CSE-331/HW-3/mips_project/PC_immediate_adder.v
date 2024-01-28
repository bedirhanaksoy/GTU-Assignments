module PC_immediate_adder(input [31:0] shift_left_result, 
								  input [31:0] PC_4_add_result, 
								  output [31:0] PC_shift_left_add_result);

								  
wire cin;
wire cout;

thirty_two_bit_adder adder2(cout, PC_shift_left_add_result[31:0], shift_left_result[31:0], PC_4_add_result[31:0], cin);

endmodule
