
--=======================================================
--  This code is generated by Terasic System Builder
--=======================================================
library ieee;
use ieee.std_logic_1164.all ;
-- **************************************************
-- AJOUTER vos bibliothèques et paquetages ci-dessous

use work.tp_package.all;

-- ***************************
-- Ne JAMAIS modifier l'entity  
entity Maquette_TP2 is
	port (
			--//////////// CLOCK //////////
			CLOCK_50, CLOCK2_50, CLOCK3_50 	:	in		std_logic ;

			--//////////// LED //////////
			LEDG										:	out	std_logic_vector(7 downto 0) ;
			LEDR										:	out	std_logic_vector(17 downto 0) ;

			--//////////// KEY //////////
			KEY										:	in		std_logic_vector(3 downto 0) ;

			--//////////// SW //////////
			SW											:	in		std_logic_vector(17 downto 0) ;

			--//////////// SEG7 //////////
			HEX0,	HEX1,	HEX2,	HEX3,	HEX4,	HEX5,	HEX6,	HEX7 : out	std_logic_vector(6 downto 0) ;

			--//////////// LCD //////////
			LCD_BLON, LCD_EN,	LCD_ON, LCD_RS, LCD_RW : out std_logic ;
			LCD_DATA									:	inout	std_logic_vector(7 downto 0) ;

			--//////////// SDCARD //////////
			SD_CLK									:	out 	std_logic ;
			SD_CMD									:	inout std_logic ;
			SD_DAT									:	inout std_logic_vector(3 downto 0) ;
			SD_WP_N									:	in 	std_logic ;

			--//////////// VGA //////////
			VGA_B, VGA_G, VGA_R					:	out	std_logic_vector(7 downto 0) ;
			VGA_BLANK_N, VGA_CLK					:	out	std_logic ;
			VGA_HS, VGA_SYNC_N, VGA_VS			:	out	std_logic ;

			--//////////// Audio //////////
			AUD_ADCDAT								:	in		std_logic ;
			AUD_ADCLRCK, AUD_BCLK, AUD_DACLRCK : inout std_logic ;
			AUD_DACDAT, AUD_XCK					:	out	std_logic ;

			--//////////// I2C for Audio HSMC  //////////
			I2C_SCLK									:	out	std_logic ;
			I2C_SDAT									:	inout	std_logic ;

			--//////////// IR Receiver //////////
			IRDA_RXD									:	in 	std_logic ;

			--//////////// SRAM //////////
			SRAM_ADDR								:	out	std_logic_vector(19 downto 0) ;
			SRAM_DQ									:	inout std_logic_vector(15 downto 0) ;
			SRAM_CE_N, SRAM_LB_N, SRAM_OE_N	:	out	std_logic ;
			SRAM_UB_N, SRAM_WE_N					:	out	std_logic ;

			--//////////// GPIO, GPIO connect to GPIO Default //////////
			GPIO										:	inout std_logic_vector(35 downto 0) ;

			--//////////// HSMC, HSMC connect to HSMC Expansion - 3.3V //////////
			HSMC_CLKIN0, HSMC_CLKIN_N1, HSMC_CLKIN_P1	:	in 	std_logic ;
			HSMC_CLKIN_N2, HSMC_CLKIN_P2		:	in 	std_logic ;
			HSMC_CLKOUT_N1, HSMC_CLKOUT_P1, HSMC_CLKOUT0	:	inout	std_logic ;
			HSMC_CLKOUT_N2, HSMC_CLKOUT_P2	:	out	std_logic ;	-- inout normalement, mais supprime un warning genant
			HSMC_D									:	inout std_logic_vector(3 downto 0) ;
			HSMC_RX_D_N								:	inout std_logic_vector(16 downto 0) ;
			HSMC_RX_D_P								:	inout std_logic_vector(16 downto 0) ;
			HSMC_TX_D_N								:	inout std_logic_vector(16 downto 0) ;
			HSMC_TX_D_P								:	inout std_logic_vector(16 downto 0) 
			) ;
end entity Maquette_TP2 ;

architecture synth of Maquette_TP2 is

-- ************************************************************
-- Ne PAS modifier le composant pll : génère l'horloge à 10 MHz
--	component pll
--		port
--		(
--			inclk0		: IN std_logic  := '0';
--			c0		: OUT std_logic 
--		);
--	end component;

-- **************************************
-- Ne JAMAIS toucher aux signaux suivants
	signal clk_10mhz : std_logic ;

	signal pulse_in, recep, em_1, em_2, shutdown : std_logic ;

	signal ssb_aff, sclk_aff, mosi_aff, miso_aff : std_logic ;
	signal ssb_pot, sclk_pot, mosi_pot : std_logic ;

	signal ssb_cna, sclk_cna, mosi_cna	:	 std_logic;
	signal ssb_can, sclk_can, mosi_can,miso_can	:	 std_logic;

	signal iSW			: std_logic_vector (17 downto 0);
	signal iKEY			: std_logic_vector (3 downto 1);

-- ********************************************
-- Ajouter vos signaux ci-dessous SI NECESSAIRE


begin
-- ********************************************************
-- INSEREZ l'instanciation du composant à tester ci-dessous

--u0_deco7seg : deco7seg
--port map(
		--	en	=> SW(17),
		--	E => SW(3 downto 0),
			--segment => HEX0);

