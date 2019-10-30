#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int bufsize = 255;

int main ()
{
  char string[bufsize];
  cout << "text: ";
  fgets (string, sizeof (string), stdin);

  int i = 0,count, j;
  char *p = strtok (string, " .");
  char *array[5];
  while (p != NULL)
  {
      array[i++] = p;
      p = strtok (NULL, " .");
  }
  for (i = 0; i < 5; ++i)
      printf("%s\n", array[i]);
    cout << "Зустрічаються в рядку по одному разy:" << "\n";

    for(i = 0; i < 5; i++){
           count = 1;
           for(j = i+1; j < 5; j++){
              if(strcmp(array[i], array[j]) == 0 && (strcmp(array[j],"0") != 0)){
                  count++;
                  strcpy(array[j],"0");
              }
           }
//           if(count == 1)
////               printf("%s\n", array[i]);
//                 cout << array[i] << "--" << count << "\n";
//         if(count > 1) {
//            cout << array[i] << "--" << count << "\n";
//        } else
            if(count == 1) {
              cout << array[i]  << "\n";
            }
//        else {
//            cout << array[i] << "--" << count << "\n";
//
//        }
 }
    return 0;
}
