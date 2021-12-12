cmake_minimum_required(VERSION 3.10)

project(pnp_demo)

find_package(OpenCV REQUIRED)

add_subdirectory(log)
add_subdirectory(solve)

include_directories(
        .
        ${OpenCV_INCLUDE_DIRS})

add_executable(pnp_demo
        test.cpp)

target_link_libraries(pnp_demo
        logger
        pnp
        ${OpenCV_LIBS}
        )

add_executable(step_test
        stepTest.cpp)

target_link_libraries(step_test
        logger
        pnp
        ${OpenCV_LIBS}
        )