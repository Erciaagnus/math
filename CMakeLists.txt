cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17) #17version으로 진행할 것
set(CMAKE_CXX_STANDARD_REQUIRED ON) #17버전 가지고 있지 않은데 on 되어 있지 않으면 error가 발생하지 않음..
set(CMAKE_CXX_EXTENSIONS OFF) #추가기능 사용하지 않도록 셋업

#여기까지가 무조건 기본적으로 필요한 부분들임!!


set(CMAKE_VERBOSE_MAKEFILE ON)

#다 똑같이 유지하고 이 부분만 바꿔서 사용한다. CMAKE PROJECT 관리하기 위한 key
project(
    CPP_PROJECT_TEMPLATE
    LANGUAGES CXX #C++이니까 CXX 넣기
    VERSION 1.0.0
    DESCRIPTION "C++ Project Template"
    HOMEPAGE_URL "https://github.com/Erciaagnus/cpp_project_template"
)

#실제 CMAKE 빌드하려면 어떻게 해야하는지
message(STATUS)
message(STATUS "Started all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS)

#Top lever--> cmakelist/module --> cmakelist
#toplevel에서 cmakecomfile_flag를 만들면 module/cpp_comfile_FLAGS XXXXX 만들필요가 없겠지? 그래서 Top level에 있는지 확인하는 것

#compile flag를 만듦...
set(CPP_COMFILE_FLAGS_MSVC /w4 /wx /permissive~)
set(CPP_COMFILE_FLAGS_OTHERS -Wall -Wpedantic -Wextra -Werror)

if(NOT CPP_COMFILE_FLAGS)
 if(CMAKE_SYSTEM_COMPILER_ID STREQUAL "MSVC")
    set(CPP_COMFILE_FLAGS ${CPP_COMFILE_FLAGS_MSVC}) #Window면 windows를 cpp_comfile_flag에 반환
 else()
    set(CPP_COMFILE_FLAGS ${CPP_COMFILE_FLAGS_OTHERS})
 endif()
endif()

# ! Set the path variables
# ! set(${PROJECT_NAME}_SOMETHING_PATH ${${PROJECT_NAME}_PATH}/something)
set(${PROJECT_NAME}_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(${PROJECT_NAME}_SOURCE_PATH "${${PROJECT_NAME}_ROOT_PATH}/src")
set(${PROJECT_NAME}_INCLUDE_PATH "${${PROJECT_NAME}_ROOT_PATH}/include")
set(${PROJECT_NAME}_THIRDPARTY_PATH "${${PROJECT_NAME}_ROOT_PATH}/thirdparty")
set(${PROJECT_NAME}_MODULE_PATH "${${PROJECT_NAME}_ROOT_PATH}/module")
set(${PROJECT_NAME}_TEST_PATH "${${PROJECT_NAME}_ROOT_PATH}/test")
set(${PROJECT_NAME}_APPLICATION_PATH "${${PROJECT_NAME}_ROOT_PATH}/application")
set(${PROJECT_NAME}_RESOURCE_PATH "${${PROJECT_NAME}_ROOT_PATH}/resource")

## 이 부분은 바뀌지 않지
if (NOT PARSED_SYSTEM_INFO)
# ! Message for the system information
message(STATUS "-----------------------Cmake information-----------------------")
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "")

message(STATUS "-----------------------System information-----------------------")
message(STATUS "SYstem architecture name: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "System os name: ${CMAKE_SYSTEM_NAME}")
message(STATUS "System os version: ${CMAKE_SYSTEM_VERSION}")
message(STATUS "")

message(STATUS "-----------------------Compiler information-----------------------")
message(STATUS "C++ compiler id: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "C++ Compile options: ${CPP_COMPILE_FLAGS}")
message(STATUS "")

message(STATUS "-----------------------C++ standard information-----------------------")
message(STATUS "C++ BUild type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard version: ${CMAKE_CXX_STANDARD}")
message(STATUS "C++ standard required: ${CMAKE_CXX_STANDARD_REQUIRED}")
message(STATUS "C++ extensions: ${CMAKE_CXX_EXTENSIONS}")
message(STATUS "")

set(PARSED_SYSTEM_INFO TRUE)
endif() # 반드시 닫아주세요~

##이러면 Top level 첫 시작에서만 호출되게 됨.

message(STATUS ${CPP_COMFILE_FLAGS})

# ! Message for the project information
message(STATUS "-----------------------Project information-----------------------")
message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "${PROJECT_NAME}_VERSION: ${PROJECT_VERSION}")
message(STATUS "${PROJECT_NAME}_DESCRIPTION: ${PROJECT_DESCRIPTION}")
message(STATUS "${PROJECT_NAME}_HOMEPAGE_URL: ${PROJECT_HOMEPAGE_URL}")
message(STATUS "")

# ! message(STATUS "${PROJECT_NAME}_SOMETHING_PATH: ${${PROJECT_NAME}_SOMETHING_PATH}")

message(STATUS "-----------------------Project path information-----------------------")
message(STATUS "${PROJECT_NAME}_ROOT_PATH ${${PROJECT_NAME}_ROOT_PATH}")
message(STATUS "${PROJECT_NAME}_SOURCE_PATH ${${PROJECT_NAME}_SOURCE_PATH}")
message(STATUS "${PROJECT_NAME}_INCLUDE_PATH ${${PROJECT_NAME}_INCLUDE_PATH}")
message(STATUS "${PROJECT_NAME}_THIRDPARTY_PATH ${${PROJECT_NAME}_THIRDPARTY_PATH}")
message(STATUS "${PROJECT_NAME}_MODULE_PATH ${${PROJECT_NAME}_MODULE_PATH}")
message(STATUS "${PROJECT_NAME}_TEST_PATH ${${PROJECT_NAME}_TEST_PATH}")
message(STATUS "${PROJECT_NAME}_APPLICATION_PATH: ${${PROJECT_NAME}_APPLICATION_PATH}")
message(STAUTS "${PROJECT_NAME}_RESOURCE_PATH: ${${PROJECT_NAME}_RESOURCE_PATH}")
message(STATUS "")

add_subdirectory(${${PROJECT_NAME}_THIRDPARTY_PATH})
add_subdirectory(${${PROJECT_NAME}_MODULE_PATH})
add_subdirectory(${${PROJECT_NAME}_APPLICATION_PATH})

set(${PROJECT_NAME}_SOURCE FILES

 #! Add source files here
)

# base구조
# base/ application/base/ module/base/ thirdparty/
# base라고 하는 것들이 위의 트리처럼 만들 수 있음. 전에 만들었던 것을 그대로.. 어디에서나 사용할 수 있는 CMAKE 구조가 되는 것

# ! IF you want to make a library, use the following code
#add_library(${PROJECT_NAME} STATIC
#${${PROJECT_NAME}_SOURCE_FILES}
# )

# ! If you want to make an executable, use the following code
#add_executable(${PROJECT_NAME}
#${${PROJECT_NAME}_SOURCE_FILES}
# )

# ! If you want to add include directories and link libraries, use the following code
# target_include_directories(${PROJECT_NAME} PUBLIC
#${${PROJECT_NAME}_INCLUDE_PATH}

# ! Add include path here
# )
# target_link_libraries(${PROJECT_NAME} PRIVATE

# ! Add libraries here
#)
# add_dependencies(${PROJECT_NAME}

# ! Add dependencies here
#)
# target_compile_options(${PROJECT_NAME} PRIVATE
#${CPP_COMFILE_FLAGS}
#)

#include(cmake/create_documents_cmake)
add_subdirectory(${${PROJECT_NAME}_TEST_PATH})

#Process
message(STATUS)
message(STATUS "Finished all process in ${PROJECT_NAME} CMakeLists.txt.")
message(STATUS)
