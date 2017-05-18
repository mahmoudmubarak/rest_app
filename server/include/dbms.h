
#ifndef DBMS_H
#define DBMS_H

#include <iostream>
#include <exception>

#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;
using namespace sql;

class dbms {
public:
    dbms();
    virtual ~dbms();
    bool connect();
    void disconnect();
    void select(char* sql);
    void execute_query(char* sql);

protected:
    void query_normal();
    void query_prepared();

private:
    sql::Driver *driver = nullptr;
    sql::Connection *conn = nullptr;
    sql::Statement *stmt = nullptr;
    sql::ResultSet *res = nullptr;


};

#endif /* DBMS_H */

