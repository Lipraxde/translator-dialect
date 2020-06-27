#include "mlir/Dialect/RISCV/RISCVOps.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/Function.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/StandardTypes.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/StringRef.h"

#include "gtest/gtest.h"

using namespace llvm;
using namespace mlir;

namespace {

class RISCVOpTest : public testing::Test {
protected:
  RISCVOpTest() : builder(&context), loc(builder.getUnknownLoc()) {
    // Create the module
    module = mlir::ModuleOp::create(loc, StringRef("test"));

    // Create the function
    auto func_type =
        builder.getFunctionType(ArrayRef<mlir::Type>{}, llvm::None);
    func = mlir::FuncOp::create(loc, "test", func_type);

    // Create the entry block of the function
    Block *entryBlock = func.addEntryBlock();

    // Set the insertion point
    builder.setInsertionPointToStart(entryBlock);

    // Insert the function to the module
    module->push_back(func);
  }

  MLIRContext context;
  OpBuilder builder;
  Location loc;
  OwningModuleRef module;
  FuncOp func;
};

} // namespace

TEST_F(RISCVOpTest, RV32I) {
  builder.create<rv32i::ADDOp>(
      loc, IntegerAttr::get(IntegerType::get(5, &context), 0),
      IntegerAttr::get(IntegerType::get(5, &context), 1),
      IntegerAttr::get(IntegerType::get(5, &context), 2));
  module->dump();
}
