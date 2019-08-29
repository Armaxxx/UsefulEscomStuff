library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packageGateswMux00.all;

entity GateswMux00 is
	port(
		AGM: in std_logic_vector(7 downto 0);
		BGM: in std_logic_vector(7 downto 0);
		sel: in std_logic_vector(2 downto 0);
		YGM: out std_logic_vector(7 downto 0));
end GateswMux00;

architecture GateswMux0 of GateswMux00 is
signal Sain,Soin,Sxin,Snain,Snoin,Snxin,Snin: std_logic_vector(7 downto 0);
begin
	
	GATES00: and00 port map(
		Aa => AGM,
		Ba => BGM,
		Ya => Sain);
	
	GATES01: or00 port map(
		Ao => AGM,
		Bo => BGM,
		Yo => Soin);
		
	GATES02: xor00 port map(
		Ax => AGM,
		Bx => BGM,
		Yx => Sxin);
		
	GATES03: nand00 port map(
		Ana => AGM,
		Bna => BGM,
		Yna => Snain);
		
	GATES04: nor00 port map(
		Ano => AGM,
		Bno => BGM,
		Yno => Snoin);
		
	GATES05: nxor00 port map(
		Anx => AGM,
		Bnx => BGM,
		Ynx => Snxin);
		
	GATES06: not00 port map(
		An => AGM,
		Yn => Snin);
		
	GATES07: mux00 port map(
		ain => Sain,
		oin => Soin,
		xin => Sxin,
		nain => Snain,
		noin => Snoin,
		nxin => Snxin,
		nin => Snin,
		msel => sel,
		Ym => YGM);
end GateswMux0;