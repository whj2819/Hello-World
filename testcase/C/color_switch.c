#include <stdio.h>


#define  Black 0x00
#define  White 0x01
#define  Red 0x02
#define  Green 0x03

unsigned short col_table[16] ={0xfff0,0xfff1,0xfff2,0xfff3,
    0xfff0,0xfff1,0xfff2,0xfff3,
    0xfff0,0xfff1,0xfff2,0xfff3,
    0xfff0,0xfff1,0xfff2,0xfff3,
};

void
change_to_2bit_color(unsigned char *dest,const unsigned short *src,int len)
{
    int i;
    int dest_len = len/4;

    for (i=0;i<dest_len;i++) {
        *(dest+i) = (src[i*4]&0x03) | ((src[i*4+1]&0x3)<< 2)\
                      |((src[i*4+2]&0x3) << 4)| ((src[i*4+3]&0x3) << 6); 
    }

}

void
change_to_16bit_color(unsigned char *color)
{
    int i = 0;

    for(i=0; i<4; i++) {
        switch(*color & 0x03) {
        case Black:
            printf("Black ===\n");
             break;
        case White:
            printf("White===\n");
             break;
        case Red:
            printf("Red===\n");
             break;
        case Green:
            printf("Green===\n");
             break;
        default:
            break;
        }

        *color >>= 2;
    }

    printf("\n");
}

int
main(int argc,char **argv)
{
    unsigned char dest[4] = {0};
    change_to_2bit_color(dest,col_table,16);

    printf("0x%x 0x%x 0x%x 0x%x \n",dest[0],dest[1],dest[2],dest[3]);
    change_to_16bit_color(&dest[0]);
    change_to_16bit_color(&dest[1]);
    change_to_16bit_color(&dest[2]);
    change_to_16bit_color(&dest[3]);
    return 0;
}
