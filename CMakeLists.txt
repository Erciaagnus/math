cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17) #17version으로 진행할 것
set(CMAKE_CXX_STANDARD_REQUIRED ON) #17버전 가지고 있지 않은데 on 되어 있지 않으면 error가 발생하지 않음..
set(CMAKE_CXX_EXTENSIONS OFF) #추가기능 사용하지 않도록 셋업

#여기까지가 무조건 기본적으로 필요한 부분들임!!


set(CMAKE_VERBOSE_MAKEFILE ON)

project(
    CPP_PROJECT_TEMPLATE
    LANGUAGES CXX #C++이니까 CXX 넣기
    VERSION 1.0.0
    DESCRIPTION "C++ Project Template"
    HOMEPAGE_URL "https://github.com/Erciaagnus/cpp_project_template"
)
message(STATUS)
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS)
