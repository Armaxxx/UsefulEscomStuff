library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity nxor00 is
	port(
		Anx: in std_logic_vector(7 downto 0);
		Bnx: in std_logic_vector(7 downto 0);
		Ynx: out std_logic_vector(7 downto 0));
end nxor00;

architecture nxor0 of nxor00 is
begin
	Ynx <= not(Anx xor Bnx);
end nxor0;