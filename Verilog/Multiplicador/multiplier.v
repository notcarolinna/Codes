module multiplier (
    input clock, reset, start // Declaração das entradas clock, reset e start
    input [31:0] A, B         // Declaração de entradas A e B como vetores de 32 bits
    output reg end_mul        // Declaração de um registrador como saída
    output reg [63:0] produto // Declaração de uma saída como um registrador de 64 bits
);

reg [31:0] a_reg, b_reg; // Declaração de dois registradores 32 bits para guardar os valores de A e B
reg [63:0] prod_reg;     // Declaração de um registrador de 6 bits para guardar o produto de A e B
reg [5:0] count;         // Declaração de um contador de 6 bits para controlar o estado da FSM

always @(posedge clock) begin // Sempre que houver uma borda de subida no clock

    if (reset) begin            // Se o sinal de reset estiver ativo
        count <= READY;         // Resetar o contador de estado para ready
        end_mul <= 1'b0;        // Desativar o sinal de end_mul
        prod_reg <= 64'h0;      // Resetar o registrador prod_reg
    end else begin              // Caso contrário

        case (count)                    // começar a máquina de estados
            READY: begin                // se estivermos no estado READY (0)
                if (start) begin        // se o sinal de start estiver ativo
                    a_reg <= A;         // salvar o valor de A em a_reg
                    b_reg <= B;         // salvar o valor de B em b_reg
                    count <= MULTIPLY;  // mudar o estado do contador para MULTIPLY (1)
                end
            end

            MULTIPLY: begin                             // Se estivermos no estado MULTIPLY (1)
                prod_reg <= prod_reg + {a_reg, b_reg};  // Adicionar o produto parcial ao prod_reg
                if (b_reg == 32'h00000000) begin        // Se B for igual a 0
                    count <= DONE;                      // Mudar o estado do contador para DONE (2)
                end else begin                          // Caso contrário
                    b_reg <= b_reg - 1;                 // Decrementar o valor de B em 1
                end
            end

            DONE: begin                     // Se estivermos no estado DONE (2)
                end_mul <= 1'b1;            // Ativar o sinal de end_mul
                count <= READY;             // Mudar o estado do contador para READY (0)
                produto <= prod_reg;        // Armazenar o resultado final em produto
            end
        endcase // Finalizar a máquina de estados
    end
end

