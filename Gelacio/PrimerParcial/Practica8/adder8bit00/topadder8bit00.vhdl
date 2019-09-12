library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packageadder8bit00.all;

entity topadder8bit00 is
port (
	Ai: in std_logic_vector (7 downto 0);
	Bi: in std_logic_vector (7 downto 0);
	Sl: in std_logic;
	So: out std_logic_vector (7 downto 0);
	LED: out std_logic  --Desbordamiento	
);
end topadder8bit00;

architecture topadder8bit0 of topadder8bit00 is
	signal SA, SB, SC: std_logic_vector(7 downto 0);
	signal SX: std_logic;
begin
	AD00: xor00 port map ( 	Ax => Sl,
							Bx => Bi(0),
							Yx => SB(0)
	);
	
	AD01: xor00 port map ( 	Ax => Sl,
							Bx => Bi(1),
							Yx => SB(1)
	);
	
	AD02: xor00 port map ( 	Ax => Sl,
							Bx => Bi(2),
							Yx => SB(2)
	);
	
	AD03: xor00 port map ( 	Ax => Sl,
							Bx => Bi(3),
							Yx => SB(3)
	);
	
	AD04: xor00 port map ( 	Ax => Sl,
							Bx => Bi(4),
							Yx => SB(4)
	);
	
	AD05: xor00 port map ( 	Ax => Sl,
							Bx => Bi(5),
							Yx => SB(5)
	);
	
	AD06: xor00 port map ( 	Ax => Sl,
							Bx => Bi(6),
							Yx => SB(6)
	);
	
	AD07: xor00 port map ( 	Ax => Sl,
							Bx => Bi(7),
							Yx => SB(7)
	);
	--Full Adder
	AD08: fa00 port map (	C00 => Sl,
							A00 => Ai (0),
							B00 => SB (0),
							C01 => SC(0),
							S00 => SA (0)
							
	);
	
	AD09: fa00 port map (	C00 => SC(0),
							A00 => Ai (1),
							B00 => SB (1),
							C01 => SC(1),
							S00 => SA (1)
							
	);
	
	AD010: fa00 port map (	C00 => SC(1),
							A00 => Ai (2),
							B00 => SB (2),
							C01 => SC(2),
							S00 => SA (2)
							
	);
	
	AD011: fa00 port map (	C00 => SC(2),
							A00 => Ai (3),
							B00 => SB (3),
							C01 => SC(3),
							S00 => SA (3)
							
	);
	
	AD012: fa00 port map (	C00 => SC(3),
							A00 => Ai (4),
							B00 => SB (4),
							C01 => SC(4),
							S00 => SA (4)
							
	);
	
	AD013: fa00 port map (	C00 => SC(4),
							A00 => Ai (5),
							B00 => SB (5),
							C01 => SC(5),
							S00 => SA (5)
	);
	
	AD014: fa00 port map (	C00 => SC(5),
							A00 => Ai (6),
							B00 => SB (6),
							C01 => SC(6),
							S00 => SA (6)
	);
	
	AD015: fa00 port map (	C00 => SC(6),
							A00 => Ai (7),
							B00 => SB (7),
							C01 => SC(7),
							S00 => SA (7)
	);
	--AND
	AD016: and00 port map ( Aa => SX,
							Ba => SA (0),
							Ya => SO(0)
	);
	
	AD017: and00 port map ( Aa => SX,
							Ba => SA (1),
							Ya => SO(1)
	);
	
	AD018: and00 port map ( Aa => SX,
							Ba => SA (1),
							Ya => SO(1)
	);
	
	AD019: and00 port map ( Aa => SX,
							Ba => SA (2),
							Ya => SO(2)
	);
	
	AD020: and00 port map ( Aa => SX,
							Ba => SA (3),
							Ya => SO(3)
	);
	
	AD021: and00 port map ( Aa => SX,
							Ba => SA (4),
							Ya => SO(4)
	);
	
	AD022: and00 port map ( Aa => SX,
							Ba => SA (5),
							Ya => SO(5)
	);
	
	AD023: and00 port map ( Aa => SX,
							Ba => SA (6),
							Ya => SO(6)
	);
	
	AD024: and00 port map ( Aa => SX,
							Ba => SA (7),
							Ya => SO(7)
	);
	
	AD025: xnor00 port map ( Anx => SC(6),
							Bnx => SC(7),
							Ynx => SX
	);
	
	AD026: xor00 port map ( Ax => SC(6),
							Bx => SC(7),
							Yx => LED
	);
end topadder8bit0;