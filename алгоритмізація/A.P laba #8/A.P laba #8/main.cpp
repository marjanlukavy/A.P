#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <stdlib.h>

using namespace std;

struct OwnerOfAuto
{
  string first;
  string last;
  string fath;
  string NumberOfAuto;
  int NumberTechPassport;
  string passportNumber;
}People[255];

void Fopen(ofstream* fout) {
  fout->open("file.dat",ios_base::binary);
if (!fout->is_open())
    {
    cout << "Помилка!Файл не може бути вiдкритим!" << endl;
    exit(0);
  }
}

void Ffill(OwnerOfAuto People[255], int Structnumb) {
  for (int i = 0; i < Structnumb; i++) {
      cout << "Прізвище: ";
      cin >> People[i].first;

      cout << "Ім'я: ";
      cin >> People[i].last;

      cout << "По батькові: ";
      cin >> People[i].fath;

      cout << "Номер автомобіля: ";
      cin >> People[i].NumberOfAuto;

      cout << "Телефон: ";
      cin >> People[i].NumberTechPassport;

      cout << "Номер техпаспорта: ";
      cin >> People[i].passportNumber;

  }
}

void Ftrans(OwnerOfAuto People[255], ofstream* fout, int Structnumb) {
  for (int i = 0; i < Structnumb; i++) {

    fout->write((char*)&People[i], sizeof(OwnerOfAuto));
  }
}


void Fshow(OwnerOfAuto People[255], int Structnumb) {
  for (int i = 0; i < Structnumb; i++) {
    cout << "Прiзвище: " << People[i].first << endl;
    cout  << "Імя " << People[i].last << endl;
    cout  << "По-батьковi: " << People[i].fath << endl;
    cout << "Номер автомобiля: " << People[i].NumberOfAuto << endl;
    cout << "Телефон: " << People[i].NumberTechPassport << endl;
    cout << "Номер техпаспорта: " << People[i].passportNumber << endl;
  }
}

void Fdell(OwnerOfAuto People[255], int Structnumb, int PointerOnDell, int* NotDELLStruct) {
  for (int i = 0; i < Structnumb; i++) {
        if (i+1 == PointerOnDell) {
          for (int k = i; k < Structnumb - 1; k++) {
            People[k] = People[k + 1];
          }
        }
        else {
          (*NotDELLStruct)++;
        }
  }
}

void Fadd(OwnerOfAuto People[255], int NotDELLStruct) {
  int k = NotDELLStruct - 1;
  for (k; k >= 0; k--) {
    People[k+2] = People[k];
  }
 cout <<"Введiть двi структури елементiв масиву,якi будуть доданi на початок: "<< endl;
  for (int i = 0; i < 2; i++) {
      cout << "Прiзвище: ";
      cin >> People[i].first;
      cout << "Імя: ";
      cin >> People[i].last;
      cout << "По-батьковi: ";
      cin >> People[i].fath;
      cout << "Номер автомобiля: ";
      cin >> People[i].NumberOfAuto;
      cout << "Телефон: ";
      cin >> People[i].NumberTechPassport;
      cout << "Номер техпаспорта: ";
      cin >> People[i].passportNumber;
  }
}

int main() {
    setlocale(LC_ALL,"UKR");
  ofstream* fout = new ofstream;

  int Structnumb;

  cout << "Введiть кiлькiсть структур: ";
  cin >> Structnumb;

  Fopen(fout );
  Ffill(People, Structnumb);
  Ftrans(People, fout, Structnumb);
  fout->close();  //зарикває файл
  Fshow(People, Structnumb);

  int PointerOnDell;
  int NotDELLStruct = 0;

cout << "Delete: ";
  cin >> PointerOnDell;
Fdell(People, Structnumb, PointerOnDell, &NotDELLStruct);
Fshow(People, NotDELLStruct);
Fadd(People, NotDELLStruct);
Fshow(People, NotDELLStruct + 2);
Fopen(fout);
Ftrans(People, fout, NotDELLStruct + 2);
fout->close();

  delete fout;
}
