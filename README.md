# C-HTTP-SERVER (WIP)
While I understand most people find the idea of an HTTP server outdated, but I believe the core and low level concepts I would learn when developing my own project are very important to my cybersecurity journey. So in this project I will be building an HTTP server from scratch in the C programming language to work on my network and low level programming.

## HOW I STARTED MY PROJECT:
This is a project that was suggested to me by multiple people and sources, and while I do have a relatively good understanding of the C programming language, I have never done any network programming in it. So I am starting this project off by researching the networking side of this project first. 
### UNDERSTATING HTTP:
I started my development journey by reading the HTTP standard itself, specifically RFC 1945. I have learned about this protocol prior to this project but wanted to read the documentation as a reminder. I have included a link to the source I used, but will state my findings first.   
HTTP uses a request/response system, where a client(request senders) establishes a connection by sending a request to the server containing information, the server can then respond with success or error code. I will break down what each of the transactions look like.   
**HTTP Request:**
- Request Line: `METHOD URI(uniform resource identifier) HTTP/1.0`(for example: `GET /hello.html HTTP/1.0`)
- Request Headers: these are optional and include headers like `Host` or `User-Agent` that provide metadata and more control.
- Empty Line
- Request Body: this is also optional and is used mainly for `POST` and `PUT`.
**HTTP Response:**   
- Status Line: `HTTP/1.0 STATUS_CODE PHRASE`(for example: `HTTP/1.0 200 OK`)
- Response Headers: includes fields like `Content-Type`, `Content-Length`, `Date`
- Empty Line
- Response Body: includes the requested file

I mentioned some of the standard HTTP methods and status codes above, so next we will go over those.   
**HTTP Methods:**   
Methods let clients express different intentions to the server beyond just fetching files.
- `GET`: retrieves a resource
- `POST`: sends data to be processed by the server
- `HEAD`: similar to `GET`, but does not include a body, only headers
- `PUT`: store or replace a resource at a given URI
- `DELETE`: remove a specified resource

**Status Codes**   
Status codes are sent back by the server in the HTTP response to tell the client what happened with the request. HTTP classifies these status codes into 5 categories: *Informational - 1xx*, *Success - 2xx*, *Redirection - 3xx*, *Client Error - 4xx*, and *Server Error - 5xx*.   
**Informational**:   
I wanted to include these codes because while they are not used in HTTP/1.0, they can be used in experimental applications.   
**Successful**:   
client request is successfully received, understood, and accepted.
- `200 OK`: the request was successful and the information sent back is dependent on the request method used
- `201 CREATED`: the request was successful and a new resource was created
- `202 ACCEPTED`: the request was accepted but still needs to be processed by the server, which could result in
- `204 No Content`: the server completed the request but does not have any information to send back

**Redirection**:
- `3xx`

**Client Error**:
- `4xx`

**Server Error**:
- `5xx`


- Hypertext Transfer Protocol -- HTTP/1.0: https://datatracker.ietf.org/doc/html/rfc1945

### UNDERSTANDING SOCKETS:
- Beej's Guide to Network Programming: https://beej.us/guide/bgnet/

