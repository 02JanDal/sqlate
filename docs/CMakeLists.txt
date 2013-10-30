find_package(Doxygen)

option(GENERATE_QHP "Whether to generate Qt Help documentation, usable by Qt Assistant" "YES")

if(DOXYGEN_FOUND)
  set(DISABLE_INDEX "NO")
  set(GENERATE_TREEVIEW "YES")
  set(HTML_DYNAMIC_SECTIONS "YES")
  if(GENERATE_QHP EQUAL "YES")
    set(DISABLE_INDEX "YES")
    set(GENERATE_TREEVIEW "NO")
    set(HTML_DYNAMIC_SECTIONS "NO")
  endif(GENERATE_QHP EQUAL "YES")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generate API documentation" VERBATIM
  )
endif(DOXYGEN_FOUND)
