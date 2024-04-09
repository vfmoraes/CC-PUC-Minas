// ---------------------------
// -- Nome: Victor Ferraz de Moraes
// -- Matrícula: 802371
// ---------------------------
// moore_1102.v
module moore_1101 ( y, x, clk, reset );
output y;
input x;
input clk;
input reset;
reg y;
parameter // identificadores de estado
start = 4'b0000,
id1 = 4'b0001,
id10 = 4'b0010,
id100 = 4'b0100,
id1001 = 4'b1000; // sequência encontrada
reg [3:0] E1; // variáveis de estado atual
reg [3:0] E2; // lógica de próximo estado
// lógica de próximo estado
always @( x or E1 )
begin
case( E1 )
start:
if ( x )
E2 = id1;
else
E2 = start;
id1:
if ( x )
E2 = start;
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
E2 = id1001;
default: // estado indefinido
E2 = 4'bxxxx;
endcase
end // always at signal or state changing
// variáveis de estado
always @( posedge clk or negedge reset )
begin
if ( reset )
E1 = E2; // atualiza estado atual
else
E1 = 0; // reset
end // always at signal changing
// lógica de saída
always @( E1 )
begin
y = (E1 == id1001); // O bit de saída é 1 quando a sequência 1001 é reconhecida
end // always at state changing
endmodule // moore_1101