#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <unistd.h>

void main() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  
  struct sockaddr_in addr = {
    AF_INET,
    0x901f,
    0
  };
  
  bind(sock, &addr, sizeof(addr));
  
  listen(sock, 10);
  
  int client_fd = accept(sock, 0, 0);
  
  char buffer[256] = {0};
  recv(client_fd, buffer, 256, 0);
  
  char* file = buffer + 5;
  *strchr(file, ' ') = 0;
  int opened_fd = open(file, O_RDONLY);
  sendfile(client_fd, opened_fd, 0, 256);
  close(opened_fd);
  close(client_fd);
  close(sock);
}
