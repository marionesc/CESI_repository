library IEEE; 
use IEEE.std_logic_1164.all;

ENTITY basculeD IS	
	port( 	rst, clk	: in std_logic;
			D 			: in std_logic; 
			Q 			: out std_logic);

END ENTITY basculeD;

ARCHITECTURE arch OF basculeD IS
BEGIN
	PROCESS(rst, clk)
	BEGIN
		IF rst = '1' THEN Q <= '0'; 
		ELSIF clk = '1' AND clk' event then 
			Q <= D;
		END IF;
	END PROCESS;

END ARCHITECTURE arch;