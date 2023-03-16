; int a = 4, b = 7, maior;
; main() {
;   if(a > b)
#     maior = a;
#   else
#     maior = b;
# }

# os símbolos "?" são abreviações para indicar que um registrador é usado
# para armazenar o valor de uma variável, ou seja:
# t0 ? a = o registrador $t0 está armazenando o valor de a

.data					# seção de dados do programa
a: .word 4				# cria uma variável a e atribui o valor de 4
b: .word 7 
maior: .space 4			# declara uma variável chamada maior que é inicializada com espaço na memória pra armazenar 4 bytes	
 
.text					# seção de código
	.globl main

main:						# main() {
	lw	$t0, a				# t0 ? a
	lw	$t1, b				# t1 ? b
	bgt	$t0, $t1, a_Maior	# if(a > b)

b_Maior:
	sw	$t1, maior		#     maior = b;
	j	fim

a_Maior:
	sw	$t0, maior		#     maior = a;

fim:					# }
	j	fim				# faz um salto para o fim do programa

# lw: 	carrega um valor da memória para o registrador
# bgt: 	faz um salto condicional se o primeiro registrador for maior que o segundo,
# 	   	se for verdade, vai para a_Maior e se não for, vai para b_Maior
# sw: 	armazena o valor de um registrador na memória
# j: 	faz um salto incondicional para um lugar específico.
