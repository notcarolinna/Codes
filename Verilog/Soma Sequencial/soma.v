module soma ( // Declaração do módulo

  input clock, reset, // Entrada: um sinal de clock e um sinal de reset
  output [7:0] saida // Saída: um vetor de 8 bits

);

reg  [7:0] opA, opB; // Declaração de dois registradores de 8 bits
wire [7:0] soma; // Declaração de um fio de 8 bits (variável não registrada)

always @(posedge clock, posedge reset) // always: é ativado na subida do clock e/ou no sinal de subida do reset

begin
  if (reset ==  1) begin // Quando o sinal de reset é ativado, as variáveis são resetadas para 0 
    opA <= 0;
    opB <= 0;
  end

  else begin
    opA <= opA + 1; // Caso não seja ativado, a variável opA é incrementada em 1 a cada pulso de clock
    opB <= soma; // E a variável opB recebe a soma entre opA e opB
  end
end

assign soma  = opA + opB;
assign saida = opB;

endmodulemodule soma ( // Declaração do módulo

  input clock, reset, // Entrada: um sinal de clock e um sinal de reset
  output [7:0] saida // Saída: um vetor de 8 bits

);

reg  [7:0] opA, opB; // Declaração de dois registradores de 8 bits
wire [7:0] soma; // Declaração de um fio de 8 bits (variável não registrada)

always @(posedge clock, posedge reset) // always: é ativado na subida do clock e/ou no sinal de subida do reset

begin
  if (reset ==  1) begin // Quando o sinal de reset é ativado, as variáveis são resetadas para 0 
    opA <= 0;
    opB <= 0;
  end

  else begin
    opA <= opA + 1; // Caso não seja ativado, a variável opA é incrementada em 1 a cada pulso de clock
    opB <= soma; // E a variável opB recebe a soma entre opA e opB
  end
end

assign soma  = opA + opB;
assign saida = opB;

endmodule
