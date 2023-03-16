; 	int a = 4, b = 7, maior;
;	int i=4, j;
;
;	main() {
;  	j = getchar();
;  	if(i==j)
;   i = i + 2;
;  	else
;   j = j - 1;
;  	printf("%d", i);
;  	printf("%d", j);
;	}

; li: carrega uma constante de 32 bits no registrador do destino

.data
i: .word 4
j: .space 4
 
.text
	.globl main

main:					
	li	$v0, 5					; o valor 5 é carregado no registrador $v0, que armazena o valor de retorno das chamadas de sistema	
	syscall 					; chamada de sistema que executa uma operação específica

	move	$t1, $v0			; copia o valor de um registrador para outro, ou seja, o valor de $v0 é copiado para $t1
	lw	$t0, i					; carrega uma palavra (4 bytes) da memória para o registrador
	beq	$t0, $t1, v_Igual		; realiza um desvio condicional para o endereço especificado caso os dois registradores especificados como parâmetros forem iguais
		
v_Diferente:
	subi	$t1, $t1, 1			; subtrai uma constante de 16 bits do registrador: o valor 1 é substituído de $t1
	j	fim			

v_Igual:
	addi	$t0, $t0, 2			; adiciona o valor 2 ao registrador $t0

fim:
	li	$v0, 1				
	move	$a0, $t0			
	syscall 				
	move	$a0, $t1			
	syscall 				
	li	$v0, 10			
	syscall				

