library ieee;
library lattice;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use lattice.all;

entity contdataLCD00 is
	port(
	clkcd: in std_logic;
	resetcd: in std_logic;
	inFlagcd: in std_logic;--bandera del modulo de configuracion
	outcontcd: inout std_logic_vector (4 downto 0);
	RWcd: out std_logic;
	RScd: out std_logic;
	ENcd: out std_logic;
	outFlagcd: out std_logic);
end contdataLCD00;

architecture contdataLCD0 of contdataLCD00 is
signal scontrolcd: std_logic_vector(1 downto 0);
begin
	scontrolcd <= (resetcd)&(inFlagcd);--señal concatenada
	pcontcd: process(clkcd)
	variable aux: bit:='0';
	begin
		if(clkcd'event and clkcd='1')then
			case scontrolcd is
				when "00" =>
					outcontcd <= (others => '0' );
					outFlagcd <= '0';			
				when "10" =>
					outcontcd <= (others => '0' );
					outFlagcd <= '0';	
				when "11" =>
					case aux is
						when '0' =>
							aux:='1';
							outcontcd <= outcontcd + '1';
							outFlagcd <= '1';
							RWcd <= '0';
							RScd <= '1';
							ENcd <= '1';
						when '1' =>
							aux:='0';
							outcontcd <= outcontcd;
							outFlagcd <= '0'; --Deshabilitar
							RWcd <= '0';
							RScd <= '1';
							ENcd <= '0';
						when others => null;
					end case;
				when others => null;
			end case;
		end if;
	end process pcontcd;
end contdataLCD0;