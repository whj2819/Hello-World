#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
parse_vlans(char *s, int *vlans)
{
    char *delim = ", ";
    char *delim2 = "- ";
    char *p, *q;
    char *tmp_data[16] = {0};
    char *range[2] = {0};
    int i=0, cnt = 1;
    int start, end ;
    int j=0, vlan_nums = 0;

    for (i=0; i<16; i++)
        tmp_data[i] =(char *) malloc(sizeof(char) * 16);
    for (i=0; i<2; i++)
        range[i] =(char *) malloc(sizeof(char) * 16);

    p = strtok(s,delim);
    strcpy(tmp_data[0], p);
    while((p=strtok(NULL,delim))) {
        strcpy(tmp_data[cnt], p);
        cnt++;
    }

    for (i=0; i<cnt; i++) {
        q = strchr(tmp_data[i], '-');
        if (q != NULL) {
            p = strtok(tmp_data[i],delim2);
            strcpy(range[0], p);
            while((p=strtok(NULL,delim2))) {
                strcpy(range[1], p);
            }

            start = atoi(range[0]);
            end = atoi(range[1]);
            for (j=0; j<end - start +1; j++) {
                vlans[vlan_nums] = start + j;
                vlan_nums++;
            }
        } else {
            vlans[vlan_nums] = atoi(tmp_data[i]);
            vlan_nums++;
        }
    }
    for (i=0; i<16; i++)
        free(tmp_data[i]);
    for (i=0; i<2; i++)
        free(range[i]);

    return 0;
}

int main(int argc, const char *argv[])
{
    char s[] = "10,100-103, 200, 210-212";
    int vlans[16] = {0};
    int i, ret;

    ret =  parse_vlans(s, vlans);
    if (ret != 0)
        return -1;
    for(i=0; i<16; i++)
        printf("%d ", vlans[i]);
    printf("\n");

#if 0
    check_vlans();
        ----qsort
        --1<vlan<4095
    write_to_conf
#endif

    return 0;
}
