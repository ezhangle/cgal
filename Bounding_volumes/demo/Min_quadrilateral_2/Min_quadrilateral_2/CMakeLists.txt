# This is the CMake script for compiling a CGAL application.

project( min_quadrilateral_2 ) 

cmake_minimum_required(VERSION 2.6.2)
if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}" VERSION_GREATER 2.8.3)
  cmake_policy(VERSION 2.8.4)
else()
  cmake_policy(VERSION 2.6)
endif()

find_package(CGAL COMPONENTS Qt3 )
include( ${CGAL_USE_FILE} )

find_package(Qt3-patched)
# FindQt3-patched.cmake is FindQt3.cmake patched by CGAL developers, so
# that it can be used together with FindQt4: all its variables are prefixed
# by "QT3_" instead of "QT_".

if ( CGAL_FOUND AND CGAL_Qt3_FOUND AND QT3_FOUND )

  # use the Qt MOC preprocessor on classes that derives from QObject
  include( Qt3Macros-patched )
  qt3_generate_moc( "${CMAKE_CURRENT_SOURCE_DIR}/Qt_widget_toolbar.h" Qt_widget_toolbar.moc )
  qt3_generate_moc( "${CMAKE_CURRENT_SOURCE_DIR}/Qt_widget_toolbar_layers.h" Qt_widget_toolbar_layers.moc )
  qt3_generate_moc( "${CMAKE_CURRENT_SOURCE_DIR}/Qt_widget_move_list_point.h" Qt_widget_move_list_point.moc )
  qt3_generate_moc( "${CMAKE_CURRENT_SOURCE_DIR}/min_quadrilateral_2.cpp" min_quadrilateral_2.moc )


  # The executable itself.
  add_executable  ( min_quadrilateral_2 
    min_quadrilateral_2.cpp min_quadrilateral_2.moc
    Qt_widget_toolbar.cpp Qt_widget_toolbar.moc
    Qt_widget_toolbar_layers.cpp Qt_widget_toolbar_layers.moc
    Qt_widget_move_list_point.cpp Qt_widget_move_list_point.moc
    )

  add_to_cached_list( CGAL_EXECUTABLE_TARGETS min_quadrilateral_2 )

  target_link_libraries( min_quadrilateral_2  ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} )

else()

  message(STATUS "NOTICE: This demo requires CGAL and Qt3, and will not be compiled.")

endif()
