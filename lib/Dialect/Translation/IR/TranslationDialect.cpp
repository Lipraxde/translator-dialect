#include "mlir/Dialect/Translation/TranslationDialect.h"
#include "mlir/Dialect/Translation/TranslationOps.h"

using namespace mlir;
using namespace mlir::translation;

TranslationDialect::TranslationDialect(mlir::MLIRContext *context)
    : Dialect(getDialectNamespace(), context) {
  addOperations<
#define GET_OP_LIST
#include "mlir/Dialect/Translation/TranslationOps.cpp.inc"
      >();
}
