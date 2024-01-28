module control_unit(
output regDst,
output branch,
output memRead,
output memWrite,
output [2:0] ALUop,
output ALUsrc,
output regWrite,
output jump,
output byteOperations,
output move,
input [5:0] opcode
);

wire [5:0] opcode_;

wire [1:0] store_;

wire [6:0] res;
wire [4:0] temp_res_1;
wire [2:0] temp_res_2;
wire [2:0] temp_res_3;

wire is_move_op;
wire temp_regWrite;

not(opcode_[0], opcode[0]);
not(opcode_[1], opcode[1]);
not(opcode_[2], opcode[2]);
not(opcode_[3], opcode[3]);
not(opcode_[4], opcode[4]);
not(opcode_[5], opcode[5]);

wire move_;

not(move_, move);

not(store_[1], temp_res_1[2]); // not of the store operations 
not(store_[0], temp_res_1[0]); 


and is_111(res[5], opcode_[5], opcode_[4], opcode_[3], opcode_[2], opcode_[1], opcode_[0]);

and is_000(res[4], opcode_[5], opcode_[4], opcode_[3], opcode[2], opcode_[1], opcode_[0]);

and is_001(res[3], opcode_[5], opcode_[4], opcode_[3], opcode[2], opcode_[1], opcode[0]);

and is_100(res[2], opcode_[5], opcode_[4], opcode_[3], opcode[2], opcode[1], opcode[0]);

or  is_101(res[1], temp_res_1[0], temp_res_1[1], temp_res_1[2], temp_res_1[3], temp_res_1[4]);

or is_110(res[0], temp_res_2[2], temp_res_2[1], temp_res_2[0]);

or is_111_or_move(res[6], res[5], temp_res_3[2]);


or ALUop_2(ALUop[2], res[2], res[1], res[0], res[6]);

or ALUop_1(ALUop[1], res[0], res[6]);

or ALUop_0(ALUop[0], res[3], res[1], res[6]);

and regDst_is(regDst, res[5], move_); // R type operations makes regDst 1

or branch_is(branch, temp_res_2[1], temp_res_2[0], temp_res_3[1], temp_res_3[0]); // beq or bne or jump ops makes branch 1

or memRead_is(memRead, temp_res_1[3], temp_res_1[1]); // lw or lb makes memRead 1

or memWrite_is(memWrite, temp_res_1[2], temp_res_1[0]); // sw or sb makes memWrite 1

or ALUsrc_is(ALUsrc, res[1], res[4], res[3], res[2], temp_res_2[2]); // ALUsrc is 1 when there is immediate value or load-store operation

and temp_regWrite_is(temp_regWrite, store_[0], store_[1]);

or regWrite_is(regWrite, temp_regWrite, temp_res_3[2]);

or jump_is(jump, temp_res_3[1], temp_res_3[0]);

or byteOperation_is(byteOperations, temp_res_1[1], temp_res_1[0]);

and move_is(move, temp_res_3[2], 1'b1);


and is_addi(temp_res_1[4], opcode_[5], opcode_[4], opcode_[3], opcode_[2], opcode[1], opcode_[0]);

and is_lw(temp_res_1[3], opcode_[5], opcode_[4], opcode[3], opcode_[2], opcode_[1], opcode_[0]);

and is_sw(temp_res_1[2], opcode_[5], opcode[4], opcode_[3], opcode_[2], opcode_[1], opcode_[0]);

and is_lb(temp_res_1[1], opcode_[5], opcode_[4], opcode[3], opcode_[2], opcode_[1], opcode[0]);

and is_sb(temp_res_1[0], opcode_[5], opcode[4], opcode_[3], opcode_[2], opcode_[1], opcode[0]);


and is_subi(temp_res_2[2], opcode_[5], opcode_[4], opcode_[3], opcode_[2], opcode[1], opcode[0]);

and is_beq(temp_res_2[1], opcode[5], opcode_[4], opcode_[3], opcode_[2], opcode[1], opcode[0]);

and is_bne(temp_res_2[0], opcode[5], opcode_[4], opcode_[3], opcode[2], opcode[1], opcode[0]);


and is_move(temp_res_3[2], opcode[5], opcode_[4], opcode_[3], opcode_[2], opcode_[1], opcode_[0]);

and is_j(temp_res_3[1], opcode[5], opcode[4], opcode[3], opcode_[2], opcode_[1], opcode_[0]);

and is_jal(temp_res_3[0], opcode[5], opcode[4], opcode[3], opcode_[2], opcode_[1], opcode[0]);



endmodule
