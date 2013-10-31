/**
 * @page functionqueries_page Function Style Queries
 *
 * On very nice thing included in SQLate are function style queries, that let
 * you write code like the following:
 * @code
SqlQuery myQuery = select(Animals.Name).from(Animals).where(Animals.Age < 5).queryBuilder().query();
 * @endcode
 *
 * Of course you have type checking etc.
 *
 * The operations currently supporting this type of query building:
 * - @subpage select_page
 *
 */
