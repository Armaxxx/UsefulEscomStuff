library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packageadder4bit00.all;

entity topadder4bit00 is
	port(
		Ai: in std_logic_vector(7 downto 0);
		Bi: in std_logic_vector(7 downto 0);
		SL: in std_logic;
		LED: out std_logic;
		So: out std_logic_vector(7 downto 0));
end topadder4bit00;

architecture topadder4bit0 of topadder4bit00 is
Signal SA,SB,CS: std_logic_vector(7 downto 0);
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
		
	AD04: xor00 port map(
		Ax => SL,
		Bx => Bi(4),
		Yx => SB(4));
	
	AD05: xor00 port map(
		Ax => SL,
		Bx => Bi(5),
		Yx => SB(5));
		
	AD06: xor00 port map(
		Ax => SL,
		Bx => Bi(6),
		Yx => SB(6));
		
	AD07: xor00 port map(
		Ax => SL,
		Bx => Bi(7),
		Yx => SB(7));
		
	AD08: fa00 port map(
		A00 => Ai(0),
		B00 => SB(0),
		C01 => CS(0),
		C00 => SL,
		S00 => SA(0));
	
	AD09: fa00 port map(
		A00 => Ai(1),
		B00 => SB(1),
		C01 => CS(1),
		C00 => CS(0),
		S00 => SA(1));
	
	AD10: fa00 port map(
		A00 => Ai(2),
		B00 => SB(2),
		C01 => CS(2),
		C00 => CS(1),
		S00 => SA(2));
	
	AD11: fa00 port map(
		A00 => Ai(3),
		B00 => SB(3),
		C01 => CS(3),
		C00 => CS(2),
		S00 => SA(3));
		
	AD12: fa00 port map(
		A00 => Ai(4),
		B00 => SB(4),
		C01 => CS(4),
		C00 => CS(3),
		S00 => SA(4));
	
	AD13: fa00 port map(
		A00 => Ai(5),
		B00 => SB(5),
		C01 => CS(5),
		C00 => CS(4),
		S00 => SA(5));
	
	AD14: fa00 port map(
		A00 => Ai(6),
		B00 => SB(6),
		C01 => CS(6),
		C00 => CS(5),
		S00 => SA(6));
	
	AD15: fa00 port map(
		A00 => Ai(7),
		B00 => SB(7),
		C01 => CS(7),
		C00 => CS(6),
		S00 => SA(7));
		
	AD16: and00 port map(
		Aa => Sax,
		Ba => SA(0),
		Ya => So(0));
		
	AD17: and00 port map(
		Aa => Sax,
		Ba => SA(1),
		Ya => So(1));
		
	AD18: and00 port map(
		Aa => Sax,
		Ba => SA(2),
		Ya => So(2));
		
	AD19: and00 port map(
		Aa => Sax,
		Ba => SA(3),
		Ya => So(3));
	AD20: and00 port map(
		Aa => Sax,
		Ba => SA(4),
		Ya => So(4));
		
	AD21: and00 port map(
		Aa => Sax,
		Ba => SA(5),
		Ya => So(5));
		
	AD22: and00 port map(
		Aa => Sax,
		Ba => SA(6),
		Ya => So(6));
		
	AD23: and00 port map(
		Aa => Sax,
		Ba => SA(7),
		Ya => So(7));
	
	AD24: xor00 port map(
		Ax => CS(6),
		Bx => CS(7),
		Yx => LED);
	
	AD25: nxor00 port map(
		Anx => CS(6),
		Bnx => CS(7),
		Ynx => SaX);

end topadder4bit0;
	