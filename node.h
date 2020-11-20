#include<iostream>
using namespace std;


template <typename Type> struct node{
    Type val;
    node<Type> *next;
};

template <typename Type> void Add(node<Type> *& H, Type value){
    node<Type> * p = new node<Type>;
    p->val = value;
    p->next=NULL;
    if(H != NULL)
        p->next = H;
    H = p;
}


template <typename Type> void Delete(node<Type> *& H){
    if(H!=NULL)
        H = H->next;
}


template <typename Type> void Show(node<Type> * H){
    while(H!=NULL){
        cout<<H->val<<" ";
        H = H->next;
    }
    cout<<"NULL\n";
}


template <typename Type> void DeleteChosen(node<Type> *& H, Type x){
    if(H != NULL)
    {
        if (H->val == x)
            Delete<Type>(H);
        else{
            node<Type> *tmp = new node<Type>;
            tmp = H;
            while(tmp->next != NULL && tmp->next->val != x)
            {
                tmp = tmp->next;
            }
            if(tmp->next != NULL)
                Delete<Type>(tmp->next);
        }
    }
}


template <typename Type> void Merge(node<Type> *& A, node<Type> *&  B){

    if(A!=NULL){
        node<Type> * a = NULL;
        a = A;
        while(a->next!=NULL){
            a=a->next;
           
        }
        a->next = B;
    }
    else{
        A=B;
    }
    B=NULL;
    
}


template <typename Type> void Swap(node<Type> *& h){
    if(!(h && h->next))
        return;
    node<Type> *tmp =NULL;
    tmp = h;
    h = tmp->next;
    tmp->next = h->next;
    h->next = tmp;
}


template <typename Type> void SwapX(node<Type> *& h, node<Type> * wsk){
    if(!(h && h->next))
        return;
    if(wsk == NULL)
        Swap<Type>(h);
    else{
        node<Type> *tmp = wsk->next;
        wsk->next = tmp->next;
        tmp->next = tmp->next->next;
        wsk->next->next = tmp;
    }
}








template <typename Type> void BubbleSwap(node<Type> *& left, node<Type> *& right, node<Type> *& watchDog){
    Type a = right->val;
    right->val = left->val;
    left->val = a;
    watchDog = right;
}


template <typename Type> void BubbleSort(node<Type> *& H){
    if(H==NULL)
        return;
    node<Type> * i = H;
    node<Type> * j;
    node<Type> * watchDog = NULL;
    while(i != NULL){
        j=H;
        while((j->next!=watchDog)&&(j->next!=NULL)){
            if(j->val>j->next->val)
                BubbleSwap(j,j->next,watchDog);
            j=j->next;
        }
        i=i->next;
    }
}
