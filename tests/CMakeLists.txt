# Ищем Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(run_tests
    test_main.cpp
    test_audiof.cpp
    test_videof.cpp
    test_imagef.cpp
    test_handcom.cpp
    test_utils.cpp
    test_container.cpp
)

target_link_libraries(run_tests
    PRIVATE
    gtest_main
    gmock
)

# Добавляем пути к исходникам проекта
target_include_directories(run_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Явно добавляем исходники проекта для компиляции
target_sources(run_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src/files/audiof.cpp
    ${CMAKE_SOURCE_DIR}/src/files/videof.cpp
    ${CMAKE_SOURCE_DIR}/src/files/imagef.cpp
    ${CMAKE_SOURCE_DIR}/src/files/filesAVI.cpp
    ${CMAKE_SOURCE_DIR}/src/hand_commands/handCom.cpp
    ${CMAKE_SOURCE_DIR}/src/utils/utils.cpp
    ${CMAKE_SOURCE_DIR}/src/container/container.cpp
)

# Добавляем тест в CTest
add_test(NAME run_tests COMMAND run_tests)