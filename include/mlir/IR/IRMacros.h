#pragma once

#ifndef MLIR_CONTEXT
#error Please define MLIR_CONTEXT
#endif

#ifndef MLIR_OP_BUILDER
#error Please define MLIR_OP_BUILDER
#endif

/*** Type Macros start ***/

#define INTNTy(n)                                                              \
  ::mlir::IntegerType::get((n), ::mlir::IntegerType::Signless, &MLIR_CONTEXT)
#define SINTNTy(n)                                                             \
  ::mlir::IntegerType::get((n), ::mlir::IntegerType::Signed, &MLIR_CONTEXT)
#define UINTNTy(n)                                                             \
  ::mlir::IntegerType::get((n), ::mlir::IntegerType::Unsigned, &MLIR_CONTEXT)

#define INT1Ty  INTNTy(1)
#define INT5Ty  INTNTy(5)
#define INT8Ty  INTNTy(8)
#define INT16Ty INTNTy(16)
#define INT32Ty INTNTy(32)
#define INT64Ty INTNTy(64)

#define SINT1Ty  SINTNTy(1)
#define SINT5Ty  SINTNTy(5)
#define SINT8Ty  SINTNTy(8)
#define SINT16Ty SINTNTy(16)
#define SINT32Ty SINTNTy(32)
#define SINT64Ty SINTNTy(64)

#define UINT1Ty  UINTNTy(1)
#define UINT5Ty  UINTNTy(5)
#define UINT8Ty  UINTNTy(8)
#define UINT16Ty UINTNTy(16)
#define UINT32Ty UINTNTy(32)
#define UINT64Ty UINTNTy(64)

/*** Type Macros end ***/

/*** Attribute Macros start ***/

#define INTNAttr(n, val)  ::mlir::IntegerAttr::get(INTNTy((n)), (val))
#define SINTNAttr(n, val) ::mlir::IntegerAttr::get(SINTNTy((n)), (val))
#define UINTNAttr(n, val) ::mlir::IntegerAttr::get(UINTNTy((n)), (val))

#define INT1Attr(val)  INTNAttr(1, (val))
#define INT5Attr(val)  INTNAttr(5, (val))
#define INT8Attr(val)  INTNAttr(8, (val))
#define INT16Attr(val) INTNAttr(16, (val))
#define INT32Attr(val) INTNAttr(32, (val))
#define INT64Attr(val) INTNAttr(64, (val))

#define SINT1Attr(val)  SINTNAttr(1, (val))
#define SINT5Attr(val)  SINTNAttr(5, (val))
#define SINT8Attr(val)  SINTNAttr(8, (val))
#define SINT16Attr(val) SINTNAttr(16, (val))
#define SINT32Attr(val) SINTNAttr(32, (val))
#define SINT64Attr(val) SINTNAttr(64, (val))

#define UINT1Attr(val)  UINTNAttr(1, (val))
#define UINT5Attr(val)  UINTNAttr(5, (val))
#define UINT8Attr(val)  UINTNAttr(8, (val))
#define UINT16Attr(val) UINTNAttr(16, (val))
#define UINT32Attr(val) UINTNAttr(32, (val))
#define UINT64Attr(val) UINTNAttr(64, (val))

#define Sym(name) ::mlir::SymbolRefAttr::get((name), &MLIR_CONTEXT)
#define NestSym(__namespace, symref)                                           \
  ::mlir::SymbolRefAttr::get((__namespace), (symref), &MLIR_CONTEXT)

/*** Attribute Macros end ***/

/*** Operation Macros start ***/

#define ALIAS_NAME(name_space, alias, name)                                    \
  using alias##name = name_space::name##Op;

#define OP(name, ...)                                                          \
  MLIR_OP_BUILDER.create<name>(MLIR_OP_BUILDER.getUnknownLoc(), ##__VA_ARGS__)

/*** Operation Macros end ***/

#define Array(...)                                                             \
  ArrayRef { __VA_ARGS__ }
