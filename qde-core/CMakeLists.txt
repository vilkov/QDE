# Project root directory
set (qde-core_ROOT ${CMAKE_CURRENT_SOURCE_DIR})


# Sources
add_subdirectory("src")
QT4_WRAP_UI(qde-core_UIS_HEADERS ${qde-core_UIS})
QT4_WRAP_CPP (qde-core_MOC_SOURCES ${qde-core_HEADERS} OPTIONS "-nw")
set (qde-core_SOURCES ${qde-core_SOURCES} ${qde-core_MOC_SOURCES} ${qde-core_UIS_HEADERS})


# Resources
add_subdirectory("resources")
QT4_ADD_RESOURCES(qde-core_RESOURCES_BIN ${qde-core_RESOURCES})
set (qde-core_SOURCES ${qde-core_SOURCES} ${qde-core_RESOURCES_BIN})


# Target - qde-core
add_definitions (-DQDE_CORE_BUILD)
add_library (qde-core SHARED ${qde-core_SOURCES})
target_link_libraries (qde-core ${qde-core_LIBS})

# It is because of Qt (qglobal.h)
set_target_properties (qde-core PROPERTIES COMPILE_FLAGS "-Wno-long-long")
