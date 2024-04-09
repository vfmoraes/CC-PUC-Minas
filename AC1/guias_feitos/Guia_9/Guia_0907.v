// ---------------------------
// -- Nome: Victor Ferraz de Moraes
// -- Matrícula: 802371
// ---------------------------
`include "clock.v"
module pulse_gen (
    input clk,
    output reg pulse
);

reg prev_clk;

always @(clk) begin
    if (clk && !prev_clk) begin // detecta a borda de subida
        prev_clk <= clk;
    end
    else if (!clk && prev_clk) begin // detecta a borda de descida
        prev_clk <= clk;
    end
    else if (clk && prev_clk) begin // detecta o nível alto estável
        pulse <= 1'b1;
        #5 pulse <= 1'b0;
    end
end

initial begin
    pulse <= 1'b0;
    prev_clk <= 1'b0;
end

endmodule
module Guia_0907;
wire clk;
wire pulse;
clock CLK1 ( clk );
pulse_gen PG1 ( clk, pulse );

initial begin
    $dumpfile ( "Guia_0907.vcd" );
    $dumpvars;
    #120 $finish;
end

endmodule // Guia_0907
