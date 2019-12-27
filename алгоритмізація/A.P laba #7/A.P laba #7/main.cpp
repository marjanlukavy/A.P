#include <iostream>
using namespace std;

int first_date_month;
int first_date_days;
int first_date_year;
int second_date_month;
int second_date_days;
int second_date_year;
int days;

int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int average(int num, ...)
{
    va_list valist;
  
    int i,value;
    int array[6];
    va_start(valist, num);
    for (i = 0; i < num; i++) {
        value = va_arg(valist, int);
        array[i] = value;
    }
    va_end(valist);
  
        first_date_days = array[0];
        first_date_month = array[1];
        first_date_year = array[2];
        second_date_days = array[3];
        second_date_month = array[4];
        second_date_year = array[5];
        if(first_date_year == second_date_year)
        {
            if(first_date_month == second_date_month)
                days = second_date_days - first_date_days;
            else
            {
                for(int i = first_date_month; i < second_date_month-1;i++)
                    days += month_days[i];
                days += month_days[first_date_month-1] - first_date_days + second_date_days;
            }
        }
        else
        {
            for(int i = 0; i < second_date_month-1; i++)
                days += month_days[i];
            for(int i = first_date_month; i < 12; i++)
                days += month_days[i];
            if(second_date_year - first_date_year >= 0)
            days += (second_date_year - first_date_year - 1)*365 +
                month_days[first_date_month-1] - first_date_days + second_date_days;
        }
    
        cout << "Days between " << array[0]  << "/" << array[1] << "/" << array[2] << " and " << array[3] << "/" << array[4] << "/" << array[5] << " : " << days << "\n";
    
    return (0);
}

int main()
{

    printf("%d\n",average(6,2, 3,2001,1, 2,2002));
    printf("%d\n",average(6,1, 4,2001,1, 2,2004));


    return(0);
}
