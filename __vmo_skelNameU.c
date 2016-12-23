#include <stdio.h>
#include <stdlib.h>


#include "__vmo_skelNameU.h"

static struct _vmo_SkelName_obj_u_t _vmo_t_SkelName_u[ __VMO_V_MAX_SkelName +1 ] =
{
	#define			 __VMO_DefLists__SkelName
	    #define		 __VMO_DefObjct__SkelName(...)  __vmo_SkelName_obj_INIT(__VA_ARGS__)
		#include	"__vmo_skelNameU.h"
	    #undef		 __VMO_DefObjct__SkelName
	#undef			 __VMO_DefLists__SkelName
};

#if defined __VMO_SkelName_LibTEST
void main(void)
{
    int i=0;

    printf("__vmo_ForEachObj_in_SkelName_do\n");

    __vmo_ForEachObj_in_SkelName_do(i)
    {
	__vmo_dumpObject_SkelName_s(_vmo_t_SkelName_u,i);
    }

    printf("__vmo_ForEachObj_in_SkelName_doReverce\n");

    __vmo_ForEachObj_in_SkelName_doReverce(i)
    {
	__vmo_dumpObject_SkelName_s(_vmo_t_SkelName_u,i);
    }
}
#endif
