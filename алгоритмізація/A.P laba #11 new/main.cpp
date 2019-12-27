#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>
using std::string;
using namespace std;
template<typename T>
class SparseOneDimensionalArray
{
    class Node;
    using PNode = std::shared_ptr < Node >;
private:
    PNode pFirst;
    PNode pLast;

public:
    SparseOneDimensionalArray() = default;                                   // Конструктор
    SparseOneDimensionalArray& operator=(const SparseOneDimensionalArray& array);          // Присвоєння
    T& operator[](int index);                                  // Посилання SparseArray
    bool element_exists(int index);                             // return true
    void show();                                                // show

private:
    class Node
    {
    public:
        int index {};
        T* pObject;
        PNode pNext;
        PNode pPrevious;

        Node(int newIndex) : index(newIndex), pObject(new T) {}
        Node(const Node& node) : index(node.index), pObject(new T(*node.pObject)) {}
        ~Node(){ delete pObject; }
    };
};

template<typename T> SparseOneDimensionalArray<T>& SparseOneDimensionalArray<T>::operator=(const SparseOneDimensionalArray& array)
{
    if (this == &array)
        return *this;

    PNode pCurrent;
    if (array.pFirst)
    {
        pLast = pFirst = std::make_shared<Node>(*array.pFirst);
        Node* pTemp;
        pCurrent = array.pFirst;
    }
    return *this;
}

template<typename T> T& SparseOneDimensionalArray<T>::operator[](int index)
{
    PNode pCurrent {pFirst};
    while (pCurrent)
    {
        if (pCurrent->index == index)
            return *pCurrent->pObject;
        if (pCurrent->index > index)
            break;
        pCurrent = pCurrent->pNext;
    }

    PNode pNode = std::make_shared<Node>(index);
    pNode->pObject = new T;
    if (pCurrent)
    {
        if (pCurrent->pPrevious)
        {
            pCurrent->pPrevious->pNext = pNode;
            pNode->pPrevious = pCurrent->pPrevious;
            pCurrent->pPrevious = pNode;
            pNode->pNext = pCurrent;
        }
        else
        {
            pNode->pNext = pCurrent;
            pCurrent->pPrevious = pNode;
            pFirst = pNode;
        }
    }
    else
    {
        if (pLast)
        {
            pLast->pNext = pNode;
            pNode->pPrevious = pLast;
            pLast = pNode;
        }
        else
            pFirst = pLast = pNode;
    }
    return *pNode->pObject;
}

template<typename T> void SparseOneDimensionalArray<T>::show()
{
    PNode pCurrent {pFirst};
    while (pCurrent)
    {
        std::cout << "\n[" << std::setw(2) << pCurrent->index << "] : " << *pCurrent->pObject;
        pCurrent = pCurrent->pNext;
    }
    std::cout << std::endl;
}

template<typename T>
bool SparseOneDimensionalArray<T>::element_exists(int index)
{
    PNode p {pFirst};
    while (p)
    {
        if (p->index == index) return true;
        p = p->pNext;
    }
    return false;
}

int random(int count)
{
    return static_cast<int>((count*static_cast<unsigned long>(rand()))/(RAND_MAX+1UL));
}

int main()
{
    SparseOneDimensionalArray<int> numbers;
    SparseOneDimensionalArray<float> double1;

    const int count {5};
    float index {};
    srand((unsigned)time(0));

    try
    {
        for (int i {}; i < count; ++i)
        {
            for(;;)
            {
                index = random(55);

                if (numbers.element_exists(index)) continue;
                if (double1.element_exists(index)) continue;

                break;
            }
            numbers[index] = 5+random(22);
            double1[index] = 5.5323+random(22);
        }
    }
    catch(std::exception& e)
    {
        std::cout << "\nException thrown " << e.what() << std::endl;
    }



//    cout << double1[34] << endl;
//    cout << double1[53] << endl;
//    cout << double1[11] << endl;
//    cout << endl;
//    cout << "Double" << endl;
        double1.show();
//    cout << endl;
//    cout << "Int" << endl;
//    numbers.show();
}
