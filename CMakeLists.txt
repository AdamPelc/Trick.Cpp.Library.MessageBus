cmake_minimum_required(VERSION 3.16)

########################################################################################################################
# Project general information
########################################################################################################################
project(Trick.MessageBus CXX)
include(scripts/cmake/StandardProjectSettings.cmake)
include(scripts/cmake/PreventInSourceBuilds.cmake)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)
include(scripts/cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

########################################################################################################################
# Subdirectories
########################################################################################################################
add_subdirectory(source)