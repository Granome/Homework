#include <iostream>

int main()
{
    int i = 10;

    std::cout << "Give me a nubmer: ";
    std::cin >> i;

    std::cout << ++i << std::endl;
    std::cout << i << std::endl;
    std::cout << i++ << std::endl;
    std::cout << i << std::endl;

    std::cout << --i << std::endl;
    std::cout << i << std::endl;
    std::cout << i-- << std::endl;
    std::cout << i << std::endl;

    return 1;
}