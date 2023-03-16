module RTL (

  input clock, reset,
  output [3:0] saida // saída de 4 bits

);

// transferência de registros

reg  [3:0] r1, r2; // circuito com dois registradores de 4 bits 
wire [3:0] soma;

always @(posedge clock, posedge reset) // os registradores serão atualizados a cada borda de subida do sinal de clock ou reset
begin
  if (reset ==  1) begin // quando o sinal do reset for ativado

    // ocorre a inicialização dos registradores
    r1 <= 4'h1;
    r2 <= 4'h0;

  end

  else begin // caso o sinal não seja ativado, os valores dos registradore são atualizados para a soma dos valores anteriores
    r1 <= soma;
    r2 <= r1;
  end
end

//assign: atribuição de sinal contínua
assign soma  = r1 + r2;
assign saida = soma;

endmodule
