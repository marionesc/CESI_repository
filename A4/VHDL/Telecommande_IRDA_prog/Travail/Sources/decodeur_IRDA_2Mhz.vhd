-- LIBRARY USED
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL ;
USE IEEE.NUMERIC_STD.ALL ;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;  

-- ENTITY 
ENTITY decodeur_IRDA_2MHz IS 
	GENERIC( n 					: NATURAL := 4 );
	
	PORT( arazb, clk_2MHz		: IN STD_LOGIC;
		  new_touche, recept	: IN STD_LOGIC; 
		  touche				: IN STD_LOGIC_VECTOR(7 DOWNTO 0); 
		  
		  up, down, valide		: OUT STd_LOGIC; 
		  s_load_T				: OUT STD_LOGIC; 
		  canal_T				: OUT STD_LOGIC_VECTOR(9 DOWNTO 0));
		  
END ENTITY decodeur_IRDA_2MHz; 

-- ARCHITECTURE
ARCHITECTURE archi OF decodeur_IRDA_2MHz IS
	SIGNAL cpt_1		: UNSIGNED(n-1 DOWNTO 0);
	SIGNAL cpt_2		: UNSIGNED(n-1 DOWNTO 0);
	
	SIGNAL chiffre_conv	: INTEGER := 0; 
	SIGNAL cpt_touche	: INTEGER := 0; 
	SIGNAL touche_s		: INTEGER := 0; 

	BEGIN
		PROCESS(clk_2MHZ, arazb)
		BEGIN
			IF arazb = '0' THEN 
				cpt_1 <= (others => '0');
				cpt_2 <= (others => '0');
			ELSIF RISING_EDGE(clk_2MHz) THEN 
			-- CREATION DES DIFFERENTS COMPTEURS PUR LA GESTION DU TEMPS
				-- Compteur_1 jusqu'à 1 ms
				IF cpt_1 <= 1000 THEN
					cpt_1 <= cpt_1 + 1;
					
					-- Compteur_2 jusqu'à 3s
					IF cpt_2 <= 6000 THEN
						cpt_2 <= cpt_2 + 1; 
					ELSE 
						cpt_2 <= "0000";
					END IF; 
				ELSE   
					cpt_1 <= "0000";
				END IF;
				
				-- lancement de la sortie s_load_T
				IF recept <= '1' THEN
					IF cpt_2 < 3000 THEN
						s_load_T <= '1'; 
					ELSE 
						s_load_T <= '0';
					END IF; 
				END IF; 
				
				
				
				-- 13 branches d'état 
				CASE touche IS
						
					-- TOUCHE UP : 0001 1010 -- 0x1a
					WHEN "00011010" =>
						IF cpt_1 < 500 THEN
							up <= '1'; 
						ELSE 
							up <= '0';
						END IF;
					
					-- TOUCHE DOWN	: 0001 1110 -- 0x1e
					WHEN "00011110" => 
						IF cpt_1 < 500 THEN
							down <= '1'; 
						ELSE 
							down <= '0';
						END IF; 
					
					-- TOUCHE VALIDE : 0001 0010 -- 0x12
					WHEN "00010010" =>
						IF cpt_1 < 500 THEN
							valide <= '1'; 
						ELSE 
							valide <= '0';
						END IF; 
					
					WHEN OTHERS =>
				END CASE; 
				
				-- TOUCHE CHIFFRE :
				chiffre_conv <= to_integer(unsigned(touche)); 
				CASE chiffre_conv IS
					WHEN 0 to 9 =>
						IF new_touche <= '0' THEN 				
							IF cpt_touche < 4 THEN
								cpt_touche <= cpt_touche + 1; 
								touche_s <= touche_s * 10 + to_integer(unsigned(touche)); 
							ELSE 
								-- Si on de passe de 4 dizaines, on repart à zero les rentrees de chiffres
								cpt_touche <= 0;
								touche_s <= to_integer(unsigned(touche)); 
							END IF; 
							
							-- Si les chiffres sont validées
							IF touche <= "00010010" THEN
								canal_T <= std_logic_vector(to_unsigned(touche_s,10)); 
							END IF;
						END IF; 
					WHEN OTHERS =>
				END CASE; 
			END IF; 
		END PROCESS; 
END ARCHITECTURE archi; 