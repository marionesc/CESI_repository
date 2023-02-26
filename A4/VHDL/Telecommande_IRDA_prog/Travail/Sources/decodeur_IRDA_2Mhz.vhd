-- LIBRARY USED
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL ;
USE IEEE.NUMERIC_STD.ALL ;			-- Ajout pour faire le décalage avec nb decimaux : utilisation des fonction to_integer() et std_logic_vector()
USE IEEE.STD_LOGIC_UNSIGNED.ALL;  


-- ENTITY 
ENTITY decodeur_IRDA_2MHz IS 	
	PORT( arazb, clk_2MHz		: IN STD_LOGIC;		-- Variable de la clock / Reset
		  new_touche, recept	: IN STD_LOGIC; 	-- Variable d entree 1 bit
		  touche				: IN STD_LOGIC_VECTOR(7 DOWNTO 0); -- Variable d entree 8 bits
		  
		  up, down, valide		: OUT STD_LOGIC; 	-- variable de sortie 1 bit
		  s_load_T				: OUT STD_LOGIC; 	-- variable de sortie 1 bit (s_load_T : indique l'appui ou le maintien d un chiffre)
		  canal_T				: OUT STD_LOGIC_VECTOR(9 DOWNTO 0));	-- variable de sortie 10 bits (canal_T : sortie de la valeur entrée via les chiffres)
		  
END ENTITY decodeur_IRDA_2MHz; 



-- ARCHITECTURE
ARCHITECTURE archi OF decodeur_IRDA_2MHz IS
	-- Declaration des differents etat
	TYPE etat IS (e0, e1, e2); 
	SIGNAL state 	: etat; 
		-- e0 : etat d'initialisation (tous les elements à 0)
		-- e1 : permet d activer le cpt_1 : 500 µs (pour touche up/down/valide)
		-- e2 : permet d activer le cpt_2 : 3s 	(pour touche chiffre avec s_load_T)
	
     -- Declaration des differents compteur 
		-- RAPPEL : integer > +2 147 483 648d TO -2 147 483 647d
	SIGNAL cpt_1		: INTEGER RANGE 0 TO 1000; 	-- 1000d = 500µs
	SIGNAL cpt_2		: INTEGER RANGE 0 TO 2000; 	-- 6000000d = 3s on met 2000 pour les simu (1ms)

    -- Declaration des differentes variables pour les sorties
	SIGNAL touche_conv	: INTEGER RANGE 0 TO 1000; 			-- utiliser pour application des fonctions de la librairie IEEE.NUMERIC_STD.ALL
	SIGNAL touche_s 	: STD_LOGIC_VECTOR(9 DOWNTO 0); 	-- signal a appliquer ensuite a canal_T après les différents décalages

BEGIN
	PROCESS(clk_2MHz, arazb)
		BEGIN
			-- RESET : tout est remis a 0
			IF arazb = '1' THEN 
				state 		<= e0 ;
				down 		<= '0';
				up			<= '0';  
				valide 		<= '0';  
				s_load_T    <= '0';  
				touche_s 	<= (OTHERS => '0');
				--touche_conv <= 0;   
				cpt_1 		<= 0; 
				cpt_2		<= 0; 
			
			ELSIF RISING_EDGE(clk_2MHZ) THEN

				------------------------------------------------------------------------------------------------
				-- DECLARATION DE LA MACHINE A ETAT
				CASE state IS

					-- ETAT e0 : etat d'initialisation
					WHEN e0 =>
						-- Touche DOWN -- 0x1E -- 0001 1110
						IF ((touche = "00011110") AND (new_touche = '1')) THEN
							down 	<= '1'; 
							cpt_1 	<= 0;  
							state 	<= e1; 
						
						-- Touche UP -- 0x1A -- 0001 1010
						ELSIF ((touche = "00011010") AND (new_touche = '1')) THEN 
							up	 	<= '1'; 
							cpt_1 	<= 0; 
							state 	<= e1; 
						
						-- Touche CHIFFRE-- 0x00 TO 0x09
						ELSIF (((touche >= "00000000") AND (touche <= "00001001")) AND (new_touche = '1')) THEN 
							touche_s 	<=  "0000000000" OR touche; -- "00" & touche = combinaison pour passer de 8 bits a 10 bits
							s_load_T 	<= '1'; 
							cpt_2 		<= 0; 
							state 		<= e2; 
						END IF; 
							
				------------------------------------------------------------------------------------------------
				-- DECLARATION DE L ETAT 1 : appui sur up/down + application compteur 
					WHEN e1 => 
						cpt_1 <= cpt_1 + 1; 
						IF cpt_1 = 1000 THEN 	-- si cpt_1 = 1000, alors on est a 500 us
							down 		<= '0'; 
							up 			<= '0'; 
							valide  	<= '0'; 		
							s_load_T 	<= '0'; 
							touche_s 	<=(OTHERS => '0'); 
							state 		<= e0; 				
						END IF; 
					
				------------------------------------------------------------------------------------------------
				-- DECLARATION DE L ETAT 2 : appui sur chiffre
					WHEN e2 => 
						cpt_2 <= cpt_2 + 1;  
						IF cpt_2 = 2000 THEN -- si cpt_2 = 6 000 000, alors on est a 3s (2000 pour les simusoit 1ms)
							state 		<= e0; 
							s_load_T 	<= '0'; 
							touche_s 	<= (OTHERS => '0'); 
						
						-- On ecrit les chiffre au fur et a mesure (on passe en décimal pour le decalage des dizaines)
						ELSIF (((touche >= "00000000") AND (touche < "00001010")) AND (new_touche = '1')) THEN 
							touche_conv <= to_integer(unsigned(touche_s)) * 10;
							touche_s 	<= std_logic_vector(to_unsigned(touche_conv, 10)); 	-- 10 car on veut une conversion de integer vers std_logic_vector(10 bits)  
							touche_s 	<= touche_s + ("0000000000" OR touche); 			-- On décale d une dizaine la valeur de touche_s et on lui ajoute le nouveau chiffre
							cpt_2 		<= 0; 
						
						-- On valide donc on repart a e1 pour cpt_1
						ELSIF ((touche = "00010111") AND (new_touche = '1')) THEN 
							valide 	<= '1';
							touche_conv <= 0; 
							cpt_1 	<= 0; 
							state 	<= e1; 
							
						END IF; 
						
				------------------------------------------------------------------------------------------------
				-- DECLARATION DE L ETAT OTHERS : 
					WHEN OTHERS => 
                        state		<= e0;
                        down		<= '0';
                        up 			<= '0';
                        valide		<= '0';
                        s_load_T	<= '0';
                        touche_s 	<= (others => '0');
                        cpt_1		<= 0;
                        cpt_2 		<= 0;
                        
                 
					END CASE; 
				END IF; 
		END PROCESS; 
		
		
		canal_T <= touche_s; --std_logic_vector(to_unsigned(touche_conv, 10)); 
		
END ARCHITECTURE archi; 


