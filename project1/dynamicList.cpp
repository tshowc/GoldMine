// 
// Implementation file for Unsorted List ADT.
//
template <class ITEMTYPE>
 bool operator==(ITEMTYPE left, ITEMTYPE right)
{
	if (left.character == right.character)
		return true;
	else
		return false;
}


template <class ITEMTYPE>
dynamicList<ITEMTYPE>::dynamicList()		// Class constructor
{
     length = 0;
	size = defmaxlistsize;
	element = new ITEMTYPE [defmaxlistsize];
}

template <class ITEMTYPE>
dynamicList<ITEMTYPE>::dynamicList(int maxnumber)		// Class constructor
{
    length = 0;
	size = maxnumber;
	element = new ITEMTYPE [maxnumber];
}


template <class ITEMTYPE>
dynamicList<ITEMTYPE>::~dynamicList()
// Post: List is empty; all items have been deallocated.
{
 
     delete [] element;
    length = 0;
}

template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Print() const
{
	for (int i=0; i<length;i++)
	{
		cout<<"\tLocation "<<i<<" = "<<element[i]<<endl;

	}
}
template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Full() const
// Returns true if there is no room for another int on the free store;
// false otherwise.
{
 	if (length==size)
		return true;
	else
		return false;
}



template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Empty() const
// Post: List is empty; all items have been deallocated.
{
	if (length==0)
		return true;
	else
		return false;
}


template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Search(ITEMTYPE item)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the list and 
//       a copy of that element has been stored in item; otherwise, item is
//       unchanged. 
{
    bool moreToSearch;
	int location=0;


    moreToSearch = true;

    while ((moreToSearch) && (location < size))
    {
        if (item == element[location])
        {
            return true;
        }
        else
        {
            location++;
        }
    }
	return false;
}


template <class ITEMTYPE>
int dynamicList<ITEMTYPE>::GetLocation(ITEMTYPE item)
// Used for checking and debugging purposes 
{
    bool moreToSearch;
	int location=0;


    moreToSearch = true;

    while ((moreToSearch) && (location < size))
    {
        if (item == element[location])
        {
            return location;
        }
        else
        {
            location++;
        }
    }
	return 0;
}

template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Insert(ITEMTYPE item)
// item is in the list; length has been incremented.
{

    if (!Full())
	{
	    element[length]=item;
		length++;
		return true;
	}
	else
	{
		cout<<"Error: Cannot Insert.  List is Full.\n";
		return false;
	}
		
}


template <class ITEMTYPE>
ITEMTYPE  dynamicList<ITEMTYPE>::RemoveLast(ITEMTYPE item, bool &found)
{
    // Locate node to be deleted.
    if (!Empty())
    {
			    item=element[length];
			    length--;
			    found = true;
			    return ;
	    }
    else
    {
		cout<<"Error: List is Empty.  Cannot Delete.\n";
		found = false;
    }
    found = false;
    return item;

}


template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Clear()
// Post: Current position has been initialized.
{
    length=0;
}


template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Getlast(ITEMTYPE &item, bool &found)
// Post:  Current position has been updated; item is current item.
{
    if (!Empty())
    {		
		item=element[length-1];
		found = true;
    }
    else
    {
		cout<<"Error: List is Empty.  Cannot Get Top Element.\n";
		found = false;
    }
} 


template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::BubbleSort()
{
    int endIndex = length-1;
    for (int current = 0; current < endIndex; current++)
    {	
        for (int index = endIndex; index > current; index--)
        	if (element[index] < element[index-1])
			{
				ITEMTYPE temp=element[index];
            			element[index]=element[index-1];
				element[index-1]=temp;
			}
    }
}

template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::BinarySearch(ITEMTYPE item)
{
	int mid;
        // To start, find the subscript of the middle position.
        int lowerbound = 0;
	int upperbound = length;
	int position = ( lowerbound + upperbound) / 2;
				     
	while((element[position] != item) && (lowerbound <= upperbound))
        {
		if (element[position] > item){                             
                        upperbound = position - 1;    
		} else  {                   
			lowerbound = position + 1;
		}
                position = (lowerbound + upperbound);
	}
	if (lowerbound <= upperbound)
		return true;
	else
		return false;
}

template <class ITEMTYPE>
ITEMTYPE dynamicList<ITEMTYPE>::RemoveOne(ITEMTYPE item, bool &found)
{
	int position = -1;
	int index = 0;
	while ((position == -1) && (index < length))
	{
		if (item == element [index])
		{
			position = index;
		}
		else
		{
			index++;
		}
	}
	int location = position;
	if (location != -1)
	{
		item = element [location];
		for (int i = location; i < length - 1; i++)
		{
			element[i] = element[i+1];
		}
		length--;
		found = true;
		return item;
	}
	else 
	{
		found = false;
		return item;
	}  

}

template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::InsertAt(ITEMTYPE item, int index)
{
	if (Full())
	{
		return false;
	}
	else
	{
		element[index] = item;
		return true;
	}
}

template<class ITEMTYPE>
ITEMTYPE dynamicList<ITEMTYPE>::getItem(int index)
{
	return element[index];
}
