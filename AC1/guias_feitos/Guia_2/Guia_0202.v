/*
Guia_0201.v
802371 - Victor Ferraz de Moraes
*/
module Guia_0202;
// define data
real x; // decimal
integer y = 7 ; // counter
reg [7:0] b = 0 ; // binary
integer i; // index for loop

// actions
initial
begin : main
$display ( "Guia_0202 - Tests" );

for (i = 0; i < 5; i = i + 1) begin
  y = 7;
  b = 0;
  case(i)
    0: x = 0.75;
    1: x = 0.375;
    2: x = 0.625;
    3: x = 0.875;
    4: x = 0.03125;
  endcase
  $display ( "x = %f" , x );
  $display ( "b = 0.%8b", b );
  while ( x > 0 && y >= 0 )
  begin
    if ( x*2 >= 1 )
    begin
      b[y] = 1;
      x = x*2.0 - 1.0;
    end
    else
    begin
      b[y] = 0;
      x = x*2.0;
    end // end if
    $display ( "b = 0.%8b", b );
    y=y-1;
  end // end while
  $display();
end // end for

end // main
endmodule // Guia_0202
