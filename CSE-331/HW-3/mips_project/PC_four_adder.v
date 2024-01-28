module PC_four_adder(input [31:0] PC, output [31:0] incremented_PC);

wire cin;
wire cout;

thirty_two_bit_adder adder1(cout, incremented_PC[31:0], PC[31:0], 32'b00000000000000000000000000000100,cin);


endmodule
