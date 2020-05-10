#ifndef DLIST_H
#define DLIST_H
#include <iostream>
using std::cerr;
using std::endl;


template <class T>
class Dlist{
    friend class Iteratore;
    friend class IteratoreConst;
private:
    class Nodo{
    public:
       T info;
       Nodo* next;
       Nodo* prev;
       Nodo(const T &i=T(), Nodo* n=0, Nodo* p=0);
       Nodo(const Nodo& f);
       ~Nodo();
    };

    Nodo* first;
    Nodo* last;
    unsigned int dim;
    void copia(Nodo *primo);//statica forse meglio
public:
    Dlist();
    Dlist(const Dlist & c);
    Dlist(unsigned int k, const T& t):  first(nullptr),last(nullptr),dim(k) {
    for(unsigned int i=0; i<k; ++i) 
      push_front(t);
  }
    Dlist& operator=(const Dlist& c);
    ~Dlist();
    T& operator[](unsigned int) const;
    T *primo() const;
    T *ultimo() const;
    int size() const;
    void push_back(const T& f);
    void push_front(const T &f);
    void pop_back();
    void pop_front();
    void edit(const T& t);

    class Iteratore{
    public:
        Nodo* p;
        Iteratore();
        Iteratore& operator++();
        Iteratore operator ++(int);
        Iteratore& operator--();
        Iteratore operator --(int);
        T& operator*()const;
        T* operator->()const;
        bool operator!= (const Iteratore&) const;
        bool operator==(const Iteratore&)const;

    };

    class IteratoreConst{
    public:
        const Nodo* p;
        IteratoreConst();
        IteratoreConst& operator++();
        IteratoreConst operator ++(int);
        IteratoreConst& operator--();
        IteratoreConst operator --(int);
        const T& operator*()const;
        const T* operator->()const;
        bool operator!= (const IteratoreConst&) const;
        bool operator==(const IteratoreConst&)const;

    };
    Iteratore begin();
    Iteratore end();
    IteratoreConst begin()const;
    IteratoreConst end()const;

};
#endif // Dlist_H

template <class T>
Dlist<T>::Nodo::Nodo(const T& i, Dlist<T>::Nodo *n, Dlist<T>::Nodo *p):info(i),next(n), prev(p){} //costruttore Nodo()Nodo(T)

template<class T>
Dlist<T>::Nodo::Nodo(const Dlist<T>::Nodo &f): info(f.info),next(f.next),prev(f.prev){}     //costruttore di copia di Nodo

template<class T>
Dlist<T>::Nodo::~Nodo(){                                                                //Distruttore profondo di Nodo
    if(next)
        delete next;
}


template<class T>
Dlist<T>::Dlist():first(0), last(0), dim(0){}                                       //Dlist()

template<class T>
Dlist<T>::Dlist(const Dlist<T> &c):first(0), last(0), dim(c.dim){                    //Costruttore di copia profondo Dlist
    copia(c.first);
}
template<class T>
Dlist<T> &Dlist<T>::operator=(const Dlist<T> &c){                                    //assegnazione profonda smart Dlist
    if(this != &c){
        if(first)
            delete first;
        first=0;
        last=0;
        copia(c.first);
        dim=c.dim;
    }
    return *this;
}
template<class T>
Dlist<T>::~Dlist(){                                                                 //distuttore profondo Dlist
    if(first){
        delete first;
    }
}

template <class T>
void Dlist<T>::copia(Nodo* primo){                                                  //funzione di utilità copia/assegnazione profonda profonda
    if(primo){
        first=last=new Nodo(primo->info);
        while(primo->next){
            primo=primo->next;
            last->next= new Nodo(primo->info,0, last);
            last=last->next;
        }
    }
}
template<class T>
T& Dlist<T>::operator[](unsigned int i) const{                                     //operatore [] per Dlist
     /*if(i>=dim)
        throw string("indice fuori bound");*/

    Nodo* temp= first;
    bool esci =false;
    for (unsigned int j=0; j<dim && !esci; ++j){
        if(j==i)
            esci=true;
        else
        temp=temp->next;
    }
    return (temp->info);
}


template<class T>                                                               //funzioni di utilità di Dlist
T* Dlist<T>::primo() const{
    return &(first->info) ;
}
template<class T>
T *Dlist<T>::ultimo() const{
    return &(last->info);
}
template<class T>
int Dlist<T>::size() const{
    return dim;
}

template<class T>                                                              //pushfront dentro Dlist
void Dlist<T>::push_front(const T &f){
    if(!first)
        first=last=new Nodo(f);
    else{
        Nodo*tmp=first;
        first=new Nodo(f,first,0);//T,n,p
        tmp->prev=first;
    }
    ++dim;
}

