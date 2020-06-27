include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND ""
  TEST_COMMAND      ""
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  # https://github.com/google/googletest/issues/868
  add_subdirectory(${googletest_SOURCE_DIR}
									 ${googletest_BINARY_DIR}
 									 EXCLUDE_FROM_ALL)
endif()

function(add_gtest TESTNAME)
  add_executable(${TESTNAME} ${ARGN})
  target_link_libraries(${TESTNAME} gtest gmock gtest_main)
  add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
  set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endfunction()

add_subdirectory(Dialect)
