/**
 *
 * @page getting_started_page Getting Started
 *
 * This page should serve as a starting point on how to use SQLate. Once you are
 * done, you might want to check out the examples.
 *
 * This guide assumes Qt/C++ and basic SQL knowledge.
 *
 * @section setup_sec Setup
 *
 * Make sure you have a working setup of Qt, PostgreSQL and SQLate.
 * Start by creating a new project, and setup a QSqlDatabase.
 *
 * @section tables_and_schemas_sec Tables and Schemas
 *
 * Start by creating the files Schema.h and Schema.cpp with the following
 * content:
 *
 * Schema.h:
 * @code
 * #ifndef SCHEMA_H
 * #define SCHEMA_H
 *
 * #include <SqlSchema_p.h>
 *
 * #define MY_PROJECT_EXPORT
 *
 * // Tables will go here
 *
 * #define MY_SCHEMA
 *
 * DECLARE_SCHEMA(MySchema, MY_SCHEMA);
 *
 * #endif
 * @endcode
 *
 * Schema.cpp
 * @code
 * #include "Schema.h"
 *
 * DEFINE_SCHEMA(MY_SCHEMA);
 * @endcode
 *
 * MY_PROJECT_EXPORT should be the export macro of your project (if it's a
 * library)
 * You can of course rename MY_SCHEMA and MySchema to something else, but for
 * this tutorial these names will be used.
 *
 * To create your first table, exchange the comment in the header with the
 * following code:
 * @code
 * TABLE(Animals, MY_PROJECT_EXPORT) {
 *     SQL_NAME("Animals");
 *     ADMIN_GROUP("admins");
 *     USER_GROUP("users");
 *     NO_USER_DELETE;
 *     COLUMN(Name, QString, Sql::NotNull);
 *     typedef boost::mpl::vector<NameType> columns;
 * };
 * @endcode
 * and set change the define at the end of the header to the following:
 * @code
 * #define MY_SCHEMA (Animals)
 * @endcode
 *
 * Now lets go through that table and see what it does:
 * Firstly, we create a new table that will be available in C++ code
 * as @c Animals.
 * - In SQL, the table will be called @c Animals
 * - Users in the @c admins group will have administrator access to the table
 * - Users in the @c users group will not have this access, they can do basic
 * operations though
 * - @c NO_USER_DELETE says that users in the USER_GROUP will not be able to
 * delete from the table
 *   + There are other, similar options, including @c NO_USER_UPDATE,
 * @c O_USER_DELETE, @c NO_USER_INSERT and @c ONLY_USER_SELECT
 * - Then we tell the table we want 1 column named Name (this is the name used
 * both for SQL and C++). More on columns later.
 * - The typedef is just there for some template magic.
 *
 * @subsection columns_sec The COLUMN macro
 *
 * The syntax for this macro is as follows:
 * @code
 * COLUMN(name, type, flags, maxsize)
 * @endcode
 * @c name can be any name also valid in SQL and C++<br/>
 * @c type can be one out of many common C++ and Qt types,
 * including @c bool, @c int, @c floar, @c QString, @c QUuid, @c QDateTime,
 * @c QTime, @c QDate, and @c QByteArray<br/>
 * @c flags is used for specifying special properties for the column. The
 * available flags can be found in the @link Sql::ColumnProperties @endlink
 * enumeration
 *
 * Try to add a column that describes the age of the animal!
 *
 * @section query_builders_sec Query Builders
 *
 * Alright, now you have your table setup and ready, now lets use it.<br/><br/>
 * Query builders are classes that have several properties you can set, and
 * that then will give you a query, ready and prepared. See
 * @subpage cond_qb_page for how to create DELETE, SELECT and UPDATE
 * statements and @subpage insert_qb_page for how to create INSERT statements.
 *
 * Regardless of which query builder you use, you will always have to set the
 * table to operate on. You can do that using the
 * @link SqlQueryBuilderBase::setTable setTable@endlink function
 * @code
qb.setTable(Animals);
 * @endcode
 *
 * The available query builders are:
 * - SqlDeleteQueryBuilder (for DELETE statements) (@ref delete_qb_page)
 * - SqlInsertQueryBuilder (for INSERT statements) (@ref insert_qb_page)
 * - SqlSelectQueryBuilder (for SELECT statements) (@ref select_qb_page)
 * - SqlUpdateQueryBuilder (for UPDATE statements) (@ref update_qb_page)
 *
 * Once you have created your query builder (see above links), you want to
 * execute the query. To do that, you use the @c query function of the query
 * builder. This will give you an object of type SqlQuery.
 * @code
SqlQuery sqlquery = qb.query();
 * @endcode
 * This code will create the SQL query string, prepare the query, and return
 * the SqlQuery object. As SqlQuery is a subclass of QSqlQuery, you can then
 * call the bindValue method (and others) to bind values to any placeholders.
 * @warning NEVER cast SqlQuery to QSqlQuery, even though it's a subclass.
 * SqlQuery reimplements some functions which are non-virtual, and casting
 * would call the QSqlQuery variants.
 *
 * Once ready, just call @c exec:
 * @code
sqlquery.exec();
 * @endcode
 * This also checks some extra stuff, like if the database server still is
 * available. See @ref database_management_page for more information.
 *
 * After that call you can proced with processing the returned data like you
 * would with a QSqlQuery.
 *
 * @section in_depth_sec More in-depth information
 *
 * See @ref createtable_and_schemaupdater_page for how to create tables
 * defined using the TABLE macro, and for a nice way to update a database
 * schema to a new version.
 *
 * See @ref transactions_page for handling SQL transactions from C++ code.
 *
 * Take a look at @ref watchers_and_monitors_page for a signal and slots way
 * of getting change notifications and more.
 *
 */
