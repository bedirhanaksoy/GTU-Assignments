module jump_mux(
			input [25:0] jump_address, 
			input [31:0] PC, 
			input jump, 
			output [31:0] selected_PC);


  wire [31:0] temp_res1;
  wire [31:0] temp_res2;

  wire jump_;


  not not1(jump_, jump);

  and and1(temp_res1[31], 1'b0, jump);
  and and2(temp_res1[30], 1'b0, jump);
  and and3(temp_res1[29], 1'b0, jump);
  and and4(temp_res1[28], 1'b0, jump);
  and and5(temp_res1[27], 1'b0, jump);
  and and6(temp_res1[26], 1'b0, jump);
  and and7(temp_res1[25], jump_address[25], jump);
  and and8(temp_res1[24], jump_address[24], jump);
  and and9(temp_res1[23], jump_address[23], jump);
  and and10(temp_res1[22], jump_address[22], jump);
  and and11(temp_res1[21], jump_address[21], jump);
  and and12(temp_res1[20], jump_address[20], jump);
  and and13(temp_res1[19], jump_address[19], jump);
  and and14(temp_res1[18], jump_address[18], jump);
  and and15(temp_res1[17], jump_address[17], jump);
  and and16(temp_res1[16], jump_address[16], jump);
  and and17(temp_res1[15], jump_address[15], jump);
  and and18(temp_res1[14], jump_address[14], jump);
  and and19(temp_res1[13], jump_address[13], jump);
  and and20(temp_res1[12], jump_address[12], jump);
  and and21(temp_res1[11], jump_address[11], jump);
  and and22(temp_res1[10], jump_address[10], jump);
  and and23(temp_res1[9], jump_address[9], jump);
  and and24(temp_res1[8], jump_address[8], jump);
  and and25(temp_res1[7], jump_address[7], jump);
  and and26(temp_res1[6], jump_address[6], jump);
  and and27(temp_res1[5], jump_address[5], jump);
  and and28(temp_res1[4], jump_address[4], jump);
  and and29(temp_res1[3], jump_address[3], jump);
  and and30(temp_res1[2], jump_address[2], jump);
  and and31(temp_res1[1], jump_address[1], jump);
  and and32(temp_res1[0], jump_address[0], jump);

  and and33(temp_res2[31], PC[31], jump_);
  and and34(temp_res2[30], PC[30], jump_);
  and and35(temp_res2[29], PC[29], jump_);
  and and36(temp_res2[28], PC[28], jump_);
  and and37(temp_res2[27], PC[27], jump_);
  and and38(temp_res2[26], PC[26], jump_);
  and and39(temp_res2[25], PC[25], jump_);
  and and40(temp_res2[24], PC[24], jump_);
  and and41(temp_res2[23], PC[23], jump_);
  and and42(temp_res2[22], PC[22], jump_);
  and and43(temp_res2[21], PC[21], jump_);
  and and44(temp_res2[20], PC[20], jump_);
  and and45(temp_res2[19], PC[19], jump_);
  and and46(temp_res2[18], PC[18], jump_);
  and and47(temp_res2[17], PC[17], jump_);
  and and48(temp_res2[16], PC[16], jump_);
  and and49(temp_res2[15], PC[15], jump_);
  and and50(temp_res2[14], PC[14], jump_);
  and and51(temp_res2[13], PC[13], jump_);
  and and52(temp_res2[12], PC[12], jump_);
  and and53(temp_res2[11], PC[11], jump_);
  and and54(temp_res2[10], PC[10], jump_);
  and and55(temp_res2[9], PC[9], jump_);
  and and56(temp_res2[8], PC[8], jump_);
  and and57(temp_res2[7], PC[7], jump_);
  and and58(temp_res2[6], PC[6], jump_);
  and and59(temp_res2[5], PC[5], jump_);
  and and60(temp_res2[4], PC[4], jump_);
  and and61(temp_res2[3], PC[3], jump_);
  and and62(temp_res2[2], PC[2], jump_);
  and and63(temp_res2[1], PC[1], jump_);
  and and64(temp_res2[0], PC[0], jump_);

  or or1(selected_PC[31], temp_res1[31], temp_res2[31]);
  or or2(selected_PC[30], temp_res1[30], temp_res2[30]);
  or or3(selected_PC[29], temp_res1[29], temp_res2[29]);
  or or4(selected_PC[28], temp_res1[28], temp_res2[28]);
  or or5(selected_PC[27], temp_res1[27], temp_res2[27]);
  or or6(selected_PC[26], temp_res1[26], temp_res2[26]);
  or or7(selected_PC[25], temp_res1[25], temp_res2[25]);
  or or8(selected_PC[24], temp_res1[24], temp_res2[24]);
  or or9(selected_PC[23], temp_res1[23], temp_res2[23]);
  or or10(selected_PC[22], temp_res1[22], temp_res2[22]);
  or or11(selected_PC[21], temp_res1[21], temp_res2[21]);
  or or12(selected_PC[20], temp_res1[20], temp_res2[20]);
  or or13(selected_PC[19], temp_res1[19], temp_res2[19]);
  or or14(selected_PC[18], temp_res1[18], temp_res2[18]);
  or or15(selected_PC[17], temp_res1[17], temp_res2[17]);
  or or16(selected_PC[16], temp_res1[16], temp_res2[16]);
  or or17(selected_PC[15], temp_res1[15], temp_res2[15]);
  or or18(selected_PC[14], temp_res1[14], temp_res2[14]);
  or or19(selected_PC[13], temp_res1[13], temp_res2[13]);
  or or20(selected_PC[12], temp_res1[12], temp_res2[12]);
  or or21(selected_PC[11], temp_res1[11], temp_res2[11]);
  or or22(selected_PC[10], temp_res1[10], temp_res2[10]);
  or or23(selected_PC[9], temp_res1[9], temp_res2[9]);
  or or24(selected_PC[8], temp_res1[8], temp_res2[8]);
  or or25(selected_PC[7], temp_res1[7], temp_res2[7]);
  or or26(selected_PC[6], temp_res1[6], temp_res2[6]);
  or or27(selected_PC[5], temp_res1[5], temp_res2[5]);
  or or28(selected_PC[4], temp_res1[4], temp_res2[4]);
  or or29(selected_PC[3], temp_res1[3], temp_res2[3]);
  or or30(selected_PC[2], temp_res1[2], temp_res2[2]);
  or or31(selected_PC[1], temp_res1[1], temp_res2[1]);
  or or32(selected_PC[0], temp_res1[0], temp_res2[0]);

endmodule
