# CMake tools
include ("collect_sources")


collect_sources (src_HEADERS src_SOURCES ${qde-core_ROOT})


# Headers
set (qde-core_HEADERS ${qde-core_HEADERS} ${src_HEADERS} PARENT_SCOPE)


# Sources
set (qde-core_SOURCES ${qde-core_SOURCES} ${src_SOURCES} PARENT_SCOPE)


# UIs
file (GLOB_RECURSE src_UIS RELATIVE ${qde-core_ROOT} FOLLOW_SYMLINKS "*.ui")
set (qde-core_UIS ${qde-core_UIS} ${src_UIS} PARENT_SCOPE)
