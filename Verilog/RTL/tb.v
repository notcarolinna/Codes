`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

module tb;
  reg reset, clock;
  wire[3:0] saida;

  localparam PERIOD = 40;  

  RTL DUT (.clock(clock), .reset(reset), .saida(saida));

  initial
  begin
    clock = 1'b0;
	reset <= 1'b1;
	reset <= #5 1'b0;
	forever #(PERIOD/2) clock = ~clock;
  end
  
endmodule
