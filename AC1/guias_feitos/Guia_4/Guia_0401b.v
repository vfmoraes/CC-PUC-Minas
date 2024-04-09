module fxy (output s,
 input x, y, z);
 // mintermos
assign s = ~(~x | y) & z;
endmodule // SoP

// ---------------------
// -- test_module
// ---------------------
module test_module;
reg x, y, z;
wire s1;
 // instancias
fxy FXY1 (s1, x, y, z);
 // valores iniciais
initial begin: start
 x=1'bx; y=1'bx; z=1'bx; // indefinidos
end
 // parte principal
initial begin: main
 // identificacao
 $display("Exemplo- Victor Ferraz de Moraes - 802371");
 $display("Test boolean expression");
 $display("\n(x' + y)' . z = s\n");
 // monitoramento
 $display(" x  y  z =  s");
 $monitor("%2b %2b %2b = %2b", x, y, z, s1);
 // sinalizacao
 #1 x=0; y=0; z=0;
 #1 x=0; y=0; z=1;
 #1 x=0; y=1; z=0;
 #1 x=0; y=1; z=1;
 #1 x=1; y=0; z=0;
 #1 x=1; y=0; z=1;
 #1 x=1; y=1; z=0;
 #1 x=1; y=1; z=1;
end
endmodule // test_module