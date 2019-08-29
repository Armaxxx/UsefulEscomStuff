library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;
use packagelcd00.all;

entity toplcd00 is
	port(
		clk00: inout std_logic;
		cdiv00: in std_logic_vector(4 downto 0);
		reset0: in std_logic;
		outFlagcc0: inout std_logic;
		outFlagc0: inout std_logic;
		outFlagcd0: inout std_logic;
		outFlagd0: inout std_logic;
		outcontcc0: inout std_logic_vector(4 downto 0);
		outcontcd0: inout std_logic_vector(4 downto 0);
		outwordLCD0: out std_logic_vector(7 downto 0);
		outwordLED0: out std_logic_vector(7 downto 0);
		outRWLCD0: out std_logic;
		outRSLCD0: out std_logic;
		outENLCD0: out std_logic;
		outRWLED0: out std_logic;
		outRSLED0: out std_logic;
		outENLED0: out std_logic);
		
end toplcd00;

architecture toplcd0 of toplcd00 is
signal scommand: std_logic_vector(7 downto 0);
signal sdata: std_logic_vector(7 downto 0);
signal sword0: std_logic_vector(7 downto 0);
signal sRWc, sRSc, sENc: std_logic;
signal sRWcd, sRScd, sENcd: std_logic;
signal soutRW0, soutRS0, soutEN0: std_logic;
begin
outwordLCD0 <= sword0;
outwordLED0 <= sword0;
outRWLCD0 <= soutRW0;
outRSLCD0 <= soutRS0;
outENLCD0 <= soutEN0;

outRWLED0 <= soutRW0;
outRSLED0 <= soutRS0;
outENLED0 <= soutEN0;

	LC00: topdiv00 port map(clk0 => clk00,
							cdiv0 => cdiv00);
	
	LC01: lcdContConfig00 port map(clkcc => clk00,
								   resetcc => reset0,
								   inFlagcc => outFlagc0,
								   outContcc => outcontcc0,
								   outFlagcc => outFlagcc0);
	
	LC02: lcdConfig00 port map(clkc => clk00,
							   resetc => reset0,
							   inFlagc => outFlagcc0,
							   incontc => outcontcc0,
							   outcommandc => scommand,
							   RWc => sRWc,
							   RSc => sRSc,
							   ENc => sENc,
							   outFlagc => outFlagc0);
	
	LC03: lcdContData00 port map(clkcd => clk00,
								 resetcd => reset0,
								 inFlagcd => outFlagc0,
								 outcontcd => outcontcd0,
								 RWcd => sRWcd,
								 RScd => sRScd,
								 ENcd => sENcd,
								 outFlagcd => outFlagcd0);
	
	LC04: lcdData00 port map(
							 clkd => clk00,
							 resetd => reset0,
							 inFlagd => outFlagc0,
							 incontd => outcontcc0,
							 outWordd => sdata,
							 outFlagd => outFlagd0);
	
	LC05: lcdmux00 port map(
						    resetm => reset0,
						    inFlagcm => outFlagc0,
							inFlagdm => outFlagcd0,
						    inCommandm => scommand,
						    inRWcm => sRWc,
						    inRScm => sRSc,
						    inENcm => sENc,
							inWordm => sdata,
							inRWdm => sRWcd,
							inRSdm => sRScd,
							inENdm => sRScd,
							outWordm => sword0,
							outRWm => soutRW0,
							outRSm => soutRS0,
							outENm => soutEN0);
	
end toplcd0;