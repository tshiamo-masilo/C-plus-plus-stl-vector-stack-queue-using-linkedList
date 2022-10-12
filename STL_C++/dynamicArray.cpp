//Provide the implementation for the DynamicArray class in this file.

//#include "dynamicArray.h"

using namespace std;
template<class T>
ostream& operator<<(ostream& strm,DynamicArray<T>& obj)
{
	strm << "[";	
	for (int i = 0; i<obj.size; i++)	
	{
		if (obj.elements[i] == nullptr)
		{
			strm << "*";
		}
		else 
		{
			strm << *(obj.elements[i]);
		}
		
		if ( i !=obj.size-1)
		{
			strm << ",";
		}	
	}
	strm << "]";
	return strm; 
}

template<class T>
DynamicArray<T>::DynamicArray(int s)
{
	if (s <= 0)
	{
		throw("Invalid size provided");
	}	
	size =s;
	numElements = 0;
	
	elements = new T*[size];
	for (int i = 0; i < size; i++)
	{
		//elements[i] = new T;
		elements[i] = nullptr;
	}
	
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
	size = other.size;
	numElements = other.numElements;
	elements = new T*[size];

	for (int i = 0; i<size; i++)
	{
		elements[i] = new T;
		elements[i] = other.elements[i];
	}
}
			
		
		/*
		The overloaded assignment operator.
		*/
template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
	delete [] elements;
	numElements = other.numElements;
	size = other.size;
	
	elements = new T*[size];
	for (int i = 0; i<size;i++)
	{
		elements[i] = new T;
		elements[i] = other.elements[i];
	}
	return *this;
}
template<class T>
DynamicArray<T>* DynamicArray<T>::clone()		//virtual
{
	DynamicArray<T>* temp = new DynamicArray<T>(*this);
	return temp;
		
}

		
		/*
		The destructor.
		*/
template<class T>
DynamicArray<T>::~DynamicArray()			//virtual
{
	delete [] elements;
	elements = NULL;
}
	

		
		/*
		Inserts an element at the given index in the array.  If
		the index is larger than the size of the array, grow
		the array to accomodate the index.
				
		Any index >= 0 is valid. For an invalid index, throw an exception message "invalid index".
		
		NOTE: a value can only be inserted at a given index if the
		given index does not store a value yet. If the index position
		is occupied, all elements from the given index onwards
		are shifted one position forward to free the requested position.
		
		Eg: Array object stores [a,c,b,m]. A request is made to insert 'j'
		at location '1'. Currently, 'c' is stored there. All elements are shifted 
		forward: [a,*,c,b,m], and 'j' is put in the now open position '1':
		[a,j,c,b,m]. Note that the array had to be resized to accomodate the insertion.
		*/
template<class T>
void DynamicArray<T>::insert(int index, T element)  		//virtual
{
	
	if (index<0)
	{	
		throw "invalid index";
	}

	if (index <=size-1)
	{
		if (elements[index] == nullptr)
		{
			//*elements[index] = element;
			elements[index] = new T(element);
		}	
	
		else 
		{
			if (elements[size-1] ==nullptr)
			{
				for (int i = size-1; i<index; i--)
				{
					elements[i] = elements[i-1];
				}
				elements[index] = new T(element);
				//*elements[index] = element;
			}
			else 
			{	++size;	
				for(int i= size-1;i>index-1;i--)
					{
						elements[i] = elements[i-1];
					}
					elements[index]=new T(element);
			}
			
		}
	}
	else 
	{
		resize(index+1);
		for (int i = size-1; i<index; i--)
		{
			elements[i] = elements[i-1];
		}
		elements[index] = new T(element);
		
	}	
}	
		/*
		Removes and returns the element at the index passed in 
		as a parameter.  All elements from the removed index onwards
		are shifted one position backward. Array is not resized. If an element is null,
		throw the string "No element found".
		*/
