# $s0 -> x
# $s1 -> y
# $s2 -> z

.text
.globl main
main:
ori $t0, $zero, 0x186A
sll $s0, $t0, 8 # x = 1.600.000
ori $t0, $zero, 0x1388
sll $s1, $t0, 4 # y = 80.000
ori $t0, $zero, 0x61A8
sll $s2, $t0, 4 # z = 400.000

div $s0, $s2 # lo = 1.600.000 / 400.000
mflo $t0 # t0 = 4
mult $t0, $s1 # lo = 4 * 80.000
mflo $s2 # s2 = lo
