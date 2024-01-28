
module alu_input_mux(
  input [31:0] read_data2,
  input [31:0] sign_extended,
  input ALUsrc,
  output [31:0] res
);

  wire [31:0] temp_res1;
  wire [31:0] temp_res2;
  wire ALUsrc_;

  not not1(ALUsrc_, ALUsrc);

  and and1(temp_res1[31], read_data2[31], ALUsrc_);
  and and2(temp_res1[30], read_data2[30], ALUsrc_);
  and and3(temp_res1[29], read_data2[29], ALUsrc_);
  and and4(temp_res1[28], read_data2[28], ALUsrc_);
  and and5(temp_res1[27], read_data2[27], ALUsrc_);
  and and6(temp_res1[26], read_data2[26], ALUsrc_);
  and and7(temp_res1[25], read_data2[25], ALUsrc_);
  and and8(temp_res1[24], read_data2[24], ALUsrc_);
  and and9(temp_res1[23], read_data2[23], ALUsrc_);
  and and10(temp_res1[22], read_data2[22], ALUsrc_);
  and and11(temp_res1[21], read_data2[21], ALUsrc_);
  and and12(temp_res1[20], read_data2[20], ALUsrc_);
  and and13(temp_res1[19], read_data2[19], ALUsrc_);
  and and14(temp_res1[18], read_data2[18], ALUsrc_);
  and and15(temp_res1[17], read_data2[17], ALUsrc_);
  and and16(temp_res1[16], read_data2[16], ALUsrc_);
  and and17(temp_res1[15], read_data2[15], ALUsrc_);
  and and18(temp_res1[14], read_data2[14], ALUsrc_);
  and and19(temp_res1[13], read_data2[13], ALUsrc_);
  and and20(temp_res1[12], read_data2[12], ALUsrc_);
  and and21(temp_res1[11], read_data2[11], ALUsrc_);
  and and22(temp_res1[10], read_data2[10], ALUsrc_);
  and and23(temp_res1[9], read_data2[9], ALUsrc_);
  and and24(temp_res1[8], read_data2[8], ALUsrc_);
  and and25(temp_res1[7], read_data2[7], ALUsrc_);
  and and26(temp_res1[6], read_data2[6], ALUsrc_);
  and and27(temp_res1[5], read_data2[5], ALUsrc_);
  and and28(temp_res1[4], read_data2[4], ALUsrc_);
  and and29(temp_res1[3], read_data2[3], ALUsrc_);
  and and30(temp_res1[2], read_data2[2], ALUsrc_);
  and and31(temp_res1[1], read_data2[1], ALUsrc_);
  and and32(temp_res1[0], read_data2[0], ALUsrc_);

  and and33(temp_res2[31], sign_extended[31], ALUsrc);
  and and34(temp_res2[30], sign_extended[30], ALUsrc);
  and and35(temp_res2[29], sign_extended[29], ALUsrc);
  and and36(temp_res2[28], sign_extended[28], ALUsrc);
  and and37(temp_res2[27], sign_extended[27], ALUsrc);
  and and38(temp_res2[26], sign_extended[26], ALUsrc);
  and and39(temp_res2[25], sign_extended[25], ALUsrc);
  and and40(temp_res2[24], sign_extended[24], ALUsrc);
  and and41(temp_res2[23], sign_extended[23], ALUsrc);
  and and42(temp_res2[22], sign_extended[22], ALUsrc);
  and and43(temp_res2[21], sign_extended[21], ALUsrc);
  and and44(temp_res2[20], sign_extended[20], ALUsrc);
  and and45(temp_res2[19], sign_extended[19], ALUsrc);
  and and46(temp_res2[18], sign_extended[18], ALUsrc);
  and and47(temp_res2[17], sign_extended[17], ALUsrc);
  and and48(temp_res2[16], sign_extended[16], ALUsrc);
  and and49(temp_res2[15], sign_extended[15], ALUsrc);
  and and50(temp_res2[14], sign_extended[14], ALUsrc);
  and and51(temp_res2[13], sign_extended[13], ALUsrc);
  and and52(temp_res2[12], sign_extended[12], ALUsrc);
  and and53(temp_res2[11], sign_extended[11], ALUsrc);
  and and54(temp_res2[10], sign_extended[10], ALUsrc);
  and and55(temp_res2[9], sign_extended[9], ALUsrc);
  and and56(temp_res2[8], sign_extended[8], ALUsrc);
  and and57(temp_res2[7], sign_extended[7], ALUsrc);
  and and58(temp_res2[6], sign_extended[6], ALUsrc);
  and and59(temp_res2[5], sign_extended[5], ALUsrc);
  and and60(temp_res2[4], sign_extended[4], ALUsrc);
  and and61(temp_res2[3], sign_extended[3], ALUsrc);
  and and62(temp_res2[2], sign_extended[2], ALUsrc);
  and and63(temp_res2[1], sign_extended[1], ALUsrc);
  and and64(temp_res2[0], sign_extended[0], ALUsrc);

  or or1(res[31], temp_res1[31], temp_res2[31]);
  or or2(res[30], temp_res1[30], temp_res2[30]);
  or or3(res[29], temp_res1[29], temp_res2[29]);
  or or4(res[28], temp_res1[28], temp_res2[28]);
  or or5(res[27], temp_res1[27], temp_res2[27]);
  or or6(res[26], temp_res1[26], temp_res2[26]);
  or or7(res[25], temp_res1[25], temp_res2[25]);
  or or8(res[24], temp_res1[24], temp_res2[24]);
  or or9(res[23], temp_res1[23], temp_res2[23]);
  or or10(res[22], temp_res1[22], temp_res2[22]);
  or or11(res[21], temp_res1[21], temp_res2[21]);
  or or12(res[20], temp_res1[20], temp_res2[20]);
  or or13(res[19], temp_res1[19], temp_res2[19]);
  or or14(res[18], temp_res1[18], temp_res2[18]);
  or or15(res[17], temp_res1[17], temp_res2[17]);
  or or16(res[16], temp_res1[16], temp_res2[16]);
  or or17(res[15], temp_res1[15], temp_res2[15]);
  or or18(res[14], temp_res1[14], temp_res2[14]);
  or or19(res[13], temp_res1[13], temp_res2[13]);
  or or20(res[12], temp_res1[12], temp_res2[12]);
  or or21(res[11], temp_res1[11], temp_res2[11]);
  or or22(res[10], temp_res1[10], temp_res2[10]);
  or or23(res[9], temp_res1[9], temp_res2[9]);
  or or24(res[8], temp_res1[8], temp_res2[8]);
  or or25(res[7], temp_res1[7], temp_res2[7]);
  or or26(res[6], temp_res1[6], temp_res2[6]);
  or or27(res[5], temp_res1[5], temp_res2[5]);
  or or28(res[4], temp_res1[4], temp_res2[4]);
  or or29(res[3], temp_res1[3], temp_res2[3]);
  or or30(res[2], temp_res1[2], temp_res2[2]);
  or or31(res[1], temp_res1[1], temp_res2[1]);
  or or32(res[0], temp_res1[0], temp_res2[0]);

endmodule
