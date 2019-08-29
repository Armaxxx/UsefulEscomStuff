library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.all;

entity adder4bitLib00 is
	port(
		Ai: in std_logic_vector(7 downto 0);
		Bi: in std_logic_vector(7 downto 0);
		So: out std_logic_vector(7 downto 0));
end adder4bitLib00;

architecture adder4bitLib0 of adder4bitLib00 is
begin
So <= Ai + Bi;
end adder4bitLib0;