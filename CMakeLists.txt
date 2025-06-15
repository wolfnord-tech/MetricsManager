cmake_minimum_required(VERSION 3.18)
project(VK_Intern VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(VK_Intern main.cpp data/timedata.cpp data/timedata.h control/filemanager.h control/filemanager.cpp control/metricsmanager.cpp control/metricsmanager.h  data/metrics.h data/metrics.cpp control/eventprocessor.h control/eventprocessor.cpp)

target_compile_features(VK_Intern PRIVATE cxx_std_20)