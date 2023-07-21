add_subdirectory(Communication)
add_subdirectory(Entities)
add_subdirectory(Network)

robocin_cpp_executable(
        NAME robocin_player
        SRCS player_main.cpp
)