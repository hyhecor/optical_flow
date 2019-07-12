cmake_minimum_required(VERSION 3.10)
project(opticalflow_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
message(STATUS "CMAKE_C_FLAGS=${CMAKE_C_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

find_package(PkgConfig REQUIRED)
pkg_check_modules(OpenCV REQUIRED opencv4)

message(STATUS "OpenCV_INCLUDE_DIRS=${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBRARIES=${OpenCV_LIBRARIES}")
message(STATUS "OpenCV_CFLAGS_OTHER=${OpenCV_CFLAGS_OTHER}")

include_directories(${OpenCV_INCLUDE_DIRS})

message(STATUS "CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")


include_directories("${CMAKE_SOURCE_DIR}/"
        "${CMAKE_SOURCE_DIR}/opticalflow"
        "${CMAKE_SOURCE_DIR}/../.."
        )

include_directories("${CMAKE_SOURCE_DIR}/"
        "${CMAKE_SOURCE_DIR}/opticalflow_cuda"
        "${CMAKE_SOURCE_DIR}/../.."
        )

#add_library (OpticalFlow SHARED "${PROJECT_SOURCE_DIR}/opticalflow_cuda/dense_optical_flow_cuda.cpp"
#"${PROJECT_SOURCE_DIR}/opticalflow_cuda/dual_tvl1_optical_flow_cuda.cpp")


get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
    message(STATUS "include_dirs='${dir}'")
endforeach()

add_executable(
        opticalflow_test
#        opticalflow/dense_optical_flow.h
        opticalflow/dense_optical_flow.cpp
#        opticalflow/dual_tvl1_optical_flow.h
        opticalflow/dual_tvl1_optical_flow.cpp
#        ../../core.h
        ../../core.cpp
        opticalflow_test/app.h
        opticalflow_test/app.cpp
        opticalflow_test/main.c)

add_executable(
        opticalflow_cuda_test
#        opticalflow_cuda/dense_optical_flow_cuda.h
        opticalflow_cuda/dense_optical_flow_cuda.cpp
#        opticalflow_cuda/dual_tvl1_optical_flow_cuda.h
        opticalflow_cuda/dual_tvl1_optical_flow_cuda.cpp
#        ../../core.h
        ../../core.cpp
        opticalflow_cuda_test/app.h
        opticalflow_cuda_test/app.cpp
        opticalflow_cuda_test/main.c)


target_link_libraries(opticalflow_test ${OpenCV_LIBRARIES})
target_link_libraries(opticalflow_cuda_test ${OpenCV_LIBRARIES} )
