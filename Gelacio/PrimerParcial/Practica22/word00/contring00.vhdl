library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity contring00 is
	port(
		clkcr: in std_logic;
		resetcr: in std_logic;
		outcr: out std_logic_vector(3 downto 0));
end contring00;

architecture contring0 of contring00 is
signal ssr: std_logic_vector(3 downto 0);
begin
	pring: process(clkcr)
	begin
		if (rising_edge(clkcr)) then
			case resetcr is
				when '0' =>
					outcr <= "1111";
					ssr <= "1110";
				when '1' =>
					ssr(0) <= ssr(3);
					ssr(3 downto 1) <= ssr(2 downto 0);
					outcr <= ssr;
				when others => null;
			end case;
		end if;
	end process pring;
end contring0;