/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "oper.h"

bool_t
xdr_Operandos (XDR *xdrs, Operandos *objp)
{
	register int32_t *buf;

	 if (!xdr_float (xdrs, &objp->i))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->j))
		 return FALSE;
	return TRUE;
}
