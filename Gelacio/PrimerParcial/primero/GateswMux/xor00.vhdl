library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity xor00 is
	port(
		Ax: in std_logic_vector(7 downto 0);
		Bx: in std_logic_vector(7 downto 0);
		Yx: out std_logic_vector(7 downto 0));
end xor00;

architecture xor0 of xor00 is
begin
	Yx <= Ax xor Bx;
end xor0;