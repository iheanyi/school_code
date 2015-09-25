// FILE: simple_string.h
// CLASS PROVIDED: simple_string (a sequence of characters)
//
// CONSTRUCTORS for the simple_string class:
//   simple_string()
//     Postcondition: The simple_string contains an empty sequence of chars.
//
//   simple_string(char c)
//     Postcondition: The simple_string contains an empty sequence of chars.
//
//   simple_string(const char str[ ])
//     Precondition: str is an ordinary null-terminated string.
//     Postcondition: The simple_string contains the sequence of chars from str.
//
//   simple_string(const simple_string& source)
//     Postcondition: The simple_string has the same contents as the source object
//
// DESTRUCTOR for the simple_string class:
//   ~simple_string()
//     Postcondition: All memory allocated by this instance of simple_string is free.
//
// CONSTANT MEMBER FUNCTIONS for the simple_string class:
//   std::size_t length( ) const
//     Postcondition: The return value is the number of characters in the
//     simple_string.
//
//   char operator [ ](std::size_t position) const
//     Precondition: position < length( ).
//     Postcondition: The value returned is the character at the specified
//     position of the simple_string. A simple_string's positions start from 0 at the start
//     of the sequence and go up to length( )-1 at the right end.
//
// MODIFICATION MEMBER FUNCTIONS for the simple_string class:
//   void operator +=(const simple_string& addend)
//     Postcondition: addend has been catenated to the end of the simple_string.
//
//   void operator +=(const char addend[ ])
//     Precondition: addend is an ordinary null-terminated simple_string.
//     Postcondition: addend has been catenated to the end of the simple_string.
//
//   void operator +=(char addend)
//     Postcondition: The single character addend has been catenated to the
//     end of the simple_string.
//
//   void operator =(const simple_string& source)
//     Postcondition: The simple_string has the same contents as the source object
//
// NON-MEMBER FUNCTIONS for the simple_string class:
//   simple_string operator +(const simple_string& s1, const simple_string& s2)
//     Postcondition: The simple_string returned is the catenation of s1 and s2.
//
//   std::ostream& operator <<(ostream& outs, const simple_string& source)
//     Postcondition: The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.

#ifndef SIMPLE_STRING_H
#define SIMPLE_STRING_H
#include <cstdlib>  // Provides std::size_t
#include <iostream> // Provides ostream and istream
#include <vector>

namespace goirish {
    template <typename T>
    class string_node
    {
    // Remove this comment before submitting your work!
    // >>>The student should define a node class here. It may be simple
    // (with nothing more than public data and link) or more complex
    // (as in Chapter 5).<<<
        public:

        string_node(const T& init_data = T(), string_node<T>* init_link = NULL) {
            data = init_data;
            next = init_link;
        }

        T data;
        string_node* next; //Link to next field



    };

    // >>>The student should (1) implement this class and
    //    (2) transform it into a template class called linked_list.<<<

    //template <typename T> T goirish::simple_string<T>::NULL_ELEMENT = T();
    template <typename T>
    class simple_string {

    public:
        // The element that denotes the end of the string ('\0' for char)
        static T NULL_ELEMENT;
        typedef T value_type;


        // CONSTRUCTORS and DESTRUCTOR
        simple_string(); // Done
        simple_string(T c); // Done
        simple_string(const T str[ ]); //Done 
        simple_string(const simple_string<T>& source); //Done
        ~simple_string(); // Done

        // MODIFICATION MEMBER FUNCTIONS
        void pushback(T record);
        void next();
        T returnCurrent();
        T printAll();
        int getSize();
        void traverse();

        string_node<T>* getHead() const;
        string_node<T>* getCurr() const;
        string_node<T>* getTail() const;

        string_node<T>* getHead();
        string_node<T>* getCurr();
        string_node<T>* getTail();

        void setHead(string_node<T> value);
        void setCurr(string_node<T> value);
        void setTail(string_node<T> value);

        void list_head_remove(string_node<T>*& head_ptr);
        void list_remove(string_node<T>*& previous_ptr);
        void list_clear(string_node<T>*& head_ptr);
        void list_copy(const string_node<T>* source_ptr, string_node<T>*& head_ptr, string_node<T>*& tail_ptr);
        void list_insert(string_node<T> *previous_ptr, const T& entry);
        void list_head_insert(string_node<T>*& head_ptr, T entry);


        void operator +=(const simple_string<T>& addend); // Done
        void operator +=(const T addend[ ]); //Done 
        void operator +=(T addend); // Done
        void operator =(const simple_string<T>& source); // NOT DONE

        // CONSTANT MEMBER FUNCTIONS
        std::size_t length( ) const; // Done
        T operator [ ](std::size_t position) const; // Done

    private:
        string_node<T>* head_ptr;
        string_node<T>* tail_ptr;
        string_node<T>* curr_ptr;
        std::size_t many_nodes;
    };

    // Definition of element for end of the string ('\0' for char)
    // >>>The student should add "template <typename T>" before "static"
    //    and replace '\0' with T().<<<


