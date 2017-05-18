
#include "include/dbms.h"

dbms::dbms() {
    //ctor
}

dbms::~dbms() {
    //dtor
}

bool dbms::connect() {
    try {
        /* Create a connection */
        this->driver = get_driver_instance();
        this->conn = driver->connect("tcp://127.0.0.1:3306", "root", "datastore");

        /* Connect to the MySQL test database */
        this->conn->setSchema("stockexchangedb");
        
    } catch (sql::SQLException &e) {
        cout << "# ERR: " << e.what();
    }
}

void dbms::disconnect() {
    this->conn->close();
    delete this->conn;
    this->conn = nullptr;
}

void dbms::execute_query(char* sql_statement) {
    try {
        this->stmt = this->conn->createStatement();
        this->res = this->stmt->executeQuery(sql_statement);
        delete this->res;
        delete this->stmt;
    } catch (sql::SQLException &e) {
        cerr << e.what() << std::endl;
    }
}


void dbms::select(char* sql_statement) {
    try {
        this->stmt = this->conn->createStatement();
        this->res = this->stmt->executeQuery(sql_statement);
        while (res->next()) {
            cout << this->res->getString(1) << endl;
        }
        delete this->res;
        delete this->stmt;
    } catch (sql::SQLException &e) {
        cerr << e.what() << std::endl;
    }
}

