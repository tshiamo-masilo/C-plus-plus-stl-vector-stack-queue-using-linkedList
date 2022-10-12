//Provide the implementation for the DynamicArray class in this file.
#include "dynamicArray.h"
template<class T>
DynamicArray<T>::DynamicArray(int s){
	if(s<=0)
	throw "Invalid size provided";
	else
	size = s;
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other){
	 T** temp;
	 temp = new T*[size];
	 for(int x=0;x<size;x++){
	 	temp[x] = new T;
	 }
	 
	 for(int x =0;x<size;x++)
	 	delete elements[x];
	 	
	 	delete [] elements;
	 	
	for(int x=0;x<size;x++){
	 	for(int y=0;y<x;y++){
	 		elements[x][y] = new T;
		 }
	 }
	 
	 size =other.size;
	 numElements = other.numElements; 
}
template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other){
	T *temp = new T;
	return this;
}
template<class T>
DynamicArray<T>* DynamicArray<T>::clone(){
	DynamicArray* temp = new DynamicArray;
	temp->size = this->size;
	temp->numElements = this->numElements;
	
	for(int x =0; x<size;x++){
		temp->elements[x] =  this->elements[x];
	}
	return *temp;
}

template<class T>
void DynamicArray<T>::resize(int newSize){
//====================create a temp arrray =============================
	T ** val;
	val = new T*[size];
	for(int x=0;x<size;x++){
		val[x] = new T*;
		val[x] = elements[x];
	}
//=====================delete array ====================================
	for(int x=0;x<size;x++){
		delete [] elements[x]; 
	}
	delete [] elements;
//==================== allocate memory for array =================
elements = new T*[newSize];
for(int j=0;j<newSize;j++){
	elements[j] = new T*;
}
//======================= assign values to the array==============
for(int j=0;j<size;j++){
	*elements[j] = *val[j];
}
//============= change size=============
size = newSize;	
}

template<class T>
DynamicArray<T>::~DynamicArray(){
	for(int x=0;x<size;x++){
		delete [] elements[x];
	}
		delete [] elements;
}

template<class T>
void DynamicArray<T>::insert(int index, T element){
	if(index <0){
		throw "invalid index";
	}else if(index >=0){
		if(index>size){
			int newSize= size+1;
			resize(newSize);
			elements[index] = element;
		}
	}
}

template<class T>
ostream& operator<<(ostream& output,DynamicArray<T>& obj){
	for(int x =0;x< obj.size;x++){
		if(obj.elements[x] == NULL){
			output<<"*";
			if(x<obj.size-2)
			output<<",";
		}else{
			output<<obj.elements[x];
			if(x<obj.size-2)
			output<<",";
		}
	}
	output<<endl;
	return  output;
}

template<class T>
T DynamicArray<T>::get(int index){
	if(this->elements[index]== nullptr){
	throw("No element found");
	}else 
	return elements[index];
}

template<class T>
const T& DynamicArray<T>::getFirst(){
	bool ifNull = true;
	T el;
	for(int x = 0; x<size;x++){
		if(elements[x]!= nullptr)
		ifNull = false;
	}
	if(ifNull){
		throw("No elements found");
	}else{
		for(int x =0; x<size;x++){
			if(elements[x] != nullptr)
			el = elements[x];
			break;
		}
	}
	return el;
}

template<class T>
const T& DynamicArray<T>::getLast(){
	bool ifNull = true;
	T el;
	for(int x = 0; x<size;x++){
		if(elements[x]!= nullptr)
		ifNull = false;
	}
	if(ifNull){
		throw("No elements found");
	}else{
		for(int x =(size-1); x>=0;x--){
			if(elements[x] != nullptr)
			el = elements[x];
			break;
		}
	}
	return el;
}

template<class T>
int DynamicArray<T>::getIndexFirst(){
	int index;
	bool ifNull = true;
	for(int x = 0; x<size;x++){
		if(elements[x]!= nullptr)
		ifNull = false;
	}
	
	if(ifNull){
		throw("No elements found");
	}else{
			for(int x =0; x<size;x++){
			if(elements[x] != nullptr)
			index = x;
			break;
		}
	}
	return x;
}

template<class T>
int DynamicArray<T>::getIndexLast(){
	int index;
	bool ifNull = true;
	for(int x = 0; x<size;x++){
		if(elements[x]!= nullptr)
		ifNull = false;
	}
	
	if(ifNull){
		throw("No elements found");
	}else{
			for(int x =(size-1); x>=0;x--){
			if(elements[x] != nullptr)
			index = x;
			break;
		}
	}
	return x;
}

template<class T>
bool DynamicArray<T>::isEmpty(){
		bool ifFull = true;
	for(int x = 0; x<size;x++){
		if(elements[x]!= NULL)
		ifFull = false;
	}	
	return ifFull;
}

template<class T>
void DynamicArray<T>::clear(){
	for(int x =0;x<size;x++)
	elements[x] = NULL;
}






