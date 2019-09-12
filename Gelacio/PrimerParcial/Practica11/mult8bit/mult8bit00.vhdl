library ieee;
use ieee.std_logic_1164.all;
library lattice;
use lattice.all;
use packagemult8bit00.all;

entity mult8bit00 is
	port(
		Ai: in std_logic_vector (7 downto 0);
		Bi: in std_logic_vector (7 downto 0);
		R: out std_logic_vector (15 downto 0)
	);
end mult8bit00;

architecture mult8bit0 of mult8bit00 is
signal Sa00, Sc00, Sc01, Sc02, Sc03, Sc04, Sc05, Sc06: std_logic_vector (6 downto 0);
signal Sa01, Sa02, Sa03, Sa04, Sa05, Sa06, Sa07, Ss00, Ss01, Ss02, Ss03, Ss04, Ss05, Ss06: std_logic_vector (7 downto 0);
begin
	Mu000: and00 port map (
		Aa => Ai(0),
		Ba => Bi(0),
		Ya => R(0)
	);
	
	Mu001: and00 port map (
		Aa => Ai(1),
		Ba => Bi(0),
		Ya => Sa00(0)
	);
	
	Mu002: and00 port map (
		Aa => Ai(2),
		Ba => Bi(0),
		Ya => Sa00(1)
	);
	
	Mu003: and00 port map (
		Aa => Ai(3),
		Ba => Bi(0),
		Ya => Sa00(2)
	);
	
	Mu004: and00 port map (
		Aa => Ai(4),
		Ba => Bi(0),
		Ya => Sa00(3)
	);
	
	Mu005: and00 port map (
		Aa => Ai(5),
		Ba => Bi(0),
		Ya => Sa00(4)
	);
	
	Mu006: and00 port map (
		Aa => Ai(6),
		Ba => Bi(0),
		Ya => Sa00(5)
	);
	
	Mu007: and00 port map (
		Aa => Ai(7),
		Ba => Bi(0),
		Ya => Sa00(6)
	);
	
	Mu008: and00 port map (
		Aa => Ai(0),
		Ba => Bi(1),
		Ya => Sa01(0)
	);
	
	Mu009: and00 port map (
		Aa => Ai(1),
		Ba => Bi(1),
		Ya => Sa01(1)
	);
	
	Mu010: and00 port map (
		Aa => Ai(2),
		Ba => Bi(1),
		Ya => Sa01(2)
	);
	
	Mu011: and00 port map (
		Aa => Ai(3),
		Ba => Bi(1),
		Ya => Sa01(3)
	);
	
	Mu012: and00 port map (
		Aa => Ai(4),
		Ba => Bi(1),
		Ya => Sa01(4)
	);
	
	Mu013: and00 port map (
		Aa => Ai(5),
		Ba => Bi(1),
		Ya => Sa01(5)
	);
	
	Mu014: and00 port map (
		Aa => Ai(6),
		Ba => Bi(1),
		Ya => Sa01(6)
	);
	
	Mu015: and00 port map (
		Aa => Ai(7),
		Ba => Bi(1),
		Ya => Sa01(7)
	);
	
	Mu016: fa00 port map (
		C00 => '0',
		A00 => Sa00(0),
		B00 => Sa01(0),
		C01 => Sc00(0),
		S00 => R(1)
	);
	
	Mu017: fa00 port map (
		C00 => Sc00(0),
		A00 => Sa00(1),
		B00 => Sa01(1),
		C01 => Sc00(1),
		S00 => Ss00(0)
	);
	
	Mu018: fa00 port map (
		C00 => Sc00(1),
		A00 => Sa00(2),
		B00 => Sa01(2),
		C01 => Sc00(2),
		S00 => Ss00(1)
	);
	
	Mu019: fa00 port map (
		C00 => Sc00(2),
		A00 => Sa00(3),
		B00 => Sa01(3),
		C01 => Sc00(3),
		S00 => Ss00(2)
	);
	
	Mu020: fa00 port map (
		C00 => Sc00(3),
		A00 => Sa00(4),
		B00 => Sa01(4),
		C01 => Sc00(4),
		S00 => Ss00(3)
	);
	
	Mu021: fa00 port map (
		C00 => Sc00(4),
		A00 => Sa00(5),
		B00 => Sa01(5),
		C01 => Sc00(5),
		S00 => Ss00(4)
	);
	
	Mu022: fa00 port map (
		C00 => Sc00(5),
		A00 => Sa00(6),
		B00 => Sa01(6),
		C01 => Sc00(6),
		S00 => Ss00(5)
	);
	
	Mu023: fa00 port map (
		C00 => Sc00(6),
		A00 => '0',
		B00 => Sa01(7),
		C01 => Ss00(7),
		S00 => Ss00(6)
	);
	
	Mu024: and00 port map (
		Aa => Ai(0),
		Ba => Bi(2),
		Ya => Sa02(0)
	);
	
	Mu025: and00 port map (
		Aa => Ai(1),
		Ba => Bi(2),
		Ya => Sa02(1)
	);
	
	Mu026: and00 port map (
		Aa => Ai(2),
		Ba => Bi(2),
		Ya => Sa02(2)
	);
	
	Mu027: and00 port map (
		Aa => Ai(3),
		Ba => Bi(2),
		Ya => Sa02(3)
	);
	
	Mu028: and00 port map (
		Aa => Ai(4),
		Ba => Bi(2),
		Ya => Sa02(4)
	);
	
	Mu029: and00 port map (
		Aa => Ai(5),
		Ba => Bi(2),
		Ya => Sa02(5)
	);
	
	Mu030: and00 port map (
		Aa => Ai(6),
		Ba => Bi(2),
		Ya => Sa02(6)
	);
	
	Mu031: and00 port map (
		Aa => Ai(7),
		Ba => Bi(2),
		Ya => Sa02(7)
	);
	
	Mu032: fa00 port map (
		C00 => '0',
		A00 => Ss00(0),
		B00 => Sa02(0),
		C01 => Sc01(0),
		S00 => R(2)
	);
	
	Mu033: fa00 port map (
		C00 => Sc01(0),
		A00 => Ss00(1),
		B00 => Sa02(1),
		C01 => Sc01(1),
		S00 => Ss01(0)
	);
	
	Mu034: fa00 port map (
		C00 => Sc01(1),
		A00 => Ss00(2),
		B00 => Sa02(2),
		C01 => Sc01(2),
		S00 => Ss01(1)
	);
	
	Mu035: fa00 port map (
		C00 => Sc01(2),
		A00 => Ss00(3),
		B00 => Sa02(3),
		C01 => Sc01(3),
		S00 => Ss01(2)
	);
	
	Mu036: fa00 port map (
		C00 => Sc01(3),
		A00 => Ss00(4),
		B00 => Sa02(4),
		C01 => Sc01(4),
		S00 => Ss01(3)
	);
	
	Mu037: fa00 port map (
		C00 => Sc01(4),
		A00 => Ss00(5),
		B00 => Sa02(5),
		C01 => Sc01(5),
		S00 => Ss01(4)
	);
	
	Mu038: fa00 port map (
		C00 => Sc01(5),
		A00 => Ss00(6),
		B00 => Sa02(6),
		C01 => Sc01(6),
		S00 => Ss01(5)
	);
	
	Mu039: fa00 port map (
		C00 => Sc01(6),
		A00 => Ss00(7),
		B00 => Sa02(7),
		C01 => Ss01(7),
		S00 => Ss01(6)
	);
	
	Mu040: and00 port map (
		Aa => Ai(0),
		Ba => Bi(3),
		Ya => Sa03(0)
	);
	
	Mu041: and00 port map (
		Aa => Ai(1),
		Ba => Bi(3),
		Ya => Sa03(1)
	);
	
	Mu042: and00 port map (
		Aa => Ai(2),
		Ba => Bi(3),
		Ya => Sa03(2)
	);
	
	Mu043: and00 port map (
		Aa => Ai(3),
		Ba => Bi(3),
		Ya => Sa03(3)
	);
	
	Mu044: and00 port map (
		Aa => Ai(4),
		Ba => Bi(3),
		Ya => Sa03(4)
	);
	
	Mu045: and00 port map (
		Aa => Ai(5),
		Ba => Bi(3),
		Ya => Sa03(5)
	);
	
	Mu046: and00 port map (
		Aa => Ai(6),
		Ba => Bi(3),
		Ya => Sa03(6)
	);
	
	Mu047: and00 port map (
		Aa => Ai(7),
		Ba => Bi(3),
		Ya => Sa03(7)
	);
	
	Mu048: fa00 port map (
		C00 => '0',
		A00 => Ss01(0),
		B00 => Sa03(0),
		C01 => Sc02(0),
		S00 => R(3)
	);
	
	Mu049: fa00 port map (
		C00 => Sc02(0),
		A00 => Ss01(1),
		B00 => Sa03(1),
		C01 => Sc02(1),
		S00 => Ss02(0)
	);
	
	Mu050: fa00 port map (
		C00 => Sc02(1),
		A00 => Ss01(2),
		B00 => Sa03(2),
		C01 => Sc02(2),
		S00 => Ss02(1)
	);
	
	Mu051: fa00 port map (
		C00 => Sc02(2),
		A00 => Ss01(3),
		B00 => Sa03(3),
		C01 => Sc02(3),
		S00 => Ss02(2)
	);
	
	Mu052: fa00 port map (
		C00 => Sc02(3),
		A00 => Ss01(4),
		B00 => Sa03(4),
		C01 => Sc02(4),
		S00 => Ss02(3)
	);
	
	Mu053: fa00 port map (
		C00 => Sc02(4),
		A00 => Ss01(5),
		B00 => Sa03(5),
		C01 => Sc02(5),
		S00 => Ss02(4)
	);
	
	Mu054: fa00 port map (
		C00 => Sc02(5),
		A00 => Ss01(6),
		B00 => Sa03(6),
		C01 => Sc02(6),
		S00 => Ss02(5)
	);
	
	Mu055: fa00 port map (
		C00 => Sc02(6),
		A00 => Ss01(7),
		B00 => Sa03(7),
		C01 => Ss02(7),
		S00 => Ss02(6)
	);
	
	Mu056: and00 port map (
		Aa => Ai(0),
		Ba => Bi(4),
		Ya => Sa04(0)
	);
	
	Mu057: and00 port map (
		Aa => Ai(1),
		Ba => Bi(4),
		Ya => Sa04(1)
	);
	
	Mu058: and00 port map (
		Aa => Ai(2),
		Ba => Bi(4),
		Ya => Sa04(2)
	);
	
	Mu059: and00 port map (
		Aa => Ai(3),
		Ba => Bi(4),
		Ya => Sa04(3)
	);
	
	Mu060: and00 port map (
		Aa => Ai(4),
		Ba => Bi(4),
		Ya => Sa04(4)
	);
	
	Mu061: and00 port map (
		Aa => Ai(5),
		Ba => Bi(4),
		Ya => Sa04(5)
	);
	
	Mu062: and00 port map (
		Aa => Ai(6),
		Ba => Bi(4),
		Ya => Sa04(6)
	);
	
	Mu063: and00 port map (
		Aa => Ai(7),
		Ba => Bi(4),
		Ya => Sa04(7)
	);
	
	Mu064: fa00 port map (
		C00 => '0',
		A00 => Ss02(0),
		B00 => Sa04(0),
		C01 => Sc03(0),
		S00 => R(4)
	);
	
	Mu065: fa00 port map (
		C00 => Sc03(0),
		A00 => Ss02(1),
		B00 => Sa04(1),
		C01 => Sc03(1),
		S00 => Ss03(0)
	);
	
	Mu066: fa00 port map (
		C00 => Sc03(1),
		A00 => Ss02(2),
		B00 => Sa04(2),
		C01 => Sc03(2),
		S00 => Ss03(1)
	);
	
	Mu067: fa00 port map (
		C00 => Sc03(2),
		A00 => Ss02(3),
		B00 => Sa04(3),
		C01 => Sc03(3),
		S00 => Ss03(2)
	);
	
	Mu068: fa00 port map (
		C00 => Sc03(3),
		A00 => Ss02(4),
		B00 => Sa04(4),
		C01 => Sc03(4),
		S00 => Ss03(3)
	);
	
	Mu069: fa00 port map (
		C00 => Sc03(4),
		A00 => Ss02(5),
		B00 => Sa04(5),
		C01 => Sc03(5),
		S00 => Ss03(4)
	);
	
	Mu070: fa00 port map (
		C00 => Sc03(5),
		A00 => Ss02(6),
		B00 => Sa04(6),
		C01 => Sc03(6),
		S00 => Ss03(5)
	);
	
	Mu071: fa00 port map (
		C00 => Sc03(6),
		A00 => Ss02(7),
		B00 => Sa04(7),
		C01 => Ss03(7),
		S00 => Ss03(6)
	);
	
	Mu072: and00 port map (
		Aa => Ai(0),
		Ba => Bi(5),
		Ya => Sa05(0)
	);
	
	Mu073: and00 port map (
		Aa => Ai(1),
		Ba => Bi(5),
		Ya => Sa05(1)
	);
	
	Mu074: and00 port map (
		Aa => Ai(2),
		Ba => Bi(5),
		Ya => Sa05(2)
	);
	
	Mu075: and00 port map (
		Aa => Ai(3),
		Ba => Bi(5),
		Ya => Sa05(3)
	);
	
	Mu076: and00 port map (
		Aa => Ai(4),
		Ba => Bi(5),
		Ya => Sa05(4)
	);
	
	Mu077: and00 port map (
		Aa => Ai(5),
		Ba => Bi(5),
		Ya => Sa05(5)
	);
	
	Mu078: and00 port map (
		Aa => Ai(6),
		Ba => Bi(5),
		Ya => Sa05(6)
	);
	
	Mu079: and00 port map (
		Aa => Ai(7),
		Ba => Bi(5),
		Ya => Sa05(7)
	);
	
	Mu080: fa00 port map (
		C00 => '0',
		A00 => Ss03(0),
		B00 => Sa05(0),
		C01 => Sc04(0),
		S00 => R(5)
	);
	
	Mu081: fa00 port map (
		C00 => Sc04(0),
		A00 => Ss03(1),
		B00 => Sa05(1),
		C01 => Sc04(1),
		S00 => Ss04(0)
	);
	
	Mu082: fa00 port map (
		C00 => Sc04(1),
		A00 => Ss03(2),
		B00 => Sa05(2),
		C01 => Sc04(2),
		S00 => Ss04(1)
	);
	
	Mu083: fa00 port map (
		C00 => Sc04(2),
		A00 => Ss03(3),
		B00 => Sa05(3),
		C01 => Sc04(3),
		S00 => Ss04(2)
	);
	
	Mu084: fa00 port map (
		C00 => Sc04(3),
		A00 => Ss03(4),
		B00 => Sa05(4),
		C01 => Sc04(4),
		S00 => Ss04(3)
	);
	
	Mu085: fa00 port map (
		C00 => Sc04(4),
		A00 => Ss03(5),
		B00 => Sa05(5),
		C01 => Sc04(5),
		S00 => Ss04(4)
	);
	
	Mu086: fa00 port map (
		C00 => Sc04(5),
		A00 => Ss03(6),
		B00 => Sa05(6),
		C01 => Sc04(6),
		S00 => Ss04(5)
	);
	
	Mu087: fa00 port map (
		C00 => Sc04(6),
		A00 => Ss03(7),
		B00 => Sa05(7),
		C01 => Ss04(7),
		S00 => Ss04(6)
	);
	
	Mu088: and00 port map (
		Aa => Ai(0),
		Ba => Bi(6),
		Ya => Sa06(0)
	);
	
	Mu089: and00 port map (
		Aa => Ai(1),
		Ba => Bi(6),
		Ya => Sa06(1)
	);
	
	Mu090: and00 port map (
		Aa => Ai(2),
		Ba => Bi(6),
		Ya => Sa06(2)
	);
	
	Mu091: and00 port map (
		Aa => Ai(3),
		Ba => Bi(6),
		Ya => Sa06(3)
	);
	
	Mu092: and00 port map (
		Aa => Ai(4),
		Ba => Bi(6),
		Ya => Sa06(4)
	);
	
	Mu093: and00 port map (
		Aa => Ai(5),
		Ba => Bi(6),
		Ya => Sa06(5)
	);
	
	Mu094: and00 port map (
		Aa => Ai(6),
		Ba => Bi(6),
		Ya => Sa06(6)
	);
	
	Mu095: and00 port map (
		Aa => Ai(7),
		Ba => Bi(6),
		Ya => Sa06(7)
	);
	
	Mu096: fa00 port map (
		C00 => '0',
		A00 => Ss04(0),
		B00 => Sa06(0),
		C01 => Sc05(0),
		S00 => R(6)
	);
	
	Mu097: fa00 port map (
		C00 => Sc05(0),
		A00 => Ss04(1),
		B00 => Sa06(1),
		C01 => Sc05(1),
		S00 => Ss05(0)
	);
	
	Mu098: fa00 port map (
		C00 => Sc05(1),
		A00 => Ss04(2),
		B00 => Sa06(2),
		C01 => Sc05(2),
		S00 => Ss05(1)
	);
	
	Mu099: fa00 port map (
		C00 => Sc05(2),
		A00 => Ss04(3),
		B00 => Sa06(3),
		C01 => Sc05(3),
		S00 => Ss05(2)
	);
	
	Mu100: fa00 port map (
		C00 => Sc05(3),
		A00 => Ss04(4),
		B00 => Sa06(4),
		C01 => Sc05(4),
		S00 => Ss05(3)
	);
	
	Mu101: fa00 port map (
		C00 => Sc05(4),
		A00 => Ss04(5),
		B00 => Sa06(5),
		C01 => Sc05(5),
		S00 => Ss05(4)
	);
	
	Mu102: fa00 port map (
		C00 => Sc05(5),
		A00 => Ss04(6),
		B00 => Sa06(6),
		C01 => Sc05(6),
		S00 => Ss05(5)
	);
	
	Mu103: fa00 port map (
		C00 => Sc05(6),
		A00 => Ss04(7),
		B00 => Sa06(7),
		C01 => Ss05(7),
		S00 => Ss05(6)
	);
	
	Mu104: and00 port map (
		Aa => Ai(0),
		Ba => Bi(7),
		Ya => Sa07(0)
	);
	
	Mu105: and00 port map (
		Aa => Ai(1),
		Ba => Bi(7),
		Ya => Sa07(1)
	);
	
	Mu106: and00 port map (
		Aa => Ai(2),
		Ba => Bi(7),
		Ya => Sa07(2)
	);
	
	Mu107: and00 port map (
		Aa => Ai(3),
		Ba => Bi(7),
		Ya => Sa07(3)
	);
	
	Mu108: and00 port map (
		Aa => Ai(4),
		Ba => Bi(7),
		Ya => Sa07(4)
	);
	
	Mu109: and00 port map (
		Aa => Ai(5),
		Ba => Bi(7),
		Ya => Sa07(5)
	);
	
	Mu110: and00 port map (
		Aa => Ai(6),
		Ba => Bi(7),
		Ya => Sa07(6)
	);
	
	Mu111: and00 port map (
		Aa => Ai(7),
		Ba => Bi(7),
		Ya => Sa07(7)
	);
	
	Mu112: fa00 port map (
		C00 => '0',
		A00 => Ss05(0),
		B00 => Sa07(0),
		C01 => Sc06(0),
		S00 => R(7)
	);
	
	Mu113: fa00 port map (
		C00 => Sc06(0),
		A00 => Ss05(1),
		B00 => Sa07(1),
		C01 => Sc06(1),
		S00 => R(8)
	);
	
	Mu114: fa00 port map (
		C00 => Sc06(1),
		A00 => Ss05(2),
		B00 => Sa07(2),
		C01 => Sc06(2),
		S00 => R(9)
	);
	
	Mu115: fa00 port map (
		C00 => Sc06(2),
		A00 => Ss05(3),
		B00 => Sa07(3),
		C01 => Sc06(3),
		S00 => R(10)
	);
	
	Mu116: fa00 port map (
		C00 => Sc06(3),
		A00 => Ss05(4),
		B00 => Sa07(4),
		C01 => Sc06(4),
		S00 => R(11)
	);
	
	Mu117: fa00 port map (
		C00 => Sc06(4),
		A00 => Ss05(5),
		B00 => Sa07(5),
		C01 => Sc06(5),
		S00 => R(12)
	);
	
	Mu118: fa00 port map (
		C00 => Sc06(5),
		A00 => Ss05(6),
		B00 => Sa07(6),
		C01 => Sc06(6),
		S00 => R(13)
	);
	
	Mu119: fa00 port map (
		C00 => Sc06(6),
		A00 => Ss05(7),
		B00 => Sa07(7),
		C01 => R(15),
		S00 => R(14)
	);

end mult8bit0;