/*
  Guia_0103.v
  802371 - Victor Ferraz de Moraes
*/
module Guia_0103;
// define data
   integer x = 61; // decimal
   reg [9:0] b = 0; // binary
// actions
   initial
    begin : main
     $display ( "Guia_0103 - Tests" );
     b = x;
     $display ( "a.) %d = %d%d%d%d%d (4)" , x, b[9:8], b[7:6], b[5:4], b[3:2], b[1:0] );
     x = 54;
     b = x;
     $display ( "b.) %d = %2o (8)" , x, b );
     x = 77;
     b = x;
     $display ( "c.) %d = %2x (16)" , x, b );
     x = 151;
     b = x;
     $display ( "d.) %d = %x (16)" , x, b );
     x = 738;
     b = x;
     $display ( "e.) %d = %x (16)" , x, b );
end // main
endmodule // Guia_0103