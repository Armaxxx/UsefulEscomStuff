library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library lattice;
use lattice.components.all;
library machxo2;
use machxo2.all;

entity mul8 is
	PORT(
	         Ai: IN std_logic_vector(7 DOWNTO 0); 
             Bi: IN std_logic_vector(7 DOWNTO 0); 
             Ri: OUT std_logic_vector(15 DOWNTO 0)
			 );
end mul8;

architecture mul of mul8 is
begin
	PROCESS (Ai, Bi) IS
       BEGIN
        
           Ri <= Ai*Bi;
           
       END PROCESS;
end mul;