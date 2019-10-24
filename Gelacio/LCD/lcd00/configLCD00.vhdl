library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packagediv00.all;

entity configLCD00 is
	port (
	clkcf: in std_logic;
	resetcf: in std_logic;
	inFlagcf: in std_logic; --sincronizar procesos
	incontcf: in std_logic_vector(4 downto 0);
	commandcf: out std_logic_vector(7 downto 0);
	RWcf: out std_logic;
	RScf: out std_logic;
	ENcf: out std_logic;
	outFlagcf: out std_logic
);
end configLCD00;

architecture configLCD0 of configLCD00 is
signal scontrolcf: std_logic_vector(1 downto 0);
begin
scontrolcf <= (resetcf)&(inFlagcf);
	pconfig: process(clkcf)
	begin
		if (clkcf'event and clkcf='1') then
			case scontrolcf is
				when "00" =>
					commandcf <= "00000000";
					outFlagcf <= '0';
				--when "01" =>
					--outFlagcf <= '0';
				when "11" =>
					case incontcf is
						when "00001" =>
							commandcf <= "00000001";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '1';
							outFlagcf <= '0';
---------------------------------------------------------------------------										
						when "00010" =>
							commandcf <= "00000001";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '0';
							outFlagcf <= '0';
---------------------------------------------------------------------------									
						when "00011" =>
							commandcf <= "00000011";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '1';
							outFlagcf <= '0';
---------------------------------------------------------------------------						
						when "00100" =>
							commandcf <= "00000011";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '0';
							outFlagcf <= '0';
---------------------------------------------------------------------------						
						when "00101" =>
							commandcf <= "00000111"; --input set
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '1';
							outFlagcf <= '0';							
---------------------------------------------------------------------------						
						when "00110" =>
							commandcf <= "00000111";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '0';
							outFlagcf <= '0';	
---------------------------------------------------------------------------						
						when "00111" =>
							commandcf <= "00001111";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '1';
							outFlagcf <= '0';								
---------------------------------------------------------------------------						
						when "01000" =>
							commandcf <= "00001111";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '0';
							outFlagcf <= '0';

---------------------------------------------------------------------------						
						when "01001" =>
							commandcf <= "00011100";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '1';
							outFlagcf <= '0';

---------------------------------------------------------------------------						
						when "01010" =>
							commandcf <= "00111100";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '0';
							outFlagcf <= '0';
---------------------------------------------------------------------------						
						when "01011" =>
							commandcf <= "00111100";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '1';
							outFlagcf <= '0';							
---------------------------------------------------------------------------						
						when "01100" =>
							commandcf <= "00111100";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '0';
							outFlagcf <= '0';
---------------------------------------------------------------------------						
						when "01101" =>
							commandcf <= "00111100";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '1';
							outFlagcf <= '0';							
---------------------------------------------------------------------------						
						when "01110" =>
							commandcf <= "00111100";
							RWcf <= '0';
							RScf <= '0';
							ENcf <= '0';
							outFlagcf <= '1';							
						when others => null;	
					end case;						
				when others => null;				
			end case;
		end if;
	end process pconfig;	
end configLCD0;