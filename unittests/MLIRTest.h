#pragma once

#include "mlir/IR/Builders.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/Verifier.h"
#include "llvm/Support/raw_os_ostream.h"

#include "gtest/gtest.h"

namespace mlir {

std::ostream &operator<<(std::ostream &_os, ModuleOp module) {
  llvm::raw_os_ostream os(_os);
  module.print(os);
  return _os;
}

class MLIRTest : public testing::Test {
protected:
  MLIRTest() : builder(&context), loc(builder.getUnknownLoc()) {
    // Create the module
    module = mlir::ModuleOp::create(loc, StringRef("test"));
    builder.setInsertionPointToStart(module->getBody());
  }

  ~MLIRTest() { EXPECT_TRUE(succeeded(verify(*module))) << *module; }

  MLIRContext context;
  OpBuilder builder;
  Location loc;
  OwningModuleRef module;
};

} // namespace mlir
