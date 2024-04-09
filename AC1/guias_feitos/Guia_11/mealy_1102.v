// ---------------------------
// -- Nome: Victor Ferraz de Moraes
// -- Matrícula: 802371
// ---------------------------
// mealy_1102.v
module mealy_1102 ( y, x, clk, reset );
`define found 1
`define notfound 0
output y;
input x;
input clk;
input reset;
reg y;
parameter // Identificadores de estado
start = 3'b000,
id1 = 3'b001,
id10 = 3'b010,
id100 = 3'b100,
id1001 = 3'b101; // sequência encontrada
reg [2:0] E1; // variáveis de estado atual
reg [2:0] E2; // lógica de próximo estado
// lógica de próximo estado
always @( x or E1 )
begin
y = `notfound;
case ( E1 )
start:
if ( x )
E2 = id1;
else
E2 = start;
id1:
if ( x )
E2 = id1;
else
E2 = id10;
id10:
if ( x )
E2 = id10;
else
E2 = id100;
id100:
if ( x )
begin
E2 = id1001;
y = `found;
end
default: // estado indefinido
E2 = 3'bxxx;
endcase
end // sempre em sinal ou estado mudando
// variáveis de estado
always @( posedge clk or negedge reset )
begin
if ( reset )
E1 = E2; // atualiza estado atual
else
E1 = 0; // reset
end // always at signal changing
endmodule // mealy_1102
