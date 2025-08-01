module write_data_mux(input [31:0] read_data, 
                      input [31:0] ALU_result, 
							 input memRead, 
							 output [31:0] write_data);

  wire [31:0] temp_res1;
  wire [31:0] temp_res2;
  wire memRead_;

  not not1(memRead_, memRead);

  and and1(temp_res1[31], ALU_result[31], memRead_);
  and and2(temp_res1[30], ALU_result[30], memRead_);
  and and3(temp_res1[29], ALU_result[29], memRead_);
  and and4(temp_res1[28], ALU_result[28], memRead_);
  and and5(temp_res1[27], ALU_result[27], memRead_);
  and and6(temp_res1[26], ALU_result[26], memRead_);
  and and7(temp_res1[25], ALU_result[25], memRead_);
  and and8(temp_res1[24], ALU_result[24], memRead_);
  and and9(temp_res1[23], ALU_result[23], memRead_);
  and and10(temp_res1[22], ALU_result[22], memRead_);
  and and11(temp_res1[21], ALU_result[21], memRead_);
  and and12(temp_res1[20], ALU_result[20], memRead_);
  and and13(temp_res1[19], ALU_result[19], memRead_);
  and and14(temp_res1[18], ALU_result[18], memRead_);
  and and15(temp_res1[17], ALU_result[17], memRead_);
  and and16(temp_res1[16], ALU_result[16], memRead_);
  and and17(temp_res1[15], ALU_result[15], memRead_);
  and and18(temp_res1[14], ALU_result[14], memRead_);
  and and19(temp_res1[13], ALU_result[13], memRead_);
  and and20(temp_res1[12], ALU_result[12], memRead_);
  and and21(temp_res1[11], ALU_result[11], memRead_);
  and and22(temp_res1[10], ALU_result[10], memRead_);
  and and23(temp_res1[9], ALU_result[9], memRead_);
  and and24(temp_res1[8], ALU_result[8], memRead_);
  and and25(temp_res1[7], ALU_result[7], memRead_);
  and and26(temp_res1[6], ALU_result[6], memRead_);
  and and27(temp_res1[5], ALU_result[5], memRead_);
  and and28(temp_res1[4], ALU_result[4], memRead_);
  and and29(temp_res1[3], ALU_result[3], memRead_);
  and and30(temp_res1[2], ALU_result[2], memRead_);
  and and31(temp_res1[1], ALU_result[1], memRead_);
  and and32(temp_res1[0], ALU_result[0], memRead_);

  and and33(temp_res2[31], read_data[31], memRead);
  and and34(temp_res2[30], read_data[30], memRead);
  and and35(temp_res2[29], read_data[29], memRead);
  and and36(temp_res2[28], read_data[28], memRead);
  and and37(temp_res2[27], read_data[27], memRead);
  and and38(temp_res2[26], read_data[26], memRead);
  and and39(temp_res2[25], read_data[25], memRead);
  and and40(temp_res2[24], read_data[24], memRead);
  and and41(temp_res2[23], read_data[23], memRead);
  and and42(temp_res2[22], read_data[22], memRead);
  and and43(temp_res2[21], read_data[21], memRead);
  and and44(temp_res2[20], read_data[20], memRead);
  and and45(temp_res2[19], read_data[19], memRead);
  and and46(temp_res2[18], read_data[18], memRead);
  and and47(temp_res2[17], read_data[17], memRead);
  and and48(temp_res2[16], read_data[16], memRead);
  and and49(temp_res2[15], read_data[15], memRead);
  and and50(temp_res2[14], read_data[14], memRead);
  and and51(temp_res2[13], read_data[13], memRead);
  and and52(temp_res2[12], read_data[12], memRead);
  and and53(temp_res2[11], read_data[11], memRead);
  and and54(temp_res2[10], read_data[10], memRead);
  and and55(temp_res2[9], read_data[9], memRead);
  and and56(temp_res2[8], read_data[8], memRead);
  and and57(temp_res2[7], read_data[7], memRead);
  and and58(temp_res2[6], read_data[6], memRead);
  and and59(temp_res2[5], read_data[5], memRead);
  and and60(temp_res2[4], read_data[4], memRead);
  and and61(temp_res2[3], read_data[3], memRead);
  and and62(temp_res2[2], read_data[2], memRead);
  and and63(temp_res2[1], read_data[1], memRead);
  and and64(temp_res2[0], read_data[0], memRead);

  or or1(write_data[31], temp_res1[31], temp_res2[31]);
  or or2(write_data[30], temp_res1[30], temp_res2[30]);
  or or3(write_data[29], temp_res1[29], temp_res2[29]);
  or or4(write_data[28], temp_res1[28], temp_res2[28]);
  or or5(write_data[27], temp_res1[27], temp_res2[27]);
  or or6(write_data[26], temp_res1[26], temp_res2[26]);
  or or7(write_data[25], temp_res1[25], temp_res2[25]);
  or or8(write_data[24], temp_res1[24], temp_res2[24]);
  or or9(write_data[23], temp_res1[23], temp_res2[23]);
  or or10(write_data[22], temp_res1[22], temp_res2[22]);
  or or11(write_data[21], temp_res1[21], temp_res2[21]);
  or or12(write_data[20], temp_res1[20], temp_res2[20]);
  or or13(write_data[19], temp_res1[19], temp_res2[19]);
  or or14(write_data[18], temp_res1[18], temp_res2[18]);
  or or15(write_data[17], temp_res1[17], temp_res2[17]);
  or or16(write_data[16], temp_res1[16], temp_res2[16]);
  or or17(write_data[15], temp_res1[15], temp_res2[15]);
  or or18(write_data[14], temp_res1[14], temp_res2[14]);
  or or19(write_data[13], temp_res1[13], temp_res2[13]);
  or or20(write_data[12], temp_res1[12], temp_res2[12]);
  or or21(write_data[11], temp_res1[11], temp_res2[11]);
  or or22(write_data[10], temp_res1[10], temp_res2[10]);
  or or23(write_data[9], temp_res1[9], temp_res2[9]);
  or or24(write_data[8], temp_res1[8], temp_res2[8]);
  or or25(write_data[7], temp_res1[7], temp_res2[7]);
  or or26(write_data[6], temp_res1[6], temp_res2[6]);
  or or27(write_data[5], temp_res1[5], temp_res2[5]);
  or or28(write_data[4], temp_res1[4], temp_res2[4]);
  or or29(write_data[3], temp_res1[3], temp_res2[3]);
  or or30(write_data[2], temp_res1[2], temp_res2[2]);
  or or31(write_data[1], temp_res1[1], temp_res2[1]);
  or or32(write_data[0], temp_res1[0], temp_res2[0]);



endmodule
