;	int power(int base, int expoente) {
;   int pow = 1;   
;   while(expoente >= 1) { // negativo n�o � tratado
;  	pow = pow * base;
; 	expoente--;
;   }
;   return pow;
; 	}

; 	int a = 2, b = 3;
; 	int res1, res2;
; 	void main() {
; 	res1 = power(a, b);
; 	res2 = power(b, a);
; 	}

.text
  	.globl main		

main:				
	lw $a0, a
	lw $a1, b

	jal power					; jump and link: chama a função power, salva o endereço de retorno na variável $ra e salta para o endereço de power
	sw $v0, res1				; salva o resultado do primeiro cálculo na variável res1
	lw $a0, b
	lw $a1, a
	jal power					; chamada da função power, que salva o retorno em $ra
	sw $v0, res2		
	li $v0, 10		
	syscall			

power:				
	li $v0, 1	

loop:
	ble $a1, $zero, retorno  	; ble: branch if less than or equal to, verifica se o expoente é menor ou igual a zero
	mul $v0, $v0, $a0			; mul: multiply, multiplica a variável pow pela base em cada iteração do loop
	subi $a1, $a1, 1	
	j loop	

retorno:						; jr: jump register, retorna da função power para a função que a chamou
	jr $ra						; $ra: registrador usado para armazenar o endereço de retorno da função power		

.data
a: .word 2
b: .word 3
res1: .space 4
res2: .space 4

	
