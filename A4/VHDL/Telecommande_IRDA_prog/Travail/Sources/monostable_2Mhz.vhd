-- LIBRARY USED
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL ;
USE IEEE.NUMERIC_STD.ALL ;			-- Ajout pour faire le décalage avec nb decimaux : utilisation des fonction to_integer() et std_logic_vector()
USE IEEE.STD_LOGIC_UNSIGNED.ALL;  

-- ENTITY 
ENTITY monostable_2Mhz IS 	
	PORT( arazb, clk					: IN STD_LOGIC;		-- Variable de la clock / Reset
		  up_in, down_in, valid_in		: IN STD_LOGIC; 	-- Variable d entree 1 bit
		  
		  up_out, down_out, valid_out	: OUT STD_LOGIC); 	-- Variable d entree 1 bit
		  
END ENTITY monostable_2Mhz; 



-- ARCHITECTURE
ARCHITECTURE archi OF monostable_2Mhz IS
	-- Declaration des differents etat
	TYPE etat IS (e0, e1, e2); 
	SIGNAL state 	: etat; 
		-- e0 : etat d'initialisation (tous les elements à 0)
		-- e1 : permet d activer le cpt : 200ms (pour impulsions des touches up/down/valid)
	
     -- Declaration des differents compteur 
		-- RAPPEL : integer > +2 147 483 648d TO -2 147 483 647d
	SIGNAL cpt		: INTEGER RANGE 0 TO 200; 	-- 400 000d = 200 ms (200d = 100 µs pouyr les simulations)
BEGIN
	PROCESS(clk, arazb)
		BEGIN
			-- RESET : tout est remis a 0
			IF arazb = '1' THEN 
				state 		<= e0 ;
				up_out 		<= '0';
				down_out	<= '0'; 
				valid_out	<= '0'; 
			
			ELSIF RISING_EDGE(clk) THEN
				------------------------------------------------------------------------------------------------
				-- DECLARATION DE LA MACHINE A ETAT
				CASE state Is
					WHEN e0 =>
						-- Touche UP 
						IF(up_in = '1') THEN
							up_out 	<= '1'; 
							cpt 	<= 0;
							state 	<= e1; 
						
						-- Touche DOWN 
						ELSIF(down_in = '1') THEN
							down_out 	<= '1'; 
							cpt 		<= 0;
							state 		<= e1;
						 
						-- Touche VALID 
						ELSIF(valid_in = '1') THEN
							valid_out 	<= '1'; 
							cpt 		<= 0;
							state 		<= e1; 
					
						END IF; 
					
						
					------------------------------------------------------------------------------------------------
					-- DECLARATION DE L ETAT 1 : impulsion cpt 200 ms lors d'une entree a 1 
						WHEN e1 => 		
							cpt <= cpt + 1; 
							IF(cpt = 200) THEN -- si cpt = 400 000, alos on est a 200ms (on mets 200d (100µs) pour les simulations)
								up_out 		<= '0'; 
								down_out 	<= '0';	
								valid_out	<= '0'; 
								state 		<= e0;  				
							END IF; 
					------------------------------------------------------------------------------------------------
					-- DECLARATION DE L ETAT OTHERS : 
						WHEN OTHERS => 
							up_out		<= '0';
							down_out	<= '0';
							valid_out	<= '0';
							state		<= e0;
							
					END CASE; 
				END IF; 
		END PROCESS; 				
END ARCHITECTURE archi; 		
						
						