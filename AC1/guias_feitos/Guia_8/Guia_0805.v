// -------------------------
// Guia_0805 - UNIDADE LÓGICA
// Nome: Victor Ferraz de Moraes
// Matricula: 802371
// -------------------------
// -------------------------
// Complemento de 2
// -------------------------
module TwoComplement(
    output wire [5:0] complement,
    input wire [5:0] value
);
    assign complement = ~value + 1'b1;
endmodule // TwoComplement
module test_TwoComplement;
    reg [5:0] value;
    wire [5:0] complement;

    TwoComplement TC (
        .value(value),
        .complement(complement)
    );

    initial begin
        $display("Guia_0805 - Victor Ferraz de Moraes - 802371");
        $display("Test Two's Complement");

        $display("value complement");
        for (value = 0; value <= 2; value = value + 1) begin
            #10;
            $display("%b %b", value, complement);
        end

        $finish;
    end
endmodule // test_TwoComplement
