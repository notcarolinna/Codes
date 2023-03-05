--------------------------------------
-- Biblioteca
--------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

--------------------------------------
-- Entidade
--------------------------------------

ENTITY somador IS
    PORT (
        a, b : IN INTEGER RANGE 0 TO 15;
        z : OUT INTEGER RANGE 0 TO 15

        -- a, b são entradas
        -- são do tipo inteiro (integer)
        -- range: tamanho de 0 to 15 (4 bits)
        -- z é uma saída

    );
END somador;

--------------------------------------
-- Arquitetura
--------------------------------------

ARCHITECTURE main OF somador IS
BEGIN

    z <= a + b;
    -- z recebe a + b
    
END main;
