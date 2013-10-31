/*
    Copyright (C) 2011-2013 Klarälvdalens Datakonsult AB,
        a KDAB Group company, info@kdab.net,
        author Volker Krause <volker.krause@kdab.com>

    This library is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This library is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301, USA.
*/

#ifndef POSTGRESSCHEMA_H
#define POSTGRESSCHEMA_H

#include "SqlSchema_p.h"
#include "sqlate_export.h"

#include <QDateTime>

/**
 * Schema definition for the PostgreSQL system tables to the extend we need to access them
 * @note Do not use this in combination with the create table query builder!
 */
namespace Sql {

/// @ingroup schemaupdater_group
TABLE( PgUser, SQLATE_EXPORT ) {
    SQL_NAME( "pg_user" );
    COLUMN( usename, QString, Null );
    COLUMN( usesysid, int, Null );
    COLUMN( usecreatedb, bool, Null );
    COLUMN( usesuper, bool, Null );
    COLUMN( usecatupd, bool, Null );
    COLUMN( userepl, bool, Null );
    COLUMN( passwd, QString, Null );
    COLUMN( valuntil, QDateTime, Null );
    typedef boost::mpl::vector<usenameType, usesysidType, usecreatedbType, usesuperType, usecatupdType, usereplType, passwdType, valuntilType> columns;
};

/// @ingroup schemaupdater_group
TABLE( PgGroup, SQLATE_EXPORT ) {
    SQL_NAME( "pg_group" );
    COLUMN( groname, QString, Null );
    COLUMN( grosysid, int, Null );
    typedef boost::mpl::vector<gronameType, grosysidType> columns;
};

/// @ingroup schemaupdater_group
TABLE( PgAuthMembers, SQLATE_EXPORT ) {
    SQL_NAME( "pg_auth_members" );
    COLUMN( roleid, int, NotNull );
    COLUMN( member, int, NotNull );
    COLUMN( grantor, int, NotNull );
    COLUMN( admin_option, bool, NotNull );
    typedef boost::mpl::vector<roleidType, memberType, grantorType, admin_optionType> columns;
};

/// @internal
#define POSTGRES_SCHEMA (PgUser)(PgGroup)(PgAuthMembers)

/// @internal
DECLARE_SCHEMA( PostgresSchema, POSTGRES_SCHEMA );

}

#endif
