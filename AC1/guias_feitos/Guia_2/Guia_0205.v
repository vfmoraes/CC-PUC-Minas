/*
Guia_0205.v
802371 - Victor Ferraz de Moraes
*/
module Guia_0205;
// define data
// For operation a.) 101,01(2) + 11,111(2) = X(2)
reg [7:0] a = 8'b10101 ; 
reg [7:0] b = 8'b11111 ;
reg [7:0] c;
// actions
initial
begin : main
$display ( "Guia_0205 - Tests" );
$display ( "a = %8b", a );
$display ( "b = %8b", b );
c = a+b;
$display ( "c = a+b = %8b", c );
$display ( );
a = 8'b1001111 ; 
b = 8'b0101100 ;
$display ( "a = %8b", a );
$display ( "b = %8b", b );
c = a-b;
$display ( "c = a-b = %8b", c );
$display ( );
a = 8'b100101 ; 
b = 8'b011110 ;
$display ( "a = %8b", a );
$display ( "b = %8b", b );
c = a*b;
$display ( "c = a*b = %8b", c );
$display ( );
a = 8'b10110010 ; 
b = 8'b00010011 ;
$display ( "a = %8b", a );
$display ( "b = %8b", b );
c = a/b;
$display ( "c = a/b = %8b", c );
$display ( );
a = 8'b1101101 ; 
b = 8'b1011 ;
$display ( "a = %8b", a );
$display ( "b = %8b", b );
c = a%b;
$display ( "c = a%%b = %8b", c );
$display ( );
end // main
endmodule // Guia_0205
