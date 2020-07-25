add_mlir_dialect_library(MLIRTranslationDialect
  IR/RegOpInterface.cpp
  IR/TranslationDialect.cpp
  IR/TranslationOps.cpp

  DEPENDS
  MLIRRegOpInterfaceIncGen
  MLIRTranslationOpsIncGen

  LINK_LIBS PUBLIC
  MLIRIR
)
