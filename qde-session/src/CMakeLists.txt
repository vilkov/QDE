# CMake tools
include ("collect_sources")


collect_sources (src_HEADERS src_SOURCES ${qde-session_ROOT})


# Headers
set (qde-session_HEADERS ${qde-session_HEADERS} ${src_HEADERS} PARENT_SCOPE)


# Sources
set (qde-session_SOURCES ${qde-session_SOURCES} ${src_SOURCES} PARENT_SCOPE)


# UIs
file (GLOB_RECURSE src_UIS RELATIVE ${qde-session_ROOT} FOLLOW_SYMLINKS "*.ui")
set (qde-session_UIS ${qde-session_UIS} ${src_UIS} PARENT_SCOPE)
