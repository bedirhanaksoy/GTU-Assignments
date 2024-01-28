module mod_dp(
	input CLK,
	input loadA,
	input doSub,
	input [31:0] A,
	input [31:0] B,
	output reg [31:0] R,
	output reg x
);

wire w1, w2;
reg [31:0] temp;
wire [31:0] sub;
always @(posedge CLK) begin

	if (loadA) begin
		temp <= A;
	end
	else if (w2) begin
		R <= temp;
	end
	else if (doSub) begin
		temp <= sub; 
		x <= w2; 
	end 

	
	

	end
	thirty_two_bit_subtractor subb1(sub[31:0], w1, temp[31:0], B[31:0]);
	is_less_than is_lt1(w2, temp[31:0], B[31:0]);
	
endmodule





