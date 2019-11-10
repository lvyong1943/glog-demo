cmake_minimum_required(VERSION 2.8)

set(EXE_NAME glogDemo)

#set(glog_Dir ${CMAKE_SOURCE_DIR}/../glog-libs)
set(glog_Dir /opt/glog)

set(CMAKE_BUILD_TYPE Release)
set(CPLUSPLUS_VER "c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=${CPLUSPLUS_VER} -fPIC")

message("config types: ${CMAKE_CONFIGURATION_TYPES}")
message("glog's path : ${glog_Dir}")

# Set project's name
project(${EXE_NAME})

include_directories(
    include
    ${glog_Dir}/include
    ${glog_Dir}/include/glog
)

set(SOURCE_FILES
    src/glogDemo.cpp
    src/GLogger.cpp
)


link_directories(${glog_Dir}/lib/)

add_executable(${EXE_NAME} ${SOURCE_FILES})

target_link_libraries(${EXE_NAME} glog)
