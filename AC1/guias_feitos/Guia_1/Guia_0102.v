/*
  Guia_0102.v
  802371 - Victor Ferraz de Moraes
*/
module Guia_0102;
// define data
   integer x = 0; // decimal
   reg [7:0] b = 8'b10110; // binary (bits - little endian)

// actions
   initial
    begin : main
     $display ( "Guia_0102 - Tests" );
     x = b;
     $display ( "a.) %8b = %d" , b, x );
     b = 8'b11011;
     x = b;
     $display ( "b.) %8b = %d" , b, x );
     b = 8'b100100;
     x = b;
     $display ( "c.) %8b = %d" , b, x );
     b = 8'b101001;
     x = b;
     $display ( "d.) %8b = %d" , b, x );
     b = 8'b110111;
     x = b;
     $display ( "e.) %8b = %d" , b, x );
    end // main

endmodule // Guia_0102