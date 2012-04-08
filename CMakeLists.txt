cmake_minimum_required (VERSION 2.8)
project (qde)


# Main information
if (CMAKE_CROSSCOMPILING)
    message (STATUS "Cross compiling to: " ${CMAKE_SYSTEM_NAME} " " ${CMAKE_SYSTEM_VERSION})
else ()
    message (STATUS "System: " ${CMAKE_SYSTEM_NAME} " " ${CMAKE_SYSTEM_VERSION})
endif ()
message (STATUS "Processor: " ${CMAKE_HOST_SYSTEM_PROCESSOR})
if (MSVC)
	message(STATUS "Compiler: MSVC, version: " ${MSVC_VERSION})

	# C CXX Flags - turn on WARNINGS
    set (PROJECT_COMP_FLAGS "/W3")
    
elseif (BORLAND)
	message(STATUS "Compiler: BCC")
elseif (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_GNUC) 
	message(STATUS "Compiler: GCC")
	
	# C CXX Flags - turn on WARNINGS
    set (PROJECT_COMP_FLAGS "-Wall -Wextra -pedantic -Wundef -Wcast-align -Wpointer-arith -Wformat")

	# C CXX Flags - turn off WARNINGS
    set (PROJECT_COMP_FLAGS "${PROJECT_COMP_FLAGS} -Wno-unused-parameter -Wno-parentheses -Wno-shadow -Wno-overloaded-virtual -Wno-ignored-qualifiers")
	
	# C CXX Flags - WARNINGS to ERRORS
    set (PROJECT_COMP_FLAGS "${PROJECT_COMP_FLAGS} -Werror=return-type -Werror=non-virtual-dtor")
    
	# C CXX Flags - turn on CODE GEN
    set (PROJECT_COMP_FLAGS "${PROJECT_COMP_FLAGS} -fvisibility=hidden -fvisibility-inlines-hidden")
    
	# C CXX Flags - turn off CODE GEN
    set (PROJECT_COMP_FLAGS "${PROJECT_COMP_FLAGS} -fno-exceptions -fno-check-new -fno-common -fno-threadsafe-statics")

    #Useful link: "http://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html"
else () 
	message (STATUS "Unknown compiler")
endif ()
message (STATUS "CMake generates " ${CMAKE_GENERATOR})


# Main settings
set (USE_GPROF    NO)
set (UNIT_TESTING NO CACHE BOOL "Compile binary executable for unit testing?")


# Custom modules
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")


# Set up compiler flags
set (CMAKE_CXX_FLAGS "${PROJECT_COMP_FLAGS}")

if (USE_GPROF)
    set (CMAKE_CXX_FLAGS        ${CMAKE_CXX_FLAGS}        -pg)
    set (CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -pg)
endif (USE_GPROF)


# 3rdparty
find_package (Qt4 4.7.1 COMPONENTS QtCore QtGui QtXml QtDbus REQUIRED)
include (${QT_USE_FILE})
set (qde_LIBS ${qde_LIBS} ${QT_LIBRARIES})
add_definitions (${QT_DEFINITIONS})


# Includes
include_directories ("${PROJECT_SOURCE_DIR}/include")

# Link directories

# Libs
if (USE_GPROF)
	set (qde_LIBS ${qde_LIBS} gmon)
endif (USE_GPROF)
 
# Definitions
add_definitions (
    -DUNICODE
    -DTOOLS_THREADS_BACKEND_QT
    -DTOOLS_TYPES_BACKEND_QT
    -DTOOLS_POINTERS_BACKEND_QT
)


# QDE core library
add_subdirectory ("qde-core")


# QDE session manager
add_subdirectory ("qde-session")