    template <typename T>
    T simple_string<T>::NULL_ELEMENT = T();
}

// NON-MEMBER FUNCTIONS for the simple_string class.
// Remove this comment before submitting your work!
// >>>The student may move these to friend functions if needed.<<<
    template <typename T>
    std::ostream& operator <<(std::ostream& outs, const goirish::simple_string<T>& source);

    template <typename T>
    goirish::simple_string<T> operator+(const goirish::simple_string<T> &s1, const goirish::simple_string<T> &s2);
#endif // SIMPLE_STRING_H

template <typename T>
goirish::simple_string<T>::simple_string() {
    head_ptr = NULL;

    //head_ptr->data = NULL;
    //head_ptr->next = tail_ptr;

    //tail_ptr->data = NULL;
    //tail_ptr->next = NULL;

    curr_ptr = head_ptr;

    many_nodes = 0;

}

template <typename T>
goirish::simple_string<T>::simple_string(T c) {
    head_ptr = NULL;
    many_nodes = 0;

    //pushback(c);

    //list_head_insert(head_ptr, c);

    *this+=c;
}

template <typename T>
goirish::simple_string<T>::simple_string(const T str[]) {
    head_ptr =  NULL;
    tail_ptr = NULL;
    many_nodes = 0;

    for(int i = 0; str[i] != NULL_ELEMENT; ++i) {

    /*    if( i == 0) {
            head_ptr = cursor;
        }
*/

        *this += str[i];
        //cursor = cursor->next;

       /* *this+=cursor->data;
        cursor->next = NULL;
        previous_ptr->next = cursor;
        many_nodes++;
        previous_ptr = cursor;
        tail_ptr = cursor;*/
    }

    //tail_ptr = new string_node<T>;


    //head_ptr->data = NULL;
    //head_ptr->next = tail_ptr;

   // tail_ptr->data = NULL;
    //tail_ptr->next = NULL;

 /*   curr_ptr = head_ptr;

    many_nodes = 0;

    int i = 0;

    //string_node<T>* temp;

    while(str[i] != NULL_ELEMENT) {

        std::cout << str[i];
        list_insert(tail_ptr, str[i]);
        ++i;
    }*/


}

template <typename T>
goirish::simple_string<T>::simple_string(const simple_string<T>& source) {
    string_node<T> *tail_ptr;
    list_copy (source.getHead(), head_ptr, tail_ptr);
    many_nodes = source.many_nodes;

    std::cout << "COPY CONSTRUCTOR" << std::endl;



}

template <typename T>
std::size_t goirish::simple_string<T>::length() const {

    const string_node<T> *cursor;

    size_t answer = 0;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor->next) {
        ++answer;
    }

    return answer;
}

template <typename T>
void goirish::simple_string<T>::next() {

    if(curr_ptr != tail_ptr && curr_ptr->next != NULL) {

        curr_ptr = curr_ptr->next;

    }

    else {
        std::cout << "Can't move to next, already at tail." << std::endl;
    }

}

template <typename T>
goirish::simple_string<T>::~simple_string() {
 
    list_clear(head_ptr);
    many_nodes = 0;
}

template <typename T>
T goirish::simple_string<T>::returnCurrent() {

    if( curr_ptr != tail_ptr || curr_ptr != head_ptr) {
        return curr_ptr->data;
    }

    else {
        return NULL;
    }
}

template <typename T>
void goirish::simple_string<T>::operator+=(const T addend[ ]) {

    std::cout << "ADDING AN ARRAY ON TO THE END" << std::endl;

    for( unsigned int i = 0; addend[i] != NULL_ELEMENT; ++i) {
        *this+=addend[i];
     
            }

        

}

template <typename T>
void goirish::simple_string<T>::operator+=(const simple_string<T>& addend) {
    std::cout << "Adding a word onto the end!" << std::endl;

    
    string_node<T>* cursor;

    cursor = addend.getHead();
    //cursor = added.head_ptr;
    for(int i = 0, n = addend.length(); i < n; ++i) {
        *this+=cursor->data;
        cursor = cursor->next;
        //many_nodes++;
    }
  /*  unsigned int j = 0;

    for(cursor = addend.getHead(); j != addend.length(); cursor = cursor->next) {
    list_insert(tail_ptr, cursor->data);
    cursor = cursor->next;
    j++; 
    }

string_node<T>* cursor3;

many_nodes = 0;

for(cursor3 = head_ptr; cursor3 != NULL; cursor3 = cursor3->next) {

    many_nodes++;
} */


}

template <typename T>
void  goirish::simple_string<T>::operator+=(T addend) {

    //std::cout << "Adding a single character onto the end!" << std::endl;

    if(head_ptr == NULL) {
        head_ptr = new string_node<T>;
        head_ptr->data = addend;
        tail_ptr = head_ptr;
    }

    else {
    tail_ptr->next = new string_node<T>;
    tail_ptr->next->data = addend;
    tail_ptr = tail_ptr->next;

    }

    many_nodes++;
    /*string_node<T>* temp = new string_node<T>;

    head_ptr->next = temp;

    temp->next = tail_ptr;

    temp->data = addend;*/

    //pushback(temp->data);

    //list_head_insert(head_ptr, addend);

}

