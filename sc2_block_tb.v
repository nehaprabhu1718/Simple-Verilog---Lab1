module sc2_test;
reg a_in,b_in,c_in;
wire s_out,c_out;

sc2_block s1(s_out,c_out,a_in,b_in,c_in);
initial begin
$dumpfile("sc2.vcd");
$dumpvars(0,sc2_test);

c_in=0;a_in=0;b_in=0; # 10;
c_in=0;a_in=0;b_in=1; # 10;
c_in=0;a_in=1;b_in=0; # 10;
c_in=0;a_in=1;b_in=1; # 10;
c_in=1;a_in=0;b_in=0; # 10;
c_in=1;a_in=0;b_in=1; # 10;
c_in=1;a_in=1;b_in=0; # 10;
c_in=1;a_in=1;b_in=1; # 10;

$finish;

end
initial
    $monitor("At time %2t, c_in = %d a_in = %d b_in = %d s_out = %d c_out = %d",
                 $time, c_in, a_in, b_in, s_out, c_out);

endmodule // sc2_test
