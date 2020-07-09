cmake_minimum_required(VERSION 3.4.1)

FILE(GLOB source_c src/main/cpp/get_result/**.c)

add_library(    get-result
                SHARED
                ${source_c}
                )

include_directories(src/main/cpp/get_result/include/)


find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()


FILE(GLOB source_cpp src/main/cpp/get_predict/**.cpp)

add_library(    get-predict
                SHARED
                ${source_cpp}
)

include_directories(src/main/cpp/get_predict/include/)