#include <iostream>
#include <chrono>

int count_days(int birth_year, tm local_tm, int birth_month, int birth_day) 
{
    int days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_year = local_tm.tm_year + 1900;
    int current_day = local_tm.tm_yday;

    int days = 0;
    for (int i = birth_year; i < current_year-1; i++){ //Counting days in full years that passed, including leap years
        if (i%100 == 0)
        {
            if (i%400 == 0)
            {
                days += 366;
            }
            else
            {
                continue;
            }
        } 
        if (i%4 == 0)
        {
            days += 366;
        }
        else
        {
            days += 365;
        }
    }

    for (int i = 11; i >= birth_month; i--) // Adding days from date of birth, to the end of the year
    {
        days += days_in_months[i];
    }
    days += days_in_months[birth_month] - birth_day; // adding days from date of birth tothe end of first month

    days += current_day; // Adding days of current year (I don't know how chrono's now() method works with leap years,
                         // but it doesn't matter for now)


    return days;
}

int main() {

    char first_name[20];
    char last_name[20];
    char father_name[20];
    int father_age;
    char mother_first_name[20];
    int mother_age;
    char mother_family_name[20];
    char birth_place[20];
    int birth_year;
    int birth_month;
    int birth_day;

    int current_year;
    int current_day;

    std::cout << "First name: ";
    std::cin >> first_name;
    std::cout << "Last name: ";
    std::cin >> last_name;
    std::cout << "Father's first name: ";
    std::cin >> father_name;
    std::cout << "Father's age: ";
    std::cin >> father_age;
    std::cout << "Mother's first name: ";
    std::cin >> mother_first_name;
    std::cout << "Mother's age: ";
    std::cin >> mother_age;
    std::cout << "Mother's family name: ";
    std::cin >> mother_family_name;
    std::cout <<"Birth place: ";
    std::cin >> birth_place;
    std::cout << "Birth year: ";
    std::cin >> birth_year;
    std::cout << "Birth month: ";
    std::cin >> birth_month;
    std::cout << "Birth day: ";
    std::cin >> birth_day;
    


    auto cr = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(cr);
    tm local_tm = *localtime(&tt);
    current_year = local_tm.tm_year + 1900;
    current_day = local_tm.tm_yday;


    printf("Citizen %s %s was born in %s %d years ago. His mother, mrs %s (of a %s), was %d years old then and his father %d years old.\n\n", first_name, last_name, birth_place, current_year-birth_year, mother_first_name, mother_family_name, mother_age-current_year+birth_year, father_age -current_year+birth_year);
    printf("%s %s lived exactly %d days.\n", last_name, first_name, count_days(birth_year, local_tm, birth_month, birth_day));
    printf("His father is %4.2f times older than him and mother %4.2f.\n", father_age/1.0/(current_year-birth_year), mother_age/1.0/(current_year-birth_year));
    printf("It is an old family, because together they have %d years.", father_age+mother_age+(current_year-birth_year));

   return 0;
}
