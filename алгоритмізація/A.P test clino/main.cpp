#include <iostream>
#include <string>
#include <fstream>
using namespace std;



void display_file(string path)
{
    string information;
    ifstream file (path);
    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, information);
            cout << information << endl;
        }
    }
}

int main()
{
    int carsLeft = 0,carLeft = 0;
    int skipYear = 0;
    int delete_el;
    int n;
    string lastname;

    struct CarOwner
    {
        int n = 0;
        string first; // brand
        string last; // brand
        string fath; // brand
        int carNumber; //release_year
        int phone; //cost
        int passportNumber; //color
    };


    cout << "Скільки cтруктур \"Власник автомобіля\":  ";
    cin >> carsLeft;

    int cars_left = carsLeft;
    CarOwner car[carsLeft];

    const string origin_file_path = "cars.txt";
    const string updated_file_path = "upd_cars.txt";

    ofstream updated_file;
    updated_file.open(updated_file_path, ios::app);


    ofstream origin_file;
    origin_file.open(origin_file_path,ios::binary | ios::out);
    if(!origin_file.is_open()) {
        cout << "Файл не відкрився" << endl;
    } else {
        while(carsLeft--) {

            cout << "Прізвище: ";
            cin >> car[carsLeft].first;

            cout << "Ім'я: ";
            cin >> car[carsLeft].last;

            cout << "По батькові: ";
            cin >> car[carsLeft].fath;

            cout << "Номер автомобіля: ";
            cin >> car[carsLeft].carNumber;

            cout << "Телефон: ";
            cin >> car[carsLeft].phone;

            cout << "Номер техпаспорта: ";
            cin >> car[carsLeft].passportNumber;


            origin_file << "Прізвище: "<< car[carsLeft].first << endl;
            origin_file << "Ім'я: "<< car[carsLeft].last << endl;
            origin_file << "По батькові: "<< car[carsLeft].fath << endl;
            origin_file << "Номер автомобіля: "<<car[carsLeft].carNumber << endl;;
            origin_file << "Телефон: "<< car[carsLeft].phone << endl;
            origin_file << "Номер техпаспорта: "<< car[carsLeft].passportNumber << endl;
            origin_file << "----------------------------------------------" << endl;
        }
    }
    origin_file.close();
    cout << "Видалити? ";
    cin >> delete_el;

    if(!updated_file.is_open()) {
        cout << "Файл не відкрився" << endl;
    } else {
        for(int i = 0; i < cars_left; i++) {
            if(delete_el != car[i].carNumber) {

                    updated_file << "Прізвище: " << car[i].first << endl;
                    updated_file << "Ім'я: " << car[i].last << endl;
                    updated_file << "По батькові: " << car[i].fath << endl;
                    updated_file << "Номер автомобіля: " << car[i].carNumber << endl;;
                    updated_file << "Телефон: " << car[i].phone << endl;
                    updated_file << "Номер техпаспорта: " << car[i].passportNumber << endl;
                    updated_file << "----------------------------------------------" << endl;

            }
        }
    }

    cout << "Last Name: ";
    cin >> lastname;

    if(!updated_file.is_open()) {
        cout << "Файл не відкрився" << endl;
    } else {
        for(int i = 0; i < 2; i++) {
            if(lastname ==  car[i].first) {

                cout << "Прізвище: ";
                cin >> car[i].first;

                cout << "Ім'я: ";
                cin >> car[i].last;

        cout << "По батькові: ";
        cin >> car[i].fath;

        cout << "Номер автомобіля: ";
        cin >> car[i].carNumber;

        cout << "Телефон: ";
        cin >> car[i].phone;

        cout << "Номер техпаспорта: ";
        cin >> car[i].passportNumber;

                updated_file << "Прізвище: " << car[i].first << endl;
                updated_file << "Ім'я: " << car[i].last << endl;
                updated_file << "По батькові: " << car[i].fath << endl;
                updated_file << "Номер автомобіля: " << car[i].carNumber << endl;;
                updated_file << "Телефон: " << car[i].phone << endl;
                updated_file << "Номер техпаспорта: " << car[i].passportNumber << endl;
                updated_file << "----------------------------------------------" << endl;
                cout << "Прізвище: ";
                cin >> car[i].first;

                cout << "Ім'я: ";
                cin >> car[i].last;

                cout << "По батькові: ";
                cin >> car[i].fath;

                cout << "Номер автомобіля: ";
                cin >> car[i].carNumber;

                cout << "Телефон: ";
                cin >> car[i].phone;

                cout << "Номер техпаспорта: ";
                cin >> car[i].passportNumber;
                updated_file << "Прізвище: " << car[i].first << endl;
                updated_file << "Ім'я: " << car[i].last << endl;
                updated_file << "По батькові: " << car[i].fath << endl;
                updated_file << "Номер автомобіля: " << car[i].carNumber << endl;;
                updated_file << "Телефон: " << car[i].phone << endl;
                updated_file << "Номер техпаспорта: " << car[i].passportNumber << endl;
                updated_file << "----------------------------------------------" << endl;

            }
        }
    }

    updated_file.close();

    return 0;

}
