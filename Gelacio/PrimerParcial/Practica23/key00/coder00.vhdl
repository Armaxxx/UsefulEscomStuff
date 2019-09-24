library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;

entity coder00 is
	port(
		clkc: in std_logic;
		inkeyc: in std_logic_vector(3 downto 0);
		incontc: in std_logic_vector(3 downto 0);
		outcoderc: out std_logic_vector(6 downto 0));
end coder00;

architecture coder0 of coder00 is
begin
	pcoder: process(clkc)
	variable aux: bit :='0';
	begin
		if (rising_edge(clkc)) then
			case incontc is
				when "1000" =>
					case inkeyc is
						when "0000" =>
							aux:= '0';
						when "0001" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "1001111"; --1
							end if;
						when "0010" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0010010"; --2
							end if;
						when "0100" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0000110"; --3
							end if;
						when "1000" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0001000"; --A
							end if;
						when others => null;
					end case;
				when "0100" =>
					case inkeyc is
						when "0000" =>
							aux:= '0';
						when "0001" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "1001100"; --4
							end if;
						when "0010" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0100100"; --5
							end if;
						when "0100" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0100000"; --6
							end if;
						when "1000" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "1100000"; --b
							end if;
						when others => null;
					end case;
				when "0010" =>
					case inkeyc is
						when "0000" =>
							aux:= '0';
						when "0001" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0001111"; --7
							end if;
						when "0010" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0000000"; --8
							end if;
						when "0100" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0001100"; --9
							end if;
						when "1000" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0110001"; --C
							end if;
						when others => null;
					end case;
				when "0001" =>
					case inkeyc is
						when "0000" =>
							aux:= '0';
						when "0001" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0011100"; --*
							end if;
						when "0010" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "0000001"; --0
							end if;
						when "0100" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "1001110"; --#
							end if;
						when "1000" =>
							if (aux = '0') then
								aux := '1';
								outcoderc <= "1000010"; --d
							end if;
						when others => null;
					end case;
				when others => null;
			end case;
		end if;
	end process pcoder;
end coder0;