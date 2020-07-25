#ifndef MLIR_TRANSLTION_TRANSLTIONDIALECT
#define MLIR_TRANSLTION_TRANSLTIONDIALECT

include "mlir/IR/OpBase.td"

def Translation_Dialect : Dialect {
  let name = "translation";
  let summary = "A binary translation out-of-tree MLIR dialect.";
  let description = [{
    This dialect is a MLIR dialect designed to represent hardware register and
    instruction behavior.
  }];

  let cppNamespace = "translation";
}

class Translation_Op<string mnemonic, list<OpTrait> traits = []>
    : Op<Translation_Dialect, mnemonic, traits>;

#endif // MLIR_TRANSLTION_TRANSLTIONDIALECT
