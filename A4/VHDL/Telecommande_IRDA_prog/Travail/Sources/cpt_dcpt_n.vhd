                                                                                                                                                                                                                       library ieee;
USE IEEE.STD_LOGIC_1164.ALL ;
USE IEEE.NUMERIC_STD.ALL ;


ENTITY cpt_dcpt_n IS
	GENERIC ( n 					: natural := 4 ) ;
	PORT 	( clk, arazb 			: IN STD_LOGIC ;
			  sraz,sload,en,upb_dn 	: IN STD_LOGIC ;
			  E 					: IN STD_LOGIC_VECTOR (n-1 DOWNTO 0) ;
			  Q 					: OUT STD_LOGIC_VECTOR (n-1 DOWNTO 0)) ;
END cpt_dcpt_n ;



ARCHITECTURE synth OF cpt_dcpt_n IS
	SIGNAL cpt : unsigned (n-1 DOWNTO 0);
BEGIN

	PROCESS (clk,arazb)
	BEGIN
		if arazb = '0' then cpt <= (others => '0');
		elsif clk = '1' and clk'event then
			if sraz = '1' then cpt <= (others => '0') ;
			elsif sload = '1' then cpt <= unsigned (E) ;
			elsif en = '1' then 
				if upb_dn = '1' then 		-- decomptage
					cpt <= cpt - 1 ;
				else 						-- comptage
					cpt <= cpt + 1 ;
				END IF;
			END IF;
		END IF ;
	END PROCESS ;
	
	Q <= STD_LOGIC_VECTOR (cpt) ;
	
END ARCHITECTURE;