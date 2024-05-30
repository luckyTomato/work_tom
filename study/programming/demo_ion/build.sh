#!/bin/bash

# 获取脚本所在的目录
SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

# 创建构建目录
BUILD_DIR="$SCRIPT_DIR/build"
mkdir -p "$BUILD_DIR"

# 列出当前目录中的子目录
SUBDIRS=$(ls -d "$SCRIPT_DIR"/*/)

echo "Building projects in the following subdirectories:"

for dir in $SUBDIRS; do
    # 检查子目录中是否存在 CMakeLists.txt
    if [ -f "$dir/CMakeLists.txt" ]; then
        echo "Found CMake project in: $dir"

        # 创建子目录的构建目录
        SUB_BUILD_DIR="$BUILD_DIR/$(basename $dir)"
        mkdir -p "$SUB_BUILD_DIR"

        # 运行 CMake 配置和构建
        cd "$SUB_BUILD_DIR"
        cmake "$dir"
        cmake --build .

        # 返回脚本目录
        cd "$SCRIPT_DIR"
    else
        echo "No CMake project found in: $dir"
    fi
done

echo "Build completed!"
