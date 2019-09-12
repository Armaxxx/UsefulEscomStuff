library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

entity lcdMux00 is
	port(
		resetm: in std_logic;
		inFlagcm: in std_logic;
		inFlagdm: in std_logic;
		inCommandm: in std_logic_vector(7 downto 0);
		inRWcm: in std_logic;
		inRScm: in std_logic;
		inENcm: in std_logic;
		inWordm: in std_logic_vector(7 downto 0);
		inRWdm: in std_logic;
		inRSdm: in std_logic;
		inENdm: in std_logic;
		outWordm: out std_logic_vector(7 downto 0);
		outRWm: out std_logic;
		outRSm: out std_logic;
		outENm: out std_logic);
end lcdMux00;

architecture lcdMux0 of lcdMux00 is
signal scontrol: std_logic_vector(2 downto 0);
begin
scontrol <= (resetm)&(inFlagcm)&(inFlagdm);
	with scontrol select
		outWordm <= inCommandm when "100",
					inWordm when "111",
					"00000000" when others;
	with scontrol select
		outRWm <= inRWcm when "100",
				  inRWdm when "111",
				  '0' when others;
	with scontrol select
		outRSm <= inRWcm when "100",
				  inRWdm when "111",
				  '0' when others;
	with scontrol select
		outENm <= inENcm when "100",
				  inENdm when "111",
				  '0' when others;
end lcdMux0;