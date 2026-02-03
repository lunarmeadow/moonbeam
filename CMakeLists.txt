# partially adapted from barrett's cmake, thank you erysdren :3

cmake_minimum_required(VERSION 3.11)
project(moonbeam
	DESCRIPTION "A 90s style raycasting game engine written in C with raylib"
	HOMEPAGE_URL "https://github.com/lunarmeadow/moonbeam"
	LANGUAGES C CXX
)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_C_STANDARD 23)

option(USE_ASAN "Turn on ASAN" OFF)

# DEPENDENCIES

include(FetchContent)

# https://github.com/raysan5/raylib/blob/master/projects/CMake/CMakeLists.txt
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
  endif()
endif()

FetchContent_Declare(
	miniz
	GIT_REPOSITORY https://github.com/richgel999/miniz.git
	GIT_TAG 3.1.0
	EXCLUDE_FROM_ALL
)

FetchContent_Declare(
	adlmidi
	GIT_REPOSITORY https://github.com/Wohlstand/libADLMIDI.git
	GIT_TAG v1.6.1
	EXCLUDE_FROM_ALL
)

FetchContent_MakeAvailable(miniz adlmidi)

# LIBRARY CONFIG

add_library(ASAN::ASAN IMPORTED INTERFACE)
target_compile_options(ASAN::ASAN INTERFACE -fsanitize=address,undefined $<$<NOT:$<COMPILE_LANG_AND_ID:C,MSVC>>:-fno-omit-frame-pointer>)
target_link_options(ASAN::ASAN INTERFACE -fsanitize=address,undefined)

# ADD ALL SOURCE FILES

set(SOURCES
	${PROJECT_SOURCE_DIR}/src/main.c
	${PROJECT_SOURCE_DIR}/src/cast.c
	${PROJECT_SOURCE_DIR}/src/draw.c
	${PROJECT_SOURCE_DIR}/src/gamestate.c
	${PROJECT_SOURCE_DIR}/src/player.c
	${PROJECT_SOURCE_DIR}/src/archive.c
)

# BUILD TARGET CONFIG

add_executable(moonbeam ${SOURCES})
target_link_libraries(moonbeam PRIVATE raylib miniz ADLMIDI)
target_link_libraries(moonbeam PUBLIC $<$<BOOL:${USE_ASAN}>:ASAN::ASAN>)

# BUILD TYPES / COMPILE OPTIONS

if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "CLANG")
	target_compile_options(moonbeam PRIVATE -Wall -Wextra -Wshadow=compatible-local -Wpedantic -Wfatal-errors)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(moonbeam PRIVATE -g -O0)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(moonbeam PRIVATE -O2)
endif()

if(WIN32)	
    if(MINGW)
		target_link_options(moonbeam PRIVATE -static-libgcc -static-libstdc++ -static)
	endif()
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND NOT WIN32)
    target_link_options(moonbeam PRIVATE -rdynamic)
endif()
