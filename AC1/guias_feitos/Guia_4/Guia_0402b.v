module fxy (output s1, output s2, input x, y);
assign s1 = (~x | ~y) | ( x & ~y ) ;
assign s2 = ~x | ~y;
endmodule // fxy

// ---------------------
// -- test_module
// ---------------------
module test_module;
reg x, y, z;
wire s1;
 // instancias
fxy FXY1 (s1, s2, x, y);
 // valores iniciais
initial begin: start
 x=1'bx; y=1'bx; z=1'bx; // indefinidos
end
 // parte principal
initial begin: main
 // identificacao
 $display("Exemplo- Victor Ferraz de Moraes - 802371");
 $display("Test boolean expression");
 $display("\n( x' + y' ) + ( x . y' )  = s1\n");
 $display("\nx' + y' = s2\n");
 // monitoramento
 $display(" x  y =  s1 s2");
 $monitor("%2b %2b = %2b %2b", x, y, s1, s2);
 // sinalizacao
 #1 x=0; y=0;
 #1 x=0; y=1;
 #1 x=1; y=0;
 #1 x=1; y=1;
end
endmodule // test_module