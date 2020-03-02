module keypad(valid, number, a, b, c, d, e, f, g);
   output 	valid;
   output [3:0] number;
   input 	a, b, c, d, e, f, g;
   //wires for valid combinations (w0-w9)
   //wires for invalid combinations (w10 and w11)
   wire w0, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11;
   //extra wire temp
   wire w12;

   //gates for valid combinations
   and a0(w0, b, g);
   and a1(w1, d, a);
   and a2(w2, b, d);
   and a3(w3, c, d);
   and a4(w4, a, e);
   and a5(w5, b, e);
   and a6(w6, c, e);
   and a7(w7, a, f);
   and a8(w8, b, f);
   and a9(w9, c, f);

   //gates for invalid combinations
   //and a10(w10, a, g);
   //and a11(w11, c, g);

   //gates for returning an output of valid
   //or o1(w12, w10, w11);
   //not n2(valid, w12);

   or o1(w10, a, b, c, d, e, f, g);
   not n1(w11, w10);
   not n2(valid, w11);



   //gates for returning a number
   or o2(number[0], w1, w3, w5, w7, w9);
   or o3(number[1], w2, w3, w6, w7);
   or o4(number[2], w4, w5, w6, w7);
   or o5(number[3], w8, w9);

endmodule // keypad
