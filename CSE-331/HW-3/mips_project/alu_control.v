module alu_control(
output [2:0] alu_ctr,
input [5:0] function_code,
input [2:0] ALUop);


wire is_R_type;
wire is_not_R_type;
wire is_move;

wire [5:0] function_code_;

wire [5:0] res;

wire [2:0] can_I_type_op;


not not1(function_code_[5], function_code[5]);
not not2(function_code_[4], function_code[4]);
not not3(function_code_[3], function_code[3]);
not not4(function_code_[2], function_code[2]);
not not5(function_code_[1], function_code[1]);
not not6(function_code_[0], function_code[0]);
not not7(is_not_R_type, is_R_type);


or ALUctr_2(alu_ctr[2], can_I_type_op[2], res[3], res[2], res[1], is_move);

or ALUctr_1(alu_ctr[1], can_I_type_op[1], res[1], is_move);

or ALUctr_0(alu_ctr[0], can_I_type_op[0], res[4], res[2], is_move);



and find_type(is_R_type, ALUop[2], ALUop[1], ALUop[0]);

and find_move(is_move, function_code_[5], function_code_[4], function_code_[3], function_code_[2], function_code_[1], function_code_[0], ALUop[2], ALUop[1], ALUop[0]);



and is_not_R_type_op1(can_I_type_op[2], ALUop[2], is_not_R_type);

and is_not_R_type_op2(can_I_type_op[1], ALUop[1], is_not_R_type);

and is_not_R_type_op3(can_I_type_op[0], ALUop[0], is_not_R_type);



and is_and(res[5], is_R_type, function_code_[5], function_code_[4], function_code_[3], function_code[2], function_code_[1], function_code_[0]);

and is_or(res[4], is_R_type, function_code_[5], function_code_[4], function_code_[3], function_code[2], function_code_[1], function_code[0]);

and is_slt(res[3], is_R_type, function_code_[5], function_code_[4], function_code_[3], function_code[2], function_code[1], function_code[0]);

and is_add(res[2], is_R_type, function_code_[5], function_code_[4], function_code_[3], function_code_[2], function_code[1], function_code_[0]);

and is_sub(res[1], is_R_type, function_code_[5], function_code_[4], function_code_[3], function_code_[2], function_code[1], function_code[0]);

and is_jr(res[0], is_R_type, function_code_[5], function_code_[4], function_code[3], function_code_[2], function_code_[1], function_code_[0]);



endmodule