/**
 * @page select_qb_page Select Query Builder
 *
 * See @ref cond_qb_page for instructions regarding the WHERE part of the
 * SELECT statement.
 *
 * @section add_columns_sec Choosing which columns to select
 * Use @link SqlSelectQueryBuilder::addColumn addColumn@endlink to add a column
 * to select. Here are some variants of the function (using the Animals
 * table):
 * @code
qb.addColumn("Age"); // = SELECT Age FROM...
qb.addColumn(Animals.Age); // = SELECT Age FROM...
qb.addColumn("Age", "age"); // = SELECT Age AS age FROM...
qb.addColumn(Animals.Age, "age"); // = SELECT Age AS age FROM...

// you could also use the following for SELECT * FROM...
qb.addAllColumns();
 * @endcode
 *
 * @section joins_sec JOIN
 * For creating JOIN statements, use @link SqlSelectQueryBuilder::addJoin
 * addJoin@endlink. Some ways of doing that:
 * @code
// all of these will add INNER JOIN Owners ON Owners.Name = Animals.OwnerName

SqlCondition condition;
condition.addColumnCondition("Owners.Name", SqlCondition::Equals, "Animals.OwnerName");
// or:
condition.addColumnCondition(Owners.Name, SqlCondition::Equals, Animals.OwnerName);
qb.addJoin(SqlSelectQueryBuilder::InnerJoin, "Owners", condition);
qb.addJoin(SqlSelectQueryBuilder::InnerJoin, Owners, condition);
qb.addJoin(SqlSelectQueryBuilder::InnerJoin, "Owners", "Owners.Name", "Animals.OwnerName");
qb.addJoin(SqlSelectQueryBuilder::InnerJoin, Owners, "Owners.Name", "Animals.OwnerName");

// excerise: which one should you use?
 * @endcode
 *
 * You can take a look at @ref cond_qb_page for more information on how to use the SqlCondition
 *
 * @section order_group_limit_sec Sorting, Grouping and Limiting
 * For customizing what you get from a database query, you might want to choose
 * to sort the results, to group them and maybe to limit the number of
 * results.
 *
 * @subsection order_by_sec ORDER BY Age DESC
 * @code
qb.addSortColumn("Age", Qt::Descending);
qb.addSortColumn(Animals.Age, Qt::Descending);
 * @endcode
 *
 * @subsection group_by_sec GROUP BY Name
 * @code
qb.addGroupColumn("Name");
qb.addGroupColumn(Animals.Name);
 * @endcode
 *
 * @subsection limit_sec OFFSET 5 LIMIT 10
 * @code
qb.addLimit(5, 10);
 * @endcode
 *
 * @section finished_query_sec Finished Query
 *
 * Both of the following code snippets will produce the following SQL query:
 * @code
SELECT Animals.Name, Animals.Age AS age FROM Animals INNER JOIN Owners ON Owners.Name = Animals.OwnerName ORDER BY Animals.Age DESC GROUP BY Animals.Name OFFSET 5 LIMIT 10
 * @endcode
 *
 * @code
SqlSelectQueryBuilder qb;
qb.setTable(Animals);

qb.addColumn(Animals.Name);
qb.addColumn(Animals.Age, "age");

SqlCondition condition;
condition.addColumnCondition(Owners.Name, SqlCondition::Equals, Animal.OwnerName);
qb.addJoin(SqlSelectQueryBuilder::InnerJoin, Owners, condition);

qb.addSortColumn(Animals.Age, Qt::Descending);
qb.addGroupColumn(Animals.Name);
qb.addLimit(5, 10);
 * @endcode
 *
 * @code
SqlSelectQueryBuilder qb;
qb.setTable("Animals");

qb.addColumn("Animals.Name");
qb.addColumn("Animals.Age", "age");

SqlCondition condition;
condition.addColumnCondition("Owners.Name", SqlCondition::Equals, "Animal.OwnerName");
qb.addJoin(SqlSelectQueryBuilder::InnerJoin, "Owners", condition);

qb.addSortColumn("Animals.Age", Qt::Descending);
qb.addGroupColumn("Animals.Name");
qb.addLimit(5, 10);
 * @endcode
 *
 * Now take a look at both of the above code snippets. There is a typo in each
 * of them, at the same place in both. But the first snippet won't compile
 * because of that. Typo found, typo fixed, nice!
 */
