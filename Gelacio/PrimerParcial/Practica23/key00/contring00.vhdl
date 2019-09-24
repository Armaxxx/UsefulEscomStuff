library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity contring00 is
	port(
		clkr: in std_logic;
		resetr: in std_logic;
		outr: out std_logic_vector(3 downto 0));
end contring00;

architecture contring0 of contring00 is
signal sring: std_logic_vector(3 downto 0);
begin
	pring: process(clkr)
	begin
		if (rising_edge(clkr)) then
			case resetr is
				when '0' =>
					outr <= (others => '0');
					sring <= "1000";
				when '1' =>
					sring(3) <= sring(0);
					sring(2 downto 0) <= sring(3 downto 1);
					outr <= sring;
				when others => null;
			end case;
		end if;
	end process pring;
end contring0;