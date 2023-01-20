LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

ENTITY bintobcd_10bits IS
	PORT (	
		ck 			:	IN  STD_LOGIC;
		arazb 		:  IN  STD_LOGIC;
		binary		:	IN  STD_LOGIC_VECTOR(9 downto 0);
		
		BCD_uni		:  OUT  STD_LOGIC_VECTOR(3 downto 0);
		BCD_diz		:  OUT  STD_LOGIC_VECTOR(3 downto 0);
		BCD_cen		:  OUT  STD_LOGIC_VECTOR(3 downto 0)
		);
	end bintobcd_10bits;

architecture a of bintobcd_10bits is	
	
	SIGNAL uni, diz, cen, shift	:	STD_LOGIC_VECTOR(3 downto 0);
	SIGNAL i_binary, byte			:	STD_LOGIC_VECTOR(9 downto 0);
	SIGNAL temp							: 	STD_LOGIC_VECTOR(21 downto 0);
	SIGNAL add, mesure, decal		: STD_LOGIC;					
	
	BEGIN
	
--d�tection de l'addition	
	add  	<= 	'1' 	WHEN uni >= 5 and mesure = '1' and decal = '1' ELSE	
					'1' 	WHEN diz >= 5 and mesure = '1' and decal = '1' ELSE
					'1' 	WHEN cen >= 5 and mesure = '1' and decal = '1' ELSE		
					'0';	
		
	temp 	<= (cen(2 downto 0) & diz & uni & byte & '0');		
			
-- decalage des bits		
		digits : PROCESS(ck, arazb, add, uni, diz, cen)
		BEGIN
			IF arazb='0' THEN 	uni 	<= (OTHERS => '0');
										diz 	<= (OTHERS => '0');
										cen 	<= (OTHERS => '0');
										byte 	<= (OTHERS => '0');
																	
			ELSIF ck'EVENT and ck='1' THEN
					IF add = '1' and mesure ='1' and decal = '1' THEN
						IF uni >= 5 THEN uni <= uni + 3;
						END IF;
						IF diz >= 5 THEN diz <= diz + 3;
						END IF;
						IF cen >= 5 THEN cen <= cen + 3;
						END IF;
					ELSIF add = '0' and mesure ='1' THEN
						cen 	<= temp(21 downto 18);
						diz 	<= temp(17 downto 14);
						uni 	<= temp(13 downto 10);
						byte	<= temp(9 downto 0);
					ELSIF shift = 0 and (i_binary /= binary) THEN
						cen 	<= (OTHERS => '0');
						diz 	<= (OTHERS => '0');
						uni 	<= (OTHERS => '0');
						byte	<= binary;
					END IF;	
			END IF;
		END PROCESS digits;			

-- Recopie du r�sultat de la conversion en sortie en fin de conversion
		Recopie : PROCESS(ck, arazb, shift, add)
		BEGIN
			IF arazb='0' THEN 
				BCD_uni <= (OTHERS => '0');
				BCD_diz <= (OTHERS => '0');
				BCD_cen <= (OTHERS => '0');								
			ELSIF ck'EVENT and ck='1' THEN
					IF mesure = '0' THEN
						BCD_uni <= uni;
						BCD_diz <= diz;
						BCD_cen <= cen;
					END IF;
			END IF;
		END PROCESS recopie;
		
-- Mesure en cours							
		tp_mes : PROCESS(ck, arazb, shift, add)
		BEGIN
			IF arazb='0' THEN mesure <= '0';								
			ELSIF ck'EVENT and ck='1' THEN
					IF shift = 0 and (i_binary /= binary) THEN
						mesure <= '1';
						i_binary <= binary;
					ELSIF shift = 9 and add ='0' THEN
						mesure <= '0';	
					END IF;
			END IF;
		END PROCESS tp_mes;
		
-- compteur de d�calage		
		b_shift : PROCESS(ck, arazb, mesure, add)
		BEGIN
			IF arazb='0' THEN shift <= (OTHERS => '0');						
			ELSIF ck'EVENT and ck='1' THEN
					IF mesure = '1' and add ='0' and shift < 9 THEN
						shift <= shift + 1;
					ELSIF shift = 9 and add = '0' THEN
						shift <= (OTHERS => '0');	
					END IF;
			END IF;
		END PROCESS b_shift;	
	
 --Autorisation du d�calage	
		bit_deca : PROCESS(ck, arazb, mesure)
		BEGIN
			IF arazb='0' THEN decal <= '0';								
			ELSIF ck'EVENT and ck='1' THEN
					IF mesure = '1' and add ='0' THEN
						decal <= '1';
					ELSIF add = '1' and mesure ='1' THEN
						decal <= '0';	
					END IF;
			END IF;
		END PROCESS bit_deca;	
end a;