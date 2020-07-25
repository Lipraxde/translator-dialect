#include "../../MLIRTest.h"
#include "mlir/Dialect/Translation/TranslationOps.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/StandardTypes.h"
#include "mlir/IR/Verifier.h"
#include "llvm/Support/raw_os_ostream.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace llvm;
using namespace mlir;
using namespace testing;

namespace {

class TranslationOpTest : public mlir::MLIRTest {};

} // namespace

#define MLIR_CONTEXT    context
#define MLIR_OP_BUILDER builder
#include "mlir/IR/IRMacros.h"

ALIAS_NAME(::mlir::translation, BT, RegModule)
ALIAS_NAME(::mlir::translation, BT, Reg)
ALIAS_NAME(::mlir::translation, BT, RegConcat)

TEST_F(TranslationOpTest, DefineReg) {
  auto regModule = OP(BTRegModule);
  regModule.setName("unknown_regtable");
  builder.setInsertionPointToStart(regModule.getBody());

  auto reg1 = OP(BTReg, 8);
  auto reg2 = OP(BTReg, 8);
  auto reg3 = OP(BTRegConcat, ValueRange{reg1, reg2});

  reg1.setName("reg1");
  reg2.setName("reg2");
  reg3.setName("reg3");

  auto reg = module->lookupSymbol(NestSym("unknown_regtable", Sym("reg3")));
  EXPECT_NE(reg, nullptr) << "Referenced register not found";
}
