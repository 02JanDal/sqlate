find_package(Qt4 REQUIRED)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}
  ${QT_INCLUDES}
)

if (NOT SQLATE_DATABASE_HOST)
  set(SQLATE_DATABASE_HOST "sqlate-postgres")
endif()

if (NOT SQLATE_DATABASE_USER)
  set(SQLATE_DATABASE_USER "sqlate.user")
endif()

if (NOT SQLATE_DATABASE_PASSWORD)
  set(SQLATE_DATABASE_PASSWORD "sql123456")
endif()

macro(add_example name_ sources_)
  add_executable(${name_} ${sources_})
  target_link_libraries(
    ${name_}
    Qt4::QtSql
    Qt4::QtCore
    sqlate
  )
endmacro(add_example)

add_example(example_select_qb example_select_qb.cpp)
