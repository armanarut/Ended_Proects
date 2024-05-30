#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

char buff[200100];
int arr[65000];
fd_set aset, rset, wset;
int max_fd;
int sockfd;

void fatal(char *err)
{
	if (sockfd > 2)
		close (sockfd);
	write(2, err, strlen(err));
	exit(1);
}

void send_msg(int connfd)
{
	for(int fd = 2; fd <= max_fd; ++fd)
		if (fd != connfd && FD_ISSET(fd, &wset))
			if (send(fd, buff, strlen(buff), 0) < 0)
				fatal("Fatal error\n");
}

int main(int av, char *ac[]) {
	if(av < 2)
		fatal("Wrong number of arguments\n");

	int connfd;
	socklen_t len;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) 
		fatal("Fatal error\n");
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(ac[1])); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) 
		fatal("Fatal error\n");
	if (listen(sockfd, 10) != 0)
		fatal("Fatal error\n");

	FD_ZERO(&aset);
	FD_ZERO(&rset);
	FD_ZERO(&wset);
	FD_SET(sockfd, &aset);
	max_fd = sockfd;
	len = sizeof(cli);
	int id = 0;

	while (1) {
		rset = wset = aset;
		if (select(max_fd + 1, &rset, &wset, 0, 0) < 0)
			continue ;
		if (FD_ISSET(sockfd, &rset)) {
			connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
			if (connfd < 0) 
				fatal("Fatal error\n");
			sprintf(buff, "server: client %d just arrived\n", id);
			FD_SET(connfd, &aset);
			arr[connfd] = id++;
			send_msg(connfd);
			max_fd = connfd > max_fd ? connfd : max_fd;
			continue ;
		}
		for(int fd = 2; fd <= max_fd; ++fd) {
			if (FD_ISSET(fd, &rset)) {
				int ret = 1;
				char msg[200000];
				bzero(&msg, sizeof(msg));
				while (ret == 1 && msg[strlen(msg) - 1] != '\n')
					ret = recv(fd, msg + strlen(msg), 1, 0);
				if (ret <= 0) {
					FD_CLR(fd, &aset);
					close(fd);
					sprintf(buff, "server: client %d just left\n", arr[fd]);
				}
				else
					sprintf(buff, "client %d: %s", arr[fd], msg);
				send_msg(fd);
			}
		}
	}
}