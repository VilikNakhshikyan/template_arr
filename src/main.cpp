#include <iostream>
#include <string>
#include "include/my_arr.h"
#include <vector>
// bool isuniq(const std::string &txt)
// {
//     unsigned int binar_key[8]{0};
//     short index;
//     for (char ch : txt)
//     {
//         index = ch / 32;
//         ch %= 32;
//         if (binar_key[index] & (1 << ch))
//             return false;
//         else
//             binar_key[index] |= (1 << ch);
//     }
//     return true;
// }

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