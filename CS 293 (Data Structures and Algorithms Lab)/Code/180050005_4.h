#include<iostream>
#include<vector>

template <class T>
class myvector
{
	// declare variables that are needed. These are private to the class.
	std::vector<T> v;
	int length;
	int start;

    public:

    myvector<T>(){  // constructor
    	length=0;
    	start=0;
    } 
    // define the methods     

    void push_front(T x){
        if (start==0){  
            if (length==0){
                v.push_back(x);
                length++;
            }
            else { // length==v.size()
                for(int i=0;i<length;i++) v.push_back(0);
                for(int i=0;i<length;i++){
                    v[i+length]=v[i];
                    v[i]=0;
                }
                v[length-1]=x;
                start=length-1;
                length++;
            }
        }
        else{ // there is space behind (start>0)
            v[start-1]=x;
            start--;
            length++;
        }
    }

    void push_back(T x){
    	v.push_back(x);
    	length++;
    }

    void pop_front(){
        if (length!=0){
            start++; 
            length--; 
        }       
    }

    void pop_back(){
        v.pop_back();
        length--;
    }

    int const size(){
        return length;
    }

    T & operator[](int i){
        return v[i+start];
    }  
};

