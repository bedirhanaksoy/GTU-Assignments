module mod(
	input [31:0] A,
	input [31:0] B,
	input reset,
	input clk,
	output [31:0] R
);
wire x, loadA, doSub;
mod_cu modcu1(
	reset,
	clk,
	x,
	loadA,
	doSub
);
mod_dp moddp1(
	clk,
	loadA,
	doSub,
	A[31:0],
	B[31:0],
	R[31:0],
	x
);
endmodule
