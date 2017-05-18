
#include "include/service_handler.h"

service_handler::service_handler() {
    //ctor
}

service_handler::service_handler(utility::string_t url) : m_listener(url) {
    m_listener.support(methods::GET, std::bind(&service_handler::handle_get, this, std::placeholders::_1));
//    m_listener.support(methods::PUT, std::bind(&service_handler::handle_put, this, std::placeholders::_1));
//    m_listener.support(methods::POST, std::bind(&service_handler::handle_post, this, std::placeholders::_1));
//    m_listener.support(methods::DEL, std::bind(&service_handler::handle_delete, this, std::placeholders::_1));

}

service_handler::~service_handler() {
    //dtor
}

void service_handler::handle_error(pplx::task<void>& t) {
    try {
        t.get();
    }    catch (...) {
        // Ignore the error, Log it if a logger is available
    }
}


//
// Get Request 
//

void service_handler::handle_get(http_request message) {
    ucout << message.to_string() << endl;

    auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));

    message.relative_uri().path();
    
    dbms* db  = new dbms();
    db->connect();

//    concurrency::streams::fstream::open_istream(U("static/index.html"), std::ios::in).then([ = ](concurrency::streams::istream is){
//        message.reply(status_codes::OK, is, U("text/html"))
//        .then([](pplx::task<void> t) {
//            try {
//                t.get();
//            } catch (...) {
//                //
//            }
//        });
//    }).then([ = ](pplx::task<void>t){
//        try {
//            t.get();
//        } catch (...) {
//            message.reply(status_codes::InternalError, U("INTERNAL ERROR "));
//        }
//    });

    return;

};

////
//// A POST request
////
//
//void service_handler::handle_post(http_request message) {
//    ucout << message.to_string() << endl;
//
//
//    message.reply(status_codes::OK, message.to_string());
//    return;
//};
//
////
//// A DELETE request
////
//
//void service_handler::handle_delete(http_request message) {
//    ucout << message.to_string() << endl;
//
//    string rep = U("WRITE YOUR OWN DELETE OPERATION");
//    message.reply(status_codes::OK, rep);
//    return;
//};
//
//
////
//// A PUT request 
////
//
//void service_handler::handle_put(http_request message) {
//    ucout << message.to_string() << endl;
//    string rep = U("WRITE YOUR OWN PUT OPERATION");
//    message.reply(status_codes::OK, rep);
//    return;
//};
