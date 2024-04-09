module PoS (output S, input X, Y, W, Z); // MAXTERMOS
// M 0, 1, 2, 3, 5, 11, 15 
 assign S = (X| Y| W| Z) & (X| Y| W| ~Z) & (X| Y| ~W| Z) & (X| Y| ~W| ~Z) & (X| ~Y| W| ~Z) & (~X| Y| ~W| ~Z) & (~X| ~Y| ~W| ~Z);
endmodule // PoS

// ---------------------
// -- test_module
// ---------------------
module test_module;
reg x, y, w, z;
wire s1;
 // instancias
PoS POS1 (s1, x, y, w, z);
 // valores iniciais
initial begin: start
 x=1'bx; y=1'bx; w=1'bx; z=1'bx; // indefinidos
end
 // parte principal
initial begin: main
 // identificacao
 $display("Exemplo- Victor Ferraz de Moraes - 802371");
 $display("Test boolean expression");
 $display("\nf (x,y,w,z) = PoS (0,1,2,3,5,11,15) =  0 = s\n");
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