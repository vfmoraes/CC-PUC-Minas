// ---------------------------
// -- Nome: Victor Ferraz de Moraes
// -- Matrícula: 802371
// ---------------------------
// moore_1103.v
module moore_1103 ( y, x, clk, reset );
`define found 1
`define notfound 0
output y;
input x;
input clk;
input reset;
reg y;
parameter // Identificadores de estado
start = 4'b0000,
id1 = 4'b0001,
id10 = 4'b0010,
id100 = 4'b0100,
id1001 = 4'b1001, // sequência encontrada
id10010 = 4'b1010; // sequência encontrada
reg [3:0] E1; // variáveis de estado atual
reg [3:0] E2; // lógica de próximo estado
// lógica de próximo estado
always @( x or E1 )
begin
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
E2 = id1001;
else
E2 = start;
id1001:
if ( x )
E2 = start;
else
E2 = id10010;
id10010:
E1 = id10010;
default: // estado indefinido
E2 = 4'bxxxx;
endcase
end // sempre em sinal ou estado mudando
// variáveis de estado
always @( posedge clk or negedge reset )
begin
if ( reset )
E1 = E2; // atualiza estado atual
else
E1 = 0; // reset
end // sempre em sinal mudando
// lógica de saída
always @( E1 )
begin
y = (E1 == id10010); // O bit de saída é 1 quando a sequência 10010 é reconhecida
end // sempre em estado mudando
endmodule // moore_1103
