module blackbox_test;
reg a,b,c;
wire s;

blackbox b1(s,a,b,c);
initial begin
$dumpfile("blackbox.vcd");
$dumpvars(0,blackbox_test);

c=0;a=0;b=0; # 10;
c=0;a=0;b=1; # 10;
c=0;a=1;b=0; # 10;
c=0;a=1;b=1; # 10;
c=1;a=0;b=0; # 10;
c=1;a=0;b=1; # 10;
c=1;a=1;b=0; # 10;
c=1;a=1;b=1; # 10;


$finish;

end
initial
    $monitor("At time %2t, s = %d a = %d b = %d c = %d",
                 $time, s, a, b, c);

endmodule // sc2_test
