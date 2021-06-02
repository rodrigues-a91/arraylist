#include <iostream>
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

using namespace std;
template <class T> class ArrayList
{
    private:
        int m_size;
        int m_capacity;
        T* m_elements;
        void aumentaCapacidade(){
            if(m_size==m_capacity){
                T* m_newelements = new T[m_capacity*=2];
                for (int i=0;i<m_size;i++){
                    m_newelements[i]= m_elements[i];
                }
                delete[] m_elements;
                m_elements=m_newelements;

            }
        }

    public:
        ArrayList() {
        m_capacity=5;
        m_size=0;
        m_elements = new T[m_capacity];
        }
        ~ArrayList() {
        delete[] m_elements;
        }

        int size(){
            return m_size;
        }
        bool isEmpty(){
            return m_size==0;
        }
        void add (T elem){
           aumentaCapacidade();

            m_elements[m_size]=elem;
            m_size++;

        }
        bool add (T element, int index){
            if(index < 0 || index >= size()){
                return false;
            }else{
                T* newElements = new T[m_capacity];
                for(int i=0;i<m_size;i++){
                    if(index>i){
                        newElements[i]=m_elements[i];
                    }else if (index==i){
                        newElements[i]=element;
                        newElements[i+1]=m_elements[i];
                    }else{
                        newElements[i+1]=m_elements[i];
                    }
                }
                delete[] m_elements;
                m_elements = newElements;
                m_size++;
            }
        }

        int indexOf(T elem){
            for(int i=0; i<m_size;i++){
                if (m_elements[i]==elem){
                    return i;
                }
            }
            return -1;
        }

        bool remove (T elem){
            int index = indexOf(elem);
            if(index==-1){
                return false;
            }
            remove(index);
            return true;

        }
        bool remove (int index){
            if(index < 0 || index>=m_size ){
                return false;
            }else{
                T* newElements = new T[m_capacity];
                for(int i=0;i<m_size;i++){
                    if(index>i){
                        newElements[i] = m_elements[i];
                    }else if(index==i){
                        continue;
                    }else{
                        newElements[i-1] = m_elements[i];
                    }
                }
                delete[] m_elements;
                m_elements = newElements;
                m_size--;
            }
        }

        T get(int index){
            if(index<0 || index>=m_size){
                throw "Indice fora dos limites da lista!";
            }else{
                return m_elements[index];
            }
        }

        void clear(){
            m_size = 0;
        }

        void print(){
            if (isEmpty()){
            cout<<"<--------Lista Vazia--------->"<<endl;
            }else{
                cout<<"<--------Inicio da lista------>"<<endl;
                for (int i=0;i<m_size;i++){
                    cout<<m_elements[i]<<endl;
                }
                cout<<"<--------Fim da lista--------->"<<endl;
            }
        }

    protected:


};

#endif // ARRAYLIST_H
