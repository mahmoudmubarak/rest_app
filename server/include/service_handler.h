
#ifndef SERVICE_HANDLER_H
#define SERVICE_HANDLER_H

#include "service.h"
#include "dbms.h"

using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

class service_handler
{
    public:
        service_handler();
        service_handler(utility::string_t url);
        virtual ~service_handler();

        pplx::task<void>open(){return m_listener.open();}
        pplx::task<void>close(){return m_listener.close();}

    protected:

    private:
        void handle_get(http_request message);
//        void handle_put(http_request message);
//        void handle_post(http_request message);
//        void handle_delete(http_request message);
        void handle_error(pplx::task<void>& t);
        http_listener m_listener;
};

#endif /* SERVICE_HANDLER_H */

