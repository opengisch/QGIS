
# Auto-Generate files - every class will have a cpp and h file
set(pyqgis_core_SRC
    # individual classes
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgswkbtypes_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgswkbtypes_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsunittypes_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsunittypes_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfield_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfield_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsexpressioncontext_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsexpressioncontext_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeature_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeature_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeaturerequest_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeaturerequest_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsgeometry_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsgeometry_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeedback_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeedback_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsvectorlayer_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsvectorlayer_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsmaplayer_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsmaplayer_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsmaplayerrenderer_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsmaplayerrenderer_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsrendercontext_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsrendercontext_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsreadwritecontext_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsreadwritecontext_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgscoordinatetransformcontext_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgscoordinatetransformcontext_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgscoordinatereferencesystem_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgscoordinatereferencesystem_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfields_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfields_wrapper.h

    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeaturesource_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeaturesource_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeaturesink_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsfeaturesink_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsexpressioncontextscopegenerator_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsexpressioncontextscopegenerator_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsexpressioncontextscope_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsexpressioncontextscope_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsexpressioncontextgenerator_wrapper.h
    ${CMAKE_CURRENT_BINARY_DIR}/core/qgsexpressioncontextgenerator_wrapper.cpp

    # ${CMAKE_CURRENT_BINARY_DIR}/core/qgsinterval_wrapper.cpp
    # ${CMAKE_CURRENT_BINARY_DIR}/core/qgsinterval_wrapper.h
    # global module wrapper
    ${CMAKE_CURRENT_BINARY_DIR}/core/core_module_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/core/core_python.h
)

# The includes are needed to parse and build classes specified in our typesystem
set(pyqgis_core_include_paths
  $<JOIN:$<TARGET_PROPERTY:qgis_core,INTERFACE_INCLUDE_DIRECTORIES>,${PATH_SEP}>
  ${CMAKE_BINARY_DIR}
)
message("${pyqgis_core_include_paths}")

# Set list of paths where shiboken should look for typesystem
set(pyqgis_core_typesystem_paths
    # PySide path, this variable was exposed by FindPySide2.cmake
    ${PYSIDE_TYPESYSTEMS}
)

# Include flags/path that will be set in 'target_include_directories'
set(pyqgis_core_target_include_directories
    ${Python_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
)

# Libraries necessary to link the target for the command 'target_link_libraries'
set(pyqgis_core_target_link_libraries
    qgis_core
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Xml
    ${Python_LIBRARIES}
)

# Dependencies - changes on these files should trigger new bindings
set(pyqgis_core_DEPENDS
   ${CMAKE_SOURCE_DIR}/src/core/geometry/qgswkbtypes.h
   ${CMAKE_SOURCE_DIR}/src/core/qgsunittypes.h
   ${CMAKE_SOURCE_DIR}/src/core/qgsfield.h
   ${CMAKE_SOURCE_DIR}/src/core/qgsfeature.h
   ${CMAKE_SOURCE_DIR}/src/core/qgsmaplayerrenderer.h
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
