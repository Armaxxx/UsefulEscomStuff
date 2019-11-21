library ieee;
library lattice;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use lattice.all;

entity dataLCD00 is
	port(
		clkd: in std_logic;
		resetd: in std_logic;
		inFlagd: in std_logic;
		inFlagcfd: in std_logic;
		indird: in std_logic_vector(4 downto 0);
		outchar: inout std_logic_vector(7 downto 0));
end dataLCD00;

architecture dataLCD0 of dataLCD00 is
signal scontrol: std_logic_vector(2 downto 0);
type arraydata is array(0 to 63) of std_logic_vector(7 downto 0);
constant wordd: arraydata:=( "00100000", --ESPACIO
							"00100001", --!
							"01001000", --H
							"01001111", --O
							"01001100", --L
							"01000001", --A
							"00100000", --ESPACIO
							"01001101", --M
							"01010101", --U
							"01001110", --N
							"01000100", --D
							"01001111", --O
							"00100001", --!
							others => "00000000");
begin
scontrol <= (resetd)&(inFlagd)&(inFlagcfd);
	pdata: process(clkd)
	begin
		if (clkd'event and clkd = '1') then
			case scontrol is
				--when "10" =>
				--	outchar <= outchar;
				when "111" =>
					outchar <= wordd(conv_integer(indird));
				when others => null;			end case;
		end if;
	end process pdata;
end dataLCD0;