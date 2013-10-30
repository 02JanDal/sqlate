/**
 * @page update_qb_page Update Query Builder
 *
 * See @ref cond_qb_page for instructions regarding the WHERE part of the
 * UPDATE statement.
 *
 * The SqlUpdateQueryBuilder provides one function (and some overloads)
 * for setting which values the query will set, called
 * @link SqlUpdateQueryBuilder::addColumnValue addColumnValue@endlink.
 *
 * The basic usage of this function is
 * @code
 * addColumnValue("sql_column_name", value);
 * @endcode
 *
 * Now, to make use of the tables created with the TABLE macro, you will
 * probably want to use on of the overloads. We then can use the
 * @link SqlUpdateQueryBuilder::query query@endlink function to retrieve our
 * query.<br/>
 * Using the table created in the @ref getting_started_page guide, we could
 * use the following code to celebrate the 5th birthday of our animal:
 * @code
 * SqlUpdateQueryBuilder qb;
 * qb.addColumnValue(Animals.Age, 5);
 * qb.query().exec();
 * @endcode
 * Not a single string, nice right?
 * You could now go ahead and add more values to set.
 *
 */
