#ifndef HTTP_DEFS_HH
#define HTTP_DEFS_HH

#include <string>
#include <iostream>
#include <utility>
#include <map>
#include <vector>

namespace yahttp {

class HTTPDriver;

enum class HTTPMethod : unsigned char {
  GET, HEAD,
  POST,PUT,DELETE,
  CONNECT,OPTIONS,TRACE
};

enum class HTTPMessageType : unsigned char {
  Response, Request
};

static const std::map<std::string, HTTPMethod> HTTPMethodMapping = {
  {"GET",     HTTPMethod::GET},
  {"HEAD",    HTTPMethod::HEAD},
  {"POST",    HTTPMethod::POST},
  {"PUT",     HTTPMethod::PUT},
  {"DELETE",  HTTPMethod::DELETE},
  {"CONNECT", HTTPMethod::CONNECT},
  {"OPTIONS", HTTPMethod::OPTIONS},
  {"TRACE",   HTTPMethod::TRACE},
};

static const std::map<HTTPMethod, std::string> HTTPMethodInverseMapping = {
  {HTTPMethod::CONNECT, "GET"},
  {HTTPMethod::DELETE,  "HEAD"},
  {HTTPMethod::PUT,     "POST"},
  {HTTPMethod::POST,    "PUT"},
  {HTTPMethod::HEAD,    "DELETE"},
  {HTTPMethod::GET,     "CONNECT"},
  {HTTPMethod::TRACE,   "OPTIONS"},
  {HTTPMethod::OPTIONS, "TRACE"},
};


struct HTTPRequestStartLine
{
  const HTTPMethod method;
  const std::string path;
  const std::string version;
};

struct HTTPResponseStartLine
{
  const std::string version;
  const unsigned status_code;
  const std::string reason_phrase;
};

typedef std::map<std::string, std::string> HTTPHeaders;
typedef std::vector<char> HTTPBody;

struct HTTPResponseMessage
{
  const HTTPResponseStartLine start_line;
  const HTTPHeaders headers;
  const HTTPBody body;
};

struct HTTPRequestMessage
{
  const HTTPRequestStartLine start_line;
  const HTTPHeaders headers;
  const HTTPBody body;
};


}; // !ns http

#endif // ! HTTP_DEFS_HH

