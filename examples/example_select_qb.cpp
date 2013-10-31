#include <SqlSelectQueryBuilder.h>
#include <SqlSchema.h>
#include <QDate>

using namespace Sql;

/* The EXPORT macro should normally be the export macro used for classes in
 * case you are creating a library
 */
#define EXPORT
// Defining of a table
TABLE(MyTable, EXPORT)
{
    // The name the table is referenced with from SQL
    SQL_NAME("mytable");
    // Users in this group will have normal access (SELECT, INSERT, UPDATE etc.)
    USER_GROUP("users");
    // Users in this group will have some more privileges
    ADMIN_GROUP("admins");
    // Users will only be able to SELECT from this table
    ONLY_USER_SELECT;
    // The colums
    COLUMN(id, int, Sql::NotNull | Sql::PrimaryKey);
    COLUMN(name, QString, Sql::NotNull);
    COLUMN(born, QDate, Sql::NotNull);
    /* Do not care about this to much. The only thing you need to do is to make
     * sure that all your columns are in the list, suffixed with "Type".
     * If you would add a gender column, the following line would look like this:
     * typedef boost::mpl::vector<idType, nameType, bornType, genderType> columns
     */
    typedef boost::mpl::vector<idType, nameType, bornType> columns;
};
/* The following define is just there to reduce typos (as we need exactly the
 * same list of tables for both DECLARE_SCHEMA and DEFINE_SCHEMA.
 */
#define SCHEMA (MyTable)
DECLARE_SCHEMA(Schema, SCHEMA);
// This would normally go into your source file
DEFINE_SCHEMA(SCHEMA);

int main(int argc, char **argv)
{
    // Just open a database connection like usual
    QSqlDatabase db = QSqlDatabase::addDatabase(QLatin1String("QPSQL"));
    db.setDatabaseName(QLatin1String("sqlate"));
    db.setUserName(QLatin1String("sqlate.user"));
    db.setPassword(QLatin1String("sql123456"));
    db.setHostName(QLatin1String("localhost"));
    Q_ASSERT(db.open());

    // Now the fun starts:
    SqlSelectQueryBuilder qb(db);
    // Sets the FROM table
    qb.setTable(MyTable);
    // Adds some columns (with AS)
    qb.addColumn(MyTable.id, QLatin1String("Id"));
    qb.addColumn(MyTable.name, QLatin1String("Name"));

    // Add a placeholder condition. You will have to bind a value here before executing.
    qb.whereCondition().addPlaceholderCondition(MyTable.born, SqlCondition::Less, QLatin1String(":date"));
    // Just bind a value
    qb.whereCondition().addValueCondition(MyTable.name, SqlCondition::GreaterOrEqual, QLatin1String("G"));

    /* The above code would generate the following query:
     * SELECT mytable.id AS Id, mytable.name AS Name FROM mytable WHERE mytable.born < :date AND mytable.name >= 'G'
     */

    /* Finally, we let the query builder create our query using the query
     * function. We can then prepare the query and bind any values we want
     * and finally execute it. Then we just loop through the result and output
     * it. This part of the code is very similar to how you would do it using
     * QSqlQuery.
     */
    SqlQuery query = qb.query();
    query.bindValue(QLatin1String(":date"), QDate(2000, 1, 1));
    query.exec();
    while (query.next()) {
        qDebug() << "Id:" << query.value(0).toInt() << "Name:" << query.value(1).toString();
    }

    return 1;
}
