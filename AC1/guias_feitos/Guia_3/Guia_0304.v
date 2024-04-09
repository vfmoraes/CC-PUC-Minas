/*
Guia_0304.v
802371 - Victor Ferraz de Moraes
*/
module Guia_0304;
// define data
reg signed [11:0] a = 8'b11100; // binary
reg signed [11:0] b = 8'b1101 ; // binary
reg signed [7:0] c = 0 ; // binary
reg signed [6:0] d = 0 ; // binary
reg signed [5:0] e = 0 ; // binary
reg signed [11:0] f = 0 ; // binary
// actions
initial
begin : main
$display ( "Guia_0304 - Tests" );
f = a-b;
$display ( "a.) %11b-%11b = %11b(2)", a, b, f );
a = 8'b101_0111;
b = 8'b010_1100;
f = a-b;
$display ( "b.) %11b-%11b = %11b(2)", a, b, f );
a = 8'b101101; // base 4 to binary
b = 8'b011110; // base 4 to binary
f = a-b;
$display ( "c.) 231(4)-132(4) = %11b-%11b = %11b = %d%d(4)", a, b, f, f[3:2], f[1:0]);
a = 12'o513; // octal
b = 12'o173; // octal
f = a-b;
$display ( "d.) %o(8)-%o(8) = %11b-%11b = %11b = %o(8)", a, b, a, b, f, f );
a = 12'h8b3; // octal
b = 12'hc4f; // octal
f = b-a;
$display ( "e.) %h(16)-%h(16) = %11b-%11b = %11b = %h(16)", a, b, a, b, f, f );
end // main
endmodule // Guia_0304