#include <iostream>

/** 
 * Datatypes:
 * - domain (set of values that are held)
 * - operations allowed on the type
 * - Datatypes are ranked by the largest value they can hold - value types can be promoted or demoted on the type hierarchy by casting
 * - Simple
 *  - Integral Types:
 *      NORMAL          UNSIGNED                TYPE                SIZE                        RANGE                           UNSIGNED RANGE
 *    - char            unsigned char           characters          (1 bytes)                   -128 to 127
 *    - short           unsigned short        \                     (2 bytes)                   normal: ~-32000 to ~32000       unsigned: 0 to ~64000
 *    - int             unsigned int          | whole numbers       (4 bytes)                   normal: ~-2bil to ~2bil         unsigned: 0 to ~4bil
 *    - long            unsigned long         |                     (long and int are ==)
 *    - long long       unsigned long long    /                     (8 bytes)
 *    - bool                                    Boolean values      (1 bytes)                   true and false
 *  
 *  - Floating point (represented with e+ notation)
 *      NORMAL          SIZE                        RANGE                
 *    - float           (4 bytes)                   -3.4e+38 to 3.4e+38
 *    - double          (8 bytes)                   -1.7e+308 to 1.7e+308
 *    - long double     (long double and double are ==)
 * 
 *    - maximum # of sig figures is 6 or 7 for float (single precision)
 *    - maximum # of sig figures is 15 for a double  (double precision)
 * 
 *    - real number literals are taken as doubles by compiler as default type
 *    - real whole number literals are taken as int
 *  
 *  - Enumeration
 * 
 * - structured 
 *    - Arrays (for later tho D:)
 *    - hashmaps
 *    - strings
 * - pointers
 * 
 * - Operators
 *    - +, -, /, *
 *    - int division of 5/2 = 2 not 2.5, floating point ignored
 *    - floating point div 5f/2f = 2.5
 *    - % (modulus operator) returns remainder
 *    - 5 % 2 = 1
 *    - 
 * 
 * Bits:
 * bit
 * - smallest piece of memory
 * - 0 - 1
 * - context sensitive
 * 
 * Nibble
 * - 4 bits
 * 
 * Byte
 * - 8 bits
 * 
 * Word
 * - Usually 4 consecutive bytes
 * - Has a memory address
*/

int main () {
    std::cout << "Hello World\n";
    return  0;
}