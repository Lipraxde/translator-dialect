#include "mlir/Dialect/RISCV/RISCVDialect.h"
#include "mlir/Dialect/RISCV/RISCVOps.h"

using namespace mlir;
using namespace mlir::rv32i;

RV32IDialect::RV32IDialect(mlir::MLIRContext *context)
    : Dialect(getDialectNamespace(), context) {
  addOperations<
#define GET_OP_LIST
#include "mlir/Dialect/RISCV/RV32IOps.cpp.inc"
      >();
}
