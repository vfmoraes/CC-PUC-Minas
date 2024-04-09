// ---------------------------
// -- Nome: Victor Ferraz de Moraes
// -- Matrícula: 802371
// ---------------------------
`include "clock.v"
module pulse_gen (
    input clk,
    output reg pulse
);

always @(negedge clk) begin
    pulse <= 1'b1;
    #4 pulse <= 1'b0;
end

initial begin
    pulse <= 1'b0;
end

endmodule
module Guia_0906;
wire clk;
wire pulse;
clock CLK1 ( clk );
pulse_gen PG1 ( clk, pulse );

initial begin
    $dumpfile ( "Guia_0906.vcd" );
    $dumpvars;
    #120 $finish;
end

endmodule // Guia_0906
