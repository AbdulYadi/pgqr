#include <postgres.h>
#include <fmgr.h>
#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

#include <utils/builtins.h>

#include "QR_Encode.h"

#define QR_ARGCOUNT 4

PG_FUNCTION_INFO_V1(pgqr);
Datum pgqr(PG_FUNCTION_ARGS);

Datum
pgqr(PG_FUNCTION_ARGS)
{
	char* qr_char;
	int32 level, version, scale, bmp_size;
	unsigned char* p_bmp=0;
	bytea* blobout;

	if(PG_NARGS()!=QR_ARGCOUNT){
		elog(ERROR, "argument count must be %d", QR_ARGCOUNT);
	}

	if(PG_ARGISNULL(0)){
		elog(ERROR, "text must be defined");
	}
	if(PG_ARGISNULL(1)){
		elog(ERROR, "error correction level must be defined, 0 to 3");
	}
	if(PG_ARGISNULL(2)){
		elog(ERROR, "model number must be defined, 0 to 2");
	}
	if(PG_ARGISNULL(3)){
		elog(ERROR, "scale must be defined, minimum 1");
	}
	
	qr_char = TextDatumGetCString(PG_GETARG_DATUM(0));
	if(!strlen(qr_char))
		elog(ERROR, "please fill in text");

	level = PG_GETARG_INT32(1);
	if(level<0 || level>3)
		elog(ERROR, "accepted error correction level: 0 to 3");
		
	version = PG_GETARG_INT32(2);
	if(version<0 || version>2)
		elog(ERROR, "accepted model number: 0 to 2");
	
	scale = PG_GETARG_INT32(3);
	if(scale<1)
		elog(ERROR, "accepted scale: minimum 1");
	
	bmp_size = EncodeData(qr_char, level, version, scale, &p_bmp);
	if(!p_bmp || bmp_size<=0)	
		elog(ERROR, "invalid encoding");
		
	blobout=(bytea*)palloc(VARHDRSZ+bmp_size);
	memcpy(VARDATA(blobout), p_bmp, bmp_size);
	pfree(p_bmp);
	SET_VARSIZE(blobout, bmp_size+VARHDRSZ);

	PG_RETURN_BYTEA_P(blobout);
}
