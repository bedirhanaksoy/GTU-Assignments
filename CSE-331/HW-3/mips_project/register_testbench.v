`timescale 1ns / 1ps

module register_testbench;
    // Inputs
    reg byteOperations;
    reg [31:0] write_data;
    reg [4:0] read_reg1;
    reg [4:0] read_reg2;
    reg [4:0] write_reg;
    reg regWrite;

    // Outputs
    wire [31:0] read_data1;
    wire [31:0] read_data2;

    // Instantiate the Unit Under Test (UUT)
    register_block uut (
        .read_data1(read_data1), 
        .read_data2(read_data2), 
        .byteOperations(byteOperations), 
        .write_data(write_data),
        .read_reg1(read_reg1), 
        .read_reg2(read_reg2), 
        .write_reg(write_reg), 
        .regWrite(regWrite)
    );

    initial begin
        // Initialize Inputs
        byteOperations = 0;
        write_data = 0;
        read_reg1 = 0;
        read_reg2 = 0;
        write_reg = 0;
        regWrite = 0;

        // Wait 100 ns for global reset to finish
        #100;
        
        // Add stimulus here
        write_data = 32'hDEADBEEF;
        write_reg = 5'b00001;
        regWrite = 1'b1;
        #10;
        regWrite = 1'b0;
        read_reg1 = 5'b11111;
        #10;
		  $display("%b", read_data1);
    end
      
endmodule