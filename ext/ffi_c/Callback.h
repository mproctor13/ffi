#ifndef _CALLBACK_H
#define	_CALLBACK_H

#include "Types.h"
#include "Type.h"

#ifdef	__cplusplus
extern "C" {
#endif
#include <ffi.h>
    
typedef struct {
    Type type; // The native type of a CallbackInfo object
    VALUE rbReturnType;
    VALUE rbParameterTypes;

    NativeType returnType;
    NativeType* parameterTypes;
    ffi_type* ffiReturnType;
    ffi_type** ffiParameterTypes;
    ffi_cif ffi_cif;
    int parameterCount;
    int flags;
    ffi_abi abi;
} CallbackInfo;

typedef struct {
    void* code;
    ffi_closure* ffi_closure;
    ffi_cif ffi_cif;
    int flags;
    CallbackInfo* cbInfo;
    VALUE rbCallbackInfo;
    VALUE rbProc;
} NativeCallback;

extern VALUE rb_FFI_CallbackInfo_class;
extern void rb_FFI_Callback_Init(VALUE ffiModule);
extern VALUE rb_FFI_NativeCallback_new(VALUE, VALUE);
extern VALUE rb_FFI_NativeCallback_for_proc(VALUE proc, VALUE cbInfo);

#ifdef	__cplusplus
}
#endif

#endif	/* _CALLBACK_H */

