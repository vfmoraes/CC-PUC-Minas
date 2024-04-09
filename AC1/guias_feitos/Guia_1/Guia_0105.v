/*
  Guia_0105.v
  802371 - Victor Ferraz de Moraes
*/
module Guia_0105;
// define data
   integer x = 13; // decimal
   reg [7:0] b ; // binary
   reg [0:13][7:0] s = "PUC-Minas"; // char array[14] (3x8 bits - little Endian)

// actions
   initial
    begin : main
     $display ( "Guia_0105 - Tests" );
     $display ( "a.) %s = %h %h %h %h %h %h %h %h %h (16_ASCII)" , s, s[5], s[6], s[7], s[8], s[9], s[10], s[11], s[12], s[13] );
     s = "2023-02";
     $display ( "b.) %s = %h %h %h %h %h %h %h (16_ASCII)" , s, s[7], s[8], s[9], s[10], s[11], s[12], s[13] );
     s = "Belo Horizonte";
     $display ( "c.) %s = %b %b %b %b %b %b %b %b %b %b %b %b %b %b (2_ASCII)" , s, s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8], s[9], s[10], s[11], s[12], s[13] );
     s[0] = 8'o116;
     s[1] = 8'o157;
     s[2] = 8'o151;
     s[3] = 8'o164;
     s[4] = 8'o145;
     $display ( "d.) 116 157 151 164 145 (8) = %s (ASCII)", s[0:4] );
     s[0] = 8'h4D;
     s[1] = 8'h2E;
     s[2] = 8'h20;
     s[3] = 8'h47;
     s[4] = 8'h2E;
     $display ( "e.) 4D 2E 20 47 2E (16) = %s (ASCII)", s[0:4] );
    end // main

endmodule // Guia_0105

