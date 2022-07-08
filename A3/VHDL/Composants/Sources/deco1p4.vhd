library IEEE; 
use IEEE.std_logic_1164.all;

ENTITY deco1p4 IS	
	port(
		en			: in std_logic;
		sel			: in std_logic_vector(1 DOWNTO 0);
		s_deco_var 	: out std_logic_vector(3 DOWNTO 0);
		s_deco_prio : out std_logic_vector(3 DOWNTO 0));

END ENTITY deco1p4;

ARCHITECTURE with_select OF deco1p4 IS
BEGIN
	 s_deco_prio <= 	"0000" WHEN en = '0' ELSE
						"0001" WHEN sel = "00" ELSE
						"0010" WHEN sel = "01" ELSE
						"0100" WHEN sel = "10" ELSE
						"1000" WHEN sel = "11";


 WITH sel(1 DOWNTO 0) SELECT
     s_deco_var	 <= 	"000" & en 			WHEN "00",
						"00"  & en & '0'  	WHEN "01",
						'0'   & en & "00" 	WHEN "10",
						        en & "000" 	WHEN "11";
			
END ARCHITECTURE with_select;