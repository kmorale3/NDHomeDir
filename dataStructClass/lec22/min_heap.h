#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <iostream>

#define VECTOR std::vector

template<class T>
class min_heap{

    private:
        VECTOR<T>* heap_vec;

    public:
        min_heap() : heap_vec( new VECTOR<T> ) {}
        ~min_heap(){ //destructor
            delete heap_vec;
        }
        min_heap(const min_heap<T>& copy) : heap_vec(copy.heap_vec){}//copy constructor
        min_heap& operator=(const min_heap<T>& assign{//operator 
            if (this != &assign){
                this->heap_vec = assign.heap_vec;
            }
            return *this;
        }
        void push( const T& push_elem){
            heap_vec->push_back(push_elem);
            long unsigned int loc = heap_vec->size()-1;
            bool stop_swaps = false;
            long unsigned int parent;
            while(loc!=0 && !stop_swaps){
                parent=(loc/2);
                if(loc%2==0)
                    --parent;
               if (heap_vec->at(parent) >heap_vec->at(loc)){
                   T temp = heap_vec->at(parent);
                   heap_vec->at(parent)= heap_vec->at(loc);
                   heap_vec->at(loc) = temp;
                   loc=parent;
               } 
                else
                    stop_swaps=true;
        
            }
        }

};
	
#endif