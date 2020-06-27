#include "mlir/Dialect/RISCV/RISCVOps.h"
#include "mlir/Dialect/RISCV/RISCVDialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/StandardTypes.h"

namespace mlir {
namespace rv32i {

#define GET_OP_CLASSES
#include "mlir/Dialect/RISCV/RV32IOps.cpp.inc"

} // namespace rv32i
} // namespace mlir
