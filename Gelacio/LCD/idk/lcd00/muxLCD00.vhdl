library ieee;
library ieee;
library lattice;
library lattice;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use lattice.all;

entity muxLCD00 is
	port(
	resetm: in std_logic;
	inFlagcfm: in std_logic;
	inFlagcdm: in std_logic;
	incommandcfm: in std_logic_vector(7 downto 0);
	inworddm: in std_logic_vector(7 downto 0);
	inRWcfm: in std_logic;
	inRScfm: in std_logic;
	inENcfm: in std_logic;
	inRWcdm: in std_logic;
	inRScdm: in std_logic;
	inENcdm: in std_logic;
	outwordm: out std_logic_vector(7 downto 0);
	outRWm: out std_logic;
	outRSm: out std_logic;
	outENm: out std_logic
);
end muxLCD00;

architecture muxLCD0 of muxLCD00 is
signal scontrolm: std_logic_vector(1 downto 0);
begin
scontrolm <= (resetm)&(inFlagcfm);	
	with scontrolm select 
		outwordm <= incommandcfm when "10", 
					inworddm when "11",
					"00000000" when others;
---------------------------------------------------------------------
with scontrolm select 
		outRWm <= inRWcfm when "10", 
					inRWcdm when "11",
					'0' when others;
----------------------------------------------------------------------		
---------------------------------------------------------------------
with scontrolm select 
		outRSm <= inRScfm when "10", 
					inRScdm when "11",
					'0' when others;
----------------------------------------------------------------------	
---------------------------------------------------------------------
with scontrolm select 
		outENm <= inENcfm when "10", 
					inENcdm when "11",
					'0' when others;
----------------------------------------------------------------------	
end muxLCD0;