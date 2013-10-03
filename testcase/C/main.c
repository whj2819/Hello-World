#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <regex.h>

#define ERR_BUF_SIZE (256)

int main(void)
{

    regex_t compiled;
    char *bematch[2] = {
        "08:00:27:00:e4:c5",
        "08:00:27:00:e4:c7",
    };
    char *pattern[3] = {
	"08:00:27:00:e4:c5",
	"08:00:27:00:e4:c6",
	"08:00:27:00:e4:c7",
    };
    char err[ERR_BUF_SIZE] = { 0 };
    regmatch_t pmatch[2];
    char match[1024] = { 0 };
    int ret = 0, len = 0;
    int i = 0, j = 0;
    int k = 0;


    for (i = 0; i < 3; i++) {
        ret = regcomp(&compiled, pattern[i], REG_EXTENDED);
        if (ret < 0) {
            regerror(ret, &compiled, err, sizeof(err));
            printf("err: %s \n", err);
            return -1;
        }

        for(j=0; j<2; j++) {
            ret = regexec(&compiled, bematch[j], 1, pmatch, 0);
            if (ret == REG_NOMATCH) {
                printf("not match \n");
            } else if (ret) {
                regerror(ret, &compiled, err, sizeof(err));
                printf("err: %s \n", err);
                return -1;
            } else {
            }
        }

        if (k < 2) {
            len = pmatch[0].rm_eo - pmatch[0].rm_so;
            if (len) {
                memset(match, 0, sizeof(match));
                memcpy(match, bematch[i] + pmatch[0].rm_so, len);
                printf("[%s] \n", match);
            }
            k++;
        } else {
            regfree(&compiled);
            break;
        }

        regfree(&compiled);
    }

    return 0;
}
