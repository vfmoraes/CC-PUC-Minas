/*
Guia_0303.v
802371 - Victor Ferraz de Moraes
*/
module Guia_0303;
// define data
reg signed [4:0] a = 8'b10101; // binary
reg signed [5:0] b = 8'b110011 ; // binary
reg signed [5:0] c = 8'b100111 ; // binary
reg signed [6:0] d = 8'b1011011 ; // binary
reg signed [6:0] e = 8'b1010001 ; // binary
reg signed [7:0] f = 0 ; // binary
// actions
initial
begin : main
$display ( "Guia_0303 - Tests" );
f = ~a+1;
$display ( "a.) = %4b -> C1(a) = %4b -> C2(a) = %5b = %d", a, ~a, f, f );
f = ~b+1;
$display ( "b.) = %5b -> C1(b) = %5b -> C2(b) = %5b = %d", b, ~b, f, f );
f = ~c+1;
$display ( "c.) = %5b -> C1(c) = %5b -> C2(c) = %5b", c, ~c, f );
f = ~d+1;
$display ( "d.) = %6b -> C1(c) = %6b -> C2(c) = %5b", d, ~d, f );
f = ~e+1;
$display ( "e.) = %6b -> C1(c) = %6b -> C2(c) = %5b = %h", e, ~e, f, f );
end // main end // main
endmodule // Guia_0303