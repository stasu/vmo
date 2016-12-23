/*
    __VMO.H

    VECTOR-MAPPED OBJECTS

    by Stanislav Stratu: stas.stratu@gmail.com

    Licence: GNU GPLv3
*/

#if defined	__VMO_DefLists__SkelName
//-----------------------------------------------------------------------------------------------------------------
//	__VMO		here will go all VMO typedefs and functions helper
//-----------------------------------------------------------------------------------------------------------------
		__VMO_DefObjct__SkelName( V1, 0, 1)
		__VMO_DefObjct__SkelName( V2, 0, 2)
		__VMO_DefObjct__SkelName( V3, 0, 3)
		__VMO_DefObjct__SkelName( V4, 1, 'a')
		__VMO_DefObjct__SkelName( V5, 1, 'b')
		__VMO_DefObjct__SkelName( V6, 1, 'c')
		__VMO_DefObjct__SkelName( V7, 2, "Hellow")
		__VMO_DefObjct__SkelName( V8, 2, "World")
		__VMO_DefObjct__SkelName( V9, 2, "!!!")

		// !!!!  This Item Is MANDATORY !!!!!!
		__VMO_DefObjct__SkelName( __VMO_V_MAX_SkelName,0,0)

#endif //	__VMO_DefLists__SkelName


#ifndef __VMO_UTILS_H_
#define __VMO_UTILS_H_
//-----------------------------------------------------------------------------------------------------------------
//	__VMO		preprocessor helpers
//-----------------------------------------------------------------------------------------------------------------

#define __VMO_CNCT(  _a_, _b_) \
	__VMO_CNCT_I(_a_, _b_)
#define __VMO_CNCT_I(_a_, _b_) _a_ ## _b_

#define __VMO_ELEM(_n_, ...) \
	__VMO_CNCT( __VMO_ELEM_, _n_)(__VA_ARGS__,)

#define __VMO_ELEM_0( _e0, ...) _e0
#define __VMO_ELEM_1( _e0, _e1, ...) _e1
#define __VMO_ELEM_2( _e0, _e1, _e2, ...) _e2

#endif //__VMO_UTILS_H_



#ifndef __VMO_SkelName__H_
#define __VMO_SkelName__H_
//-----------------------------------------------------------------------------------------------------------------
//	__VMO		here will go all VMO typedefs and functions helper
//-----------------------------------------------------------------------------------------------------------------

typedef enum _vmo_v_SkelName
{
	#define			 __VMO_DefLists__SkelName
	    #define		 __VMO_DefObjct__SkelName( v, ...)  v,
		#include	"__vmo_skelNameU.h"
	    #undef		 __VMO_DefObjct__SkelName
	#undef			 __VMO_DefLists__SkelName

} vmo_v_SkelName;

typedef struct _vmo_SkelName_obj_u_t
{
    char *name;

    int type;

    #define __vmo_SkelName_obj_uType_int		0
    #define __vmo_SkelName_obj_uType_chr		1
    #define __vmo_SkelName_obj_uType_str		2

    #define __vmo_SkelName_obj_INIT(_v_, _t_, _c_)    [(_v_)].name=#_v_, [(_v_)].type=(_t_), __VMO_ELEM( _t_, [(_v_)].u.i.i=(_c_), [(_v_)].u.c.c=(_c_), [(_v_)].u.s.s=(_c_),),

	union
	{
		struct
		{
		    int i;
		} i;
		struct
		{
		    char c;
		} c;
		struct
		{
		    char *s;
		} s;
	} u;

} vmo_SkelName_obj_u_t;

#define __vmo_getP_SkelName(_t_,_i_) ((_t_)[_i_])

#define __vmo_ForEachObj_in_SkelName_do(_i_) \
				for( (_i_)=0;			   (_i_) < __VMO_V_MAX_SkelName;	(_i_)++)

#define __vmo_ForEachObj_in_SkelName_doReverce(_i_) \
				for( (_i_)=(__VMO_V_MAX_SkelName-1); (_i_) >= 0;			(_i_)--)

#define __vmo_dumpObject_SkelName_s(_t_,_i_)\
			    do {\
				switch( ((_t_)[(_i_)]).type)\
				{\
				    case __vmo_SkelName_obj_uType_int:\
					printf("ts v_id %d v_name %s  v_type %d  value %d\n",(_i_),(_t_)[(_i_)].name,(_t_)[(_i_)].type,(_t_)[(_i_)].u.i.i);\
					break;\
				    case __vmo_SkelName_obj_uType_chr:\
					printf("ts v_id %d v_name %s  v_type %d  value %c\n",(_i_),(_t_)[(_i_)].name,(_t_)[(_i_)].type,(_t_)[(_i_)].u.c.c);\
					break;\
				    case __vmo_SkelName_obj_uType_str:\
					printf("ts v_id %d v_name %s  v_type %d  value %s\n",(_i_),(_t_)[(_i_)].name,(_t_)[(_i_)].type,(_t_)[(_i_)].u.s.s);\
					break;\
				};\
			    } while(0);

#endif //__VMO_SkelName__H_
