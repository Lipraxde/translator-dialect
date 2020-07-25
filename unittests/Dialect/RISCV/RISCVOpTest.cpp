#include "../../MLIRTest.h"
#include "mlir/Dialect/RISCV/RISCVOps.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/Function.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/StandardTypes.h"
#include "mlir/IR/Verifier.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/Support/raw_ostream.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <string>

using namespace llvm;
using namespace mlir;
using namespace testing;

namespace {

class RISCVOpTest : public mlir::MLIRTest {
protected:
  RISCVOpTest() {
    // Create the function
    auto func_type =
        builder.getFunctionType(ArrayRef<mlir::Type>{}, llvm::None);
    auto func = mlir::FuncOp::create(loc, "test", func_type);

    // Create the entry block of the function
    Block *entryBlock = func.addEntryBlock();

    // Set the insertion point
    builder.setInsertionPointToStart(entryBlock);

    // Insert the function to the module
    module->push_back(func);
  }
};

} // namespace

#define MLIR_CONTEXT    context
#define MLIR_OP_BUILDER builder
#include "mlir/IR/IRMacros.h"

ALIAS_NAME(::mlir::rv32i, RV32, ADD)
ALIAS_NAME(::mlir, Std, Return)

TEST_F(RISCVOpTest, RV32I) {
  OP(RV32ADD, INT5Attr(0), INT5Attr(1), INT5Attr(2));
  OP(StdReturn);

  std::string text;
  llvm::raw_string_ostream stream(text);
  module->print(stream);

  EXPECT_THAT(text, HasSubstr("rv32i.add"));
}
