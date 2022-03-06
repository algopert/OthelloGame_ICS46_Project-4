cmake_minimum_required(VERSION 3.16)


set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_PREFIX_PATH $ENV{QT_HOME})


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



project(othelloaistudent)

file(GLOB CORE_SRC_FILES ${CMAKE_SOURCE_DIR}/core/*.cpp)
file(GLOB CORE_INCLUDE_FILES ${CMAKE_SOURCE_DIR}/core/*.hpp)

if(CORE_SRC_FILES)
    include_directories(${CMAKE_SOURCE_DIR}/core)

    add_definitions("-std=c++17 -stdlib=libc++ -Wall -Wno-c++17-extensions -pedantic-errors -Werror -g -fstandalone-debug")

    add_library(${PROJECT_NAME} STATIC ${CORE_SRC_FILES} ${CORE_INCLUDE_FILES})
    target_link_libraries(${PROJECT_NAME} c++ pthread)

    set(CORE_LIBS ${PROJECT_NAME})
else()
    set(CORE_LIBS)
endif()



project(a.out.app)

find_package(Qt6Widgets)

include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/othellogame)
include_directories(${CMAKE_SOURCE_DIR}/include/othelloui)

file(GLOB APP_SRC_FILES ${CMAKE_SOURCE_DIR}/app/*.cpp)
file(GLOB APP_INCLUDE_FILES ${CMAKE_SOURCE_DIR}/app/*.hpp)

add_definitions("-std=c++17 -stdlib=libc++ -Wall -Wno-c++17-extensions -pedantic-errors -Werror -g -fstandalone-debug")

add_executable(${PROJECT_NAME} ${APP_SRC_FILES} ${APP_INCLUDE_FILES})

set(APP_LIBS ${ICS46_PROJECT_LIB_DIR}/libothelloui.so ${ICS46_PROJECT_LIB_DIR}/libothelloplugin.so ${ICS46_PROJECT_LIB_DIR}/libothelloclient.so ${ICS46_PROJECT_LIB_DIR}/libothellogame.so ${ICS46_PROJECT_LIB_DIR}/libothelloai.so c++ pthread ${Qt6Widgets_LIBRARIES} -Wl,--whole-archive ${CORE_LIBS} -Wl,--no-whole-archive)

target_link_libraries(${PROJECT_NAME} ${APP_LIBS} Qt6::Core Qt6::Widgets)



project(a.out.exp)

include_directories(${CMAKE_SOURCE_DIR}/exp)

file(GLOB EXP_SRC_FILES ${CMAKE_SOURCE_DIR}/exp/*.cpp)
file(GLOB EXP_INCLUDE_FILES ${CMAKE_SOURCE_DIR}/exp/*.hpp)

add_definitions("-std=c++17 -stdlib=libc++ -Wall -Wno-c++17-extensions -pedantic-errors -Werror -g -fstandalone-debug")

add_executable(${PROJECT_NAME} ${EXP_SRC_FILES} ${EXP_INCLUDE_FILES})

set(EXP_LIBS ${ICS46_PROJECT_LIB_DIR}/libothellogame.so ${ICS46_PROJECT_LIB_DIR}/libothelloai.so pthread c++ -Wl,--whole-archive ${CORE_LIBS} -Wl,--no-whole-archive)

target_link_libraries(${PROJECT_NAME} ${EXP_LIBS})



project(a.out.gtest)

include_directories(${CMAKE_SOURCE_DIR}/gtest)

file(GLOB GTEST_SRC_FILES ${CMAKE_SOURCE_DIR}/gtest/*.cpp)
file(GLOB GTEST_INCLUDE_FILES ${CMAKE_SOURCE_DIR}/gtest/*.hpp)

add_definitions("-std=c++17 -stdlib=libc++ -Wall -Wno-c++17-extensions -pedantic-errors -Werror -g -fstandalone-debug")

add_executable(${PROJECT_NAME} ${GTEST_SRC_FILES} ${GTEST_INCLUDE_FILES})

set(GTEST_LIBS ${ICS46_PROJECT_LIB_DIR}/libothellogame.so ${ICS46_PROJECT_LIB_DIR}/libothelloai.so pthread c++ gtest gtest_main -Wl,--whole-archive ${CORE_LIBS} -Wl,--no-whole-archive)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBS})

