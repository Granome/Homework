#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cstring>


void bubbleSort(char arr[], int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}


void insertionSort(float arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


float binarySearchClosest(float arr[], int l, int r, float target)
{
    float closestValue = arr[0];

    while (l <= r) 
    {
        int m = l + (r - l) / 2;
 
        if (std::abs(arr[m] - target) < std::abs(closestValue - target)) {
            closestValue = arr[m];
        }
        if (arr[m] == target)
            return m;
 
        if (arr[m] < target)
            l = m + 1;
 
        else
            r = m - target;
    }
 
    return closestValue;
}


void exercise1()
{
    char text[50];
    std::cout << "Enter some piece of text: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(text, 50);
    for (int i = 0; i < 50; i++)
    {
        if (text[i] >= 97 && text[i] <= 122)
        {
            text[i] -= 32;
        }
    }
    std::cout<<text<<std::endl;
}


void exercise2()
{
    srand(time(nullptr));

    int array[15];
    for (int i = 0; i < 15; i++)
    {
        array[i] = rand() % 100 + 1;
    }

    int min = 101;
    int max = 0;
    float mean;
    for (int i = 0; i < 15; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
        if (array[i] > max)
        {
            max = array[i];
        }
        mean += array[i];
    }
    mean /= 15.0;

    std::cout << "[" << array[0];
    for (int i = 1; i < 15; i++)
    {
        std::cout  << ", " << array[i];
    }
    std::cout << "]" << std::endl;
    std::cout << "Maximum value: " << max << std::endl;
    std::cout << "Minimal value: " << min << std::endl;
    std::cout << "Mean value: " << mean << std::endl;
}


void exercise3()
{
    int charCount[256] = {0};

    char text[50] = {" "};
    std::cout << "Enter some text: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(text, 50);

    for (int i = 0; i < 50; i++)
    {
        charCount[static_cast<unsigned char>(text[i])]++;
    }

    std::cout << "Character statistics:" << std::endl;
    for (int i = 0; i < 256; i++)
    {
        std::cout << "ASCII character №"<< i  << " - " << charCount[i] << " times" << std::endl; //terminal cant display some of the characters, so I decided to only show their index
    }

    bubbleSort(text, 50);
    std::cout << "Sorted array: ";
    std::cout << "[" << text[0];
    for (int i = 1; i < 50; i++)
    {
        std::cout  << ", " << text[i];
    }
    std::cout << std::endl;
}


void exercise4()
{
    float array[20] = {0};
    for (int i = 0; i < 20; i++)
    {
        array[i] = (rand() % 901 + 100)/10;
    }

    std::cout << "Array: ";
    std::cout << "[" << array[0];
    for (int i = 1; i < 15; i++)
    {
        std::cout  << ", " << array[i];
    }
    std::cout << "]" << std::endl;
    insertionSort(array, 20);

    float target_value=0;
    std::cout << "Enter float value between 10 and 100: ";
    std::cin >> target_value;
    std::cout << "Closest value in array is: " << binarySearchClosest(array, 0, 19, target_value) << std::endl;

}


void exercise5()
{
    char text[100] = "";
    std::cout << "Enter a sentence: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(text, 100);
    int length = strlen(text);
    int endOfTheWord = length-1;
    for (int i = length-1; i >= 0; i--)
    {
        //std::cout <<std::isspace(text[i]);
        if (std::isspace(text[i]) || i == 0)
        {
            if (i == 0)
            {
                std::cout << text[i];
            }
            for (int j = i+1; j<=endOfTheWord; j++)
            {
                std::cout << text[j];
            }
            std::cout << " ";
            if (i>0)
            {
                endOfTheWord = i-1;
            }
        }
    }
    std::cout << std::endl;

}


void exercise6()
{
    char text[100];
    char subString[20];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter some text: ";
    std::cin.getline(text, 100);
    int textLength = strlen(text);

    std::cout << "Enter a word to search for: ";
    std::cin >> subString;
    int subStringLength = strlen(subString);

    char currentWord[20] = {'\0'};

    for (int i = 0; i < textLength; i++) 
    {
        if (std::isspace(text[i]) || i == textLength - 1) 
        {
            if (i == textLength - 1 && !std::isspace(text[i])) 
            {
                currentWord[strlen(currentWord)] = text[i];
            }

            if (!strcmp(currentWord, subString))
            {
                std::cout << i-strlen(currentWord) << " ";
            }

            memset(currentWord, '\0', sizeof(currentWord));

            if (!std::isspace(text[i])) {
                currentWord[0] = text[i];
            }
        } else {
            currentWord[strlen(currentWord)] = text[i];
        }
    }

    std::cout << std::endl;


}


void exercise7()
{
    char resultString[100] = {'\0'};

    char text[100];
    char subString[20];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter some text: ";
    std::cin.getline(text, 100);
    int textLength = strlen(text);

    std::cout << "Enter a word to change: ";
    std::cin >> subString;
    int subStringLength = strlen(subString);

    char newWord[20] = {"\0"};
    std::cout << "Enter a word to change with: ";
    std::cin >> newWord;

    char currentWord[20] = {'\0'};

    for (int i = 0; i < textLength; i++) 
    {
        if (std::isspace(text[i]) || i == textLength - 1) 
        {
            if (i == textLength - 1 && !std::isspace(text[i])) 
            {
                currentWord[strlen(currentWord)] = text[i];
            }

            if (!strcmp(currentWord, subString))
            {
               strcat(resultString, newWord); 
            }
            else
            {
                strcat(resultString, currentWord);
            }
            strcat(resultString, " ");

            memset(currentWord, '\0', sizeof(currentWord));

            if (!std::isspace(text[i])) {
                currentWord[0] = text[i];
            }
        } else {
            currentWord[strlen(currentWord)] = text[i];
        }
    }

    std::cout << resultString << std::endl;


}

void menu()
{
    while (true)
    {
        int exercise_number;
        std::cout << "Choose an exercise:  \n  1 - Small letters to capital\n  2 - Stats of int array\n  3 - Char array stats and bubble sorting\n  4 - Float array, insertion sort and binary searh for closest\n  5 - Reversing sentence\n  6 - Word search\n  7 - Word replacing\n0 -- EXIT\n";
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