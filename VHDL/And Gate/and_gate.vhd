--------------------------------------
-- Biblioteca
--------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

-- AND: 1 quando ambos forem 1

--------------------------------------
-- Entidade
--------------------------------------

-- Descreve a interface do dispositivo e declarando as entradas 

ENTITY and_gate IS -- O nome da entidade tem que ser obrigatóriamente o nome do arquivo
PORT (
a, b : IN BIT;
z : OUT BIT
);

END ENTITY and_gate;

--------------------------------------
-- Arquitetura
--------------------------------------

-- Descreve o comportamento das portas lógicas

ARCHITECTURE main OF and_gate IS
BEGIN
z <= a AND b;
END ARCHITECTURE main;
