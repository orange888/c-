#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
struct Node
{
    T _data;
    Node<T>* _next;
    Node<T>* _prev;

    Node(const T& x)
        :_data(x)
         ,_next(NULL)
         ,_prev(NULL)
    {}
};

template<class T>

class list
{
public:
    list()
        :_head(NULL)
    {}
    ~list()
    {
        clear();
    }
    list(list<T>& l)
        :_head(NULL)
         ,_tail(NULL)
    {
        Node<T>* begin = l._head;
        while(begin)
        {
            pushback(begin->_data);
            begin = begin->_next;
        }
    }
    void Swap(list<T>& l)
    {
        swap(_head,l._head);
        swap(_tail,l._tail);
    }
    list& operator=(list l)
    {
        Swap(l);
        
        return *this;
    }
    void print()
    {
        Node<T>* begin = _head;
        while(begin)
        {
            cout<<begin->_data<<"->";
            begin = begin->_next;
        }
        cout<<"NULL"<<endl;
    }
    void clear()
    {
        Node<T>* begin = _head;
        while(begin)
        {
            Node<T>* del = begin;
            begin = begin->_next;
            delete del;
        }
    }
public:
    //_tail
    void pushback(const T& x);
    void popback();
    //_head
    void pushfront(const T& x);
    void popfront();
    //insert find  erase reverse
    void insert(Node<T>* pos , const T& x);
    Node<T>* find(const T& x);
    void erase(Node<T>* n);
    void reverse();
private:
    Node<T>* _head;
    Node<T>* _tail;
};

template<class T>
void list<T>::pushback(const T& x)
{
    //1.no node
    //2.more node
    if(_head == NULL)
    {
        _head = new Node<T>(x);
        _tail = _head;
    }
    else
    {
        Node<T>* tmp = new Node<T>(x);
        _tail->_next = tmp;
        tmp->_prev = _tail;
        _tail = tmp;
    }
}

template<class T>
void list<T>::popback()
{
    //1.no node
    //2.one node
    //3.more node
    if(_head == NULL)
    {
        return;
    }
    else if(_head == _tail)
    {
        delete _head;
        _head = NULL;
        _tail = NULL;
    }
    else
    {
        Node<T>* del = _tail;
        _tail = _tail->_prev;
        _tail->_next = NULL;
        delete del;
    }
}

template<class T>
void list<T>::pushfront(const T& x)
{
    //1.no node
    //2.more node
    if(_head == NULL)
    {
        _head = new Node<T>(x);
        _tail = _head;
    }
    else
    {
        Node<T>* tmp = new Node<T>(x);
        tmp->_next = _head;
        _head->_prev = tmp;
        _head = tmp;
    }
}

template<class T>
void list<T>::popfront()
{
    //1.no node
    //2.one node 
    //3.more node
    if(_head == NULL)
    {
        return;
    }
    else if(_head == _tail)
    {
        delete _head;
        _head = NULL;
        _tail = NULL;
    }
    else
    {
        Node<T>* del = _head;
        _head = _head->_next;
        _head->_prev = NULL;
        delete del;
    }
}

template<class T>
void list<T>::insert(Node<T>* pos,const T& x)
{
    assert(pos);
    Node<T>* tmp = new Node<T>(x);
    
    if(pos == _tail)
    {
        pos->_next = tmp;
        tmp->_prev = pos;
        _tail = tmp;
        return;
    }

    Node<T>* next = pos->_next;
    tmp->_next = next;
    next->_prev = tmp;

    pos->_next = tmp;
    tmp->_prev = pos;
}
template<class T>
Node<T>* list<T>::find(const T& x)
{
    Node<T>* begin = _head;
    while(begin)
    {
        if(begin->_data == x)
        {
            return begin;
        }
        begin = begin->_next;
    }
    return NULL;
}
template<class T>
void list<T>::erase(Node<T>* n)
{
    assert(n);
    if(n == _head)
    {
        popfront();
    }
    else if(n == _tail)
    {
        popback();
    }
    else
    {
        Node<T>* next = n->_next;
        Node<T>* prev = n->_prev;
        prev->_next = next;
        next->_prev = prev;
        delete n;
    }
}
template<class T>
void list<T>::reverse()
{
    if(_head == _tail)
    {
        return;
    }
    Node<T>* newhead = _head;
    Node<T>* begin = _head->_next;
    while(begin)
    {
        Node<T>* tmp = begin;
        begin = begin->_next;

        tmp->_next = newhead;
        newhead->_prev = tmp;
        newhead = tmp;
    }
    _tail = _head;
    _head = newhead;

    _head->_prev = NULL;
    _tail->_next = NULL;
}
void test()   //pushback popback
{
    list<int> l;

    l.pushback(1);
    l.pushback(2);
    l.pushback(3);

    l.print();

    l.popback();

    l.print();
}
void test1()    //pushfront popfront
{
    list<int> l;
    l.pushback(1);
    l.pushback(2);
    l.pushback(3);
    l.print();
    l.pushfront(4);
    l.pushfront(5);
    l.print();
    l.popfront();
    l.print();
}
void test2() //insert
{
    list<int> l;
    l.pushback(1);
    l.pushback(2);
    l.pushback(3);

    Node<int>* ret = l.find(2);
    l.insert(ret,4);
    l.print();
    ret = l.find(3);
    l.insert(ret,9);
    l.print();
}
void test3()
{
    list<int> l;
    l.pushback(1);
    l.pushback(2);
    l.pushback(3);
    l.pushback(4);
    Node<int>* ret = l.find(3);
    l.print();
    l.erase(ret);
    l.print();
    l.reverse();
    l.print();
    
    list<int> c(l);
    c.print();

    list<int> m;
    m = l;
    m.print();
}
int main()
{
    //test();
    //test1();
    //test2();
    test3();
    return 0;
}
