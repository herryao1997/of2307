cmake_minimum_required(VERSION 3.22)

if (DEFINED ENV{WM_PROJECT})
    message("Using $ENV{WM_PROJECT}-$ENV{WM_PROJECT_VERSION}")
    set(WM_PATH, ${CMAKE_SOURCE_DIR})
else()
    message(FATAL_ERROR "OpenFOAM environment not set. Aborting.")
endif ()

project(prescribedPipeInlet) # 1. 改个名字

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenFOAM_VERSION $ENV{WM_PROJECT_VERSION})
set(OpenFOAM_DIR $ENV{WM_PROJECT_DIR})
set(OpenFOAM_LIB_DIR $ENV{FOAM_LIBBIN})
set(OpenFOAM_SRC $ENV{FOAM_SRC})

# set(PATH_LIB_OPENMPI "sys-openmpi")
set(DEFINITIONS_COMPILE "-m64 -pthread -ftrapping-math -fno-elide-constructors -DOPENFOAM=2012Debug
                        -DWM_DP -DWM_LABEL_SIZE=32 -Wall -Wextra -Wold-style-cast -Wnon-virtual-dtor
                        -Wno-unused-parameter -Wno-invalid-offsetof -Wno-undefined-var-template
                        -Wno-unknown-warning-option  -O3  -DNoRepository -ftemplate-depth-100 -fPIC
                        -DIMPLEMENT_ACTIVATION -Wl,-execute,-undefined,dynamic_lookup")

include_directories(.
        ${OpenFOAM_SRC}/OpenFOAM/lnInclude
        ${OpenFOAM_SRC}/OSspecific/POSIX/lnInclude
        ${OpenFOAM_SRC}/finiteVolume/lnInclude
        ${OpenFOAM_SRC}/meshTools/lnInclude
        )
# -I，告诉在哪里找头文件,H文件

link_directories(${OpenFOAM_LIB_DIR} ${OpenFOAM_LIB_DIR}/dummy ${OpenFOAM_LIB_DIR}/${PATH_LIB_OPENMPI})
# -L，在那个位置找你
add_definitions(${DEFINITIONS_COMPILE})

add_library(${PROJECT_NAME} SHARED
        pulseFixedValueFvPatchField.C) ### 注意这一项即可
target_link_libraries(${PROJECT_NAME} OpenFOAM dl m Pstream finiteVolume fvOptions meshTools sampling dynamicFvMesh
        )