module one_bit_adder (output p, output g, output r, input a, input b, input cin);
    wire w1, w2;

    and and1(g, a, b);			// g = ab

    or or1(p, a, b);				// p = a + b

    xor xor1(r, a, b, cin);	// r = (a xor b xor cin)

endmodule

