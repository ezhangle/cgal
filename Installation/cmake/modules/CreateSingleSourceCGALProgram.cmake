macro(create_single_source_cgal_program first )

  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${first})
  
    set( all ${CMAKE_CURRENT_SOURCE_DIR}/${first} )
    
    foreach( i ${ARGN} )
      set( all ${all} ${CMAKE_CURRENT_SOURCE_DIR}/${i} ) 
    endforeach()
    
    get_filename_component(exe_name ${first} NAME_WE)
    
    add_executable(${exe_name} ${all})
    
    add_to_cached_list( CGAL_EXECUTABLE_TARGETS ${exe_name} )
    
    # Link the executable to CGAL and third-party libraries
    if ( AUTO_LINK_ENABLED )    
      target_link_libraries(${exe_name} ${CGAL_3RD_PARTY_LIBRARIES} )
    else()
      target_link_libraries(${exe_name} ${CGAL_3RD_PARTY_LIBRARIES} ${CGAL_LIBRARIES} )
    endif()
  
  endif()
    
endmacro()
