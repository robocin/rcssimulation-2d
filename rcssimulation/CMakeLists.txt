add_subdirectory(Communication)
add_subdirectory(Entities)
add_subdirectory(Network)
add_subdirectory(Utils)

robocin_cpp_executable(
        NAME robocin_player
        SRCS player_main.cpp
)

simple_client_cpp_executable(
        NAME simple_client
        SRCS simple_client.cpp
)