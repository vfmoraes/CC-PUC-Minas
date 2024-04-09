// ---------------------------
// -- Nome: Victor Ferraz de Moraes
// -- Matrícula: 802371
// ---------------------------
`include "Guia_0901.v"
module pulse_gen (
    input clk,
    output reg pulse
);

always @(posedge clk) begin
    pulse <= 1'b1;
    #2 pulse <= 1'b0;
end

initial begin
    pulse <= 1'b0;
end

endmodule
module Guia_0905;
wire clk;
wire pulse;
clock CLK1 ( clk );
pulse_gen PG1 ( clk, pulse );

initial begin
    $dumpfile ( "Guia_0905.vcd" );
    $dumpvars;
    #120 $finish;
end

endmodule // Guia_0905
