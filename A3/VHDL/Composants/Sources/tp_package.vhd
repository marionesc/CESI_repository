library	ieee;
use	ieee.std_logic_1164.all;

package tp_package is
component deco7seg is
	port (en			: in std_logic;
			E 			: in   std_logic_vector(3 downto 0);
         segment 	: out std_logic_vector(6 downto 0));
end component;

component mux4v1 is
	generic( n 	: natural :=1);
	
	port(
		sel		: in std_logic_vector(1 DOWNTO 0);
		info0 	: in std_logic_vector(n-1 DOWNTO 0);
		info1 	: in std_logic_vector(n-1 DOWNTO 0);
		info2 	: in std_logic_vector(n-1 DOWNTO 0);
		info3 	: in std_logic_vector(n-1 DOWNTO 0);
		smux 		: out std_logic_vector(n-1 DOWNTO 0));
end component;

component deco1p4 is
	port(
		en			: in std_logic;
		sel			: in std_logic_vector(1 DOWNTO 0);
		s_deco_var 	: out std_logic_vector(3 DOWNTO 0);
		s_deco_prio : out std_logic_vector(3 DOWNTO 0));
end component;
end tp_package;