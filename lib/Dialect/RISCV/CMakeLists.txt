add_mlir_dialect_library(MLIRRISCV
  IR/RISCVDialect.cpp
  IR/RISCVOps.cpp

  DEPENDS
  MLIRRV32IOpsIncGen

  LINK_LIBS PUBLIC
  MLIRIR
)
