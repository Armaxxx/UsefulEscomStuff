struct numeros{
int a;
int b;

};

program RAND_PROG{

	version RAND_VERS{
		void INICIALIZA_RANDOM(long) = 1;
		double OBTIENE_SIGUIENTE_RANDOM(void) = 2;
        int SUMA(numeros) = 3;
	} = 1;
} = 0x31111111;
