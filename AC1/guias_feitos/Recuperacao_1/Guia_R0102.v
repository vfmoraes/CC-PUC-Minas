// -------------------------
// Nome: Victor Ferraz de Moraes
// Matricula: 802371
// -------------------------
// -------------------------
module f ( output s, input a, input b, input c );
 wire w1, w2, w3, w4;
 not NOT_1 (w1, b);
 not NOT_2 (w2, c);
 and AND_1 (w3, a, w2);
 and AND_2 (w4, a, w1, c);
 or OR__1 (s, w3 ,w4);
 endmodule // s = f (a,b,c)
module test_f5;
// ------------------------- definir dados
reg x;
reg y;
reg w;
wire s;
f moduloA ( s, x, y, w );
// ------------------------- parte principal
initial
begin : main
$display("Victor Ferraz de Moraes - 802371");
$display("Test module");
$display(" x  y  w  s");
// projetar testes do modulo
$monitor("%2b %2b %2b %2b", x, y, w, s);
x = 1'b0; y = 1'b0; w = 1'b0;
 #1 x=0; y=0; w=0;
 #1 x=0; y=0; w=1;
 #1 x=0; y=1; w=0;
 #1 x=0; y=1; w=1;
 #1 x=1; y=0; w=0;
 #1 x=1; y=0; w=1;
 #1 x=1; y=1; w=0;
 #1 x=1; y=1; w=1;
end
endmodule // test_f5