template <typename T>
T goirish::simple_string<T>::operator [](size_t position) const {
    string_node<T>* temp;

    temp = head_ptr;
    for(unsigned int i = 0; (i < position && temp->next != NULL); ++i) {
        temp = temp->next;
    }
    return (temp->data);

}

template <typename T>
void  goirish::simple_string<T>::operator=(const simple_string<T>& source) {

    

    string_node<T>* tail_ptr;
    list_clear(head_ptr);
    many_nodes = 0;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_nodes = source.many_nodes;

}

template <typename T>
T goirish::simple_string<T>::printAll() {

    if(curr_ptr != tail_ptr || curr_ptr != head_ptr) {

        return (curr_ptr->data);
    }

    else {
        return NULL;
    }
}

template <typename T>
int goirish::simple_string<T>::getSize() {

    return many_nodes;
}

template <typename T>
void goirish::simple_string<T>::traverse() {

    curr_ptr = head_ptr;
    while(curr_ptr != NULL) {
        std::cout << curr_ptr->data << std::endl;
        curr_ptr = curr_ptr->next;
    }
}

template <typename T>
goirish::simple_string<T> operator +(const goirish::simple_string<T> &s1, const goirish::simple_string<T> &s2) {

    goirish::simple_string<T> temp;

    temp += s1;
    temp += s2;

    return temp;
}

template <typename T>
void goirish::simple_string<T>::list_head_remove(string_node<T>*& head_ptr) {

    string_node<T>* remove_ptr;

    remove_ptr = head_ptr;
    head_ptr = head_ptr->next;
    delete remove_ptr;

}


template <typename T>
void goirish::simple_string<T>::list_remove(string_node<T>*& previous_ptr) {
    string_node<T>* remove_ptr;

    remove_ptr = previous_ptr->next;
    previous_ptr->next = remove_ptr->next;

    delete remove_ptr;

}

template <typename T>
void goirish::simple_string<T>::list_clear(string_node<T>*& head_ptr) {

    while(head_ptr != NULL) {

        list_head_remove(head_ptr);
    }
}

template <typename T>
void goirish::simple_string<T>::list_copy(const string_node<T>* source_ptr, string_node<T>*& head_ptr, string_node<T>*& tail_ptr) {

    std::cout << "COPYING!" << std::endl;
    head_ptr = NULL;
    tail_ptr = NULL;

    if (source_ptr == NULL) {
        return;
    }

    list_head_insert(head_ptr, source_ptr->data);
    tail_ptr = head_ptr;

    source_ptr = source_ptr->next;

    while(source_ptr != NULL) {
        list_insert(tail_ptr, source_ptr->data);
        tail_ptr = tail_ptr->next;
        source_ptr = source_ptr->next;
    }

}

template <typename T>
void goirish::simple_string<T>::list_insert(string_node<T> *previous_ptr, const T& entry) {

    string_node<T>* insert_ptr;
    insert_ptr = new string_node<T>;

    insert_ptr->data = entry;

    
    insert_ptr->next = previous_ptr->next;
    previous_ptr->next = insert_ptr;

    many_nodes++;
    


}

template <typename T>
void goirish::simple_string<T>::list_head_insert(string_node<T>*& head_ptr, T entry) {

    head_ptr = new string_node<T>;
    head_ptr->data = entry;
    head_ptr->next = NULL;

}

template<typename T>
goirish::string_node<T>* goirish::simple_string<T>::getHead() {
    return head_ptr;
}

template<typename T>
goirish::string_node<T>* goirish::simple_string<T>::getCurr() {
    return curr_ptr;
}

template<typename T>
goirish::string_node<T>* goirish::simple_string<T>::getTail() {
    return tail_ptr;
}

template<typename T>
goirish::string_node<T>* goirish::simple_string<T>::getHead() const{
    return head_ptr;
}

template<typename T>
goirish::string_node<T>* goirish::simple_string<T>::getCurr() const {
    return curr_ptr;
}

template<typename T>
goirish::string_node<T>* goirish::simple_string<T>::getTail() const {
    return tail_ptr;
}

template<typename T>
void goirish::simple_string<T>::setHead(string_node<T> value) {
    head_ptr = value;
}

template<typename T>
void goirish::simple_string<T>::setCurr(string_node<T> value) {
  curr_ptr = value;
}

template<typename T>
void goirish::simple_string<T>::setTail(string_node<T> value) {
    tail_ptr = value;
}

template <typename T>
std::ostream& operator<<(std::ostream& outs, const goirish::simple_string<T>& source) {
    goirish::string_node<T>* p;
    p = source.getHead();

    while(p != NULL) {

        outs << p->data;
        p = p->next;
    }

    return outs;
}
