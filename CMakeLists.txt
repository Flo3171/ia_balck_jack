cmake_minimum_required(VERSION 3.0.0)
project(Black_Jack VERSION 0.1.0)

include(CTest)
enable_testing()

set(SRCS
    src/main.c
    src/partie.c
    src/gestionCarte.c
    src/autre.c
    src/affichage.c
    src/gestionDonnee.c
    src/listeChainee.c
    )

set (HEADERS
    src/main.h
    src/structure.h
    src/partie.h
    src/gestionCarte.h
    src/autre.h 
    src/affichage.h
    src/gestionDonnee.h
    src/listeChainee.h
    )

add_executable(Black_Jack ${SRCS} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
