

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Mar 05 13:42:30 2018
 */
/* Compiler settings for BekVideoPlugin.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_BekVideoPluginLib,0xFC71C06D,0x2BE1,0x451A,0xA5,0x3D,0x7B,0x67,0xA8,0xEF,0x3A,0xDB);


MIDL_DEFINE_GUID(IID, DIID__DBekVideoPlugin,0xF5A5DCD7,0x34C5,0x44CD,0x8E,0xF9,0x23,0xA4,0xBB,0x88,0x08,0xFB);


MIDL_DEFINE_GUID(IID, DIID__DBekVideoPluginEvents,0x5C6621D6,0xF2F1,0x4602,0xA9,0xE4,0x18,0x98,0x2B,0x30,0xD5,0x04);


MIDL_DEFINE_GUID(CLSID, CLSID_BekVideoPlugin,0x1EFF5809,0x3926,0x4D69,0x89,0xF0,0xBB,0x2A,0x5D,0x1C,0x14,0x35);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



