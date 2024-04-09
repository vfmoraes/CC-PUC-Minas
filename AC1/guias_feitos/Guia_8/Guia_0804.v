// -------------------------
// Guia_0804 - UNIDADE LÓGICA
// Nome: Victor Ferraz de Moraes
// Matricula: 802371
// -------------------------
module Logical (
    input wire [5:0] x,
    input wire [5:0] y,
    output wire s
);
    assign s = (x != y) ? 1'b1 : 1'b0;
endmodule // Logical
module test_Logical;
    reg [5:0] x;
    reg [5:0] y;
    wire s;

    Logical LU (
        .x(x),
        .y(y),
        .s(s)
    );

    initial begin
        $display("Guia_0804 - Victor Ferraz de Moraes - 802371");
        $display("Test LU's comparator for inequality");

        $display("x y s = desigualdade");
        for (x = 0; x <= 2; x = x + 1) begin
            for (y = 0; y <= 2; y = y + 1) begin
                #10;
                $display("%b %b %b", x, y, s);
            end
        end

        $finish;
    end
endmodule // test_Logical
