
#include_directories("${Root_PATH}/Source/")

IF (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0501)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
ELSE()
    #set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} -Xlinker -unresolved-symbols=ignore-in-shared-libs")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Xlinker -unresolved-symbols=ignore-in-shared-libs")
ENDIF()

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

set(BUILD_ROOT_DIR ${DLL_BUILD_PATH})

set(all_src_dll  
            Solution_dll.cpp Solution_dll.hpp)

set(all_src_staticLib  
            Solution_staticlib.cpp Solution_staticlib.hpp)
#生成动态库的 工程			
add_library(SolutionDLL SHARED  ${all_src_dll})

#生成静态态库的 工程	
add_library(SolutionStaticLib STATIC  ${all_src_staticLib})

source_group(TREE ${DLL_SOURCE_ROOT_PATH} FILES ${all_src_dll})
source_group(TREE ${DLL_SOURCE_ROOT_PATH} FILES ${all_src_staticLib})

SetDefaultTargetProperties(SolutionDLL)
target_compile_definitions(SolutionDLL PUBLIC -DBUILD_Solution_DLL)

SetDefaultTargetProperties(SolutionStaticLib)
target_compile_definitions(SolutionStaticLib PUBLIC -DBUILD_STATIC_LIB)


if(MSVC)
    set_target_properties(SolutionDLL PROPERTIES
        LINK_FLAGS " /INCREMENTAL:NO /MANIFEST /NOLOGO"
        #COMPILE_FLAGS "-DHELLO_EXPORTS"  #ajouté in last a verif demin
    )
endif(MSVC)
