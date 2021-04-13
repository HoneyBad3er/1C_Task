cmake_minimum_required(VERSION 3.17)
project(CourseManager)

set(CMAKE_CXX_STANDARD 17)
set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(CourseManager course_graph.cpp main.cpp csv.h)

add_library(${BINARY}_lib STATIC     	
    main.cpp
    course_graph.cpp
    csv.h
    )

install(TARGETS CourseManager
        RUNTIME DESTINATION  ${Prac1_SOURCE_DIR}/bin
        )