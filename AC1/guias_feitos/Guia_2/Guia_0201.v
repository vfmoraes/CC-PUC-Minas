/*
Guia_0201.v
802371 - Victor Ferraz de Moraes
*/
module Guia_0201_modified;
  // define data
  real x = 0; // decimal
  real power2 = 1.0; // power of 2
  integer y = 7; // counter
  reg [7:0] b; // binary (only fraction part, Big Endian)
  integer i; // loop variable

  initial
  begin : main
    $display("Guia_0201");

    // Loop for different values
    for (i = 0; i < 5; i = i + 1) begin
      case (i)
        0: b = 8'b01101000;
        1: b = 8'b10011000;
	2: b = 8'b10101000;
	3: b = 8'b11001000;
	4: b = 8'b11011000;
        default: b = 0;
      endcase
      
      // Initialize variables for each value
      x = 0;
      power2 = 1.0;
      y = 7;
      
      $display("Valor %0d:", i + 1);
      $display("x = %f", x);
      $display("b = 0.%8b", b);
      
      // Binary fraction to decimal conversion
      while (y >= 0) begin
        power2 = power2 / 2.0;
        if (b[y] == 1) begin
          x = x + power2;
        end
        $display("x = %f", x);
        y = y - 1;
      end // end while
    end // end loop
  end // main
endmodule // Guia_0201
