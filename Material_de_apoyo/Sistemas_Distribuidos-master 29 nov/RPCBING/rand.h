/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RAND_H_RPCGEN
#define _RAND_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct numeros {
	int a;
	int b;
};
typedef struct numeros numeros;

#define RAND_PROG 0x31111111
#define RAND_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define INICIALIZA_RANDOM 1
extern  void * inicializa_random_1(long *, CLIENT *);
extern  void * inicializa_random_1_svc(long *, struct svc_req *);
#define OBTIENE_SIGUIENTE_RANDOM 2
extern  double * obtiene_siguiente_random_1(void *, CLIENT *);
extern  double * obtiene_siguiente_random_1_svc(void *, struct svc_req *);
#define SUMA 3
extern  int * suma_1(numeros *, CLIENT *);
extern  int * suma_1_svc(numeros *, struct svc_req *);
extern int rand_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INICIALIZA_RANDOM 1
extern  void * inicializa_random_1();
extern  void * inicializa_random_1_svc();
#define OBTIENE_SIGUIENTE_RANDOM 2
extern  double * obtiene_siguiente_random_1();
extern  double * obtiene_siguiente_random_1_svc();
#define SUMA 3
extern  int * suma_1();
extern  int * suma_1_svc();
extern int rand_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_numeros (XDR *, numeros*);

#else /* K&R C */
extern bool_t xdr_numeros ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RAND_H_RPCGEN */
