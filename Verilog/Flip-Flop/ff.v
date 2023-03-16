module ff (

// O código abaixo implementa uma sequência de três registradores com realimentação,
// Onde a saída do último registrador é conectada à entrada do primeiro (flip-flop ou circuito sequencial).

  input fin, //Entrada
  output fout //Saída
);

reg qa, qb, qc; //Registradores
wire nqa, nqb, nqc; //Fios

initial
begin
  qa <= 1'b0;
  qb <= 1'b0;
  qc <= 1'b0;
end

assign fout = qc; // Saída fout é conectada ao registrador qc

//@: Sensibilidade.
//~: Inverte o sinal lógico.
//Always: define uma regra que deve ser executada sempre que houver uma mudança em algum sinal específico.
//posedge: indica que a regra deve ser executada somente na borda de subida de um sinal específico.
//begin e end: é como se fosse um bloco de chaves em C/C++ {} 


always @(posedge fin) //Será executado sempre que houver uma borda de subida no sinal fin.
begin
  qa <= nqa; //A cada borda de subida do sinal de entrada fin, o valor de nqa é atribuído para qa.
end
assign nqa = ~qa; //nqa é o valor complementar de qa, ou seja, é oposto ao valor de qa.

always @(posedge qa)
begin
  qb <= nqb;
end
assign nqb = ~qb;

always @(posedge qb)
begin
  qc <= nqc;
end
assign nqc = ~qc;

endmodule
