########################################################################################################################

if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif ()

if (NOT CMAKE_CXX_STANDARD_REQUIRED)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif ()

message("-- Using C++: ${CMAKE_CXX_STANDARD}")

########################################################################################################################

# set CMAKE_EXPORT_COMPILE_COMMANDS to ON to generate a compile_commands.json file in the build directory by default
# this file is used by clang tools such as clangd, clang-tidy and .clang-format

if (NOT CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif ()

########################################################################################################################

# find Threads package
find_package(Threads REQUIRED)

########################################################################################################################