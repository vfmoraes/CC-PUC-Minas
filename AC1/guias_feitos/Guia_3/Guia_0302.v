/*
Guia_0302.v
802371 - Victor Ferraz de Moraes
*/
module Guia_0302;
// define data
reg [5:0] a = 8'b110110 ; // quaternario em binario
reg [7:0] b = 8'h5f ; // hexadecimal
reg [7:0] c = 8'b011011 ; // quaternario em binario
reg [9:0] d = 8'o147 ; // octal
reg [7:0] e = 8'hd5 ; // hexadecimal
reg [5:0] f = 0 ; // binary
reg [9:0] g = 0 ; // binary
reg [7:0] h = 0 ; // binary
// actions
initial
begin : main
$display ( "Guia_0302 - Tests" );
$display ( "a.) = 312(4) -> C1,6(a) = %5b", ~a);
$display ( "b.) = %h -> C1,8(b) = %7b", b, ~b);
f = ~c+1;
$display ( "c.) = 123(4) -> C1,6(c) = %5b -> C2,6(c) = %7b", ~c, f );
g = ~d+1;
$display ( "d.) = %o -> C1,10(d) = %9b -> C2,10(d) = %9b", d, ~d, g );
h = ~e+1;
$display ( "e.) = %h -> C1,8(e) = %7b -> C2,8(e) = %7b", e, ~e, h );
end // main
endmodule // Guia_0302