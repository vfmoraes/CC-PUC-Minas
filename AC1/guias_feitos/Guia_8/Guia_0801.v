// -------------------------
// Guia_0801 - FULL ADDER
// Nome: Victor Ferraz de Moraes
// Matricula: 802371
// -------------------------
// half adder
// -------------------------
module halfAdder (output s1,
output s0,
input a,
input b);
// descrever por portas
xor XOR1 ( s0, a, b );
and AND1 ( s1, a, b );
endmodule // halfAdder
// -------------------------
// full adder
// -------------------------
module fullAdder ( output s1,
output s0,
input a,
input b,
input carryIn );
// descrever por portas e/ou modulos
assign s0 = a ^ b ^ carryIn;
assign s1 = (a & b) | (b & carryIn) | (carryIn & a);
endmodule // fullAdder
module test_fullAdder;
// ------------------------- definir dados
reg [5:0] x;
reg [5:0] y;
wire [5:0] carry; // “vai-um”
wire [6:0] soma;
integer i, j; // declarando i e j fora do bloco initial
// halfAdder HA0 ( carry[0], soma[0], x[0], y[0] );
genvar k;
generate
    for (k = 0; k < 6; k = k + 1) begin
        fullAdder FA (carry[k], soma[k], x[k], y[k], k == 0 ? 1'b0 : carry[k-1]);
    end
endgenerate
// ------------------------- parte principal
initial begin
$display("Guia_0801 - Victor Ferraz de Moraes - 802371");
$display("Test ALUs full adder");
// projetar testes do somador completo
x = 3;
y = 1;
end
initial begin
    $monitor("x = %b, y = %b, soma = %b, carry = %b",
             x, y, soma, carry);
end
endmodule // test_fullAdder
