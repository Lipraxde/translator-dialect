#ifndef RISCV_DIALECT
#define RISCV_DIALECT

include "mlir/IR/OpBase.td"

def RISCV_Dialect : Dialect {
  let name = "riscv";
  let summary = "A riscv out-of-tree MLIR dialect.";
  let description = [{
    This dialect is a MLIR dialect designed to represent RISCV instructions.
  }];
  let cppNamespace = "riscv";
}

class RISCV_Op<string mnemonic, list<OpTrait> traits = []> :
        Op<RISCV_Dialect, mnemonic, traits>;

#endif // RISCV_DIALECT
