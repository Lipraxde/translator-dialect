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

set(GTestMain ${CMAKE_CURRENT_LIST_DIR}/GTestMain.cpp)

function(add_gtest TESTNAME)
  cmake_parse_arguments(ARG "" "" "LINK_LIBS" ${ARGN})
  list(APPEND SRCS ${SOURCE} ${ARG_UNPARSED_ARGUMENTS})
  add_executable(${TESTNAME} ${SRCS} ${GTestMain})
  target_link_libraries(${TESTNAME} ${ARG_LINK_LIBS} gtest gmock)
  add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
  set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endfunction()

add_subdirectory(Dialect)
