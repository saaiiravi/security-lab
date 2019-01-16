#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
void encryption(char *message, int key)
{
  char ch;

  for (int i = 0; message[i] != '\0'; ++i)
  {
    ch = message[i];
    if (ch >= 'a' && ch <= 'z')
    {
      ch = ch + key;
      if (ch > 'z')
        ch = ch - 'z' + 'a' - 1;
      message[i] = ch;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      ch = ch + key;
      if (ch > 'Z')
        ch = ch - 'Z' + 'A' - 1;
      message[i] = ch;
    }
  }
}

int main()
{
  int client_socket;
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  char cli[] = "hey from client";

  struct sockaddr_in address;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_family = AF_INET;
  address.sin_port = htons(3000);

  connect(client_socket, (struct sockaddr *)&address, sizeof(address));

  char response[256];

  printf("You: ");
  fgets(response, 100, stdin);
  encryption(response, 1);
  send(client_socket, &response, sizeof(response), 0);
}