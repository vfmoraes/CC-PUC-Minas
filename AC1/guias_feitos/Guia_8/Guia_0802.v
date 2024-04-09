// -------------------------
// Guia_0802 - UNIDADE ARITMÉTICA
// Nome: Victor Ferraz de Moraes
// Matricula: 802371
// -------------------------
// half subtractor
// -------------------------
module halfSubtractor (output diff,
output borrow,
input a,
input b);
// descrever por portas
xor XOR1 ( diff, a, b );
and AND1 ( borrow, ~a, b );
endmodule // halfSubtractor
// -------------------------
// full subtractor
// -------------------------
module fullSubtractor ( output diff,
output borrow,
input a,
input b,
input borrowIn );
// descrever por portas e/ou modulos
wire diff1, borrow1;
halfSubtractor HS1 ( diff1, borrow1, a, b );
halfSubtractor HS2 ( diff, borrow, diff1, borrowIn );
endmodule // fullSubtractor
module test_fullSubtractor;
// ------------------------- definir dados
reg [5:0] x;
reg [5:0] y;
wire [5:0] borrow; // “empresta”
wire [5:0] diff; // “diferença”
integer i, j; // declarando i e j fora do bloco initial
// halfSubtractor HS0 ( diff[0], borrow[0], x[0], y[0] );
genvar k;
generate
    for (k = 0; k < 6; k = k + 1) begin
        fullSubtractor FS (diff[k], borrow[k], x[k], y[k], k == 0 ? 1'b0 : borrow[k-1]);
    end
endgenerate
// ------------------------- parte principal
initial begin
$display("Guia_0802 - Victor Ferraz de Moraes - 802371");
$display("Test AU's full subtractor");
// projetar testes da unidade aritmética
x = 3;
y = 2;
end
initial begin
    $monitor("x = %b, y = %b, diff = %b, borrow = %b", x, y, diff, borrow);
end
endmodule // test_fullSubtractor
