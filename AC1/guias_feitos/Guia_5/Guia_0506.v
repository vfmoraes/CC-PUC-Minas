// -------------------------
// Guia_0506.v - GATES
// Nome: Victor Ferraz de Moraes
// Matricula: 802371
// -------------------------
// -------------------------
// f5_gate
// m a b s
// 0 0 0 0
// 1 0 1 1 <- (a ^ b)
// 2 1 0 1
// 3 1 1 0
//
// -------------------------
module f5a ( output s,
input a,
input b );
// definir dado local
wire not_a;
wire not_b;
wire s1;
wire s2;
wire s3;
// descrever por portas
nand NAND1 ( not_a, a );
nand NAND2 ( not_b, b );
nand NAND3 ( s1, not_a, b );
nand NAND4 ( s2, not_b, a );
nand NAND5 ( s, s2, s1 );
endmodule // f5a
module f5b ( output s,
input a,
input b );
// descrever por expressao
assign s = a ^ b;
endmodule // f5b
module test_f5;
// ------------------------- definir dados
reg x;
reg y;
wire a, b;
f5a moduloA ( a, x, y );
f5b moduloB ( b, x, y );
// ------------------------- parte principal
initial
begin : main
$display("Guia_0506 - Victor Ferraz de Moraes - 802371");
$display("Test module");
$display(" x y a b");
// projetar testes do modulo
$monitor("%4b %4b %4b %4b", x, y, a, b);
x = 1'b0; y = 1'b0;
#1 x = 1'b0; y = 1'b1;
#1 x = 1'b1; y = 1'b0;
#1 x = 1'b1; y = 1'b1;
end
endmodule // test_f5