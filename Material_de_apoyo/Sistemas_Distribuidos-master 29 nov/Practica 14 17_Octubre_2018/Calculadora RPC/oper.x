/* Archivo oper.x */

struct Operandos{
	float i;
	float j;
};

program OPER_PROG{
	version OPER_VERS{
		struct Operandos suma(struct Operandos datos) = 1;
		struct Operandos producto(struct Operandos datos) = 2;
		struct Operandos cociente(struct Operandos datos) = 3;
	} = 1;
} = 0x31111111;