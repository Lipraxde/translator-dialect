#ifndef MLIR_TRANSLATION_TRANSLATIONOPS
#define MLIR_TRANSLATION_TRANSLATIONOPS

include "TranslationDialect.td"
include "mlir/IR/SymbolInterfaces.td"

def Translation_RegModuleEndOp
    : Translation_Op<"reg_module_end",
                     [HasParent<"RegModuleOp">,
                      Terminator]>;

def Translation_RegModuleOp
    : Translation_Op<"reg_module",
                     [IsolatedFromAbove,
                      SingleBlockImplicitTerminator<"RegModuleEndOp">,
                      SymbolTable]> {
  let regions = (region SizedRegion<1>:$body);

  let builders = [
    OpBuilder<"OpBuilder &b, OperationState &state", [{
      ensureTerminator(*state.addRegion(), b, state.location);
    }]>
  ];
  let skipDefaultBuilders = 1;
}

def Translation_RegOp
    : Translation_Op<"reg", [HasParent<"RegModuleOp">, Symbol]>,
      Arguments<(ins UI32Attr:$nbits)>,
      Results<(outs NoneType)> {
  let builders = [
    OpBuilder<"OpBuilder &b, OperationState &state, uint32_t nbits", [{
      build(b, state, b.getNoneType(), b.getUI32IntegerAttr(nbits));
    }]>
  ];
}

def Translation_RegConcatOp
    : Translation_Op<"reg_concat", [HasParent<"RegModuleOp">, Symbol]>,
      Arguments<(ins Variadic<NoneType>:$regs)>,
      Results<(outs NoneType)> {
  let builders = [
    OpBuilder<"OpBuilder &b, OperationState &state, ValueRange regs", [{
      build(b, state, b.getNoneType(), regs);
    }]>
  ];
}

#endif // MLIR_TRANSLATION_TRANSLATIONOPS
