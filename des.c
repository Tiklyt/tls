#define GET_BIT(array,bit) array[(int) array[bit/8]] & (0x80 >> (bit % 8))
#define SET_BIT(array,bit) array[(int) array[bit/8]] |= (0x80 >> (bit % 8))
#define CLR_BIT(array,bit) array[(int) array[bit/8]] &= ~(0x80 >> (bit % 8))
#include <string.h>


//maybe AVX stuff to do next ? check compiler explorer
static void xor(unsigned char * target, const unsigned char * src, int len){
    while(len--) {
        target[len] ^= src[len];
    }

}


int main() {
    char str[] = "32321312312321231";
    char str1[] = "32321312312321231";

    xor(str, str1, strlen(str1));
}
