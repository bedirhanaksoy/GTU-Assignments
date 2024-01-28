module four_bit_CLL(output [4:1]cout, input [3:0]p, input [3:0]g, input cin);

	wire [3:0]w;
	
	and and1(w[0], p[0], cin);
	or or1(cout[1], g[0], w[0]);			// c1 = g0 + p0c0
	
	and and2(w[1], p[1], cout[1]);
	or or2(cout[2], g[1], w[1]);			// c2 = g1 + p1c1
	
	and and3(w[2], p[2], cout[2]);
	or or3(cout[3], g[2], w[2]);			// c3 = g2 + p2c2

	and and4(w[3], p[3], cout[3]);
	or or4(cout[4], g[3], w[3]);			// c4 = g3 + p3c3
	
		
endmodule
