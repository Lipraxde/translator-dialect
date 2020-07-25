#ifndef MLIR_TRANSLATION_TRANSLATIONOPS
#define MLIR_TRANSLATION_TRANSLATIONOPS

include "TranslationDialect.td"
include "RegOpInterface.td"
include "mlir/IR/SymbolInterfaces.td"

def Translation_RegModuleEndOp
    : Translation_Op<"reg_module_end",
                     [HasParent<"RegModuleOp">,
                      Terminator]>;

def Translation_RegModuleOp
    : Translation_Op<"reg_module",
                     [IsolatedFromAbove,
                      SingleBlockImplicitTerminator<"RegModuleEndOp">,
                      Symbol,
                      SymbolTable]> {
  let regions = (region SizedRegion<1>:$body);

  let builders = [
    OpBuilder<"OpBuilder &b, OperationState &state,"
              "StringRef hardware_name", [{
      ensureTerminator(*state.addRegion(), b, state.location);
      state.addAttribute(::mlir::SymbolTable::getSymbolAttrName(),
                         b.getStringAttr(hardware_name));
    }]>
  ];
  let skipDefaultBuilders = 1;
}

def Translation_RegOp
    : Translation_Op<"reg", [HasParent<"RegModuleOp">,
                             RegOpInterface,
                             Symbol]>,
      Arguments<(ins UI32Attr:$nbits)>,
      Results<(outs NoneType)> {
  let builders = [
    OpBuilder<"OpBuilder &b, OperationState &state, StringRef name,"
              "uint32_t nbits", [{
      state.addAttribute(SymbolTable::getSymbolAttrName(),
                         b.getStringAttr(name));
      state.addAttribute("nbits", b.getUI32IntegerAttr(nbits));
      state.addTypes(b.getNoneType());
    }]>
  ];
  let skipDefaultBuilders = 1;

  let extraClassDeclaration = [{
    size_t getBitWidth() {
      return nbitsAttr().getUInt();
    }
  }];
}

def Translation_RegConcatOp
    : Translation_Op<"reg_concat", [HasParent<"RegModuleOp">,
                                    RegOpInterface,
                                    Symbol]>,
      Arguments<(ins Variadic<NoneType>:$regs)>,
      Results<(outs NoneType)> {
  let builders = [
    OpBuilder<"OpBuilder &b, OperationState &state, StringRef name,"
              "ValueRange regs", [{
      state.addAttribute(SymbolTable::getSymbolAttrName(),
                         b.getStringAttr(name));
      state.addOperands(regs);
      state.addTypes(b.getNoneType());
    }]>
  ];
  let skipDefaultBuilders = 1;

  let extraClassDeclaration = [{
    size_t getBitWidth() {
      size_t ret = 0;
      for (auto operand : regs()) {
        ret += cast<RegOpInterface>(operand.getDefiningOp()).getBitWidth();
      }
      return ret;
    }
  }];
}

#endif // MLIR_TRANSLATION_TRANSLATIONOPS
