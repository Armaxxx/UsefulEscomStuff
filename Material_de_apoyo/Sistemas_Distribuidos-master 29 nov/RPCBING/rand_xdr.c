/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rand.h"

bool_t
xdr_numeros (XDR *xdrs, numeros *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->b))
		 return FALSE;
	return TRUE;
}
