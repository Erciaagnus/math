cmake_minimum_required(VERSION 3.11)

function(build_submodule PACKAGE_PATH)
    message("Start configuration for ${ELEMENT}.")
    add_subdirectory(${PACKAGE_PATH})
    message("Finish configure for ${ELEMENT}.")
endfunction()

message(STATUS "Start configuration for tests.")

file(GLOB ELEMENTS "*")

foreach(ELEMENT ${ELEMENTS})
    if(IS_DIRECTORY ${ELEMENT} AND EXISTS ${ELEMENT}/CMakeLists.txt)
        build_submodule(${ELEMENT})
    endif()
endforeach()

message(STATUS "Finish configuration for submodules.\n")
