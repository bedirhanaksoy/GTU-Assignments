module mod_cu(
	input reset,
	input CLK,
	input x,
	output reg loadA,
	output reg doSub
);
reg [1:0] curr_state, next_state;
localparam 	S0 	= 2'b00,
				S1 	= 2'b01,
				S2 	= 2'b10;
				
//State Registers			
always @(posedge CLK)
	begin
	if(reset)
		curr_state <= S0;
	else
		curr_state <= next_state;
	end
	
//Next State Logic
always @(*)
	begin
	case(curr_state)
	S0: 	begin
			next_state = S1;
			end
	
	S1: begin
			if(x)
				next_state = S2;
			else
				next_state = S1;
			end
	
	S2: begin
			 end
	
	endcase
	end
	
//Output Logic
always @(*)
	begin
	loadA = 0;
	doSub = 0;
	case(curr_state)
	S0: 	begin
			loadA = 1;
			doSub = 0;
			end
	
	S1: begin
			loadA = 0;
			doSub = 1;
			end
	
	S2: begin
			loadA = 0;
			doSub = 0;
			end
	
	endcase
end
endmodule





