/* CDL_List.h 

Coded by Iheanyi Ekechukwu */

#include <iostream>
#include <deque>
#include <iterator>
#ifndef CDL_LIST_H
#define CDL_LIST_H

using namespace std;
  
template <typename T>
class cdl_list {
  public:
    cdl_list();
    ~cdl_list();
    void insertFromFront(const T &);
    void insertFromBack(const T &);
    void deleteFront();
    void deleteBack();
    bool isEmpty();
    void print();
    void reset();
    void next();
    T currentValue();
    void Delete();
    cdl_list<T> operator++();
    cdl_list<T> operator++(int);
    cdl_list<T> operator--();
    cdl_list<T> operator--(int);
    int getSize();
  private:
    deque<T> myDeck;
    int current;
    int i;

};
#endif

template <typename T>
cdl_list<T>::cdl_list() {
i = 0;

}

template <typename T>
cdl_list<T>::~cdl_list() {
  
}
template <typename T>
void cdl_list<T>::insertFromFront(const T &data) {
  myDeck.push_front(data);
}

template <typename T>
void cdl_list<T>::insertFromBack(const T &data) {
  myDeck.push_back(data); 
}

template <typename T>
void cdl_list<T>::deleteFront() {
 myDeck.pop_front(); 
}

template <typename T>
void cdl_list<T>::deleteBack() {
  myDeck.pop_back();
}

template <typename T>
bool cdl_list<T>::isEmpty() {
  return myDeck.empty();
}

template <typename T>
void cdl_list<T>::print() {
    ostream_iterator<int> output(cout, " ");
    copy(myDeck.begin(), myDeck.end(), output);
    cout << endl;
}

template <typename T>
void cdl_list<T>::reset() {
i = 0;
current = myDeck[0];
}

template <typename T>
void cdl_list<T>::next() {
i++;
current = myDeck[i];
}

template <typename T>
T cdl_list<T>::currentValue() {
  
  return current;
}
template <typename T>
void cdl_list<T>::Delete() {
  myDeck.erase(myDeck.begin() + i);
  //i--;
  current = myDeck[i-1];

}

template <typename T>
cdl_list<T> cdl_list<T>::operator++() {
  i+=1;
  current=myDeck[i];
  return *this;
}

template <typename T>
cdl_list<T> cdl_list<T>::operator++(int) {
  i+=1;
 cdl_list temp = *this;
 current = myDeck[i];
 return temp;
}

template <typename T>
cdl_list<T> cdl_list<T>::operator--() {
  i-=1;
  current=myDeck[i];
  return *this;
}

template <typename T>
cdl_list<T> cdl_list<T>::operator--(int) {
  i-=1;
  cdl_list temp = *this;
 current = myDeck[i];

 return temp;
}

template <typename T>
int cdl_list<T>::getSize() {
return myDeck.size(); 
}
