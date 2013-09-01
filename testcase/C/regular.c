#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>


int
main(void)
{
	char *bematch = "hhhericchd@gmail.com";
	char *pattern = "h{3,10}(.*)@.{5}.(.*)";

	char errbuf[1024] = {0};
	char match[100] = {0};

	int err = 0, nm = 10;
	int i = 0, len = 0;

	regex_t reg;
	regmatch_t pmatch[nm];

	if (regcomp(&reg, pattern, REG_EXTENDED) < 0) {
		regerror(err, &reg, errbuf, sizeof(errbuf));
        printf("err:%s \n",errbuf);
	}

	err = regexec(&reg, bematch, nm, pmatch, 0);

	if (err == REG_NOMATCH) {
		printf("not match \n");
		return -1;
	} else if(err) {
	    printf("err :%s \n", errbuf);
		regerror(err, &reg, errbuf, sizeof(errbuf));
		return -1;
	}


	for (i=0; i<nm && pmatch[i].rm_so != -1; i++) {
		len = pmatch[i].rm_eo - pmatch[i].rm_so;

		if (len) {
			memset(match, 0, sizeof(match));
			memcpy(match, bematch + pmatch[i].rm_so, len);
			printf("[%s] \n", match);
		}
	}


	return 0;
}