u0_mux4v1 : mux4v1		
generic map(n => 2)
port map(
			sel(1 DOWNTO 0)		=> SW(17 DOWNTO 16),
			info0(1 DOWNTO 0)  => SW(1 DOWNTO 0),
			info1(1 DOWNTO 0)  => SW(3 DOWNTO 2),
			info2(1 DOWNTO 0)  => SW(5 DOWNTO 4),
			info3(1 DOWNTO 0)  => SW(7 DOWNTO 6),
			smux(1 DOWNTO 0)     => LEDG(1 DOWNTO 0));
		
u0_deco1p4 : deco1p4			
port map(
			en						=> SW(8),
			sel(1 DOWNTO 0)   => SW(7 DOWNTO 6),
			s_deco_prio(3 DOWNTO 0) 	=> LEDR(11 DOWNTO 8),
			s_deco_var(3 DOWNTO 0)   	=> LEDR(3 DOWNTO 0));
			
-- Signaux utiles :
-- 	KEY(0) : arazb
-- 	clk_10mhz : horloge
-- 	iSW(17..0) : interrupteurs
--		iKEY(3..1) : boutons poussoirs 

			  
				  
				  
				  
				  
-- **************************************************
-- Commentez les affectations suivantes SI NECESSAIRE
	--ledR <= iSW ;
	--ledG <= (others => '0') ;

	hex0 <= (others => '1') ;
	hex1 <= (others => '1') ;
	hex2 <= (others => '1') ;
	hex3 <= (others => '1') ;
	hex4 <= (others => '1') ;
	hex5 <= (others => '1') ;
	hex6 <= (others => '1') ;
	hex7 <= (others => '1') ;

	em_2 <= '0' ;
	shutdown <= '0' ;
	ssb_can <= '1' ;
	sclk_can <= '0' ;
	mosi_can <= '0' ;
	ssb_cna <= '1' ;
	sclk_cna <= '0' ;
	mosi_cna <= '0' ;
		
-- ******************************		
-- NE PAS MODIFIER CE QUI SUIT !		
-- anti metastabilite
	process(clk_10mhz,key(0))
	begin
		if key(0) = '0' then  isw <= (others => '0') ;
									 ikey <= (others => '0') ;
		elsif clk_10mhz = '1' and clk_10mhz'event then
			isw <= sw ;
			ikey <= key(3 downto 1) ;
		end if ;
	end process ;

--visualisation sur analyseur logique
	ssb_pot <= ssb_can ;
	sclk_pot <= sclk_can ;
	mosi_pot <= mosi_can ;
	em_1 <= miso_can ;

	ssb_aff <= ssb_cna ;
	sclk_aff <= sclk_cna ;
	mosi_aff <= mosi_cna ;

-- connexions convertisseurs
	miso_can <= HSMC_TX_D_N(15);
	hsmc_tx_D_P(15) <= mosi_can ;
	HSMC_TX_D_P(16) <= sclk_can ;
	hsmc_tx_D_N(16) <= ssb_can ;
	
	hsmc_rx_D_n(16) <= sclk_cna ;
	hsmc_rx_D_p(16) <= mosi_cna ;
	hsmc_rx_D_n(15) <= ssb_cna ;

-- connexions Telemetre
	pulse_in <= HSMC_rx_D_n(9) ;		-- recepteur HF
	
	recep		<= HSMc_tx_D_N(12) ;
	HSMC_CLKOUT_P2 <= em_1 ;
	HSMc_tx_D_n(13)  <=  em_2 ;
	HSMc_tx_D_p(13) <= shutdown ;
	
	HSMc_tX_D_P(10) <= ssb_aff ;
	HSMc_TX_D_P(9) <= sclk_aff ;
	HSMc_TX_D_N(10) <= mosi_aff ;
	miso_aff <= HSMc_TX_D_N(9) ;
	
	HSMc_TX_D_P(12) <= ssb_pot ;
	HSMc_TX_D_P(14) <= sclk_pot ;
	HSMC_CLKOUT_N2 <= mosi_pot ;

-- instanciation pll
--	pll_inst : pll port map (
--			inclk0	 => CLOCK_50,
--			c0	 => clk_10mhz
--		);
	
-- Affectations pour éviter des warnings
	LCD_BLON <= '0' ;
	LCD_EN <= '0' ;
	LCD_ON <= '0' ;
	LCD_RS <= '0' ;
	LCD_RW  <= '0' ;
	SD_CLK <= '0' ;
	VGA_B <= (others => '0') ;
	VGA_G <= (others => '0') ;
	VGA_R <= (others => '0') ;
	VGA_BLANK_N <= '1' ;
	VGA_CLK <= '1' ;
	VGA_HS <= '1' ;
	VGA_SYNC_N <= '1' ;
	VGA_VS <= '1' ;
	AUD_DACDAT <= '0' ;
	AUD_XCK <= '0' ;
	I2C_SCLK <= '0' ;
	SRAM_ADDR <= (others => '0') ;	
	SRAM_OE_N <= '1' ;
	SRAM_CE_N <= '1' ;
	SRAM_LB_N <= '1' ;
	SRAM_UB_N <= '1' ;
	SRAM_WE_N <= '1' ;
				  
end ;

