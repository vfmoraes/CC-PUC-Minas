# $s0 -> x
# $s1 -> y
# $s2 -> z

.text
.globl main
main:
ori $t0, $zero, 0x7FFF
sll $t0, $t0, 16 
ori $s0, $t0, 0xFFFF # x = o maior inteiro possível
ori $t0, $zero, 0x493E
sll $s1, $t0, 4 # y = 300.000
sll $t0, $s1, 2 # t0 = 4y
sub $s2, $s0, $t0 # z = x - 4y
