--------------------------------------
-- Biblioteca
--------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

--------------------------------------
-- Entidade
--------------------------------------
ENTITY mux_4x1 IS

    PORT (
        D0, D1, D2, D3 : IN BIT;
        S0, S1, : IN BIT;
        Y : OUT BIT
    );

END mux_4x1

--------------------------------------
-- Arquitetura
--------------------------------------
ARCHITECTURE main OF mux_4x1 IS

    SIGNAL sel : bit_vector(1 DOWNTO 0) := "00"; -- Sinal de seleção com um vetor com 2 bits

BEGIN

    sel <= S1 & S0; -- &: Concatenação

    Y <= D0 WHEN sel = "00" ELSE
        D1 WHEN sel = "01" ELSE
        D2 WHEN sel = "10" ELSE
        D3;

END main;
