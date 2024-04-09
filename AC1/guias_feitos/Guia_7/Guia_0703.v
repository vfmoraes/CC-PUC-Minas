// -------------------------
// Guia_0700 - GATES
// Nome: xxx yyy zzz
// Matricula: 999999
// -------------------------
// -------------------------
// lu_gate
// -------------------------
module lu_gate (output s,
                input a,
                input b,
                input sel_op, // Seleção de operação (1-NAND/NOR; 0-AND/OR)
                input sel_group // Seleção de grupo (1-NAND/AND; 0-NOR/OR)
);

    wire op_and;
    wire op_nand;
    wire op_or;
    wire op_nor;
    
    // Portas de operação
    and AND1 (op_and, a, b);
    nand NAND1 (op_nand, a, b);
    or OR1 (op_or, a, b);
    nor NOR1 (op_nor, a, b);
    
    // Seleção da operação
    assign s = (sel_group) ? ((sel_op) ? op_nand : op_and) : ((sel_op) ? op_nor : op_or);
    
endmodule // lu_gate

// -------------------------
// multiplexer
// -------------------------
module mux (output s,
            input a,
            input b,
            input select
);

    wire not_select;
    
    // Descrição da seleção
    not NOT1 (not_select, select);
    
    // Multiplexação
    assign s = (not_select) ? b : a;
    
endmodule // mux

module test_lu_gate;

    // ------------------------- Definir dados
    reg x;
    reg y;
    reg s;
    wire w;
    wire z;
    
    // Criação do módulo LU
    lu_gate LU1 (w, x, y, s, 0); // Seleção inicial: Grupo AND/OR, Operação AND/OR
    
    // Multiplexador para seleção de operação
    mux MUX_op (z, w, s, x);
    
    // ------------------------- Parte principal
    initial begin : main
        $display("Guia_0700 - xxx yyy zzz - 999999");
        $display("Test LU's module");
        $display(" x y s z");
        x = 1'b0; y = 1'b1; s = 1'b0;
        
        // Projetar testes do módulo
        #1 $monitor("%4b %4b %4b %4b", x, y, s, z);
        #1 s = 1'b1;
    end
endmodule // test_lu_gate
