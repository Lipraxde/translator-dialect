add_mlir_dialect_library(MLIRTranslationDialect
  IR/TranslationDialect.cpp
  IR/TranslationOps.cpp

  ADDITIONAL_HEADER_DIRS
  ${PROJECT_SOURCE_DIR}/include

  DEPENDS
  MLIRTranslationOpsIncGen

  LINK_LIBS PUBLIC
  MLIRIR
)
