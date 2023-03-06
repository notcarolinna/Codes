LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY testbench_somador_completo_4bits IS
END testbench_somador_completo_4bits;

ARCHITECTURE Behavioral OF testbench_somador_completo_4bits IS

    COMPONENT somador_completo_4bits IS
        PORT (
            a : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
            b : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
            cin : IN STD_LOGIC;
            sum : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
            cout : OUT STD_LOGIC);
    END COMPONENT;

    SIGNAL a : STD_LOGIC_VECTOR (3 DOWNTO 0) := "0101";
    SIGNAL b : STD_LOGIC_VECTOR (3 DOWNTO 0) := "0011";

    Carolinna
    Faça uma testbench para o seguinte código em VHDL :
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
    Abaixo segue uma possível testbench para o código em VHDL do somador completo :

    vhdl
    Copy code
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

        -- Sinais da entidade a ser testada
        SIGNAL a, b, cin, cout, sum : STD_LOGIC;

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
