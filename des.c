#define GET_BIT(array,bit) array[(int) array[bit/8]] & (0x80 >> (bit % 8))
#define SET_BIT(array,bit) array[(int) array[bit/8]] |= (0x80 >> (bit % 8))
#define CLR_BIT(array,bit) array[(int) array[bit/8]] &= ~(0x80 >> (bit % 8))

static void xor(unsigned char * target, const unsigned char * src, int len){
    while(len--) {
        target[len] ^= src[len];
    }

}


int main() {

}
