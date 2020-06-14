#include "mlir/Dialect/RISCV/RISCVOps.h"
#include "mlir/Dialect/RISCV/RISCVDialect.h"
#include "mlir/IR/OpImplementation.h"

namespace mlir {
namespace riscv {

#define GET_OP_CLASSES
#include "mlir/Dialect/RISCV/RISCVOps.cpp.inc"

} // namespace riscv
} // namespace mlir
