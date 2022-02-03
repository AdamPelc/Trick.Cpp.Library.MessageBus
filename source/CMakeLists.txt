add_library(${PROJECT_NAME} STATIC)

# Add project warnings to main exec.
target_link_libraries(${PROJECT_NAME} PRIVATE project_warnings)
# Add compile features
target_compile_features(${PROJECT_NAME}
    PRIVATE
        cxx_std_17)

add_subdirectory(Trick)
