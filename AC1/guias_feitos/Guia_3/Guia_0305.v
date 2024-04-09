/*
Guia_0305.v
802371 - Victor Ferraz de Moraes
*/
module Guia_0305;
// define data
reg [5:0] a = 0 ; // binary
reg [6:0] b = 0 ; // binary
reg [5:0] c = 0 ; // binary
reg [7:0] d = 0 ; // binary
reg [7:0] e = 0 ; // binary
// actions
initial
begin : main
$display ( "Guia_0305 - Tests" );
a = 8'b0101011 + ~(8'b0001110)+1; // OVERFLOW (transbordamento)
b = 8'b0101_1011 + ~(8'b0010_1000)+1 ; // OVERFLOW (transbordamento)
c = 8'b0110110 + ~(8'b0001101)+1; // OVERFLOW (transbordamento)
d = 8'b011000011 + ~(8'b001011001)+1; // OVERFLOW (transbordamento)
e = 8'b000110011 + ~(8'b000101101)+1; // OVERFLOW (transbordamento)
$display("a.) %5b(2) - %5b(2) = %5b" ,8'b0101011, 8'b001110, a);
$display("b.) %6b(2) - 2,4(8) = %6b", 8'b0101_1011 , b );
$display("c.) 312(4) - %h(16) = %5b", 8'hd, c);
$display("d.) %h(16) - %7b(2) = %7b" ,8'hc3, 8'b1011001, d);
$display("e.) %d(10) - %h(16) = %7b" ,51, 8'h2d, e);
end // main
endmodule // Guia_0305