module second_level_CLA(output P_OUT, output G_OUT, output cout, input [0:7]P, input [0:7]G, input cin);

	wire [0:7]w1;
	
	and and1(P_OUT, P[0], P[1], P[2], P[3], P[4], P[5], P[6], P[7]);	//p_out = p7p6p5p4p3p2p1p0
	
	
	and and2(w1[0], P[7], G[6]);
	and and3(w1[1], P[7], P[6], G[5]);
	and and4(w1[2], P[7], P[6], P[5], G[4]);
	and and5(w1[3], P[7], P[6], P[5], P[4], G[3]);
	and and6(w1[4], P[7], P[6], P[5], P[4], P[3], G[2]);
	and and7(w1[5], P[7], P[6], P[5], P[4], P[3], P[2], G[1]);
	and and8(w1[6], P[7], P[6], P[5], P[4], P[3], P[2], P[1], G[0]);	
	or or1(G_OUT, G[7], w1[0], w1[1], w1[2], w1[3], w1[4], w1[5], w1[6]);	// g_out = g7 + p7g6 + p7p6g5 +p7p6p5g4 + p7p6p5p4p3 + p7p6p5p4p3g2 + p7p6p5p4p3p2g1 + p7p6p5p4p3p2p1g0
	
	and and9(w1[7], P_OUT, cin);
	or or2(cout, G_OUT, w1[7]);		// c[31:0] = G_OUT + (P_OUT * cin)
	
endmodule


