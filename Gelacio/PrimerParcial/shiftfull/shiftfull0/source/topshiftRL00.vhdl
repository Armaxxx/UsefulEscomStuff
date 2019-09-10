library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packageshiftRL00.all;

entity topshiftRL00 is
	port(
		clk0: inout std_logic;
		cdiv00: in std_logic_vector(4 downto 0);
		reset0: in std_logic;
		ins0: in std_logic_vector(7 downto 0);
		control0: in std_logic_vector(1 downto 0);
		outs0: out std_logic_vector(7 downto 0));
end topshiftRL00;

architecture topshiftRL0 of topshiftRL00 is
begin
	SR00: topdiv00 port map(
							oscout0 => clk0,
							cdiv0 => cdiv00);
	SR01: shiftRL00 port map(
							clkRL => clk0,
							controlRL => control0,
							resetRL => reset0,
							inrsRL => ins0,
							outrsRL => outs0);
end topshiftRL0;