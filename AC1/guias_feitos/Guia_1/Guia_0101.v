/*
  Guia_0101.v
  802371 - Victor Ferraz de Moraes
*/
module Guia_0101;
// define data
   integer x = 26; // decimal letra a
   reg [10:0] b = 0; // binary (bits - little endian)
// actions
initial
 begin : main
  $display ( "Guia_0101 - Tests" );
  b = x;
  $display ( "a.) %d = %10b" , x, b );
  x = 53; // decimal letra b
  b = x;
  $display ( "b.) %d = %10b" , x, b );
  x = 723; // decimal letra c
  b = x;
  $display ( "c.) %d = %10b" , x, b );
  x = 312; // decimal letra d
  b = x;
  $display ( "d.) %d = %10b" , x, b );
  x = 365; // decimal letra e
  b = x;
  $display ( "e.) %d = %10b" , x, b );
 end // main
endmodule // Guia_0101