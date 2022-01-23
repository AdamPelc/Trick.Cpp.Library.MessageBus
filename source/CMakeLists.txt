add_library(${PROJECT_NAME} STATIC)

# Add project warnings to main exec.
target_link_libraries(${PROJECT_NAME} PRIVATE project_warnings)

add_subdirectory(MessageBus)
