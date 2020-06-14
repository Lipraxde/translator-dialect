#include "mlir/Dialect/RISCV/RISCVDialect.h"
#include "mlir/Dialect/RISCV/RISCVOps.h"

using namespace mlir;
using namespace mlir::riscv;

RISCVDialect::RISCVDialect(mlir::MLIRContext *context)
    : Dialect(getDialectNamespace(), context) {
  addOperations<
#define GET_OP_LIST
#include "mlir/Dialect/RISCV/RISCVOps.cpp.inc"
      >();
}
