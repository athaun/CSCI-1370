#include <iostream>

void add_one_val (int val) {
    val ++;
    return;
}

void add_one_ref (int & ref) {
    ref ++;
    return;
}

int add_one_both (int & ref) {
    ref ++;
    return ref;
}

int main () {
    int one = 0, two = 0, three = 0, four = 0;

    add_one_val(one); // 'one' will stay the same
    add_one_ref(two); // 'two' will increment by one
    three = add_one_both(three); // Should increment 'three' by one (I assume this will assign incremented value to variable 'three' twice)
    four = add_one_both(three); // Might expect 2 because three is 1

    std::cout << "One:\t" << one << "\nTwo:\t" << two << "\nThree:\t" << three << "\nFour:\t" << four << "\n";

    /* 
    Outputs:
    One:    0 - guess was correct
    Two:    1 - guess was correct
    Three:  2 - guess was wrong (because statement on line 24 incremented 'three' from 1 to 2, assigning that new value to both 'three' and 'four')
    Four:   2 - guess was correct
    */

    return 0;
}