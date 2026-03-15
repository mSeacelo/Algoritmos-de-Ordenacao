cmake_minimum_required(VERSION 3.31)
project(trab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(trab3 Principal/main.c
        Ordena-vetores/ordena.h
        Ordena-vetores/ordena.c
        Imprimir-vetores/imprime_cria.h
        Imprimir-vetores/imprime_cria.c)
