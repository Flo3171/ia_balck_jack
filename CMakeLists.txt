cmake_minimum_required(VERSION 3.0.0)
project(Black_Jack VERSION 0.1.0)

include(CTest)
enable_testing()

set(SRCS
    src/main.c
    src/partie.c
    )

set (HEADERS
    src/partie.h)

add_executable(Black_Jack ${SRCS} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
