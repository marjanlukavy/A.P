#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
struct person {
    char name[10];
    int carNumber;
    char number[10];
    int techPassport;
};

int createBinFile(char *fname) {
    FILE *fp;
    struct person newrecord;

    fp=fopen(fname,"wb");
    if (!fp) {
        printf("Unable to open file!");
        return -1;
    }
    cout << "Скільки структур: " << endl;
    int p;
    cin >> p;
    for(int i = 0; i < p; i++) {
        cout << "Name" << endl;
        scanf("%s", newrecord.name);
        // newrecord.name="aaa bbbb";
        cout << "carNumber" << endl;
        scanf("%i", &newrecord.carNumber);
        // newrecord.code=12345;
        cout << "Number" << endl;
        scanf("%s", newrecord.number);
        // 	newrecord.number=1;
        cout << "techPassport" << endl;
        scanf("%i", &newrecord.techPassport);
        fwrite(&newrecord, sizeof(struct person), 1, fp);
    }

    fclose(fp);
    return 0;
}

int anotherBinFile(char *fname) {
    FILE *fp;
    struct person newrecord;

    fp=fopen(fname,"a");
    if (!fp) {
        printf("Unable to open file!");
        return -1;
    }
    for(int i = 0; i < 2; i++) {
        cout << "Name" << endl;
        scanf("%s", newrecord.name);
        // newrecord.name="aaa bbbb";
        cout << "carNumber" << endl;
        scanf("%i", &newrecord.carNumber);
        // newrecord.code=12345;
        cout << "Number" << endl;
        scanf("%s", newrecord.number);
        // 	newrecord.number=1;
        cout << "techPassport" << endl;
        scanf("%i", &newrecord.techPassport);
        fwrite(&newrecord, sizeof(struct person), 1, fp);
    }

    fclose(fp);
    return 0;
}

int readBinFile(char *fname) {
    FILE *fp;

    struct person myrecord;

    fp=fopen(fname,"rb");
    if (!fp) {
        printf("Unable to open file!");
        return -1;
    }

    while (fread(&myrecord,sizeof(struct person),1,fp) != NULL) {
            cout << "**************" << endl;
            cout << "Name: ";
            printf("%s\n", myrecord.name);
            cout << "carNumber: ";
            printf("%i\n", myrecord.carNumber);
            cout << "Numbe: ";
            printf("%s\n", myrecord.number);
            cout << "techPassport" << endl;
            printf("%i\n", myrecord.techPassport);
            cout << "**************" << endl;
    }
    fclose(fp);
    return 0;

}

int deleteRecordByName(char *fname, char *searchname) {
    FILE *fp;
    FILE *fp_tmp;
    int found=0;
    struct person myrecord;

    fp=fopen(fname, "rb");
    if (!fp) {
        printf("Unable to open file %s", fname);
        return -1;
    }
    fp_tmp=fopen("tmp.bin", "wb");
    if (!fp_tmp) {
        printf("Unable to open file temp file.");
        return -1;
    }

    while (fread(&myrecord,sizeof(struct person),1,fp) != NULL) {
        if (strcmp (searchname, myrecord.number) == 0) {
            printf("Видалено.\n\n");
            found=1;
        } else {
            fwrite(&myrecord, sizeof(struct person), 1, fp_tmp);
        }
    }
    if (! found) {
        printf("Не знайдено: %s\n\n", searchname);
    }

    fclose(fp);
    fclose(fp_tmp);

    remove(fname);
    rename("tmp.bin", fname);

    return 0;
}

int main() {
    int result, errno;
    createBinFile("test.bin");

    readBinFile("test.bin");

    cout << "Delete by number" << endl;
    char n[10];
    cin >> n;
    deleteRecordByName("test.bin", n);

    readBinFile("test.bin");
    cout << "Введiть двi структури елементiв масиву,якi будуть доданi на початок" << endl;
    anotherBinFile("test.bin");

    readBinFile("test.bin");
    return 0;
}