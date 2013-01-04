#include <stdio.h>
#include <stdlib.h>
 
typedef unsigned short u16;
 
#define ROW 5
#define COL 4
 
 
int
__convert(u16 *src,u16 row,u16 col,u16 *dest)
{
	int i,j;

	if (src == NULL || dest == NULL)
		return -1;

    for(j=0; j<col; j++) {
		for(i=row-1; i>=0; i--) {
	        *dest++ = *(src+i*col+j);
		}
    }

	return 0;
}

int
main(int argc,char **argv)
{
 	u16 a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
	
	u16 b[ROW*COL] = {0};
	int i = 0;
	int rv = 0;

	rv = __convert(a,ROW,COL,b);
	if(rv) {
		printf("error \n");
		//return rv;
	}


	printf("main func \n");
	for (i=0; i<ROW*COL;i++) {
		if (i%ROW ==0)
			printf("\n");
		printf("%d ",b[i]);
	}
	printf("\n");

	return 0;
}
