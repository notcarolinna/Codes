; char vetChar[8];
; char valor = 1;
;
; main() {
;	int i = 0;
;	while(i < 8) {
;		vetChar[i] = valor;
;		i++;
;		valor++;
;	}
; }

.text                    ; seção de código do programa
  .globl main            ; declaração de main como função global

main:                    ; início da função main
  la    $t0, vetChar     ; carrega o endereço base do vetor "vetChar" em $t0
  lb    $t1, valor       ; carrega o valor da variável "valor" (1 byte) em $t1
  li    $t2, 0           ; inicializa o contador do loop em $t2

loop:                    ; início do loop
  bge   $t2, 8, fim      ; se o contador $t2 >= 8, sai do loop
  add   $t3, $t0, $t2    ; calcula o endereço do elemento atual em $t3
  sb    $t1, 0($t3)      ; salva o valor de $t1 (1 byte) no endereço apontado por $t3
  addi  $t2, $t2, 1      ; incrementa o contador do loop em 1
  addi  $t1, $t1, 1      ; incrementa o valor de $t1 em 1 byte
  j     loop             ; volta para o início do loop

fim:
  li    $v0, 10         ; carrega o valor 10 em $v0 (código da syscall para encerrar o programa)
  syscall               ; chama a syscall para encerrar o programa
  
.data                   ; seção de dados do programa
  vetChar: .space 8     ; declaração de um vetor de 8 bytes
  valor:   .byte 1      ; declaração de uma variável "valor" com 1 byte de tamanho

