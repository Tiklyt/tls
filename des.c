#include <stdbool.h>
#define GET_BIT(array,bit) array[(int) array[bit/8]] & (0x80 >> (bit % 8))
#define SET_BIT(array,bit) array[(int) array[bit/8]] |= (0x80 >> (bit % 8))
#define CLR_BIT(array,bit) array[(int) array[bit/8]] &= ~(0x80 >> (bit % 8))


bool get_bit(char * array, int bit) {
    return array[(int) array[bit/8]] & (0x80 >> (bit % 8)); //big endian
}
int main() {

}
