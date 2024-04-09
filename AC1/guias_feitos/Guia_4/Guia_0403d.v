module SoP (output s, input x, y, w, z); // mintermos
// m 1, 2, 5, 6, 8, 10, 12
assign s = (~x&~y&~w&z) | (~x&~y&w&~z) | (~x&y&~w&z) | (~x&y&w&~z) | (x&~y&~w&~z) | (x&~y&w&~z) | (x&y&~w&~z);
endmodule // SoP

// ---------------------
// -- test_module
// ---------------------
module test_module;
reg x, y, w, z;
wire s1;
 // instancias
SoP SOP1 (s1, x, y, w, z);
 // valores iniciais
initial begin: start
 x=1'bx; y=1'bx; w=1'bx; z=1'bx; // indefinidos
end
 // parte principal
initial begin: main
 // identificacao
 $display("Exemplo- Victor Ferraz de Moraes - 802371");
 $display("Test boolean expression");
 $display("\nf (x,y,w,z) = SoP (1,2,5,6,8,10,12) =  1 = s\n");
 // monitoramento
 $display(" x  y  w  z =  s");
 $monitor("%2b %2b %2b %2b = %2b", x, y, w, z, s1);
 // sinalizacao
 #1 x=0; y=0; w=0; z=0;
 #1 x=0; y=0; w=0; z=1;
 #1 x=0; y=0; w=1; z=0;
 #1 x=0; y=0; w=1; z=1;
 #1 x=0; y=1; w=0; z=0;
 #1 x=0; y=1; w=0; z=1;
 #1 x=0; y=1; w=1; z=0;
 #1 x=0; y=1; w=1; z=1;
 #1 x=1; y=0; w=0; z=0;
 #1 x=1; y=0; w=0; z=1;
 #1 x=1; y=0; w=1; z=0;
 #1 x=1; y=0; w=1; z=1;
 #1 x=1; y=1; w=0; z=0;
 #1 x=1; y=1; w=0; z=1;
 #1 x=1; y=1; w=1; z=0;
 #1 x=1; y=1; w=1; z=1;
end
endmodule // test_module