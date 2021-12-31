add_executable(${PROJECT_NAME} main.cpp)

# Add project warnings to main exec.
target_link_libraries(${PROJECT_NAME} PRIVATE project_warnings)