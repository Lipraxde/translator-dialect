#ifndef MLIR_TRANSLATION_REGOPINTERFACE
#define MLIR_TRANSLATION_REGOPINTERFACE

include "mlir/IR/OpBase.td"

def RegOpInterface : OpInterface<"RegOpInterface"> {
  let description = [{
    A register definition operation is one that define hardware register.
  }];

  let methods = [
    InterfaceMethod<"Return the register bit width",
                    "size_t", "getBitWidth", (ins), [{
      return op.getBitWidth();
    }]>
  ];
}

#endif // MLIR_TRANSLATION_REGOPINTERFACE
