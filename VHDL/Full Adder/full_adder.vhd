--------------------------------------
-- Biblioteca
--------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

--------------------------------------
-- Entidade
--------------------------------------
ENTITY full_adder IS
  PORT (
    a, b, cin : IN STD_LOGIC;
    cout, sum : OUT STD_LOGIC);
END ENTITY;

--------------------------------------
-- Arquitetura
--------------------------------------
ARCHITECTURE full_adder OF full_adder IS
BEGIN
  cout <= (a AND b) OR ((a XOR b) AND cin);
  sum <= a XOR b XOR cin;
END ARCHITECTURE;
