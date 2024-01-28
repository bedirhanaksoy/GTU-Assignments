module testbench;

  wire [31:0] read_data1;
  wire [31:0] read_data2;
  reg byteOperations;
  reg [31:0] write_data;
  reg [4:0]  read_reg1;
  reg [4:0]  read_reg2;
  reg [4:0]  write_reg;
  reg regWrite;

  // Instantiate the register_block module
  register_block m1(read_data1[31:0], read_data2[31:0], byteOperations, 
  write_data[31:0], read_reg1[4:0], read_reg2[4:0], write_reg[4:0], regWrite);

  // Initial block to initialize inputs
  initial begin
  
    #5 read_reg1 = 1;
    #5 read_reg2 = 2;
    #5 regWrite = 1;

    #5 byteOperations = 1;
	 #5 write_reg = 16;
    #5 write_data = 32'b10010101011111110000001010101001;

    // Allow some time for asynchronous operations to complete
    #10;

    // Display the results
    $display("Read Data 1: %h", read_data1);
    $display("Read Data 2: %h", read_data2);

    // Add additional display statements for other signals if needed
  end

endmodule
