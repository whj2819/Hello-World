#include <stdio.h>
#include <stdlib.h>
 
typedef unsigned short u16;
 
#define ROW 3 
#define COL 5 
 
 
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
__convert2(const u16 *src,u16 h,u16 w,u16 *dest)
{
	int i,j;

	if (src == NULL || dest == NULL)
		return -1;

    for (i=w-1;i>=0;i--) {
        for(j=h-1;j>=0;j--) {
            *dest++ = *(src+w*j+i);
        }
    }

	return 0;
}



int
__convert3(const u16 *src,u16 h,u16 w,u16 *dest)
{
	int i,j;

	if (src == NULL || dest == NULL)
		return -1;

    for (i=w-1;i>=0;i--) {
        for(j=0;j<h;j++) {
            *dest++ = *(src+w*j+i);
        }
    }

	return 0;
}

int
__convert5(const u16 *src,u16 h,u16 w,u16 *dest)
{
	int i,j;

	if (src == NULL || dest == NULL)
		return -1;

    for (i=w-1;i>=0;i--) {
        for(j=0;j<h;j++) {
            *dest++ = *(src+j*w+i);
        }
    }

	return 0;
}



int
main(int argc,char **argv)
{
 	//u16 a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
 	u16 a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	u16 b[ROW*COL] = {0};
	int i = 0;
	int rv = 0;

	rv = __convert5(a,ROW,COL,b);
	if(rv) {
		printf("error \n");
		//return rv;
	}

	printf("====aaaaaa========================== \n");
	for (i=0; i<ROW*COL;i++) {
		if (i%COL ==0)
			printf("\n");
		printf("%d ",a[i]);
	}
	printf("\n");


	printf("==bbbbbbb======================== \n");
	for (i=0; i<ROW*COL;i++) {
		if (i%ROW ==0)
			printf("\n");
		printf("%d ",b[i]);
	}
	printf("\n");
	printf("============================== \n");

	return 0;
}
