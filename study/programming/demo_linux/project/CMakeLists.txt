cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(MyLibrary VERSION 1.0)

# 设置包含目录
include_directories(include)

# 添加库
add_library(mylib SHARED src/mylib.cpp)

# 定义编译选项
target_compile_definitions(mylib PRIVATE MYLIB_EXPORTS)

# 安装目标和头文件
install(TARGETS mylib DESTINATION lib)
install(FILES include/mylib.h DESTINATION include)

