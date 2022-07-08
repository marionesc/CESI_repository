library IEEE; 
use IEEE.std_logic_1164.all;

ENTITY mux4v1 IS

	generic( n 	: natural :=1);
	
	port(
		sel		: in std_logic_vector(1 DOWNTO 0);
		info0 	: in std_logic_vector(n-1 DOWNTO 0);
		info1 	: in std_logic_vector(n-1 DOWNTO 0);
		info2 	: in std_logic_vector(n-1 DOWNTO 0);
		info3 	: in std_logic_vector(n-1 DOWNTO 0);
		smux 	: out std_logic_vector(n-1 DOWNTO 0));

END ENTITY mux4v1;

ARCHITECTURE with_select OF mux4v1 IS
BEGIN
 WITH sel(1 DOWNTO 0) SELECT
     smux <= 	info0 WHEN "00",
				info1 WHEN "01",
				info2 WHEN "10",
				info3 WHEN "11";

END ARCHITECTURE with_select;