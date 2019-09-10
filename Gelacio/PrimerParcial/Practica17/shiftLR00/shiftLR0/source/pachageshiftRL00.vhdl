library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

package packageshiftRL00 is
	component topdiv00
		port(
			cdiv0: in std_logic_vector(4 downto 0);
			oscout0: inout std_logic);
	end component;
	
	component shiftRL00
		port(
			clkRL: in std_logic;
			resetRL: in std_logic;
			inrsRL: in std_logic_vector(7 downto 0);
			outrsRL: out std_logic_vector(7 downto 0));
	end component;
end packageshiftRL00;