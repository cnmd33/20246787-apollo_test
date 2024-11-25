#!/bin/bash

# 创建构建目录
mkdir -p build
cd build

# 运行 CMake 配置
cmake ..

# 编译项目
make

# 提示信息
echo "编译完成，您可以运行 ./build/SurroundedRegions 来执行程序。"