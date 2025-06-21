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

static void permute(unsigned char target [],
                    const unsigned char * src,
                    const int permute_table[],
                    int len) {

    for (int i = 0; i < len * 8; i++) {
        if (GET_BIT(src, (permute_table[i] - 1))) SET_BIT(target, i);
        else CLR_BIT(target, i);
    }
}


int main() {
    char str[] = "32321312312321231";
    char str1[] = "32321312312321231";

    xor(str, str1, strlen(str1));
}
