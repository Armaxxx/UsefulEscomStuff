library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity nand00 is
	port(
		Ana: in std_logic_vector(7 downto 0);
		Bna: in std_logic_vector(7 downto 0);
		Yna: out std_logic_vector(7 downto 0));
end nand00;

architecture nand0 of nand00 is
begin
	Yna <= Ana nand Bna;
end nand0;