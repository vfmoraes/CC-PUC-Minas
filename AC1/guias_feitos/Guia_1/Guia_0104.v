/*
  Guia_0104.v
  802371 - Victor Ferraz de Moraes
*/
module Guia_0104;
// define data
   integer x = 0; // decimal
   reg [7:0] b = 8'b10101; // binary

// actions
   initial
    begin : main
     $display ( "Guia_0104 - Tests" );
     x = b;
     $display ( "a.) [%2b] [%2b] [%2b] [%2b] = %d %d %d %d (4)" , b[7:6], b[5:4], b[3:2], b[1:0], x[7:6], x[5:4], x[3:2], x[1:0] );
     b = 8'b11010;
     x = b;
     $display ( "b.) [%3b] [%3b] [%3b] = %o %o %o (8)" , b[7:6], b[5:3], b[2:0], x[7:6], x[5:3], x[2:0] );
     b = 8'b100111;
     x = b;
     $display ( "c.) [%4b] [%4b] = %x %x (16)" , b[7:4], b[3:0], x[7:4], x[3:0] );
     b = 8'b101001;
     x = b;
     $display ( "b.) [%3b] [%3b] [%3b] = %o %o %o (8)" , b[7:6], b[5:3], b[2:0], x[7:6], x[5:3], x[2:0] );
     b = 8'b101101;
     x = b;
     $display ( "a.) [%2b] [%2b] [%2b] [%2b] = %d %d %d %d (4)" , b[7:6], b[5:4], b[3:2], b[1:0], x[7:6], x[5:4], x[3:2], x[1:0] );
    end // main

endmodule // Guia_0104