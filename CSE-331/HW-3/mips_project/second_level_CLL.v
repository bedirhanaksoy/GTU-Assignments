module second_level_CLL(output [7:0]cout, input [7:0]P, input [7:0]G, input cin);

	wire w[7:0];

	and and1(w[0], P[0], cin);
	or or1(cout[0], G[0], w[0]);			// c1 = g0 + p0c0
	
	and and2(w[1], P[1], cout[0]);
	or or2(cout[1], G[1], w[1]);			// c2 = g1 + p1c1
	
	and and3(w[2], P[2], cout[1]);
	or or3(cout[2], G[2], w[2]);			// c3 = g2 + p2c2

	and and4(w[3], P[3], cout[2]);
	or or4(cout[3], G[3], w[3]);			// c4 = g3 + p3c3

	and and5(w[4], P[4], cout[3]);
	or or5(cout[4], G[4], w[4]);			// c1 = g0 + p0c0
	
	and and6(w[5], P[5], cout[4]);
	or or6(cout[5], G[5], w[5]);			// c2 = g1 + p1c1
	
	and and7(w[6], P[6], cout[5]);
	or or7(cout[6], G[6], w[6]);			// c3 = g2 + p2c2

	and and8(w[7], P[7], cout[6]);
	or or8(cout[7], G[7], w[7]);			// c4 = g3 + p3c3

endmodule