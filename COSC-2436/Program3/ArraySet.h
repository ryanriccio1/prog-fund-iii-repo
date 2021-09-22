/** @file ArraySet.h */

#pragma once
#include "SetInterface.h"

template<class ItemType>
class ArraySet : public SetInterface<ItemType>
{
public:
    ArraySet();
    ArraySet(ItemType* initialItems, size_t initialSize);
    size_t getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newItem);
    bool remove(const ItemType& item);
    void clear();
    bool contains(const ItemType& item) const;
    std::vector<ItemType> toVector() const;
    ~ArraySet();
private:
    size_t numItems;
    size_t maxItems;
    static const int incrementAmount{ 8 };
    ItemType* itemArray;
    void incrementMaxItems();
    void arrayCopy(const ItemType* src, ItemType* dest, size_t itemCount);
    size_t getIndex(const ItemType& item) const;
};

/** @file ArraySet.cpp */

template<class ItemType>
ArraySet<ItemType>::ArraySet() : numItems(0), maxItems(0)
{   // default constructor that just loads values with 0
    incrementMaxItems();
}

template<class ItemType>
ArraySet<ItemType>::ArraySet(ItemType* initialItems, size_t initialSize) : numItems(initialSize), 
maxItems((initialSize + (incrementAmount - 1)/incrementAmount)*incrementAmount)
{   // creates new memory block with size rounded up to nearest multiple of 8 (incrementAmount)
    itemArray = new ItemType[maxItems];
    arrayCopy(initialItems, itemArray, numItems);   // copies given arguments to class
}

template<class ItemType>
size_t ArraySet<ItemType>::getCurrentSize() const
{   // normal getter
    return numItems;
}

template<class ItemType>
bool ArraySet<ItemType>::isEmpty() const
{   // if anything exists, will return false
    return numItems == 0;
}

template<class ItemType>
bool ArraySet<ItemType>::add(const ItemType& newItem)
{   // check for duplicate
    if (contains(newItem))
        return false;
    // if entering new block of memory
    if (numItems == maxItems)
        incrementMaxItems();
    // add new item and increment newItems
    itemArray[numItems++] = newItem;
    return true;
}

template<class ItemType>
bool ArraySet<ItemType>::remove(const ItemType& item)
{   // find index of item (will return numItems if not found)
    size_t index = getIndex(item);
    if (index < numItems)
    {   // shift everything over 1, starting past index of item to remove
        ItemType* itemToRemove = itemArray + index;
        arrayCopy(itemToRemove + 1, itemToRemove, numItems - index - 1);
        numItems--;
        return true;
    }
    return false;
}

template<class ItemType>
void ArraySet<ItemType>::clear()
{   // reset all and increment based on new values
    numItems = 0;
    maxItems = 0;
    incrementMaxItems();
}

template<class ItemType>
bool ArraySet<ItemType>::contains(const ItemType& item) const
{   // if index exists
    return getIndex(item) < numItems;
}

template<class ItemType>
std::vector<ItemType> ArraySet<ItemType>::toVector() const
{   // iterate through available items in block and push to vector
    std::vector<ItemType> newVector;
    for (size_t item = 0; item < numItems; item++)
    {
        newVector.push_back(itemArray[item]);
    }
    return newVector;
}

template<class ItemType>
ArraySet<ItemType>::~ArraySet()
{   // delete our block
    delete itemArray;
}

template<class ItemType>
void ArraySet<ItemType>::incrementMaxItems()
{   // keep track of our max by multiples of incrementAmount(8)
    maxItems += incrementAmount;
    // create pointer to old array
    ItemType* oldItemArray = itemArray;
    // create new array
    itemArray = new ItemType[maxItems];
    // copy from old to new
    arrayCopy(oldItemArray, itemArray, numItems);
}

template<class ItemType>
void ArraySet<ItemType>::arrayCopy(const ItemType* src, ItemType* dest, size_t itemCount)
{   // kind of like memcpy, just iterates through the src to dest
    for (size_t itemIndex{ 0 }; itemIndex < itemCount; itemIndex++)
    {
        dest[itemIndex] = src[itemIndex];
    }
}

template<class ItemType>
size_t ArraySet<ItemType>::getIndex(const ItemType& item) const
{   // linear search through array
    for (size_t itemIndex{ 0 }; itemIndex < numItems; itemIndex++)
    {
        if (itemArray[itemIndex] == item)
            return itemIndex;
    }
    return numItems;    //numItems will always be +1 of index at least, use this as sentinel.
}