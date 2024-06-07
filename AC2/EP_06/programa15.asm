# $t0 -> vet[0]
# $s0 -> i
# $s1 -> acumulador
# $t1 -> TAM

.text
.globl main
main:
lui $t0, 0x1001
ori $s0, $zero, 0 # i = 0
ori $s1, $zero, 0 # acumulador = 0
ori $t1, $zero, 100 # TAM = 100
vetor:
sll $t2, $s0, 1 # t2 = 2*i
addi $t2, $t2, 1 # t2 = 2*i + 1
sw $t2, 0($t0) # vet[i] = 2*i + 1
add $s1, $s1, $t2 # acumulador = acumulador + (2*i + 1)
addi $t0, $t0, 4 # endereço a ser guardado, aumenta 4 para cada iteração
addi $s0, $s0, 1 # i = i + 1
bne $s0, $t1, vetor
fim:
sw $s1, 0($t0) # resultado da soma de todos os numeros é armazenada

