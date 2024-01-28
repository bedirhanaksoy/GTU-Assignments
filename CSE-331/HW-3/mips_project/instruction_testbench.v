`timescale 1ns / 1ps

module instruction_testbench;
    // Inputs
    reg [31:0] pc;

    // Outputs
    wire [31:0] instruction;

    // Instantiate the Unit Under Test (UUT)
    instruction_block ib (
        .instruction(instruction), 
        .pc(pc)
    );

    initial begin
        // Initialize Inputs
        pc = 0;
		  #10
		  $display("%b", instruction);
		  
        // Wait 100 ns for global reset to finish
        #100;
        
        // Add stimulus here
        pc = 32'h00000004; // Change program counter
        #10;
		  $display("%b", instruction);

        pc = 32'h00000008; // Change program counter
        #10;
		  $display("%b", instruction);

    end
      
endmodule