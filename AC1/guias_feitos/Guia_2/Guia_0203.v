/*
Guia_0203.v
802371 - Victor Ferraz de Moraes
*/
module Guia_0203;
// define data
real x = 0.625; // decimal
reg [7:0] b = 8'b1001_0000 ; // binary
integer i;
// actions
initial
begin : main
$display ( "Guia_0203 - Tests" );
for (i = 0; i < 5; i = i + 1) begin
  b = 0;
  case(i)
    0: b = 8'b0100_1000;
    1: b = 8'b1001_0100;
    2: b = 8'b1010_1100;
    3: b = 8'b1100_0100;
    4: b = 8'b1001_0000;
  endcase
$display ( "b = 0.%8b", b );
$display ( "b = 0.%d%d%d%d (4)", b[7:6],b[5:4],b[3:2],b[1:0] );
$display ( "b = 0.%x%x (16)", b[7:4],b[3:0] );
$display ( "b = 0.%o%o%o (8) ", b[7:5],b[4:2],b[1:0] );
$display();
end // end for
end // main
endmodule // Guia_0203