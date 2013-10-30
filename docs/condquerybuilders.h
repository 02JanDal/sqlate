/**
 * @page cond_qb_page Conditional Query Builders
 *
 * For query types where you have some type of WHERE part, you will meet the
 * SqlConditionalQueryBuilderBase. The important function here is
 * @link SqlConditionalQueryBuilderBase::whereCondition whereCondition@endlink,
 * which gives you access to a SqlCondition reference. This SqlCondition can
 * then be used for constructing your WHERE part.
 *
 * Query builders which this applies to:
 * - @subpage delete_qb_page
 * - @subpage select_qb_page
 * - @subpage update_qb_page
 *
 * @section sqlcondition_sec How to use the SqlCondition
 *
 * @subsection sqlcondition_logic_operator_sec Logic Operators (AND and OR)
 * The first important part about SqlCondition is that you have to look out for
 * which logic operator currently is in use, AND or OR. Following are some ways
 * of setting the logic operator to use
 * @code
// pass to constructor
SqlCondition cond1(SqlCondition::And);
SqlCondition cond2(SqlCondition::Or);

// setter function
cond1.setLogicOperator(SqlCondition::Or);
cond2.setLogicOperator(SqlCondition::And);
 * @endcode
 *
 * @note Only one (1) logic operator can be used per SqlCondition. See
 * @ref sqlcondition_sub_cond_sec for combining different operators.
 *
 * @subsection sqlcondition_add_col_sec Adding values and columns to check for
 *
 * Adding columns:
 * @code
// will create WHERE surname = forename
cond.addColumnCondition("surname", SqlCondition::Equals, "forename");
cond.addColumnCondition(Person.Surname, SqlCondition::Equals, Person.Forename);
 * @endcode
 * @note For the second statement to compile, both columns need to be of the
 * same type
 *
 * Adding value conditions:
 * @code
// will create WHERE age < 18
cond.addValueCondition("age", SqlCondition::Less, 18);
cond.addValueCondition(Person.Age, SqlCondition::Less, 18);
 * @endcode
 * @note For the second statement to compile, the value must the of the same type as the
 * column
 *
 * If you don't know the value yet you might want to use a place holder:
 * @code
// will create WHERE surname <> :surname
cond.addPlaceholderCondition("surename", SqlCondition::NotEquals, ":surname");
cond.addPlaceholderCondition(Person.Surname, SqlCondition::NotEquals, ":surname");
 * @endcode
 *
 * Other operators can be found in the @link SqlCondition::CompareOperator@endlink
 * enumeration.
 *
 * @subsection sqlcondition_sub_cond_sec Sub-conditions
 *
 * Using the above you can now create basic conditions, like the following:
 * @code
WHERE surname = :surname AND forename = :forename
 * @endcode
 * While nice, it's still a long way from usable for all cases. What if we want
 * to only check the surname if the age is over 18? We want something like
 * this:
 * @code
WHERE forename = :forename AND (age < 18 OR forename = :forename)
 * @endcode
 * With this, if the age is under 18, the condition in the parentheses evaluates
 * to true, regardless of the surname. But how can we express that in code?
 * We can start by creating two SqlConditions, on for the parentheses and one
 * for the outside (forename):
 * @code
SqlCondition outer(SqlCondition::And);
outer.addPlaceholderCondition(Person.Forename, SqlCondition::Equals, ":forename");

SqlCondition parentheses(SqlCondition::Or); // <- this the the expression inside of the parentheses
parentheses.addValueCondition(Person.Age, SqlCondition::Less, 18);
parentheses.addPlaceholderCondition(Person.Surname, SqlCondition::Equals, ":surname");
 * @endcode
 * So far so good? Now lets combine them, it's actually really easy:
 * @code
outer.addCondition(paranthese);
 * @endcode
 * Done! This way, you could potentionally create nested conditions with many
 * hundred levels, all with different logic operators.
 *
 * @section sqlcondition_example_sec Example of usage
 *
 * You now know how to create a SqlCondition object, and how to create (nested)
 * conditions using it. Now, to use the above code on a query, use the
 * following code:
 * @code
SqlSelectQueryBuilder qb;
qb.whereCondition().setLogicOperator(SqlCondition::And);
qb.whereCondition().addPlaceholderCondition(Person.Forename, SqlCondition::Equals, ":forename");

SqlCondition parentheses(SqlCondition::Or);
parentheses.addValueCondition(Person.Age, SqlCondition::Less, 18);
parentheses.addPlaceholderCondition(Person.Surname, SqlCondition::Equals, ":surname");

qb.whereCondition().addCondition(paranthese);
 * @endcode
 *
 */
