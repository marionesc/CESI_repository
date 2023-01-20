library ieee;
use ieee.std_logic_1164.all ;
use ieee.numeric_std.all ;


entity cpt_dcpt_n is
	generic ( n : natural := 4 ) ;
	port ( clk, arazb : in std_logic ;
			sraz,sload,en,upb_dn : in std_logic ;
			E : in std_logic_vector (n-1 downto 0) ;
			Q : out std_logic_vector (n-1 downto 0) ) ;
end cpt_dcpt_n ;

architecture synth of cpt_dcpt_n is
	signal cpt : unsigned (n-1 downto 0);
begin

	process (clk,arazb)
	begin
		if arazb = '0' then cpt <= (others => '0');
		elsif clk = '1' and clk'event then
			if sraz = '1' then cpt <= (others => '0') ;
			elsif sload = '1' then cpt <= unsigned (E) ;
			elsif en ='1' then 
				if upb_dn = '1' then -- decomptage
					cpt <= cpt - 1 ;
				else 			-- comptage
					cpt <= cpt + 1 ;
				end if;
			end if ;
		end if ;
	end process ;
	
	Q <= std_logic_vector (cpt) ;
end ;