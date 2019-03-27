prac_compo: prac_compo.cpp PoligonoIrreg.o PoligonoReg.o
	g++ prac_compo.cpp PoligonoIrreg.o Poligonoreg.o Coordenada.o -o prac_compo
PoligonoReg.o: PoligonoReg.cpp Coordenada.o PoligonoIrreg.o PoligonoReg.h
	g++ PoligonoReg.cpp -c
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c