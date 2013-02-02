#include <stdio.h>


//unsigned short col_table[4] ={0xfff0,0xfff1,0xfff2,0xfff3};
unsigned short col_table[8] ={0xfff0,0xfff1,0xfff2,0xfff3,0xfff0,0xfff1,0xfff2,0xfff3};
unsigned char __2bit_col[4] ;

void
color_switch(unsigned char *dest,unsigned short *src,int len)
{
    int i;
    int dest_len = len/4;

    for (i=0;i<dest_len;) {
        *(dest+i%4) = (src[i]&0x03) | (src[i+1]<< 12)|(src[i+2] << 11)| src[i+3]; 
        i += len;
    }

    printf("0x%x 0x%x\n",dest[0],dest[1]);
}



int
main(int argc,char **argv)
{
    unsigned char dest[2] = {0};
    color_switch(dest,col_table,8);

    return 0;
}
