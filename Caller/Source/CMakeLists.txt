
include_directories("${DLL_SOURCE_ROOT_PATH}")

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

#set(BUILD_ROOT_DIR ${DLL_BUILD_PATH})

set(all_src_callDll  
            main_dll.cpp)
			
set(all_src_callStaticLib  
            main_staticlib.cpp)

#生成一个可执行文件调用dll			
add_executable(CallDLL ${all_src_callDll})

#生成一个可执行文件调用静态库			
add_executable(CallStaticLib ${all_src_callStaticLib})


source_group(TREE ${CALLER_SOURCE_ROOT_PATH} FILES ${all_src})

SetDefaultTargetProperties(CallDLL)
target_link_libraries(CallDLL debug ${DLL_PATH_LIB}/Debug/SolutionDLL.lib)
target_link_libraries(CallDLL optimized ${DLL_PATH_LIB}/Release/SolutionDLL.lib)

SetDefaultTargetProperties(CallStaticLib)
target_link_libraries(CallStaticLib debug ${STATIC_LIB_PATH}/Debug/SolutionStaticLib.lib)
target_link_libraries(CallStaticLib optimized ${STATIC_LIB_PATH}/Release/SolutionStaticLib.lib)
