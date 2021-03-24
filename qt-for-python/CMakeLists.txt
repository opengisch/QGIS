message("PYTHON VERSION: ${PYTHON_VERSION}")
find_package(Python3 ${PYTHON_VERSION} REQUIRED COMPONENTS Interpreter Development)

if (WITH_QT6)
    find_package(Shiboken6 REQUIRED)
    find_package(PySide6 ${Qt5Widgets_VERSION} EXACT REQUIRED)
    include(PySide6ModuleBuild)
    set(PYSIDE_MAJOR_VERSION "6")
else()
    find_package(Shiboken2 REQUIRED)
    find_package(PySide2 ${Qt5Widgets_VERSION} EXACT REQUIRED)
    include(PySide2ModuleBuild)
    set(PYSIDE_MAJOR_VERSION "2")
endif()

# Auto-Generate files - every class will have a cpp and h file
set(pyqgis_core_SRC
    # individual classes
    ${CMAKE_CURRENT_BINARY_DIR}/core_qgswkbtypes_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core_qgswkbtypes_wrapper.h
    # global module wrapper
    ${CMAKE_CURRENT_BINARY_DIR}/core_module_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core_python.h
)

# The includes are needed to parse and build classes specified in our typesystem
set(pyqgis_core_include_paths
    $<JOIN:$<TARGET_PROPERTY:qgis_core,INTERFACE_INCLUDE_DIRECTORIES>,${PATH_SEP}>
)

# Set list of paths where shiboken should look for typesystem
set(pyqgis_core_typesystem_paths
    # PySide path, this variable was exposed by FindPySide2.cmake
    ${PYSIDE_TYPESYSTEMS}
)

# Include flags/path that will be set in 'target_include_directories'
set(pyqgis_core_target_include_directories
    ${CMAKE_SOURCE_DIR}
)

# Libraries necessary to link the target for the command 'target_link_libraries'
set(pyqgis_core_target_link_libraries
    qgis_core
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

# Dependencies - changes on these files should trigger new bindings
set(pyqgis_core_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/core/qgswkbtypes.h
)

CREATE_PYTHON_BINDINGS(
    "core"
    "${pyqgis_core_typesystem_paths}"
    "${pyqgis_core_include_paths}"
    "${pyqgis_core_SRC}"
    "${pyqgis_core_target_include_directories}"
    "${pyqgis_core_target_link_libraries}"
    ${CMAKE_CURRENT_SOURCE_DIR}/qgis_core_global.h
    ${CMAKE_CURRENT_SOURCE_DIR}/typesystem_qgis_core.xml
    "${pyqgis_core_DEPENDS}"
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Make moduled import from build dir works
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py ${CMAKE_CURRENT_BINARY_DIR}/__init__.py)

# install
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/__init__.py DESTINATION ${Python3_SITELIB}/pyqgis_core)
