library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity nxor00 is
	port(
		Anx: in std_logic;
		Bnx: in std_logic;
		Ynx: out std_logic);
end nxor00;

architecture nxor0 of nxor00 is
begin
	Ynx <= Anx xnor Bnx;
end nxor0;