#include "../../MLIRTest.h"
#include "mlir/Dialect/Translation/TranslationOps.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/StandardTypes.h"
#include "mlir/IR/Verifier.h"
#include "llvm/ADT/SmallVector.h"
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
  auto regModule = OP(BTRegModule, "unknown");
  builder.setInsertionPointToStart(regModule.getBody());

  auto reg1 = OP(BTReg, "reg1", 8);
  auto reg2 = OP(BTReg, "reg2", 8);
  auto reg3 = OP(BTRegConcat, "reg3", ValueRange{reg1, reg2});

  auto reg = module->lookupSymbol(NestSym("unknown", Sym("reg3")));
  EXPECT_NE(reg, nullptr) << "Referenced register not found";
}

TEST_F(TranslationOpTest, RegOpInterface) {
  auto regModule = OP(BTRegModule, "unknown");
  builder.setInsertionPointToStart(regModule.getBody());

  auto reg1 = OP(BTReg, "reg1", 8);
  auto reg2 = OP(BTReg, "reg2", 8);
  auto reg3 = OP(BTRegConcat, "reg3", ValueRange{reg1, reg2});
  auto reg4 = OP(BTReg, "reg4", 16);
  auto reg5 = OP(BTRegConcat, "reg5", ValueRange{reg3, reg4});
  auto reg6 = OP(BTReg, "reg6", 32);
  auto reg7 = OP(BTRegConcat, "reg7", ValueRange{reg5, reg6});

  SmallVector<size_t, 8> bitWidths;
  module->walk([&bitWidths](RegOpInterface reg) {
    bitWidths.push_back(reg.getBitWidth());
  });

  EXPECT_THAT(bitWidths, ElementsAre(8, 8, 16, 16, 32, 32, 64));
}
