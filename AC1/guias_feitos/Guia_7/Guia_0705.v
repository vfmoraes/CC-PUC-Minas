// -------------------------
// Guia_0705 - GATES
// Nome: Victor Ferraz de Moraes
// Matricula: 802371
// -------------------------
module f7 (
  output reg s,
  input a,
  input b,
  input [2:0] select
);

  wire not_a, not_b;
  wire and_ab, nand_ab, xor_ab, xnor_ab, or_ab, nor_ab;

  // Implementação das portas lógicas
  assign not_a = ~a;
  assign not_b = ~b;
  assign and_ab = a & b;
  assign nand_ab = ~(a & b);
  assign xor_ab = a ^ b;
  assign xnor_ab = ~(a ^ b);
  assign or_ab = a | b;
  assign nor_ab = ~(a | b);

  // Selecionar a saída apropriada com base em 'select'
  always @(*) begin
    case (select)
      3'b000: s = not_a;
      3'b001: s = and_ab;
      3'b010: s = nand_ab;
      3'b011: s = xor_ab;
      3'b100: s = xnor_ab;
      3'b101: s = or_ab;
      3'b110: s = nor_ab;
      default: s = 1'b0; // Saída padrão em caso de seleção inválida
    endcase
  end

endmodule // f7

module mux (output s, input a, input b, input select);
  assign s = (select) ? b : a; // Mux simples com select como chave de seleção
endmodule // mux

module test_f7;

  // Definir dados
  reg x;
  reg y;
  wire s;
  wire z;

  // Conectar os módulos
  f7 modulo (s, x, y, 3'b001); // Por exemplo, selecionar AND como operação padrão
  mux MUX1 (z, s, y, x); // Conectar a saída de f7 (s) à entrada de mux

  // Parte principal
  initial begin : main
    $display("Guia_0705 - Victor Ferraz de Moraes - 802371");
    $display("Test LU's module");
    $display(" x y s z");
    x = 1'b0; y = 1'b1;

    // Projetar testes do módulo
    #1 $monitor("%4b %4b %4b %4b", x, y, s, z);
    #1 x = 3'b001;
    #1 x = 3'b010;
    #1 x = 3'b011;
    #1 x = 3'b100;
    #1 x = 3'b101;
    #1 x = 3'b110;
  end

endmodule // test_f7
