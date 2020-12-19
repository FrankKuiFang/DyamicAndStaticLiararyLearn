
if(CMAKE_GENERATOR MATCHES Ninja)
	# this is for Android Studio
	cmake_minimum_required(VERSION 3.6.0)
else()
	cmake_minimum_required(VERSION 3.8.0)
endif()

# Build with clang
IF (UNIX)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdeclspec -std=gnu++14 -stdlib=libc++ -Wno-inconsistent-missing-override -I/usr/include/libcxxabi")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
ENDIF()

# top project
project(SolutionDLL)

set(THREADS_PREFER_PTHREAD_FLAG ON)

# global settings
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/modules)

set(DLL_SOURCE_ROOT_PATH ${CMAKE_CURRENT_LIST_DIR}/../Source)
set(DLL_BUILD_PATH ${CMAKE_CURRENT_LIST_DIR}/build)
set(DLL_PATH_LIB ${DLL_BUILD_PATH}/lib)
set(DLL_PATH_DLL ${DLL_BUILD_PATH}/bin)

set(STATIC_LIB_BUILD_PATH ${CMAKE_CURRENT_LIST_DIR}/build)
set(STATIC_LIB_PATH ${STATIC_LIB_BUILD_PATH}/lib)


set(CALLER_SOURCE_ROOT_PATH ${CMAKE_CURRENT_LIST_DIR}/../Caller/Source)
set(CALLER_BUILD_PATH ${CMAKE_CURRENT_LIST_DIR}/build)


#CMAKE_BINARY_DIR is the full path to the top level of the current CMake build tree. 
#For an in-source build, this would be the same as CMAKE_SOURCE_DIR.
function(SetDefaultTargetProperties target)
	set_target_properties(${target} PROPERTIES
		CXX_STANDARD 14
	)
	set_target_properties(${target} PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
	)
endfunction()

IF (APPLE)
	set(CMAKE_THREAD_LIBS_INIT "-lpthread")
	set(CMAKE_HAVE_THREADS_LIBRARY 1)
	set(CMAKE_USE_WIN32_THREADS_INIT 0)
	set(CMAKE_USE_PTHREADS_INIT 1)
ENDIF()
	
IF (NOT APPLE)
	add_subdirectory(${DLL_SOURCE_ROOT_PATH} DllSolution)
	add_subdirectory(${CALLER_SOURCE_ROOT_PATH} CallerSolution)
ENDIF()

