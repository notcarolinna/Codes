;int power(int base, int expoente) {
;   int pow = 1;   
;   while(expoente >= 1) { // negativo n�o � tratado
;     pow = pow * base;
;     expoente--;
;   }
;   return pow;
; }

; int a = 2, b = 3;
; int res1, res2;
; void main() {
;   res1 = power(a, b);
;   res2 = power(b, a);
; }
.text
  	.globl main		; |
main:				; +-> main() {
	lw $a0, a
	lw $a1, b
	jal power		; |
	sw $v0, res1		; +-> ;   res1 = power(a, b);
	lw $a0, b
	lw $a1, a
	jal power		; |
	sw $v0, res2		; +-> ;   res2 = power(b, a);
	li $v0, 10		; | $v0=10 encerra programa
	syscall			; +-> chamada ao SO }

power:				;int power(int base, int expoente) {
	li $v0, 1		;   int pow = 1;  
loop:
	ble $a1, $zero, retorno ;   while(expoente >= 1) { // negativo n�o � tratado
	mul $v0, $v0, $a0	;     pow = pow * base;
	subi $a1, $a1, 1	;     expoente--;
	j loop			;   }
retorno:
	jr $ra			;   return pow;
				; }
.data
a: .word 2
b: .word 3
res1: .space 4
res2: .space 4

	
