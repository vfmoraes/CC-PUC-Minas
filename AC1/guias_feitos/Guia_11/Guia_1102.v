// ---------------------------
// -- Nome: Victor Ferraz de Moraes
// -- Matrícula: 802371
// ---------------------------
// Guia_1102.v
`include "mealy_1102.v"
module Guia_1102;
reg clk, reset, x;
wire m1;
mealy_1102 mealy1 ( m1, x, clk, reset );
initial
begin
$display ( "Time    X  Mealy" );
// valores iniciais
clk = 1;
reset = 0;
x = 0;
// mudança do sinal de entrada
#5 reset = 1;
#10 x = 1;
#10 x = 0;
#10 x = 0;
#10 x = 1;
#10 x = 1;
#10 x = 0;
#10 x = 0;
#10 x = 1;
#30 $finish;
end // initial
always
#5 clk = ~clk;
always @( posedge clk )
begin
$display ( "%4d %4b %4b", $time, x, m1 );
end // always at positive edge clocking changing
endmodule // Guia_1102
