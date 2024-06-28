.text
.globl main
main:
lui $s0, 0x1001 # s0 = A[0]
addi $a0, $s0, 16 # a0 = A[0] + endereço
add $a1, $zero, 10 # a1 = Tamanho do vetor
jal vetor # chama a função vetor
add $s1, $zero, $v0 # guarda o valor da soma retornada no registrador s1
sw $s1, 0($s0) # escreve a soma na primeira posição da memória
j fim
	vetor:
		add $t0, $zero, $zero # i = 0
		loop:
			sll $t1, $t0, 2 # t1 = 4i
			add $t1, $t1, $a0 # y[i]
			andi $t2, $t0, 0x1 # t2 verifica se é par ou impar
			beq $t2, $zero, par # vai para a operação de par ou impar
			impar:
				add $v0, $v0, $t0 # acumula o valor da soma na saida
				sw $t0, 0($t1) # escreve o valor de i na memória
				j incremento_i # pula e incrementa i
			par:
				sll $t3, $t0, 1 # t3 = 2i
				addi $t3, $t3, -1 # t3 = 2i - 1
				add $v0, $v0, $t3 # v0 = v0 + 2i - 1
				sw $t3, 0($t1) # escreve o valor do cálculo na memória
		incremento_i:
			addi $t0, $t0, 1 # i = i + 1
			slt $t4, $t0, $a1 # t4 = i < TAM
			bne $t0, $a1, loop # Se for menor, refaz o loop
			jr $ra # retorna pra main
fim: