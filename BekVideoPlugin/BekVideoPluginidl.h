

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __BekVideoPluginidl_h__
#define __BekVideoPluginidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DBekVideoPlugin_FWD_DEFINED__
#define ___DBekVideoPlugin_FWD_DEFINED__
typedef interface _DBekVideoPlugin _DBekVideoPlugin;

#endif 	/* ___DBekVideoPlugin_FWD_DEFINED__ */


#ifndef ___DBekVideoPluginEvents_FWD_DEFINED__
#define ___DBekVideoPluginEvents_FWD_DEFINED__
typedef interface _DBekVideoPluginEvents _DBekVideoPluginEvents;

#endif 	/* ___DBekVideoPluginEvents_FWD_DEFINED__ */


#ifndef __BekVideoPlugin_FWD_DEFINED__
#define __BekVideoPlugin_FWD_DEFINED__

#ifdef __cplusplus
typedef class BekVideoPlugin BekVideoPlugin;
#else
typedef struct BekVideoPlugin BekVideoPlugin;
#endif /* __cplusplus */

#endif 	/* __BekVideoPlugin_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_BekVideoPlugin_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_BekVideoPlugin_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_BekVideoPlugin_0000_0000_v0_0_s_ifspec;


#ifndef __BekVideoPluginLib_LIBRARY_DEFINED__
#define __BekVideoPluginLib_LIBRARY_DEFINED__

/* library BekVideoPluginLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_BekVideoPluginLib;

#ifndef ___DBekVideoPlugin_DISPINTERFACE_DEFINED__
#define ___DBekVideoPlugin_DISPINTERFACE_DEFINED__

/* dispinterface _DBekVideoPlugin */
/* [uuid] */ 


EXTERN_C const IID DIID__DBekVideoPlugin;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F5A5DCD7-34C5-44CD-8EF9-23A4BB8808FB")
    _DBekVideoPlugin : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DBekVideoPluginVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DBekVideoPlugin * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DBekVideoPlugin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DBekVideoPlugin * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DBekVideoPlugin * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DBekVideoPlugin * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DBekVideoPlugin * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DBekVideoPlugin * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DBekVideoPluginVtbl;

    interface _DBekVideoPlugin
    {
        CONST_VTBL struct _DBekVideoPluginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DBekVideoPlugin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DBekVideoPlugin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DBekVideoPlugin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DBekVideoPlugin_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DBekVideoPlugin_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DBekVideoPlugin_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DBekVideoPlugin_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DBekVideoPlugin_DISPINTERFACE_DEFINED__ */


#ifndef ___DBekVideoPluginEvents_DISPINTERFACE_DEFINED__
#define ___DBekVideoPluginEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DBekVideoPluginEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DBekVideoPluginEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5C6621D6-F2F1-4602-A9E4-18982B30D504")
    _DBekVideoPluginEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DBekVideoPluginEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DBekVideoPluginEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DBekVideoPluginEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DBekVideoPluginEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DBekVideoPluginEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DBekVideoPluginEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DBekVideoPluginEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DBekVideoPluginEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DBekVideoPluginEventsVtbl;

    interface _DBekVideoPluginEvents
    {
        CONST_VTBL struct _DBekVideoPluginEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DBekVideoPluginEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DBekVideoPluginEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DBekVideoPluginEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DBekVideoPluginEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DBekVideoPluginEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DBekVideoPluginEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DBekVideoPluginEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DBekVideoPluginEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BekVideoPlugin;

#ifdef __cplusplus

class DECLSPEC_UUID("1EFF5809-3926-4D69-89F0-BB2A5D1C1435")
BekVideoPlugin;
#endif
#endif /* __BekVideoPluginLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


