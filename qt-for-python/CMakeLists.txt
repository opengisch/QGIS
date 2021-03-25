

list(REMOVE_ITEM CMAKE_CXX_FLAGS "-Werror")

message(${CMAKE_CXX_FLAGS})

set(PYTHON_VERSION "3.9" CACHE STRING  "Use specific python version to build the project.")
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

add_subdirectory(core)
