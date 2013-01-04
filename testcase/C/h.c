#include <stdio.h>
#include <stdlib.h>
 
typedef unsigned short u16;
 
#define ROW 6 
#define COL 5
 
 
int
__convert(u16 *src,u16 row,u16 col,u16 *dest)
{
	u16 *p = src;
	u16 tmp[row][col];
	u16 b[col][row];
	int i,j;
	int k =0;
	

	if (src == NULL || dest == NULL)
		return -1;

	for (i=0; i<row; i++) {
	     for(j=0; j<col; j++) {
	         tmp[i][j] = *(p+j);
	     }
	     p += col;
	 }
 
	for (i =0; i<col; i++) 
		for(j=row-1; j>=0; j--) 
			b[i][row-j-1]= tmp[j][i];
	 
	for (i = 0;i<col;i++) {
		for (j = 0;j<row;j++) {
			dest[k] = b[i][j];
			k++;
		}
	}
 
	return 0;
}

int
main(int argc,char **argv)
{
 	//u16 a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	//u16 a[] = {1,2,3,4,5,6,7,8,9,10};
	u16 a[] = { 1,2,3,4,5,6,7,8,9,10,
				11,12,13,14,15,16,17,18,19,20,
				21,22,23,24,25,26,27,28,29,30
			};
	
	u16 b[ROW*COL] = {0};
	int i = 0;
	int rv = 0;

	rv = __convert(a,3,5,b);
	if(rv) {
		printf("error \n");
		//return rv;
	}


	printf("main func \n");
	for (i=0; i<ROW*COL;i++) {
        if(i%COL == 0) 
			printf("\n");
		printf("%d ",a[i]);
	}
	printf("\n");
	
	for (i=0; i<ROW*COL;i++) {
        if(i%ROW == 0) 
			printf("\n");
		printf("%d ",b[i]);
	}
	printf("\n");

	return 0;
}