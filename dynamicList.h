// File dynamicList.h: Header file for Unsorted List ADT.
#include <iostream>
#include <string>
using namespace std;

const int defmaxlistsize=50;

template <class ITEMTYPE>
class dynamicList   
{
public:
    dynamicList(); 		
    dynamicList(int maxnumber);
    ~dynamicList();   	
    bool Full() const;
    bool Empty() const;
    void Getlast(ITEMTYPE &item, bool &found);
    bool Insert(ITEMTYPE item);
    ITEMTYPE RemoveLast(ITEMTYPE item, bool &found);
    ITEMTYPE RemoveOne(ITEMTYPE item, bool &found);
    bool Search(ITEMTYPE item);
    int GetLocation(ITEMTYPE item);
    void Clear();
    void Print() const;
    void BubbleSort();
    bool BinarySearch(ITEMTYPE item);
    bool InsertAt (ITEMTYPE item, int index);
    ITEMTYPE getItem(int index);
    friend class Box;
  
private:
    ITEMTYPE *element;
    int length;
    int size;
};

#include "dynamicList.cpp"
