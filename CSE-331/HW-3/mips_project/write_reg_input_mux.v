module write_reg_input_mux(input [4:0] write_reg_1, input [4:0] write_reg_2, input regDst, output [4:0] selected_write_reg);


wire [4:0] temp_res_1;
wire [4:0] temp_res_2;
wire regDst_;

not not1(regDst_, regDst);

and and1(temp_res_1[4], write_reg_1[4], regDst_);
and and2(temp_res_1[3], write_reg_1[3], regDst_);
and and3(temp_res_1[2], write_reg_1[2], regDst_);
and and4(temp_res_1[1], write_reg_1[1], regDst_);
and and5(temp_res_1[0], write_reg_1[0], regDst_);

and and6(temp_res_2[4], write_reg_2[4], regDst);
and and7(temp_res_2[3], write_reg_2[3], regDst);
and and8(temp_res_2[2], write_reg_2[2], regDst);
and and9(temp_res_2[1], write_reg_2[1], regDst);
and and0(temp_res_2[0], write_reg_2[0], regDst);

or or1(selected_write_reg[4], temp_res_1[4], temp_res_2[4]);
or or2(selected_write_reg[3], temp_res_1[3], temp_res_2[3]);
or or3(selected_write_reg[2], temp_res_1[2], temp_res_2[2]);
or or4(selected_write_reg[1], temp_res_1[1], temp_res_2[1]);
or or5(selected_write_reg[0], temp_res_1[0], temp_res_2[0]);


endmodule
