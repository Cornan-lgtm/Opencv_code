cmake_minimum_required (VERSION 2.8)
project(bilateralBlur)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE Realse)
find_package (OpenCV 3 REQUIRED)
include_directories (${OpenCV_INCLUDE_DIRS})

include_directories(getClosenessWeight.hpp bfltGray.hpp)

add_executable(bilateralBlur main.cpp bfltGray.cpp getClosenessWeight.cpp)

target_link_libraries (bilateralBlur ${OpenCV_LIBS})
