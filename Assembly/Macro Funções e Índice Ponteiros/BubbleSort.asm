;	void swap(int *pa, int* pb) {
;	int aux = *pa;
;	*pa = *pb;
;	*pb = aux;
; }

; 	int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
; 	void main() {
; 	int *p = &vet[0];
; 	int *pFim = &vet[9];
;	while(p <= pFim) {
;		swap(p, pFim);
;		p++;
;		pFim--;
;	}
; }

.text                      ; seção de código do programa
   .globl main             ; declaração de main como função global

main:                      ; início da função main
    la $a0, vet            ; carrega o endereço base do vetor na variável $a0
    la $a1, vet+36         ; carrega o endereço do último elemento do vetor na variável $a1

while:                     ; início do loop while
    bgt $a0, $a1, fimLoop  ; se $a0 (endereço atual) > $a1 (último endereço), sai do loop while
    jal swap               ; chama a função swap para trocar os elementos
    addi $a0, $a0, 4       ; incrementa o endereço atual em 4 bytes (tamanho de uma palavra)
    subi $a1, $a1, 4       ; decrementa o último endereço em 4 bytes
    j while                ; salta para o início do loop while

fimLoop:
    li $v0, 10             ; carrega o valor 10 em $v0 (código da syscall para encerrar o programa)
    syscall                ; chama a syscall para encerrar o programa

swap:                      ; início da função swap
    lw $t0, 0($a0)         ; carrega o valor do elemento atual (apontado por $a0) em $t0
    lw $t1, 0($a1)         ; carrega o valor do último elemento (apontado por $a1) em $t1
    sw $t1, 0($a0)         ; salva o valor de $t1 no endereço atual (apontado por $a0)
    sw $t0, 0($a1)         ; salva o valor de $t0 no endereço do último elemento (apontado por $a1)
    jr $ra                 ; retorna para a função chamadora (main)

.data                      ; seção de dados do programa
vet: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9  ; declaração e inicialização do vetor
