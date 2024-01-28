module test_mips;

  // Inputs
  reg clk;

  // Instantiate the Unit Under Test (UUT)
  mips testbench (
    .clk(clk)
  );

  initial begin
    // Initialize Inputs
    #20 clk = 0;
    #20 clk = 1;
	 #20 clk = 0;
    #20 clk = 1;
    #20 clk = 0;
	 #20 clk = 1;
    #20 clk = 0;
	 #20 clk = 1;
    #20 clk = 0;
	 #20 clk = 1;
    #20 clk = 0;
	 
	 #20 $finish;
  end
  
endmodule
