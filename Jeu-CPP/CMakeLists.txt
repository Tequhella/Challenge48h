cmake_minimum_required(VERSION 3.5)
project(Challenge48h)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

file(GLOB SOURCES "src/*.cpp")
add_executable(Challenge48h ${SOURCES})

target_compile_options(Challenge48h PRIVATE -Wall -Wextra -Werror)
target_link_libraries(Challenge48h sfml-graphics sfml-window sfml-system sfml-audio)

set(OBJ_DIR ${CMAKE_CURRENT_SOURCE_DIR}/obj)

foreach(SOURCE ${SOURCES})
    get_filename_component(SOURCE_NAME ${SOURCE} NAME_WE)
    set(OBJ ${OBJ_DIR}/${SOURCE_NAME}.o)
    add_custom_command(
        OUTPUT ${OBJ}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${OBJ_DIR}
        COMMAND ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_FLAGS} -c -o ${OBJ} ${SOURCE}
        DEPENDS ${SOURCE}
        COMMENT "Building ${OBJ}"
        VERBATIM
    )
    list(APPEND OBJ_FILES ${OBJ})
endforeach()

add_custom_target(obj DEPENDS ${OBJ_FILES})

add_dependencies(Challenge48h obj)

add_custom_target(packages
    COMMAND sudo apt-get install libsfml-dev -y
)

add_custom_target(check
    COMMAND test -d obj || mkdir obj
)

add_custom_target(clean-all
    COMMAND rm -f obj/*.o Challenge48h
)