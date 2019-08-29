library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

package packageGateswMux00 is

	component and00
		port(
			Aa: in std_logic_vector(7 downto 0);
			Ba: in std_logic_vector(7 downto 0);
			Ya: out std_logic_vector(7 downto 0));
	end component;
	
	component or00
		port(
			Ao: in std_logic_vector(7 downto 0);
			Bo: in std_logic_vector(7 downto 0);
			Yo: out std_logic_vector(7 downto 0));
	end component;
	
	component xor00
		port(
			Ax: in std_logic_vector(7 downto 0);
			Bx: in std_logic_vector(7 downto 0);
			Yx: out std_logic_vector(7 downto 0));
	end component;
	
	component nand00
		port(
			Ana: in std_logic_vector(7 downto 0);
			Bna: in std_logic_vector(7 downto 0);
			Yna: out std_logic_vector(7 downto 0));
	end component;
	
	component nor00
		port(
			Ano: in std_logic_vector(7 downto 0);
			Bno: in std_logic_vector(7 downto 0);
			Yno: out std_logic_vector(7 downto 0));
	end component;
	
	component nxor00
		port(
			Anx: in std_logic_vector(7 downto 0);
			Bnx: in std_logic_vector(7 downto 0);
			Ynx: out std_logic_vector(7 downto 0));
	end component;
	
	component not00
		port(
			An: in std_logic_vector(7 downto 0);
			Yn: out std_logic_vector(7 downto 0));
	end component;
	
	component mux00
		port(
		ain: in std_logic_vector(7 downto 0);
		oin: in std_logic_vector(7 downto 0);
		xin: in std_logic_vector(7 downto 0);
		nain: in std_logic_vector(7 downto 0);
		noin: in std_logic_vector(7 downto 0);
		nxin: in std_logic_vector(7 downto 0);
		nin: in std_logic_vector(7 downto 0);
		msel: in std_logic_vector(2 downto 0);
		Ym: out std_logic_vector(7 downto 0));
	end component;
end packageGateswMux00;