library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packageadder4bit00.all;

entity topadder4bit00 is
	port(
		Ai: in std_logic_vector(3 downto 0);
		Bi: in std_logic_vector(3 downto 0);
		SL: in std_logic;
		LED: out std_logic;
		So: out std_logic_vector(3 downto 0));
end topadder4bit00;

architecture topadder4bit0 of topadder4bit00 is
Signal SA,SB,CS: std_logic_vector(3 downto 0);
Signal SaX: std_logic;
begin
	AD00: xor00 port map(
		Ax => SL,
		Bx => Bi(0),
		Yx => SB(0));
	
	AD01: xor00 port map(
		Ax => SL,
		Bx => Bi(1),
		Yx => SB(1));
		
	AD02: xor00 port map(
		Ax => SL,
		Bx => Bi(2),
		Yx => SB(2));
		
	AD03: xor00 port map(
		Ax => SL,
		Bx => Bi(3),
		Yx => SB(3));
		
	AD04: fa00 port map(
		A00 => Ai(0),
		B00 => SB(0),
		C01 => CS(0),
		C00 => SL,
		S00 => SA(0));
	
	AD05: fa00 port map(
		A00 => Ai(1),
		B00 => SB(1),
		C01 => CS(1),
		C00 => CS(0),
		S00 => SA(1));
	
	AD06: fa00 port map(
		A00 => Ai(2),
		B00 => SB(2),
		C01 => CS(2),
		C00 => CS(1),
		S00 => SA(2));
	
	AD07: fa00 port map(
		A00 => Ai(3),
		B00 => SB(3),
		C01 => CS(3),
		C00 => CS(2),
		S00 => SA(3));
		
	AD08: and00 port map(
		Aa => Sax,
		Ba => SA(0),
		Ya => So(0));
		
	AD09: and00 port map(
		Aa => Sax,
		Ba => SA(1),
		Ya => So(1));
		
	AD10: and00 port map(
		Aa => Sax,
		Ba => SA(2),
		Ya => So(2));
		
	AD11: and00 port map(
		Aa => Sax,
		Ba => SA(3),
		Ya => So(3));
	
	AD12: xor00 port map(
		Ax => CS(2),
		Bx => CS(3),
		Yx => LED);
	
	AD13: nxor00 port map(
		Anx => CS(3),
		Bnx => CS(2),
		Ynx => SaX);

end topadder4bit0;
	