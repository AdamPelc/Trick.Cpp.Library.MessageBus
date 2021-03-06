# Checks is testing should be enabled
option(ENABLE_TESTING "Flag indicates if testing should be included in build" OFF)
if (NOT ENABLE_TESTING)
    message(VERBOSE "Testing for Trick::MessageBus is DISABLED")
    return()
endif ()
message(STATUS "Testing for Trick::MessageBus is ENABLED")
enable_testing()

########################################################################################################################
# Catch2 Test
########################################################################################################################
set(UNIT_TESTS_EXE_NAME ${PROJECT_NAME}.UnitTests)
# Download google tests
include(${CMAKE_SOURCE_DIR}/scripts/cmake/DownloadCatch2Test.cmake)
add_executable(${UNIT_TESTS_EXE_NAME})
target_link_libraries(${UNIT_TESTS_EXE_NAME}
    PRIVATE
        Catch2::Catch2
        ${PROJECT_NAME}
        project_warnings)
target_compile_features(${UNIT_TESTS_EXE_NAME}
    PRIVATE
        cxx_std_20)
target_include_directories(${UNIT_TESTS_EXE_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})

include(CTest)
include(Catch)
catch_discover_tests(${UNIT_TESTS_EXE_NAME})
########################################################################################################################
# Unit tests
########################################################################################################################
add_subdirectory(Trick)
