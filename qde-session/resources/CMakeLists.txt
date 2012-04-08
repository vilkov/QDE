# Resources
file (GLOB_RECURSE src_RESOURCES RELATIVE ${qde-session_ROOT} FOLLOW_SYMLINKS "*.qrc")
set (qde-session_RESOURCES ${qde-session_RESOURCES} ${src_RESOURCES} PARENT_SCOPE)