template<class T>                                                              //pushback dentro Dlist
void Dlist<T>::push_back(const T& f){
    if(!first)
        first=last=new Nodo(f);
    else{
        last->next=new Nodo(f,0,last);//T,n,p
        last=last->next;
    }
    ++dim;
}

template <class T>
void Dlist<T>::pop_back(){
Nodo* tmp=last;
last=last->prev;
last->next=0;
dim--;
delete tmp;
}

template <class T>
void Dlist<T>::pop_front(){
Nodo*f=first;
first=first->next;
first->prev=0;f->next=0;
dim--;
delete f;
}

template <class T>
typename Dlist<T>::Iteratore Dlist<T>::begin(){                             //begin iterator
    Iteratore temp;
    temp.p=first;
    return temp;
}
template <class T>
typename Dlist<T>::Iteratore Dlist<T>::end(){                               //end interator
    Iteratore temp;
    temp.p=last->next;
    return temp;
}
template <class T>
typename Dlist<T>::IteratoreConst Dlist<T>::begin() const{                  //begin iteratorconst
    IteratoreConst temp;
    temp.p=first;
    return temp;
}
template <class T>
typename Dlist<T>::IteratoreConst Dlist<T>::end() const{                    //end iterator const
    IteratoreConst temp;
    temp.p=last->next;
    return temp;
}

template<class T>
Dlist<T>::Iteratore::Iteratore():p(0){}                                     //itertaor()
template <class T>
typename Dlist<T>::Iteratore& Dlist<T>::Iteratore::operator++(){           //operator ++ iterator
    if(p)
        p=p->next;
    return *this;
}
template <class T>
typename Dlist<T>::Iteratore Dlist<T>::Iteratore::operator ++(int){   //++ operator iterator
    Iteratore temp;
    if(p){
        temp.p=p;
        p=p->next;
    }
    return temp;
}

template <class T>
typename Dlist<T>::Iteratore & Dlist<T>::Iteratore::operator--(){           //operator -- iterator
    if(p)
        p=p->prev;
    return *this;
}
template <class T>
typename Dlist<T>::Iteratore Dlist<T>::Iteratore::operator --(int){   //-- operator iterator
    Iteratore temp;
    if(p){
        temp.p = p;
        p=p->prev;
    }
    return temp;
}

template <class T>
T & Dlist<T>::Iteratore::operator*()const{                                  //operator * di iterator
    return p->info;
}
template <class T>
T* Dlist<T>::Iteratore::operator->() const{                                 //operator -> di iterator
    return &(p->info);
}
template <class T>
bool Dlist<T>::Iteratore::operator!=(const Iteratore& i) const{             //operator != di iterator
    return !(p==i.p);
}
template <class T>
bool Dlist<T>::Iteratore::operator==(const Iteratore& i) const{             //operator ==  di iterator
    return p==i.p;
}

template<class T>
Dlist<T>::IteratoreConst::IteratoreConst():p(0){}                           //  iteratorconst()
template <class T>
typename Dlist<T>::IteratoreConst & Dlist<T>::IteratoreConst::operator++(){ //operator ++ di iteratorconst
    if(p)
        p=p->next;
    return *this;
}
template <class T>
typename Dlist<T>::IteratoreConst Dlist<T>::IteratoreConst::operator ++(int){ //operator ++ prefix di iteratorconst
    IteratoreConst temp;
    if(p){
        temp.p=p;
        p=p->next;
    }
    return temp;
}

template <class T>
typename Dlist<T>::IteratoreConst & Dlist<T>::IteratoreConst::operator--(){ //operator -- di iteratorconst
    if(p)
        p=p->prev;
    return *this;
}
template <class T>
typename Dlist<T>::IteratoreConst Dlist<T>::IteratoreConst::operator --(int){//operator -- prefix di iteratorconst
       IteratoreConst temp;
    if(p){
        temp.p=p;
        p=p->prev;
    }
    return temp;
}

template <class T>
const T & Dlist<T>::IteratoreConst::operator*()const{
    return p->info;
}
template <class T>
const T* Dlist<T>::IteratoreConst::operator->() const{
    return &(p->info);
}
template <class T>
bool Dlist<T>::IteratoreConst::operator!=(const IteratoreConst& i) const{
    return !(p==i.p);
}
template <class T>
bool Dlist<T>::IteratoreConst::operator==(const IteratoreConst& i) const{
    return p==i.p;
}
