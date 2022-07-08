library IEEE; 
use IEEE.std_logic_1164.all;

ENTITY tdregistre IS	
	port( 	SLOAD, SHIFT, ESERIE	: in std_logic;
			ECHGT					: in std_logic_vector(5 DOWNTO 0);
			clk, arazb	 			: in std_logic; 
			S 						: out std_logic_vector(5 DOWNTO 0));

END ENTITY tdregistre;

ARCHITECTURE arch OF tdregistre IS
	SIGNAL reg : std_logic_vector(5 DOWNTO 0);
BEGIN
	PROCESS(arazb, clk)
	BEGIN
	
		IF arazb = '0' THEN reg <= "000000"; 
		ELSIF clk = '1' AND clk' event then 
			IF SLOAD = '1' THEN
				reg <= ECHGT;
			ELSIF SHIFT = '1' THEN
				reg <= ESERIE & reg(4 DOWNTO 0);
			END IF;
		END IF;
	END PROCESS;
	S <= reg; 
END ARCHITECTURE arch;