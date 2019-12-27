#include<iostream>
#include <fstream>
#include <string>

using namespace std;
struct node{
    node *prev;
    char data;
    node *next;
};
struct node *start=NULL;
node* create_node(){
    node *n = new node;
    cout<<"Please enter the Data"<<endl;
    cin>>n->data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}
node* create_node1(char x){
    node *n = new node;
    n->data = x;
    n->next = NULL;
    n->prev = NULL;
    return n;
}
// Додаванн
void insert_node(){
    node *temp;
    temp = create_node();
    if(start == NULL){
        start = temp;
    }
    else{
        node *traverse;
        traverse = start;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next=temp;
        temp->prev=traverse;
    }
}
void insert_node1(char x){
    node *temp;
    temp = create_node1(x);
    if(start == NULL){
        start = temp;
    }
    else{
        node *traverse;
        traverse = start;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next=temp;
        temp->prev=traverse;
    }
}
void from_file_to_list() {
    ifstream f1;
    f1.open("filename.txt");
    string str;
    if(f1.is_open()) {
        while(!f1.eof()) {
            str = "";
            getline(f1, str);
            insert_node1(str[0]);
        }
    }
}
// Display
void display(){
    node *traverse;
    traverse  = start;
    if(traverse == NULL) {
        cout << "Список є порожнім" << endl;
    } else {
        cout<< "Дані: ";
        while(traverse!=NULL){
            cout<<traverse->data<<" ";
            traverse = traverse->next;
        }
    }
}
// Заповнення файлу елементами
void to_file(){
    node *traverse;
    traverse  = start;
    ofstream MyFile("filename.txt");
    while(traverse!=NULL){
        MyFile << traverse->data;
        MyFile << "\n";
        traverse = traverse->next;
    }
    cout<<"Готово."<<endl;

    MyFile.close();
}
// Видалення  елемента за позицією
void delete_given(){
    int n;
    cout<<"Позиція елемента: "<<endl;
    cin >> n;
    struct node* temp = start;
    if (n == 1) {
        start = temp->next;
        free(temp);
    }
    int i;
    for (i = 0; i<n-2; i++) {
        temp = temp->next;
    }
    struct node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    display();
}
// Видалення всіх елементів
void delete_all_nodes(){
    do {
        node *temp;
        temp = start;
        start = start->next;
        cout << temp->data << " видалено" << endl;
        delete (temp);
    } while (start != NULL);
        cout << "Список є порожнім" << endl;
}

void addkelements() {
    cout << "Додати К елементів у кінець списку.: " << endl;
    int nkd;
    cin >> nkd;
    for(int i =0; i< nkd; i++) {
        insert_node();
    }
}
int main(){
    int option;
    cout<<"\nEnter 0 If You want to exit"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"1 Додати елемент"<<endl;
    cout<<"2 Видалити всі елементи"<<endl;
    cout<<"6 Видалити елемент за позицією"<<endl;
    cout<<"7 Display"<<endl;
    cout<<"8 To file"<<endl;
    cout<<"9 From file to list"<<endl;
    cout<<"10 Додати К елементів у кінець списку."<<endl;

    do{
        cout << endl;
        cout << "Enter: ";
        cin>>option;
        switch(option){
            case 1:insert_node();
                break;

            case 2:delete_all_nodes();
                break;
            case 6: delete_given();
                break;
            case 7: display();
                break;
            case 8: to_file();
                break;
            case 9: from_file_to_list();
                break;
            case 10:addkelements();
                break;
        }
    }while(option != 0);
    return 0;}
