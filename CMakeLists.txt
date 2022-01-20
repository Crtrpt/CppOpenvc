# CMakeList.txt: CppOpenvc 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("CppOpenvc")




# 将源代码添加到此项目的可执行文件。
add_executable (CppOpenvc "CppOpenvc.cpp" "CppOpenvc.h")


set(OpenCV_DIR "D:\\opencv\\opencv\\build\\x64\\vc15\\lib")
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(CppOpenvc ${OpenCV_LIBS})
# TODO: 如有需要，请添加测试并安装目标。
add_subdirectory(D:\\dlib-19.22\\dlib dlib_build)
target_link_libraries(CppOpenvc dlib::dlib)


