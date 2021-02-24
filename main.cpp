#include <iostream>
#include <cstring>
#include "index_crypt.h"

int main() {
    char input[100];
    char input2[100];
    char de[100];
    int res[100];
    int k = 0;

    std::cin.getline(input, 100);
    std::cin.getline(input2, 100);

    encrypt(input, strlen(input), res, &k);
    decrypt(res, k, de, k);

    bool cmpRes = cmp(res, k, input2, strlen(input2));
    std::cout << cmpRes << "\n";

    return 0;
}
