#include	<netinet/in.h>
#include	<stdlib.h>
#include	<string.h>
#include	<arpa/inet.h>
#include	<sys/socket.h>
#include	<stdio.h>
#include	<unistd.h>

int main()
{
	int sockfd, i = 0;
    char file_name[20], ch, str[200];
	struct sockaddr_in serv_addr;
    FILE *fp;

    printf ("Enter the name of the file to be retrieved - ");
    scanf ("%s", file_name);
    printf("%s", file_name);
    fp = fopen(file_name, "r");
    
//    while (fscanf (fp, "%s", str) !=EOF) {
  //      printf("%s", str);
    //}

	bzero ((char*)&serv_addr, sizeof (serv_addr));
	serv_addr.sin_family 	= AF_INET;
    serv_addr.sin_addr.s_addr	= inet_addr ("127.0.0.1");
	serv_addr.sin_port	= htons (2345);

	sockfd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

	connect (sockfd, (struct sockaddr*)&serv_addr, sizeof (serv_addr));

	char data[4000] = {0};
    char contents[200] = "Jai Sri Ram !!!";
    write (sockfd, file_name, 200);
	read (sockfd, data, 100);
	printf ("%s", data);
	close (sockfd);
	exit (0);
	return 0;	
}
