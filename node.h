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


template <typename Type> void Show(node<Type> *& H){
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

