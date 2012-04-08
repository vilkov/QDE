# Project root directory
set (qde-session_ROOT ${CMAKE_CURRENT_SOURCE_DIR})


# Sources
add_subdirectory("src")
QT4_WRAP_UI(qde-session_UIS_HEADERS ${qde-session_UIS})
QT4_WRAP_CPP (qde-session_MOC_SOURCES ${qde-session_HEADERS} OPTIONS "-nw")
set (qde-session_SOURCES ${qde-session_SOURCES} ${qde-session_MOC_SOURCES} ${qde-session_UIS_HEADERS})


# Resources
add_subdirectory("resources")
QT4_ADD_RESOURCES(qde-session_RESOURCES_BIN ${qde-session_RESOURCES})
set (qde-session_SOURCES ${qde-session_SOURCES} ${qde-session_RESOURCES_BIN})


# Target - qde-session
add_executable (qde-session ${qde-session_SOURCES})
target_link_libraries (qde-session qde-core ${qde-session_LIBS})

# It is because of Qt (qglobal.h)
set_target_properties (qde-session PROPERTIES COMPILE_FLAGS "-Wno-long-long")
