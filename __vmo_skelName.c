/*
    __VMO.c
    
    VECTOR-MAPPED OBJECTS
    
    by Stanislav Stratu: stas.stratu@gmail.com
    
    https://github.com/stasu/vmo.git
    
    Licence: GNU GPLv3
*/

#include <stdio.h>
#include <stdlib.h>


#include "__vmo_skelName.h"

static struct _vmo_SkelName_obj_s_t _vmo_t_SkelName_s[ __VMO_V_MAX_SkelName +1 ] =
{
	#define			 __VMO_DefLists__SkelName
	    #define		 __VMO_DefObjct__SkelName( v, ...) [(v)] = { #v, ##__VA_ARGS__ },
		#include	"__vmo_skelName.h"
	    #undef		 __VMO_DefObjct__SkelName
	#undef			 __VMO_DefLists__SkelName
};

static struct _vmo_SkelName_obj_u_t _vmo_t_SkelName_u[ __VMO_V_MAX_SkelName +1 ] =
{
	#define			 __VMO_DefLists__SkelName
	    #define		 __VMO_DefObjct__SkelName( v, t, ...) [(v)] = { #v, (t)},
		#include	"__vmo_skelName.h"
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
	__vmo_dumpObject_SkelName_s(_vmo_t_SkelName_s,i);
	__vmo_dumpObject_SkelName_u(_vmo_t_SkelName_u,i);
    }

    printf("__vmo_ForEachObj_in_SkelName_doReverce\n");

    __vmo_ForEachObj_in_SkelName_doReverce(i)
    {
	__vmo_dumpObject_SkelName_s(_vmo_t_SkelName_s,i);
	__vmo_dumpObject_SkelName_u(_vmo_t_SkelName_u,i);
    }

}
#endif
