--------------------------------------
-- Biblioteca
--------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

--------------------------------------
-- Entidade
--------------------------------------

ENTITY half_adder IS
  PORT (
    a, b : IN STD_LOGIC;
    sum, carry : OUT STD_LOGIC);
END ENTITY;

--------------------------------------
-- Arquitetura
--------------------------------------
  
ARCHITECTURE half_adder OF half_adder IS
BEGIN
  sum <= a XOR b;
  carry <= a AND b;
END ARCHITECTURE;
