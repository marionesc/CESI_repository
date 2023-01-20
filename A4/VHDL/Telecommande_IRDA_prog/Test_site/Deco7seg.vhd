LIBRARY ieee;
USE ieee.std_logic_1164.all; 
USE ieee.std_logic_unsigned.all; 


ENTITY deco7seg IS 
	PORT
	(
	-- Entrees
		E 			:  	IN  STD_LOGIC_VECTOR(3 downto 0);
		comp			:		IN  STD_LOGIC;
	-- Sorties	
		Segm		:		OUT STD_LOGIC_VECTOR(6 downto 0)	
	);
END deco7seg;



ARCHITECTURE a OF deco7seg IS 

	SIGNAL i_segm	: STD_LOGIC_VECTOR(6 downto 0);
	
	BEGIN
		-- Actions implicites
			i_segm  <= 	"0111111" 	WHEN E = 0 ELSE
							"0000110" 	WHEN E = 1 ELSE
							"1011011" 	WHEN E = 2 ELSE
							"1001111" 	WHEN E = 3 ELSE
							"1100110" 	WHEN E = 4 ELSE
							"1101101" 	WHEN E = 5 ELSE
							"1111101" 	WHEN E = 6 ELSE
							"0000111" 	WHEN E = 7 ELSE
							"1111111" 	WHEN E = 8 ELSE
							"1101111" 	WHEN E = 9 ELSE
							"1110111" 	WHEN E = 10 ELSE
							"1111100" 	WHEN E = 11 ELSE
							"0111001" 	WHEN E = 12 ELSE
							"1011110" 	WHEN E = 13 ELSE
							"1111001" 	WHEN E = 14 ELSE
							"1110001" 	WHEN E = 15 ELSE						
							"0000000";
							
			segm		  <= 	i_segm	WHEN comp = '0' ELSE
								not i_segm;
END a;