#include "rand.h"

void *
inicializa_random_1_svc(long *argp, struct svc_req *rqstp)
{
	static char * result;
	printf("Semilla: %ld\n", *argp);
	srandom(*argp);

	return (void *) &result;
}

double *
obtiene_siguiente_random_1_svc(void *argp, struct svc_req *rqstp)
{
	static double  result;

	result = 1 + random()%1000;

	return &result;
}
