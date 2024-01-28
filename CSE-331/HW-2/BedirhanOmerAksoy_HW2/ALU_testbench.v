module ALU_testbench();

	reg [31:0] a;
	reg [31:0] b;
	reg reset;
	reg CLK;

	reg [2:0] select;
	
	wire [31:0] result;
	
	ALU my_alu(a[31:0], b[31:0], select[2:0], result[31:0], CLK, reset);
	
	initial begin
	
	a = 32'b00000110100000000001101001010001;
   b = 32'b01101001010101011110000101011010;
	select = 3'b000;
	#20;
   $display("Inputs: \na=	%b, \nb=    %b, \n", a, $signed(a), b, $signed(b));
	#10;
	$display("res=  %b, select=%b (AND)\n", result, select);
	        
	a = 32'b01101001011010010101010101011010;
   b = 32'b10010110100101010101010110101010;
	select = 3'b001;
	#20;
   $display("Inputs: \na=	%b, decimal a=%d\nb=    %b, decimal b=%d\n", a, $signed(a), b, $signed(b));
	#10;
	$display("res=  %b, select=%b (OR)\n", result, select);
	        
	a = 32'b11110000011111100000111111000000;
   b = 32'b00000111111000000011000000000111;
	select = 3'b010;
	#20;
   $display("Inputs: \na=	%b, decimal a=%d\nb=    %b, decimal b=%d\n", a, $signed(a), b, $signed(b));
	#10;
	$display("res=  %b, select=%b (XOR)\n", result, select);
	        
	a = 32'b00010000101011110001001010101010;
   b = 32'b10100001010101011010000111110000;
	select = 3'b011;
	#20;
   $display("Inputs: \na=	%b, decimal a=%d\nb=    %b, decimal b=%d\n", a, $signed(a), b, $signed(b));
	#10;
	$display("res=  %b, select=%b (NOR)\n", result, select);
	        
	a = 32'b00000000000000000000000011011111;
   b = 32'b00000000000000000000001000110110;
	select = 3'b100;
	#20;
   $display("Inputs: \na=	%b, decimal a=%d\nb=    %b, decimal b=%d\n", a, $signed(a), b, $signed(b));
	#10;
	$display("res=  %b, select=%b (LESS THAN)\n", result, select);
	        
	a = 32'b00000000000000000100010111000001;
   b = 32'b00000000000000000000100001110110;
	select = 3'b101;
	#20;
   $display("Inputs: \na=	%b, decimal a=%d\nb=    %b, decimal b=%d\n", a, $signed(a), b, $signed(b));
	#10;
	$display("res=  %b, select=%b (ADD)\n", result, select);
	        
	a = 32'b00000000000000000011110000110001;
   b = 32'b00000000000000000001111100111001;
	select = 3'b110;
	#20;
   $display("Inputs: \na=	%b, decimal a=%d\nb=    %b, decimal b=%d\n", a, $signed(a), b, $signed(b));
	#10;
	$display("res=  %b, select=%b (SUB)\n", result, select);
	        
	a = 32'b00000000000000000000000000010100;
   b = 32'b00000000000000000000000000000011;
	CLK = 1'b0;
	reset = 1'b1;
	select = 3'b111;
	#20;
	reset = 1'b0;
   $display("Inputs: \na=	%b, decimal a=%d\nb=    %b, decimal b=%d\n", a, $signed(a), b, $signed(b));
	#50;
	$display("res=  %b, decimal res=%d select=%b (MOD)\n", result, result, select);  
	
	$stop; // End simulation

	end

	always 
	begin
	#1
	CLK = ~CLK;
	end

endmodule