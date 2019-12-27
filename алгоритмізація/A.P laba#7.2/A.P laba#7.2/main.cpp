#include <iostream>
using namespace std;

int Convert(int m)
{
        int hours = m / 60;
        int minutes = m % 60;
        
        cout << hours << " " <<  minutes << endl;
        return 1;
}

int Convert(int h, int m)
{
        int hours = h*60;
        int minutes = m;
        cout << hours+minutes << endl;
        return 1;
}


int main ()
{
    cout << "для перетворення 2 годин і 45 хвилин у хвилини \n";
    cout << Convert(2,45) << endl;
    
    cout << "для перетворення 200 хвилин у години та хвилини \n";
    cout << Convert(200) << endl;

  return 0;
}
