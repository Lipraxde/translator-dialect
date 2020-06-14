#pragma once

#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"

namespace mlir {
namespace riscv {

#define GET_OP_CLASSES
#include "mlir/Dialect/RISCV/RISCVOps.h.inc"

} // namespace riscv
} // namespace mlir
