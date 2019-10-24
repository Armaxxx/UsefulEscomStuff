library ieee;
library lattice;
library lattice;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use lattice.all;

package packageLCD00 is

	component topdiv00
		port(
		cdiv0: in std_logic_vector(4 downto 0);
		oscout0: inout std_logic);
	end component;
	
	component contconfigLCD00
		port(
		clkcc: in std_logic;
		resetcc: in std_logic;
		inFlagcc: in std_logic;
		outcc: inout std_logic_vector(4 downto 0);
		outFlagcc: out std_logic);
	end component;
	
	component configLCD00
		port (
			clkcf: in std_logic;
			resetcf: in std_logic;
			inFlagcf: in std_logic; --sincronizar procesos
			incontcf: in std_logic_vector(4 downto 0);
			commandcf: out std_logic_vector(7 downto 0);
			RWcf: out std_logic;
			RScf: out std_logic;
			ENcf: out std_logic;
			outFlagcf: out std_logic
);
	end component;
	
	component contdataLCD00
		port(
	clkcd: in std_logic;
	resetcd: in std_logic;
	inFlagcd: in std_logic;--bandera del modulo de configuracion
	outcontcd: inout std_logic_vector (4 downto 0);
	RWcd: out std_logic;
	RScd: out std_logic;
	ENcd: out std_logic;
	outFlagcd: out std_logic);
	end component;
	
	component dataLCD00
		port(
		clkd: in std_logic;
		resetd: in std_logic;
		inFlagd: in std_logic;
		inFlagcfd: in std_logic;
		indird: in std_logic_vector(4 downto 0);
		outchar: inout std_logic_vector(7 downto 0));
	end component;
	
	component muxLCD00
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
	end component;
	
end packageLCD00;
	