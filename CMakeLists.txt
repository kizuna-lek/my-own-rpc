# cmake最低版本和项目名称
cmake_minimum_required(VERSION 3.0)
project(my_own_rpc)

# 生成debug版本，可以进行gdb调试
set(CMAKE_BUILD_TYPE "debug")

# 项目可执行文件的输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 项目库文件的输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 项目编译头文件的搜索路径 -I
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
# 项目库文件的搜索路径 -L
link_directories(${PROJECT_SOURCE_DIR}/lib)

# src包含了rpc框架所有的相关代码
add_subdirectory(src)
# example包含了rpc框架使用的实例代码
add_subdirectory(example)
