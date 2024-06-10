cmake_minimum_required (VERSION 3.24)
project (FishingGame)

set(CMAKE_CXX_STANDARD 17)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
aux_source_directory (src SRC_LIST)
include_directories (include)
add_executable (FishingGame ${SRC_LIST})

if (CMAKE_COMPILER_IS_GNUCXX)
message ("Compiler set options...")
	add_compile_options(
        -Werror
        -pedantic-errors
        -Wall
        -Wextra
        -Wpedantic
        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wduplicated-branches
        -Wduplicated-cond
        -Wextra-semi
        -Wfloat-equal
        -Wlogical-op
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wsign-promo
        )
else ()
	message ("Unknown compiler")
endif ()