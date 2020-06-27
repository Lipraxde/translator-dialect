#ifndef RV32I_DIALECT
#define RV32I_DIALECT

include "mlir/IR/OpBase.td"

def RV32I_Dialect : Dialect {
  let name = "rv32i";
  let summary = "A RISCV32 I base instruction set out-of-tree MLIR dialect.";
  let description = [{
    This dialect is a MLIR dialect designed to represent RV32I instructions.
  }];
  let cppNamespace = "rv32i";
}

class RV32I_Op<string mnemonic, list<OpTrait> traits = []> :
    Op<RV32I_Dialect, mnemonic, traits>;

#endif // RV32I_DIALECT
