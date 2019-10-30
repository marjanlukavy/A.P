#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>

using namespace std;



int  main() {
    string a;

    int i,j,s,s2,fir,sec,n;
    cout << "Size 1: ";
    cin >> s;
    cout << "Size 2: ";
    cin >> s2;
    int Matr[s][s2];
    cout << "Array element: " << "\n";

    for (i = 0; i<s; i++) {
        for (j = 0; j<s2; j++) {
            scanf("%d",&Matr[i][j]);
        }
    }
    
    for (i = 0; i<s; i++) {
           for (j = 0; j<s2; j++) {
               printf("\t%d",Matr[i][j]);
           }
        printf("\n");
    }
  
    for (i = 0; i<s; i++) {
           for (j = 0; j<s2; j++) {
               if(Matr[i][j] < Matr[i+1][j]){
//                   Matr[i][j] = Matr[i+1][j];
                   if(Matr[i+1][j] < Matr[i+2][j]) {
                       int tmp = Matr[i+1][j];
                       Matr[i+1][j] = Matr[i+2][j];
                       Matr[i+2][j] = tmp;
                   }
               }
           }
        printf("\n");
    }
    
    
      cout << "Show/del" << endl;
      while(cin >> a){
          if(a == "show"){
           for (i = 0; i<s; i++) {
                     for (j = 0; j<s2; j++) {
                         printf("\t%d",Matr[i][j]);
                     }
                  printf("\n");
              }
          }
          if(a == "del"){
              cout << "chos e column number: ";
                cin >> fir;
                cout << "chose row number: ";
                cin >> sec;
                cout << "number: ";
                cin >> n;
                for (i = 0; i<s; i++) {
                        for (j = 0; j<s2; j++) {
                            Matr[fir][sec] = n;
                        }
                     printf("\n");
                 }
          }
          if(a == "swipe"){
              int swapped;
                do {
                   swapped = false;
               for ( i = 0; i < 3; i++) {
                   for ( j = 0; j < 3; j++) {
                       if (Matr[i][j] > Matr[i + 1][j]) {
                           int tmp = Matr[i][j];
                           Matr[i][j]= Matr[i + 1][j];
                           Matr[i + 1][j] = tmp;
                           swapped = true;

                       }
                   }
               }
                } while (swapped);
                           int tmp = Matr[0][0];
                           Matr[0][0]= Matr[2][0];
                           Matr[2][0] = tmp;
                           int tm = Matr[0][1];
                           Matr[0][1]= Matr[1][1];
                           Matr[1][1] = tm;
//              if(Matr[0][1] < Matr[2][0]) {
//                  int sw = Matr[0][2];
//                  Matr[0][2]= Matr[1][2];
//                  Matr[1][2] = sw;
//              }
                           int t = Matr[2][2];
                           Matr[2][2]= Matr[0][2];
                           Matr[0][2] = t;
              if(Matr[0][2] < Matr[1][2] || Matr[1][2] > Matr[1][1]) {
                  int sw = Matr[0][2];
                  Matr[0][2]= Matr[1][2];
                  Matr[1][2] = sw;
              }
          }
      }
    return 0;
}





