#inlcude "unp.h"


int
main(int argc,char **argv)
{
	int sockfd,n;
	char recvline[MAXLINE+1];
	struct sockaddr_in servaddr;
	struct in_addr **pptr;
	struct in_addr *inetaddrp[2];
	struct in_addr inetaddr;
	struct hostent *hp;
	struct servent *sp;


	if (argc != 3) 
		err_quit(" usage:datimetcpcli1 <hostname> <service>");

	if ( (hp = gethostbyname(argv[1])) == NULL) {
		if (inet_aton(argv[1],&inetaddr) == 0) {
			err_quit("hostname error for %s:%s \n",argv[1],
						hsterror(h_errno));
		} else {
		    inetaddrp[0] = &inetaddr;
			inetaddrp[1] = NULL;
			pptr = inetaddrp;
		}
	} else {
        pptr = (in_addr **)hp->h_addr_list;
	}

	if ( (sp = getservbyname(argv[2],"tcp")) == NULL)
		err_quit("getservbyname error for %s ",argv[2]);

	
}
