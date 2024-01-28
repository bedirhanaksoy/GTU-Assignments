module four_bit_CLA(output [3:0]r, output P, output G, input [3:0]a, input [3:0]b, input cin);
	
	wire [2:0]w;

	wire [3:0]p;
	wire [3:0]g;
	
	wire [3:0]c; // cout burda 4 bit ama 3 ünü kulanmısız.
	
	one_bit_adder add1(p[0], g[0], r[0], a[0], b[0], cin);
	one_bit_adder add2(p[1], g[1], r[1], a[1], b[1], c[0]);
	one_bit_adder add3(p[2], g[2], r[2], a[2], b[2], c[1]);
	one_bit_adder add4(p[3], g[3], r[3], a[3], b[3], c[2]);

	four_bit_CLL CLL1(c[3:0], p[3:0], g[3:0], cin);
	
	
	and and2(w[0], p[3], g[2]);
	and and3(w[1], p[3], p[2], g[1]);
	and and4(w[2], p[3], p[2], p[1], g[0]);
	or	 or1(G, g[3], w[2], w[1], w[0]);
	
	and and5(P, p[3], p[2], p[1], p[0]);
	
endmodule
	