#pragma once

#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"

namespace mlir {
namespace rv32i {

#define GET_OP_CLASSES
#include "mlir/Dialect/RISCV/RV32IOps.h.inc"

} // namespace rv32i
} // namespace mlir
