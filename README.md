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

<details>   
<summary>Click here for more details on each code.</summary>   
  
**Successful**:   
client request is successfully received, understood, and accepted.
- `200 OK`: the request was successful and the information sent back is dependent on the request method used
- `201 CREATED`: the request was successful and a new resource was created
- `202 ACCEPTED`: the request was accepted but still needs to be processed by the server, which could result in
- `204 NO CONTENT`: the server completed the request but does not have any information to send back
**Redirection**:   
Further action needs to be taken by the client in order to complete the request.
- `300 MULTIPLE CHOICES`: Not directly used by HTTP/1.0 but is used to interpret redirection responses
- `301 MOVED PERMANENTLY`: the requested resource has been moved to a new permanent URL and should be accessed there
- `302 MOVED TEMPORARILY`: the requested resource has been moved to a temporary URL and should be accessed through the current access point
- `304 NOT MODIFIED`: the client has performed a conditional GET request, but the document has not been modified since the date and time specified in the If-Modified-Since field, the server must respond with this status code and not send an Entity-Body to the client
**Client Error**:   
Occurs when the client errors and cannot complete the request, the client will immediately cease all data transmission.
- `400 BAD REQUEST`: The request was not understood by the server due to malformed request syntax
- `401 UNAUTHORIZED`: The request requires client authentication and results in a response containing a WWW-Authenticate header field
- `403 FORBIDDEN`: The server received the request but won't complete it, a reason can be stated or not given.
- `404 NOT FOUND`: The requested URI was not found by the server.
**Server Error**:   
The server is unable to complete the request.
- `500 INTERNAL SERVER ERROR`: The server was unable to complete the request due to an unexpected condition.
- `501 NOT IMPLEMENTED`: The server does not support the functionality to complete the request, often sent in response to unknown request methods.
- `502 BAD GATEWAY`: A proxy/gateway server received an invalid response from an upstream server while trying to fulfill the request.
- `503 SERVICE UNAVAILABLE`: The server is currently down and unable to handle the request due to maintenance or overload. The situation should be temporary.   
  
</details>
- Hypertext Transfer Protocol -- HTTP/1.0: https://datatracker.ietf.org/doc/html/rfc1945

### UNDERSTANDING SOCKETS:
- Beej's Guide to Network Programming: https://beej.us/guide/bgnet/

