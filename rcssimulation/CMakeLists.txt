add_subdirectory(Communication)
add_subdirectory(Entities)
add_subdirectory(Network)
add_subdirectory(Network/Socket)

robocin_cpp_executable(
        NAME robocin_player
        SRCS player_main.cpp
)