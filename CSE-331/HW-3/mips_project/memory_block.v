module memory_block (
    output reg [31:0] read_data,
    input byteOperations,
    input [31:0] address,
    input [31:0] write_data,
    input memRead,
    input memWrite
);

    reg [31:0] memory [31:0];

    always @ (*) begin
        if (memRead) begin
            $readmemb("memory.mem", memory);
            if (byteOperations) begin
                read_data[7:0] = memory[address][7:0];
            end else begin
                read_data = memory[address];
            end
        end
        if (memWrite) begin
            $readmemb("memory.mem", memory);
            if (byteOperations) begin
                memory[address][7:0] = write_data[7:0];
            end else begin
                memory[address] = write_data;
            end
            $writememb("memory.mem", memory);
        end
    end

endmodule