module _8x1Mux(res, a, b, c, d, e, f, g, h, s0, s1, s2);
input a, b, c, d, e, f, g, h,s0,s1,s2;
output res;
wire temp0, temp1, temp2, temp3, temp4, temp5, temp6, temp7, s0_, s1_, s2_;

not not1(s0_, s0);
not not2(s1_, s1);
not not3(s2_, s2);

and and1(temp0, s2_, s1_, s0_, a);
and and2(temp1, s2_, s1_, s0, b);
and and3(temp2, s2_, s1, s0_, c);
and and4(temp3, s2_, s1, s0, d);
and and5(temp4, s2, s1_, s0_, e);
and and6(temp5, s2, s1_, s0, f);
and and7(temp6, s2, s1, s0_, g);
and and8(temp7, s2, s1, s0, h);

or or1(res, temp0, temp1, temp2, temp3, temp4, temp5, temp6, temp7);

endmodule
