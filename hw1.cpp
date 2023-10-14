#include <iostream>
#include <cmath>

void circumference_and_area_of_rectangle()
{
    float a;
    float b;

    std::cout << "First of all, lets calculate perimeter and area of rectangle\n";
    std::cout << "Enter first side of rectangle: ";
    std::cin >> a;
    std::cout << "Enter second side of rectangle: ";
    std::cin >> b;

    std :: cout << "Circumference of this rectangle = "  << (a+b) * 2 << std::endl;
    std :: cout << "Area of this rectangle = "  << a*b << std::endl << std::endl;
}

void circumference_and_area_of_triangle()
{
    float a;
    float b;
    float c;

    float p; //semiperimeter

    std::cout << "Time to calculate perimeter and area of traingle\n";
    std::cout << "Enter first side of triangle: ";
    std::cin >> a;
    std::cout << "Enter second side of triangle: ";
    std::cin >> b;
    std::cout << "Enter third side of triangle: ";
    std::cin >> c;

    if (a>=(b+c) || b>=(a+c) || c>=(a+b))
    {
        std::cout << "This triangle can not exist. Try another values" << std::endl;
        circumference_and_area_of_triangle(); //some recursion to make things more interesting :)
        return;
    }
    
    p = (a+b+c) / 2.0;

    std :: cout << "Circumference of this triangle = "  << a+b+c << std::endl;
    std :: cout << "Area of this triangle = "  << sqrt(p*(p-a)*(p-b)*(p-c)) << std::endl << std::endl;
}

void triangle_angles()
{
    float a;
    float b;
    float c;

    float alpha;
    float beta;
    float gamma;
    std::cout << "Lets calculate angles of triangle now!\n";
    std::cout << "Enter first side of triangle: ";
    std::cin >> a;
    std::cout << "Enter second side of triangle: ";
    std::cin >> b;
    std::cout << "Enter third side of triangle: ";
    std::cin >> c;

    if (a>=(b+c) || b>=(a+c) || c>=(a+b))
    {
        std::cout << "This triangle can not exist. Try another values" << std::endl;
        triangle_angles(); //same here
        return;
    }

    alpha = acos(((b*b)+(c*c)-(a*a))/(2*c*b)) * 180/3.14159;
    beta = acos(((a*a)+(c*c)-(b*b))/(2*a*c)) * 180/3.14159;
    gamma = acos(((a*a)+(b*b)-(c*c))/(2*b*a)) * 180/3.14159;

    printf("Angles of his triangle are: %3.2f, %3.2f, %3.2f", alpha, beta, gamma);
}

int main()
{
    circumference_and_area_of_rectangle();
    circumference_and_area_of_triangle();
    triangle_angles();

    return 1;
}