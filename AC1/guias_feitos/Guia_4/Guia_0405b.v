module PoS (output S,
 input X, Y);
 // MAXTERMOS
assign S = ( X | ~Y );
endmodule // PoS

module SoP (output s,
 input x, y);
 // mintermos
assign s = ( ~x & ~y ) | ( x & ~y ) | ( x & y);
endmodule // SoP

// ---------------------
// -- test_module
// ---------------------
module test_module;
reg x, y, z;
wire s1, s2;
 // instancias
SoP SOP1 (s1, x, y);
PoS POS1 (s2, x, y);
 // valores iniciais
initial begin: start
 x=1'bx; y=1'bx; z=1'bx; // indefinidos
end
 // parte principal
initial begin: main
 // identificacao
 $display("Exemplo- Victor Ferraz de Moraes - 802371");
 $display("Test boolean expression");
 $display("\nSoP(0,2,3) = (x'.y') + (x.y') + (x.y)\n");
 $display("\nPoS(1) = (x + y')\n");
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