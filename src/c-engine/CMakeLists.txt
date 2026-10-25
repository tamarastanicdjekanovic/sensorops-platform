
cmake_minimum_required(VERSION 3.20)

project(
    SensorOps
    VERSION 0.1.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(sensor_engine STATIC
    src/sensor.c
)

target_include_directories(sensor_engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(sensorops
    src/main.c
)

target_link_libraries(sensorops
    PRIVATE
        sensor_engine
)

if(MSVC)
    target_compile_options(sensor_engine PRIVATE /W4)
    target_compile_options(sensorops PRIVATE /W4)
else()
    target_compile_options(sensor_engine PRIVATE
        -Wall -Wextra -Wpedantic
    )
    target_compile_options(sensorops PRIVATE
        -Wall -Wextra -Wpedantic
    )
endif()

install(TARGETS sensorops
    RUNTIME DESTINATION bin
)
