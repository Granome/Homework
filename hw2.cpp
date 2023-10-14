#include <iostream>

int main()
{
    int int_a;
    int int_b;
    float float_a;
    float float_b;

    std::cout << "Enter first integer number: ";
    std::cin >> int_a;
    std::cout << "Enter second integer number: ";
    std::cin >> int_b;

    printf("Multiplication: %d, addition: %d, substraction %d, division %d\n", int_a*int_b, int_a+int_b, int_a-int_b, int_a/int_b);

    std::cout << "Enter first float number: ";
    std::cin >> float_a;
    std::cout << "Enter second float number: ";
    std::cin >> float_b;
    
    printf("Multiplication: %.2f, addition: %.2f, substraction %.2f, division %.2f\n", float_a*float_b, float_a+float_b, float_a-float_b, float_a/float_b);

    return 1;
}