`timescale 1ns / 1ps

module memory_block_testbench;

    // Inputs
    reg byteOperations;
    reg [17:0] address;
    reg [31:0] write_data;
    reg memRead;
    reg memWrite;

    // Outputs
    wire [31:0] read_data;

    // Instantiate the Unit Under Test (UUT)
    memory_block mb1 (
        .read_data(read_data), 
        .byteOperations(byteOperations), 
        .address(address), 
        .write_data(write_data), 
        .memRead(memRead), 
        .memWrite(memWrite)
    );

    initial begin
        // Initialize Inputs
        byteOperations = 0;
        address = 9;
        write_data = 32'b01101001010110101001010101011010;
        memRead = 0;
        memWrite = 1;

        // Wait 100 ns for global reset to finish
        #100;
        memRead = 1;
        address = 18'b000000000000000100;
		  #5 $display("%b", read_data);
    end

endmodule
