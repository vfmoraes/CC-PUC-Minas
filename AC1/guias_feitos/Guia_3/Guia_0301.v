/*
Guia_0301.v
802371 - Victor Ferraz de Moraes
*/
module Guia_0301;
// define data
reg [5:0] a = 8'b1001 ; // binary
reg [7:0] b = 8'b1100 ; // binary
reg [5:0] c = 8'b101101 ; // binary
reg [6:0] d = 8'b100111; // binary
reg [7:0] e = 8'b110001 ; // binary
reg [5:0] f = 0 ; // binary
reg [6:0] g = 0 ; // binary
reg [7:0] h = 0 ; // binary
// actions
initial
begin : main
$display ( "Guia_0301 - Tests" );
$display ( "a.) = %5b -> C1,6(a) = %5b", a, ~a);
$display ( "b.) = %7b -> C1,8(b) = %7b", b, ~b);
f = ~c+1;
$display ( "c.) = %5b -> C1,6(c) = %5b -> C2,6(c) = %5b", c, ~c, f );
g = ~d+1;
$display ( "d.) = %6b -> C1,7(c) = %6b -> C2,7(c) = %6b", d, ~d, g );
h = ~e+1;
$display ( "e.) = %7b -> C1,8(c) = %7b -> C2,8(c) = %7b", e, ~e, h );
end // main
endmodule // Guia_0301