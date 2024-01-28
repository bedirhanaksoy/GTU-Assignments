module mips(input clk);

reg  [31:0] PC_next;
wire [31:0] PC;
wire [31:0] PC_mux_out;
wire [31:0] instruction;
wire [31:0] sign_extended;
wire [31:0] PC_4_add_result;
wire [31:0] PC_shift_left_add_result;
wire [31:0] shift_left_result;
wire [31:0] ALU_result;
wire [31:0] read_data1;
wire [31:0] read_data2;
wire [31:0] write_data;
wire [4:0]  write_reg;
wire [31:0] mem_read_data;
wire [2:0]  alu_ctr;
wire [31:0] selected_PC_to_jump_or_four_added_pc;

wire regDst;
wire branch;
wire memRead;
wire memWrite;
wire [2:0] ALUop;
wire ALUsrc;
wire regWrite;
wire jump;
wire byteOperations;
wire move;
wire zero_bit;
wire [31:0] alu_input_mux_result;
wire branch_and_zero;
wire zero_bit_result;

	initial begin
		PC_next <= 32'b00000000000000000000000000000000;
	end

  always @(posedge clk) begin
		PC_next <= selected_PC_to_jump_or_four_added_pc;
  end
  
  assign PC = PC_next;
  assign PC_test = PC_next;


and pc_mux_and(branch_and_zero, branch, zero_bit_result);

instruction_block ib(instruction[31:0], PC[31:0]);

control_unit cu(regDst, branch, memRead, memWrite, ALUop[2:0], ALUsrc, regWrite, jump, byteOperations, move, instruction[31:26]);

write_reg_input_mux mux1(instruction[20:16], instruction[15:11], regDst, write_reg[4:0]);

register_block rb(read_data1[31:0], read_data2[31:0], byteOperations, write_data[31:0], instruction[25:21], instruction[20:16], write_reg[4:0], regWrite);

sign_extend se(sign_extended[31:0], instruction[15:0]);

alu_control ac(alu_ctr[2:0], instruction[5:0], ALUop[2:0]);

alu_input_mux mux2(read_data2[31:0], sign_extended[31:0], ALUsrc, alu_input_mux_result[31:0]);

alu alu1(ALU_result[31:0], zero_bit, read_data1[31:0], alu_input_mux_result[31:0], alu_ctr[2:0]);

shift_left_2 sl(shift_left_result[31:0], sign_extended[31:0]);

PC_four_adder pfa(PC[31:0], PC_4_add_result[31:0]);

PC_immediate_adder pia(shift_left_result[31:0], PC_4_add_result[31:0], PC_shift_left_add_result[31:0]);

zero_bit_branch_operations zbb(instruction[31:26], zero_bit, jump, zero_bit_result);

PC_mux pm(PC_4_add_result[31:0], PC_shift_left_add_result[31:0], branch_and_zero, PC_mux_out[31:0]);

jump_mux jm(instruction[25:0], PC_mux_out[31:0], jump, selected_PC_to_jump_or_four_added_pc[31:0]);

memory_block mb(mem_read_data[31:0], byteOperations, ALU_result[31:0], read_data2[31:0], memRead, memWrite);

write_data_mux wdm(mem_read_data[31:0], ALU_result[31:0], memRead, write_data[31:0]);

endmodule
