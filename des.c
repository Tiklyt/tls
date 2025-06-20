#include <stdio.h>
#include <stdbool.h>
#define GET_BIT(array,bit)
#define SET_BIT(array,bit)
#define CLR_BIT(array,bit)


bool get_bit(char * array, int bit) {
    return array[(int) array[bit/8]] & (0x80 >> (bit % 8)); //big endian
}
int main() {

}
