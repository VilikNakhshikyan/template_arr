#include <iostream>
#include <string>
#include "include/my_arr.h"
#include <vector>

int main()
{
    my_arr<int> a(2);
    a[0] = 20;
    a[1] = 30;
    my_arr<int> b(3);
    a = b;
    std::cout << (a == b) << std::endl;
    std::cout << b.size() << std::endl;
}