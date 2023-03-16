`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

module tb;
  reg fin;
  wire fout;

  localparam PERIOD = 20;  //localparam: é como se fosse uma constante

  ff DUT (.fin(fin), .fout(fout)); //criação de um sinal de entrada chamado fin e conectando ao DUT

  initial
  begin
    fin = 1'b0;
	forever #(PERIOD/2) fin = ~fin; //forever: cria um loop infinito que altera o valor de fin a cada 20/2, ou seja, 10.
  end
  
endmodule
