// -------------------------
// Guia_0704 - GATES
// Nome: Victor Ferraz de Moraes
// Matricula: 802371
// -------------------------
// -------------------------
// f7_gate
// -------------------------
module f7 (output s,
          input a,
          input b,
          input [1:0] operation_sel);
  wire or_out, nor_out, xor_out, xnor_out;

  // Implementação das portas lógicas
  or OR1 (or_out, a, b);
  nor NOR1 (nor_out, a, b);
  xor XOR1 (xor_out, a, b);
  xnor XNOR1 (xnor_out, a, b);

  // Mux para selecionar a saída correta
  mux MUX1 (s, or_out, nor_out, xor_out, xnor_out, operation_sel);
endmodule

module mux (output s,
            input or_in,
            input nor_in,
            input xor_in,
            input xnor_in,
            input [1:0] select);
  wire [3:0] mux_out;
  
  // Mux 4x1 para selecionar a saída correta
  assign mux_out[0] = or_in;
  assign mux_out[1] = nor_in;
  assign mux_out[2] = xor_in;
  assign mux_out[3] = xnor_in;

  assign s = mux_out[select];
endmodule

module test_f7;
  // ------------------------- Definir dados
  reg x;
  reg y;
  reg [1:0] operation_sel;
  wire s;
  wire z;

  f7 modulo (s, x, y, operation_sel);

  // ------------------------- Parte principal
  initial
  begin : main
    $display("Guia_0704 - Victor Ferraz de Moraes - 802371");
    $display("Test LU's module");
    $display(" x y sel s");

    x = 1'b0; y = 1'b1; operation_sel = 2'b00; // Testar operação OR
    // Projetar testes do modulo
    #1 $monitor("%4b %4b %2b %4b", x, y, operation_sel, s);
    #1 operation_sel = 2'b01; // Testar operação NOR
    #1 operation_sel = 2'b10; // Testar operação XOR
    #1 operation_sel = 2'b11; // Testar operação XNOR
  end
endmodule
