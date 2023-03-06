--------------------------------------
-- Biblioteca
--------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

--------------------------------------
-- Entidade
--------------------------------------
ENTITY full_adder_tb IS
END ENTITY;

--------------------------------------
-- Arquitetura
--------------------------------------
ARCHITECTURE testbench OF full_adder_tb IS

    SIGNAL a, b, cin, cout, sum : STD_LOGIC; -- Sinais da entidade a ser testada

BEGIN

    -- Instanciação da entidade a ser testada
    uut : ENTITY work.full_adder
        PORT MAP(
            a => a, b => b, cin => cin,
            cout => cout, sum => sum);
    cout => cout, sum => sum);

    -- Estímulos de entrada
    stimulus : PROCESS
    BEGIN

        a <= '0';
        b <= '0';
        cin <= '0';
        WAIT FOR 10 ns;
        ASSERT (cout = '0' AND sum = '0') REPORT "Erro: Teste 1" SEVERITY error;

        a <= '1';
        b <= '0';
        cin <= '0';
        WAIT FOR 10 ns;
        ASSERT (cout = '0' AND sum = '1') REPORT "Erro: Teste 2" SEVERITY error;

        a <= '0';
        b <= '1';
        cin <= '0';
        WAIT FOR 10 ns;
        ASSERT (cout = '0' AND sum = '1') REPORT "Erro: Teste 3" SEVERITY error;

        a <= '1';
        b <= '1';
        cin <= '0';
        WAIT FOR 10 ns;
        ASSERT (cout = '1' AND sum = '0') REPORT "Erro: Teste 4" SEVERITY error;

        a <= '0';
        b <= '0';
        cin <= '1';
        WAIT FOR 10 ns;
        ASSERT (cout = '0' AND sum = '1') REPORT "Erro: Teste 5" SEVERITY error;

        a <= '1';
        b <= '0';
        cin <= '1';
        WAIT FOR 10 ns;
        ASSERT (cout = '1' AND sum = '0') REPORT "Erro: Teste 6" SEVERITY error;

        a <= '0';
        b <= '1';
        cin <= '1';
        WAIT FOR 10 ns;
        ASSERT (cout = '1' AND sum = '0') REPORT "Erro: Teste 7" SEVERITY error;

        a <= '1';
        b <= '1';
        cin <= '1';
        WAIT FOR 10 ns;
        ASSERT (cout = '1' AND sum = '1') REPORT "Erro: Teste 8" SEVERITY error;

        WAIT;

    END PROCESS stimulus;
