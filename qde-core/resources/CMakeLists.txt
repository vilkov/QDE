# Resources
file (GLOB_RECURSE src_RESOURCES RELATIVE ${qde-core_ROOT} FOLLOW_SYMLINKS "*.qrc")
set (qde-core_RESOURCES ${qde-core_RESOURCES} ${src_RESOURCES} PARENT_SCOPE)
