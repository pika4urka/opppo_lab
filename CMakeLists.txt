cmake_minimum_required(VERSION 3.10)
project(FileProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(TARGET_NAME exec_file)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES 
    "${SRC_DIR}/*.cpp"
)
# list(REMOVE_ITEM SOURCES "${SRC_DIR}/test.cpp")


add_executable(${TARGET_NAME} ${SOURCES})

# флаги комипиляции
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /W4)
endif()


#перенос file в build
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/file.txt
    ${CMAKE_CURRENT_BINARY_DIR}/file.txt
    COPYONLY
)

# Сообщение об успешной конфигурации
message(STATUS "Project ${PROJECT_NAME} configured successfully")
message(STATUS "Build directory: ${CMAKE_CURRENT_BINARY_DIR}")