# Checks is testing should be enabled
option(ENABLE_TESTING "Flag indicates if testing should be included in build" OFF)
if (NOT ENABLE_TESTING)
    message(VERBOSE "Testing for Trick::MessageBus is DISABLED")
    return()
endif ()
message(STATUS "Testing for Trick::MessageBus is ENABLED")
enable_testing()

########################################################################################################################
# GoogleTests
########################################################################################################################
set(UNIT_TESTS_EXE_NAME ${PROJECT_NAME}.UnitTests)
# Download google tests
include(${CMAKE_SOURCE_DIR}/scripts/cmake/DownloadGoogleTest.cmake)
add_executable(${UNIT_TESTS_EXE_NAME})
target_link_libraries(${UNIT_TESTS_EXE_NAME}
        PRIVATE
            gtest_main
            ${PROJECT_NAME}
            project_warnings)
include(GoogleTest)
gtest_discover_tests(${UNIT_TESTS_EXE_NAME})

########################################################################################################################
# Unit tests
########################################################################################################################
add_subdirectory(MessageBus)
