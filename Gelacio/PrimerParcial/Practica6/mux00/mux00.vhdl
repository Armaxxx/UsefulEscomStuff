library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity mux00 is
	port(
		Am: in std_logic_vector(7 downto 0);
		Bm: in std_logic_vector(7 downto 0);
		--Cm: in std_logic_vector(2 downto 0);
		Sm: in std_logic_vector(2 downto 0);
		Ym: out std_logic_vector(7 downto 0));
end mux00;

architecture mux0 of mux00 is
begin
	with Sm select
		Ym <= Am and Bm when "001",
			Am or Bm when "010",
			Am xor Bm when "011",
			Am nand Bm when "100",
			Am nor Bm when "101",
			Am xnor Bm when "110",
			not(Am) when "111",
			"00000000" when others;
end mux0;