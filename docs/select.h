/**
 * @page select_page select(...).from(...)
 *
 * Using this syntax allows you to create both readable and type-safe queries
 * from C++.
 *
 * Start by including the right header:
 * @code
#include <SqlSelect.h>
 * @endcode
 * and by defining your table (see @ref getting_started_page).
 *
 * Then, to get started building your query in a bit more explaining way, start
 * with the following:
 * @code
select(Animals.Name).from(Animals)
 * @endcode
 * The arguments to @c select should be the columns to select from (may be from
 * different tables in case of joins), and the argument to @c from should be
 * the main table to select from. This would create the query
 * @c SELECT @c Animals.Name @c FROM @c Animals.
 *
 * You can then start to build on to that, appending stuff. Once you have your
 * statement finished you can go to @ref select_wrapping_up_sec.
 *
 * @section select_where_sec .where()
 *
 * For the WHERE clause, use the following code:
 * @code
select(Animals.Name).from(Animals).where(Animals.Age < 18)
 * @endcode
 * Inside the @c where function you can use columns (defined using the COLUMN
 * macro), values and placeholders, and also normal operators like && (AND),
 * || (OR), the common logic operators (<, <=, >, >=, ==, !=) and also some
 * C++ functions like @c isNull, @c isNotNull and @c like. You can also use
 * parantheses to created nested statements.
 *
 * @section select_join_sec .join()
 *
 * For the JOIN part, it's just as easy and convenient:
 * @code
select(Animals.Name, Owners.Name).from(Animals).innerJoin(Owners, Owners.Name = Animals.OwnerName)
 * @endcode
 * The first argument to the innerJoin function should be the table to join,
 * and the second argument is what goes into the @c ON part. Here you can use
 * the same stuff like in the @ref select_where_sec function.
 *
 * There are several joins available:
 * - innerJoin
 * - leftOuterJoin
 * - rightOuterJoin
 * - fullOuterJoin
 * - crossJoin
 * They are all used the same way.
 *
 * You can add as many of these to one select(...).from(...) as you want.
 *
 * @section select_group_by_sec .groupBy()
 * @code
select(Animals.Name).from(Animals).groupBy(Animals.Age, Animals.Name)
 * @endcode
 *
 * @section select_order_by_sec .orderBy()
 * @code
select(Animals.Name).from(Animals).orderBy(Animals.Age, Qt::Ascending)
 * @endcode
 *
 * @section select_wrapping_up_sec Wrapping up
 *
 * Once you have created your query this way, just assign it to a SqlQuery:
 * @code
SqlQuery myQuery = select(Animals.Name).from(Animals);
 * @endcode
 * You can then bind values and execute it like normal.
 *
 */
