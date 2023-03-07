--------------------------------------
-- Biblioteca
--------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

--------------------------------------
-- Entidade
--------------------------------------
ENTITY mux_4x1_tb IS
END mux_4x1_tb;

--------------------------------------
-- Arquitetura
--------------------------------------
ARCHITECTURE tb OF mux_4x1_tb IS

    COMPONENT mux_4x1 -- Componente que será testado
        PORT (
            D0, D1, D2, D3 : IN BIT;
            S0, S1 : IN BIT;
            Y : OUT BIT
        );
    END COMPONENT;

    SIGNAL D0_signal, D1_signal, D2_signal, D3_signal, S0_signal, S1_signal, Y_expected : BIT;  -- Sinais para os estímulos e as respostas esperadas
    SIGNAL S_signal : BIT_VECTOR(1 DOWNTO 0);

