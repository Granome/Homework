#include <iostream>
#include <cmath>
#include <cstring>

int min(int a, int b)
{
    if (a>=b)
    {
        return b;
    }
    return a;
}


int min4(int a, int b, int c, int d)
{
    return min(min(a, b), min(c, d));
}


float geoMean(float a, float b, float c)
{
    return cbrt(a*b*c);
}


int round(float n)
{
    float decimal_part;
    float whole_part;
    decimal_part = std::modf(n, &whole_part);
    if (decimal_part >= 0,5 )
    {
        return whole_part+1;
    }
    else
    {
        return whole_part;
    }
}


bool is_prime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}


void AreaAndVolume(float radius, float &area, float &volume)
{
    area = 4*3.14*radius*radius;
    volume = (4*3.14*radius*radius*radius)/3;
}


float harmonicMean(float a, float b, float c)
{
    if (((1/a)+(1/b)+(a/c)) == 0)
    {
        return 0;
    }
    float result = 3/((1/a)+(1/b)+(a/c));
    return result;
}


int GCD(int a, int b) {
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}


int GCDof3(int a, int b, int c)
{
    return GCD(GCD(a, b), c);
}


char crypter(char a)
{
    if (a >= 65 && a <= 90)
    {
        a = 91 - (a-64);
    }
    else if (a >= 97 && a <= 122)
    {
        a = 123 - (a-96);
    }
    return a;
}


void exercise1()
{
    std::cout << "Minimal between 10 & 50 is: " << min(10, 50) << std::endl;
} 


void exercise2()
{
    std::cout << "Minimal between 2, 1, 80, 12 is: " << min4(2, 1, 80, 12) << std::endl;
}


void exercise3()
{
    std::cout << "Geometric mean of 3, 2.5, 10" << geoMean(3, 2.5, 10) << std::endl;
}


void exercise4()
{
    std::cout << "Rounded 2.33 is: " << round(2.33) << std::endl;
}


void exercise5()
{
    std::cout << "All prime numbers from 1 to 100 are: ";
    for (int i = 1; i <= 100; i++)
    {
        if (is_prime(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}


void exercise6()
{
    float Area;
    float Volume;
    AreaAndVolume(4.5, Area, Volume);
    std::cout << "Area and volume of sphere of radious 4,5 are: " << Area << " and " << Volume << std::endl;
}


void exercise7()
{
    std::cout << "Harmonic mean of 3, 2.5, 10 is: " << harmonicMean(3, 2.5, 10) << std::endl;
}


void exercise8()
{
    std::cout << "GCD of 20 and 120 is: " << GCD(20, 120) << std::endl;
}


void exercise9()
{
    std::cout << "GCD of 20, 40 and 120 is: " << GCDof3(20, 120, 40) << std::endl;
}


void exercise10()
{
    char text[100] = {"\0"};
    std::cout << "Enter some text: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(text, 100);
    
    char encryptedText[100] = {"\0"};
    for (int i = 0; i < strlen(text); i++)
    {
        encryptedText[i] = crypter(text[i]);
    }

    char decryptedText[100] = {"\0"};
    for (int i = 0; i < strlen(encryptedText); i++)
    {
        decryptedText[i] = crypter(encryptedText[i]);
    }

    std::cout << "Encrypted text: " << encryptedText << std::endl;
    std::cout << "Decripted text: " << decryptedText << std::endl;
}


void menu()
{
    while (true)
    {
        int exercise_number;
        std::cout << "Choose an exercise:\n  1 - Function that returns the minimum of two numbers\n  2 - Minimum of four numbers\n  3 - Geometric mean of 3 provided numbers\n  4 - Rounding\n  5 - Prime numbers\n  6 - Area and volume of a sphere\n  7 - Harmonic mean\n  8 - Greatest common divisor\n  9 - Greatest common divisor of 3 provided numbers\n  10 - Cipher a message\n0 - EXIT\n";
        std::cin >> exercise_number;
        
        switch(exercise_number)
        {
            case 1:
                exercise1();

                break;
            case 2:
                exercise2();

                break;
            case 3:
                exercise3();

                break;
                
            case 4:
                exercise4();

                break;
            case 5:
                exercise5();

                break;
            case 6:
                exercise6();

                break;
            case 7:
                exercise7();

                break;
            case 8:
                exercise8();

                break;
            case 9:
                exercise9();

                break;
            case 10:
                exercise10();

                break;
            case 0:

                return;
            default:


                break;
        }
    }

}


int main()
{
    menu();
    
    return 1;
}