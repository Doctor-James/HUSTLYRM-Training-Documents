
find_package(OpenCV REQUIRED)
find_package(Sophus REQUIRED)

include_directories(
        .
        ${OpenCV_INCLUDE_DIRS}
        /usr/include/eigen3
        ${Sophus_INCLUDE_DIRS}
)

add_library(pnp
        Solver.cpp
        )

target_link_libraries(pnp
        /usr/lib/libSophus.so
        ${OpenCV_LIBS})