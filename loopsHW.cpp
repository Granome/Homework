#include <iostream>
#include <cmath>
#include <conio.h>

int iFactorial(int n)
{
    int factorial = 1;
    for (int i = 2; i<=n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

unsigned long long ullFactorial(int n)
{
    unsigned long long factorial = 1;
    for (int i = 2; i<=n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

unsigned long ulFactorial(int n)
{
    unsigned long factorial = 1;
    for (int i = 2; i<=n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

unsigned int uiFactorial(int n)
{
    unsigned int factorial = 1;
    for (int i = 2; i<=n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

unsigned short int usiFactorial(int n)
{
    unsigned short int factorial = 1;
    for (int i = 2; i<=n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

double calculating_pi_Leibniz(int iterations)
{
    double pi;

    int denominator = 1;
    for (int i = 0; i<iterations; i++)
    {
        pi += pow(-1, i)/(2*i+1);
    }
    pi *= 4;

    return pi;

}

double calculating_pi_Wallis(int iterations)
{
    double pi = 1;
    for (int i = 1; i<=iterations; i++)
    {
        pi *= (double)(4*i*i)/((2*i-1)*(2*i+1));
    }
    pi *= 2;
    return pi;
}

int least_common_multiple(int a, int b)
{
    int i;

    if (a>b)
    {
        i = a;
    }
    else
    {
        i = b;
    }
    while (1)
    {
        if (i%a == 0 && i%b == 0)
        {
            break;
        }
        i++;
    }
    return i;
}

double exponentialWithFormula(int z, int iterations)
{
    double result = 0;
    for (int i = 0; i < iterations; i++)
    {
        result += pow(z, i)/ullFactorial(i);
    }
    return result;
}


void exercise1()
{
    int iterations;
    int method;
    std::cout << "Enter number of iterations for calculating: ";
    std::cin >> iterations;
    std::cout << "Choose calculating method: \n 1 - Leibniz formula \n 2 - Wallis formula\n";
    std::cin >> method;

    switch (method)
    {
    case 1:
        printf("Pi = %f\n\n", calculating_pi_Leibniz(iterations));
        break;
    case 2:
        printf("Pi = %f\n\n", calculating_pi_Wallis(iterations));
        break;
    
    default:
        std::cout << "You can only choose 1 or 2";
        exercise1();
        return;
        break;
    }
}

void exercise2()
{
    // come characters can not be displayed in console, but i print them anyway
    for (unsigned char i = 1; i < 128; i++)
    {
        if (i%40==0)
        {
            std::cout << "Press any button to continue...\n";
            getch();
        }
        std::cout << int(i) << ": " << i << std::endl;
    }
}

void exercise3()
{
    int n;
    std::cout << "Enter number, to calculate it's factorial: ";
    std::cin >> n;
    if (n<1)
    {
        std::cout << "Number has to be greater than 0";
        exercise3();
        return;
    }

    std::cout << n << "! = " << iFactorial(n) << std::endl;

    for (int i = 1;;i++){
        
        if (!iFactorial(i))
        {
            std::cout << "Last accepted number for int is " << i-1 << std::endl;
            break;
        }
    }
}

void exercise4()
{
    int min;
    int max;

    std::cout << "Enter minimum: ";
    std::cin >> min;

    std::cout << "Emter maximum: ";
    std::cin >> max;


    for (int i = min; i <=max; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i%j==0)
            {
                break;
            }
            if (j == i-1)
            {
                std::cout << i << std::endl;
            }
        }
    }
}

void exercise5()
{
    for (int i = 1;;i++){
        
        if (!ullFactorial(i))
        {
            std::cout << "Last accepted number for unsigned long long is " << i-1 << std::endl;
            break;
        }
    }
    for (int i = 1;;i++){
        
        if (!ulFactorial(i))
        {
            std::cout << "Last accepted number for unsigned long is " << i-1<< std::endl;
            break;
        }
    }
    for (int i = 1;;i++){
        
        if (!uiFactorial(i))
        {
            std::cout << "Last accepted number for unsigned int is " << i-1<< std::endl;
            break;
        }
    }
    for (int i = 1;;i++){
        
        if (!usiFactorial(i))
        {
            std::cout << "Last accepted number for unsigned short int is " << i-1<< std::endl;
            break;
        }
    }
}

void exercise6()
{
    int a;
    int b;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter econd number: ";
    std::cin >> b;
    if (a<=0 || b<=0)
    {
        std::cout << "Both nubmers have to be positive" << std::endl;
        exercise6();
        return;
    }

    std::cout << "The least common multiple is " << least_common_multiple(a, b);
}

void exercise7()
{
    int z;
    std::cout << "Enter z: ";
    std::cin >> z; 

    double percise_answer = exp(z);

    std::cout << "Error of the equation with only first 2 elements of series is: " <<
                                                 percise_answer - exponentialWithFormula(z, 2) << std::endl;
    std::cout << "Error of the equation with only first 5 elements of series is: " <<
                                                 percise_answer - exponentialWithFormula(z, 5) << std::endl;
    std::cout << "Error of the equation with only first 10 elements of series is: " <<
                                                 percise_answer - exponentialWithFormula(z, 10) << std::endl;
}

void menu()
{
    int exercise_number;

    do
    {
        std::cout << std::endl << std::endl;
        std::cout << "1 - Calculating the value of pi" << std::endl;
        std::cout << "2 - Showing ASCII coded characters" << std::endl;
        std::cout << "3 - Calculating factorial" << std::endl;
        std::cout << "4 - Printing all prime numbers in provided interval" << std::endl;
        std::cout << "5 - Computing the factorial using different integer types" << std::endl;
        std::cout << "6 - Computing the least common multiple for two positive numbers" << std::endl;
        std::cout << "7 - Error while computing exponential" << std::endl;
        std::cout << "0 - EXIT" << std::endl;

        std::cout << "Choose one option: ";
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
            default:
                std::cout << "Wrong number, try again";
                break;
        }
    }while(exercise_number != 0);
}

int main()
{
    menu();    
    return 1;
}