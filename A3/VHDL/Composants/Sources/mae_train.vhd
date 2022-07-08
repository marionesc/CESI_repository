library IEEE; 
use IEEE.std_logic_1164.all;

ENTITY mae_train IS	
	port( 	clk, arazb		: IN STD_LOGIC; 
			alim, start		: IN STD_LOGIC; 
			capteur 		: IN STD_LOGIC_VECTOR(13 DOWNTO 8); -- 6 valeurs diffrentes
			
			visu_etat		: OUT STD_LOGIC_VECTOR(3 DOWNTO 0); 
			marche			: OUT STD_LOGIC_VECTOR(12 DOWNTO 8); -- 5 valeurs différentes
			sens 			: OUT STD_LOGIC_VECTOR(12 DOWNTO 8); -- 5 valeurs différentes
			aiguillage		: OUT STD_LOGIC_VECTOR(9 DOWNTO 8);	 -- 2 valeurs différentes
			cpt 			: OUT STD_LOGIC_VECTOR(3 DOWNTO 0)); -- compteur 4 bits 
END ENTITY mae_train;

ARCHITECTURE arch OF mae_train IS

  TYPE train_state IS (et0,et1,et2, et3, et4, et5, et6);
  SIGNAL etat_n 									: train_state;
  SIGNAL t_start, t8_11, t11_10, t10_12, t12_9, t9_10, t10_8	: STD_LOGIC;
  	
BEGIN
	t_start <= '1' WHEN start = '1' 		ELSE '0';	-- On commence au tronçon 8 T8 (C8)	[et0]
	t8_11 	<= '1' WHEN capteur(12) = '0'	ELSE '0';	-- T8  (C8)  --> T11 (C12)			[et1]
	t11_10 	<= '1' WHEN capteur(11) = '0'  	ELSE '0'; 	-- T11 (C12) --> T10 (C11)			[et2]
	t10_12 	<= '1' WHEN capteur(13) = '0' 	ELSE '0'; 	-- T10 (C11) --> T12 (C13)			[et3]
	t12_9 	<= '1' WHEN capteur( 9) = '0'   ELSE '0';	-- T12 (C13) --> T9  (C9)			[et4]
	t9_10 	<= '1' WHEN capteur(10) = '0'	ELSE '0';	-- T9  (C9)  --> T10 (C10)			[et5]
	t10_8 	<= '1' WHEN capteur( 8) = '0'	ELSE '0';	-- T10 (C10) --> T8  (C8)			[et6] 
	
	PROCESS(clk, arazb) IS
	BEGIN 
		IF arazb = '0' THEN etat_n <= et0;				-- RESET 
		ELSIF clk' EVENT and clk = '1' THEN				-- RISING CLOCK EDGE
		CASE etat_n IS 
		
			WHEN et0 => IF t_start 	= '1' THEN  		-- START au tronçons T8 (C8) 	[et0]
				etat_n <= et1;
				END IF;  
				
			WHEN et1 => IF t8_11 	= '1' THEN			-- T8  (C8)  --> T11 (C12)		[et1]
				etat_n <= et2; 
				END IF; 
				 
			WHEN et2 => IF t11_10 	= '1' THEN			-- T11 (C12) --> T10 (C11)		[et2]
				etat_n <= et3; 
				END IF;  
				
			WHEN et3 => IF t10_12	= '1' THEN			-- T10 (C11) --> T12 (C13)		[et3]
				etat_n <= et4;
				END IF;  
				
			WHEN et4 => IF t12_9	= '1' THEN			-- T12 (C13) --> T9  (C9)		[et4]
				etat_n <= et5;
				END IF;   
				
			WHEN et5 => IF t9_10	= '1' THEN			-- T9  (C9)  --> T10 (C10)		[et5]
				etat_n <= et6;
				END IF;  
				
			WHEN et6 => IF t10_8 	= '1' THEN			-- T10 (C10) --> T8  (C8)		[et6]
				etat_n <= et0;
				END IF;  
			
			WHEN OTHERS => NULL;
	
		END CASE;
		END IF;
	END PROCESS; 
	
	-- Configuration de la sortie marche (alimentation des tonçons correspondant)
	marche 	<= '0' & alim & alim  & '0' & alim 	WHEN etat_n = et1 ELSE 
			   '0' & alim & alim & '0' & '0' 	WHEN etat_n = et2 ELSE 
			   alim & '0' & alim & '0' & '0' 	WHEN etat_n = et3 ELSE 
			   alim & '0' & alim & alim & '0' 	WHEN etat_n = et4 ELSE
			   '0' & '0' & alim & alim & '0' 	WHEN etat_n = et5 ELSE
			   '0' & '0' & alim & '0' & alim 	WHEN etat_n = et6 ELSE
			   "00000";
			
	-- Configuration de la sortie sens 
	sens 	<= "01101" 	WHEN etat_n = et1 ELSE 
			   "10100" 	WHEN etat_n = et3 ELSE 
			   "00110"	WHEN etat_n = et5 ELSE
			   "00000";		
			
	-- configuration de la sortie aiguillage 
	aiguillage 	<= "10"	WHEN etat_n = et3 OR etat_n = et6 ELSE 
				   "00";	
				
	-- configuration de la sortie cpt (compteur)		
				 
		
	
END ARCHITECTURE arch;
