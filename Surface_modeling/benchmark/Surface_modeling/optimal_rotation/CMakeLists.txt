project( benchmark_for_closest_rotation )

cmake_minimum_required(VERSION 2.6.2)
if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" VERSION_GREATER 2.6)
  if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}" VERSION_GREATER 2.8.3)
    cmake_policy(VERSION 2.8.4)
  else()
    cmake_policy(VERSION 2.6)
  endif()
endif()

find_package(CGAL QUIET COMPONENTS Core )

if ( CGAL_FOUND )

  include( ${CGAL_USE_FILE} )

  find_package(Eigen3 3.1.0) #(requires 3.1.0 or greater)
  if (EIGEN3_FOUND)
    include( ${EIGEN3_USE_FILE} )
    include( CGAL_CreateSingleSourceCGALProgram )

    include_directories (BEFORE "../../include")

    create_single_source_cgal_program( "benchmark_for_concept_models.cpp" )

  else()
    message(STATUS "This program requires the Eigen library, version 3.1 or later and will not be compiled.")
  endif()
else()
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
endif()

