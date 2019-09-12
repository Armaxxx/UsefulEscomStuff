library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packageword00.all;

entity topword00 is
	port(
		 clk0: inout std_logic;
		 cdiv00: in std_logic_vector(4 downto 0);
		 reset0: in std_logic;
		 outtransist0: inout std_logic_vector(3 downto 0);
		 outcoder0: out std_logic_vector(6 downto 0));
end topword00;

architecture topword0 of topword00 is
begin
	WOO: topdiv00 port map(
						oscout0 => clk0,
						cdiv0 => cdiv00);
	W01: contring00 port map(
						clkcr => clk0,
						resetcr => reset0,
						outcr => outtransist0);
	W02: coder00 port map(
						incontc => outtransist0,
						outcoderc => outcoder0);
end topword0;