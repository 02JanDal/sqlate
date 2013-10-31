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
    DEPENDS copy_doc_headers
  )
  set(DOC_HEADERS
    condquerybuilders.h
    createtableschemaupdater.h
    databasemanagement.h
    deletequerybuilder.h
    functionqueries.h
    gettingstarted.h
    insertquerybuilder.h
    mainpage.h
    modules.h
    select.h
    selectquerybuilder.h
    transactions.h
    updatequerybuilder.h
    watchersmonitors.h
  )

  # some workarounds because we want to edit headers, but send .txt files to doxygen
  add_custom_target(copy_doc_headers
    COMMENT "Copy and rename documentation-only headers"
  )
  foreach(DOC_HEADER ${DOC_HEADERS})
    add_custom_command(TARGET copy_doc_headers PRE_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${DOC_HEADER} ${CMAKE_CURRENT_BINARY_DIR}/${DOC_HEADER}.txt
    )
  endforeach()
endif(DOXYGEN_FOUND)