template<class T>
T DynamicArray<T>::remove(int index)		//virtual
{

	if (elements[index] ==NULL)
	{
		throw "No element found";
	}
	else
	{
		T temp ;
		temp = *elements[index];
		if (index != size-1)
		{
			elements[index]=NULL;
			for (int i=index; i<size;i++)
			{
				elements[i] = elements[i+1];
			}
			elements[size-1] =NULL; 
		}
		else 
		{
			elements[index] =NULL;
		}

		return temp;
	}
	
}
					
		/*
		Returns the element at the index passed in as a parameter.  
		The element is not removed from the data structure. If an element 
		is null, throw the string "No element found".
		*/
template<class T>
T DynamicArray<T>::get(int index) const		//virtual
{
	if (elements[index] ==NULL)
	{
		throw "No element found";
	}
	else
	{
		return *elements[index];
	}
}
			
			
		/*
		Returns the first non-null element in the structure.
		If all elements are null, throw the string "No element found".
		*/
template<class T>
const T& DynamicArray<T>::getFirst() const		//virtual
{	
	return *elements[getIndexFirst()];

}

		
		/*
		Returns the last non-null element in the structure.
		If all elements are null, throw the string "No element found".
		*/
template<class T>
const T& DynamicArray<T>::getLast() const		//virtual
{
	return *elements[getIndexLast()];
}
	
		
		/*
		Returns the index of the first non-null element in the structure.
		If all elements are null, throw the string "No element found".
		*/
template<class T>
int DynamicArray<T>::getIndexFirst() const		//virtual
{

	int count=0;
	int x =0;
	for(int i=0;i<size;i++)
	{
		if(elements[i]!=NULL)
		{
			count=i;
			break;
		}
		else
		{		
			x++;	
		}
	}
	if(x==size)
	{				
		throw "No element found";			
	}
	else
	return count;
}

		
		/*
		Returns the index of the last non-null element in the structure.
		If all elements are null, throw the string "No element found".
		*/
template<class T>
int DynamicArray<T>::getIndexLast() const		//virtual
{
	
	int count=0;
	int x=0;
	for(int i=size-1;i>=0;i--)
	{
		if(elements[i]!=NULL)
		{
			count=i;
			break;
		}
		else
		{
			x++;	
		}
			
	}
		
	if(x==size)
	{	
		throw "No element found";		
	}
	else
	return count;
}
	

		/*
		Returns true if the array contains no elements and 
		false otherwise.
		*/
template<class T>
bool DynamicArray<T>::isEmpty()		//virtual
{
	bool bfound = true;
	for (int i = 0; i<size; i++)
	{
		if(elements[i] !=NULL)
		{
			bfound = false;
		}
	}
	return bfound;
}

		
		/*
		Removes all of the elements from the array.  After this function has
		been called on a DynamicArray object, the the array must be empty 
		(i.e. all elements in the array must be null).  The array's current
		size remains unchanged.
		*/
template<class T>
void DynamicArray<T>::clear()			 //virtual
{
	for (int i= 0; i<size; i++)
	{
		elements[i] = nullptr;
	}
}
		
		/*
		Removes empty spaces between elements by moving all elements to the front.
		For example, suppose the following array is given: [*,2,3,*,*,*,0]
		After invoking shiftToFront(), all non-null elements should be moved to 
		the front of the array as follows: [2,3,0,*,*,*,*]
		The array's current size must remain unchanged. 
		The order of the elements must remain unchanged.
		*/
template<class T>
void DynamicArray<T>::shiftToFront()
{


	for (int x =0; x<size; x++)
	{
		//if (elements[i] ==NULL)
		for (int y = x; y<size-1-x;y++)
		{
			if (elements[y+1] !=NULL && elements[y]==NULL)
			{
				elements[y] = elements[y+1];
				elements[y+1] = NULL;
			}
		}
	}
}

template<class T>
ostream& DynamicArray<T>::print(ostream& os)
{
	return os << *this;	
}

template <class T>
void DynamicArray<T>::resize(int newSize)
{
	
	T** temp = new T*[size];
	for (int i= 0; i<size; i++)
	{
		temp[i] = elements[i];
	}

	delete [] elements;
	clear();
	elements = new T*[newSize];
	for (int i =0 ; i<size; i++)
	{
		elements[i] = temp[i];
	}
	delete [] temp;
	for(int x =size;x<newSize;x++)
		elements[x] = nullptr;
size = newSize;

}

		
		
