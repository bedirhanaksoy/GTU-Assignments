module instruction_block (
    output reg [31:0] instruction,
    input [31:0] pc
);

    reg [31:0] instructions [0:16];

    initial begin
        $readmemb("instructions.mem", instructions); // Read initial instructions from file
    end

    always @(*) begin
        instruction <= instructions[pc];
    end

endmodule
