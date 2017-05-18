
#include "include/service.h"
#include "include/service_handler.h"

using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

unique_ptr<service_handler> g_httpHandler;

int main(int argc, char** argv) {

    utility::string_t port = U("3000");

    utility::string_t address = U("http://localhost:");
    address.append(port);

    uri_builder uri(address);
    auto addr = uri.to_uri().to_string();
    g_httpHandler = unique_ptr<service_handler>(new service_handler(addr));
    g_httpHandler->open().wait();
    ucout << utility::string_t(U("Listening for requests at: ")) << addr << endl;
    
    cout << "Press ENTER to exit." << endl;
    string line;
    getline(cin, line);
    
    g_httpHandler->close().wait();

    return 0;
}