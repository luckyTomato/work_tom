cmake_minimum_required(VERSION 3.10)

project(Consumer)

# 设置包含目录
include_directories(/your/install/path/include)

# 查找库
find_library(MYLIB_LIBRARY NAMES mylib PATHS /your/install/path/lib)

# 添加可执行文件
add_executable(consumer main.cpp)

# 链接库
target_link_libraries(consumer ${MYLIB_LIBRARY})
