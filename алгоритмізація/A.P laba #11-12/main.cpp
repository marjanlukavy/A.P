#include <iostream>
#include <vector>
#include <string>
using  namespace std;
template<typename T, size_t aSize>
class Array
{
    int mCounter;
    int cap;
public:
    Array();
    ~Array();
    bool isEmpty();
    void Add(T data);
    int Find(T data);
    void show();
    void removeAll();
    int GetUpperBound();
    void push(T const&);
    void pop();
    T begin () const;
    T top() const;
    void RemoveAt(int position);
    constexpr size_t size() {
        return mCounter;
    }
    T &operator[](size_t aIndex) {
        return mData[aIndex];
    }
    const T &operator[](size_t aIndex)const {
        return mData[aIndex];
    }
    T *data() {
        return mData;
    }
    const T *data()const {
        return mData;
    }
    T* end() {
        return mData+aSize;
    }
    const T* end() const{
        return mData+aSize;
    }

private:
    T *mData;
    vector<T> elems;
};
                                                    /* Array */
template <typename T, size_t aSize>
Array<T, aSize>::Array()
{
      this->mCounter = 0;
      this->cap = aSize;
      this->mData = new T[this->cap];

}
                                                    /* ~Array */
template <typename T, size_t aSize>
Array<T, aSize>::~Array()
{
   delete [] this->mData;
}
                                                    /* Видалення */
template <typename T, size_t aSize>
void Array<T, aSize>::removeAll()
{
    free(mData);
    mCounter=0;

}
                                                   /* Порожній? */
template<typename T, size_t aSize>
bool Array<T, aSize>::isEmpty() {
    if (mCounter==0) {
        return true;
    }else {
        return false;
    }
}
                                                        /*  Додавання */
template <typename T, size_t aSize>
void Array<T, aSize>::Add(T data)
{
    if(mCounter<aSize)
    {
        mData[mCounter++]=data;
    }
}
                                                            /* Знайти */
template <typename T, size_t aSize>
int Array<T, aSize>::Find(T data)
{
    for (int i = 0; i < aSize; i++) {
        if(data == mData[i]) {
            return i;
        }
    }
    for (int j = 0; j < aSize; j++) {
        if(data != mData[j]) {
            mData[mCounter++] = data;
            break;
        }
    }
}
                                                            /* Перегляд */
template <typename T, size_t aSize>
void Array<T, aSize>::show()
{
    for (int i = 0; i < mCounter; i++) {
         cout << i << ": " << mData[i] << endl;
    }
}
                                                            /* remove at */
template <typename T, size_t aSize>
void Array<T, aSize>::RemoveAt(int position)
{
    if(position<0||position>=mCounter)
    {
        return;
    }

    for(int i = position; i<mCounter; i++)
    {
        mData[i]=mData[i+1];
    }

    mCounter--;
}

template <typename T, size_t aSize>
void Array<T, aSize>::push (T const& elem) {
    elems.push_back(elem);
}

template <typename T, size_t aSize>
void Array<T, aSize>::pop () {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();
}

template <typename T, size_t aSize>
T Array<T, aSize>::top () const {
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }

    return elems.back();
}
template <typename T, size_t aSize>
T Array<T, aSize>::begin () const {

    return elems[0];
}
int main() {
                                                                /* Char */
        Array<char,5> char_arr;
        cout << "Char ";
        char_arr[1] = 'b';
        cout << char_arr[1];
        cout << endl;
        //    Array<double,5> double_arr;
        //    cout << "Double ";
        //    double_arr[1] = 2.33;
        //    cout << double_arr[1];
        //    cout << endl;
                                                                /* FLOAT */
        Array<float, 5> float_arr;
        cout << "Float ";float_arr[1] = 1.22;
        cout << float_arr[1];
        cout << endl;
                                                                 /* INT */
        Array<int, 5> arr;
        cout << "Int ";
        arr[0] = 1;
        cout << arr[0] << "\n";

        cout << endl;
                                                                  /* Add elements */
        Array<int, 10>  int_array;

        cout << "int_array.Add(2) " << endl;

        int_array.Add(2);
        cout << "int_array.Add(4) " << endl;;

        int_array.Add(4);
        cout << "int_array.Add(6) " << endl;;
        cout << endl;
        int_array.Add(6);
        cout << "Show: " << "show()" << endl;
        int_array.show();
        cout << endl;

        cout << "Find: " << "Find(8)" << endl;
        int_array.Find(8);
        cout << endl;
        cout << "Show: " << "show()" << endl;
        int_array.show();
        cout << endl;
        cout << "Find: " << "Find(4)" << endl;
        cout << int_array.Find(4) << endl;
        cout << endl;
        cout << "Show: " << "show()" << endl;
        int_array.show();
        cout << endl;
        //    cout << endl;
//    cout << int_array.Find(8) << endl;
//    cout << int_array.Find(2) << endl;
//    cout << int_array.Find(9) << endl;
//    int_array.show();
//    cout << int_array.Find(91) << endl;
//    int_array.show();
//    cout << endl;
        cout << "Remove: " << "removeAt(1)" << endl;
        int_array.RemoveAt(1);
        int_array.show();
        /* Vector */
        cout << endl;
        cout << "\t" << "Vector" << endl;
        cout << endl;
        Array<float,5> intStack;
//                                                Array<string,5> stringStack;
        cout << "intStack.push(7) " << endl;
        intStack.push(7);
        cout << "intStack.push(8) " << endl;
        intStack.push(8);
        cout << "intStack.push(9) " << endl;
        intStack.push(9);
        cout << "intStack.top(), last element : " << endl;
        cout << intStack.top() <<endl;
        cout << "intStack.push(555) " << endl;
        intStack.push(555);
        cout << endl;
        cout << "intStack.top(), last element : " << endl;
        cout << intStack.top() <<endl;
        cout << endl;
        cout << "intStack.begin(), first element : " << endl;
        cout << intStack.begin() <<endl;
        cout << endl;
        cout << "intStack.pop(), delete : " << endl;
        intStack.pop();
        cout << "intStack.top() " << endl;
        cout << intStack.top() <<endl;




    return 0;
}


