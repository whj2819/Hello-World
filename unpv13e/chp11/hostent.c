#include "unp.h"

int
main(int argc,char**argv)
{
    char *ptr,**pptr;
	char str[INET_ADDRSTRLEN];
	struct hostent *hptr;

	while (--argc > 0) {
        ptr = *++argv;
		if ((hptr = gethostbyname(ptr)) == NULL) {
             err_msg("gethostbyname error for host:%s: %s",
			 	ptr,hstrerror(h_errno));
			 continue;
		}
		printf("offical hostname:%s\n",hptr->h_name);

		for(pptr = hptr->h_aliases; pptr != NULL; pptr++) 
	        printf("\t alias:%s \n",*pptr);

		switch (hptr->h_addrtype) {
		case AF_INET:
			pptr = hptr->h_addr_list;
			for (;pptr != NULL; pptr++)
				printf("\t address: %s \n",
				    Inet_ntop(hptr->h_addrtype,*pptr,str,sizeof(str)));
		    break;
		default:
			break;
		}
	}

	exit(0);
}
