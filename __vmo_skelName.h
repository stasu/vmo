/*
    __VMO.H

    VECTOR-MAPPED OBJECTS

    by Stanislav Stratu: stas.stratu@gmail.com
    
    https://github.com/stasu/vmo.git

    Licence: GNU GPLv3
*/


#if defined	__VMO_DefLists__SkelName

		__VMO_DefObjct__SkelName( V1, 0x001, 0)
		__VMO_DefObjct__SkelName( V2, 0x002, 0)
		__VMO_DefObjct__SkelName( V3, 0x004, 0)
		__VMO_DefObjct__SkelName( V4, 0x008, 0)
		__VMO_DefObjct__SkelName( V5, 0x010, 0)
		__VMO_DefObjct__SkelName( V6, 0x020, 0)
		__VMO_DefObjct__SkelName( V7, 0x040, 0)
		__VMO_DefObjct__SkelName( V8, 0x080, 0)

		// !!!!  This Item Is MANDATORY !!!!!!
		__VMO_DefObjct__SkelName( __VMO_V_MAX_SkelName,0,0)

#endif //	__VMO_DefLists__SkelName


#ifndef __VMO_SkelName__H_
#define __VMO_SkelName__H_

typedef enum _vmo_v_SkelName
{
	#define			 __VMO_DefLists__SkelName
	    #define		 __VMO_DefObjct__SkelName( v, ...)  v,
		#include	"__vmo_skelName.h"
	    #undef		 __VMO_DefObjct__SkelName
	#undef			 __VMO_DefLists__SkelName

} vmo_v_SkelName;

typedef struct _vmo_SkelName_obj_s_t
{
    char *name;
    int msk;
    int cnt;

} vmo_SkelName_obj_s_t;

typedef struct _vmo_SkelName_obj_u_t
{
    char *name;
    int t;

} vmo_SkelName_obj_u_t;

#define __vmo_ForEachObj_in_SkelName_do(i) \
				for( (i)=0;			   (i) < __VMO_V_MAX_SkelName;	(i)++)

#define __vmo_ForEachObj_in_SkelName_doReverce(i) \
				for( (i)=(__VMO_V_MAX_SkelName-1); (i) >= 0;			(i)--)

#define __vmo_dumpObject_SkelName_s(_t_,i)\
			    do {\
				printf("ts v_id %d v_name %s %08x %d\n",(i),(_t_)[(i)].name,(_t_)[(i)].msk,(_t_)[(i)].cnt);\
			    } while(0);

#define __vmo_dumpObject_SkelName_u(_t_,i)\
			    do {\
				printf("tu v_id %d v_name %s %d\n",     (i),(_t_)[(i)].name,(_t_)[(i)].t);\
			    } while(0);

#endif //__VMO_SkelName__H_

