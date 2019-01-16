#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

void decryption(char *message, int key)
{
  char ch;
  for (int i = 0; message[i] != '\0'; ++i)
  {
    ch = message[i];
    if (ch >= 'a' && ch <= 'z')
    {
      ch = ch - key;
      if (ch < 'a')
        ch = ch + 'z' - 'a' + 1;
      message[i] = ch;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      ch = ch + key;
      if (ch < 'A')
        ch = ch + 'Z' - 'A' + 1;
      message[i] = ch;
    }
  }
}

int main()
{
  int socket_server;
  socket_server = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3000);

  bind(socket_server, (struct sockaddr *)&server_address, sizeof(server_address));

  listen(socket_server, 5);

  int client_socket;
  client_socket = accept(socket_server, NULL, NULL);

  //char message[] = "hello";
  //char buff[100];
  char response[256];

  recv(client_socket, response, sizeof(response), 0);
  printf("Encrypted message: %s", response);
  decryption(response, 1);
  printf("Cilent : %s", response);

  close(client_socket);

  return 0;
}