#pragma once

#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/IR/SymbolTable.h"

namespace mlir {
namespace translation {

#define GET_OP_CLASSES
#include "mlir/Dialect/Translation/TranslationOps.h.inc"

} // namespace translation
} // namespace mlir
