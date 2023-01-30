LIBRARY ieee;
USE ieee.std_logic_1164.all;


ENTITY reg_univ_n IS
	GENERIC	( n : NATURAL 				:= 4 ) ;
	port 	( clk, arazb 				: IN STD_LOGIC ;
			  sraz,sload,en,ser_in,sens : IN STD_LOGIC ;
			  E 						: STD_LOGIC_VECTOR (n-1 DOWNTO 0) ;
			  S 						: OUT STD_LOGIC_VECTOR (n-1 DOWNTO 0) ) ;
END reg_univ_n ;

ARCHITECTURE synth OF reg_univ_n IS
	
	-- 
	SIGNAL reg : STD_LOGIC_VECTOR (n-1 DOWNTO 0);
	
	
BEGIN
	PROCESS (clk,arazb)
	BEGIN
		if arazb = '0' then reg <= (others => '0');
		elsif clk = '1' and clk'event then
			if sraz = '1' then reg <= (others => '0') ;
			elsif sload = '1' then reg <= E ;
			elsif en ='1' then 
			
				if sens = '1' then 					-- decalage a droite
					reg <= ser_in & reg(n-1 downto 1);
					
				else 								-- decalage a gauche
					reg <= reg(n-2 downto 0) & ser_in ;
					
				END IF;
			END IF ;
		END IF ;
	END PROCESS ;
	
	S <= reg ;
END ARCHITECTURE;