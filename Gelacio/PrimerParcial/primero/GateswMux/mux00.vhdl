library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
	
entity mux00 is
	port(
		ain: in std_logic_vector(7 downto 0);
		oin: in std_logic_vector(7 downto 0);
		xin: in std_logic_vector(7 downto 0);
		nain: in std_logic_vector(7 downto 0);
		noin: in std_logic_vector(7 downto 0);
		nxin: in std_logic_vector(7 downto 0);
		nin: in std_logic_vector(7 downto 0);
		msel: in std_logic_vector(2 downto 0);
		Ym: out std_logic_vector(7 downto 0));
end mux00;

architecture mux0 of mux00 is
begin
	process (msel,ain,oin,xin,nain,noin,nxin,nin) is
	begin
		case msel is
		  when "001" =>   Ym <= ain;
		  when "010" =>   Ym <= oin;
		  when "011" =>   Ym <= xin;
		  when "100" =>   Ym <= nain;
		  when "101" =>   Ym <= noin;
		  when "110" =>   Ym <= nxin;
		  when "111" =>   Ym <= nin;
		  when others => Ym <= (others=>'0');
		end case;
	end process;
end mux0;