// ---------------------------
// -- Nome: Victor Ferraz de Moraes
// -- Matrícula: 802371
// ---------------------------
`include "clock.v"
module pulse_gen (
    input clk,
    output reg pulse
);

reg [1:0] count;

always @(posedge clk) begin
    count <= count + 1;
    if (count == 2'b10) begin
        pulse <= ~pulse;
        count <= 2'b00;
    end
end

initial begin
    pulse <= 1'b0;
    count <= 2'b00;
end

endmodule
module Guia_0903;
wire clk;
wire pulse;
clock CLK1 ( clk );
pulse_gen PG1 ( clk, pulse );

initial begin
    $dumpfile ( "Guia_0903.vcd" );
    $dumpvars;
    #120 $finish;
end

endmodule // Guia_0903
