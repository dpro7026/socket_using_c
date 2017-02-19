#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){
  //create a socket(domain, type_of_socket)
  //we will use tcp
  int network_socket;
  network_socket = socket(AF_INET, SOCK_STREAM, 0);

  //specofy an sddres for the socket
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;

  int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  //check for error with connection
  if(connection_status == -1){
    printf("There was an error making a connection to the remote socket \n\n");
  }else{
    printf("Connection successful... \n");
  }

  //recieve data from the server_address
  char server_response[256];
  recv(network_socket, &server_response, sizeof(server_response), 0);

  //print out the server's response
  printf("The server sent the data: %s\n", server_response);

  //close the socket
  close(network_socket);

  return 0;
}
