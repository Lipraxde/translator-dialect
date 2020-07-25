#include "mlir/Dialect/Translation/TranslationOps.h"
#include "mlir/Dialect/Translation/TranslationDialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/StandardTypes.h"

namespace mlir {
namespace translation {

#define GET_OP_CLASSES
#include "mlir/Dialect/Translation/TranslationOps.cpp.inc"

} // namespace translation
} // namespace mlir
