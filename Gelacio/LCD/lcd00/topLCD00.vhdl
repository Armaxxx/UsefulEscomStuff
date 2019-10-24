library ieee;
library lattice;
library lattice;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use lattice.all;
use packageLCD00.all;

entity topLCD00 is
	port(
		clk0: inout std_logic;
		reset0: in std_logic;
		cdiv00: in std_logic_vector(4 downto 0);
		outFlagcc0: inout std_logic;
		outFlagcf0: inout std_logic;
		outFlagcd0: inout std_logic;
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
end topLCD00;

architecture topLCD0 of topLCD00 is
signal sword: std_logic_vector(7 downto 0);
signal scommand: std_logic_vector(7 downto 0);
signal sdata: std_logic_vector(7 downto 0);
signal sRWcf, sRScf, sENcf: std_logic;
signal sRWcd, sRScd, sENcd: std_logic;
signal sRW0, sRS0, sEN0: std_logic;

begin
outwordLCD0 <= sword;
outwordLED0 <= sword;
outRWLCD0 <= sRW0;
outRSLED0 <= sRS0;
outENLCD0 <= sEN0;
outENLED0 <= sEN0;
	LD00: topdiv00 port map(oscout0 => clk0,
							cdiv0 => cdiv00);
	
	LD01:contconfigLCD00 port map(clkcc => clk0,
									resetcc => reset0,
									inFlagcc => outFlagcf0,
									outcc => outcontcc0,
									outFlagcc => outFlagcc0);

	LD02: configLCD00 port map(	clkcf => clk0,
								resetcf => reset0,
								inFlagcf => outFlagcd0, --correcion 
								incontcf => outcontcc0,
								commandcf => scommand,
								RWcf => sRWcf,
								RScf => sRScf,
								ENcf => sENcf, 
								outFlagcf => outFlagcf0);

	LD03:contdataLCD00 port map(clkcd => clk0,
								resetcd => reset0,
								inFlagcd => outFlagcf0,
								outcontcd => outcontcd0,
								RWcd => sRWcd,
								RScd => sRScd,
								ENcd => sENcd,
								outFlagcd => outFlagcd0);

	LD04:dataLCD00 port map(clkd => clk0,
							resetd => reset0,							inFlagcfd => outFlagcf0,
							inFlagd => outFlagcd0,
							indird => outcontcd0,
							outchar => sdata);

	LD05:muxLCD00 port map(	resetm => reset0,
							inFlagcfm => outFlagcf0,
							inFlagcdm => outFlagcd0,
							incommandcfm => scommand,
							inworddm => sdata,
							inRWcfm => sRWcf,
							inRScfm => sRScf,
							inENcfm => sENcf,
							inRWcdm => sRWcd,
							inRScdm => sRScd,
							inENcdm => sENcd,
							outwordm => sword,
							outRWm => sRW0,
							outRSm => sRS0,
							outENm => sEN0);

	
end topLCD0;