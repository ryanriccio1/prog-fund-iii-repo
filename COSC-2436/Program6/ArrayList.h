#pragma once
//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT list: Array-based implementation.
    Listing 9-1.
    @file ArrayList.h */

#include "ListInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType>
{
public:
    ArrayList();
    // Copy constructor and destructor are supplied by compiler

    // these are all final to prevent derived class from overriding them
    bool isEmpty() const final;
    int getLength() const final;
    bool insert(int newPosition, const ItemType& newEntry) final;
    bool remove(int position) final;
    void clear() final;

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    ItemType getEntry(int position) const noexcept(false) final;    // noexcecpt is the C++ 11+ way of throw()

	ItemType replace(int position, const ItemType& newEntry) noexcept(false) final;
    bool contains(const ItemType& anEntry) const final;

private:
    static const int DEFAULT_CAPACITY = 5; // Small capacity to test for a full list 
    ItemType items[DEFAULT_CAPACITY + 1];      // Array of list items (not using element [0]
    int itemCount;                         // Current count of list items 
    int maxItems;                          // Maximum capacity of the list
}; // end ArrayList

#include "ArrayList.h"  // Header file

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayList<ItemType>::getLength() const
{
    return itemCount;
}  // end getLength

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1)
        && (newPosition <= itemCount + 1)
        && (itemCount < maxItems);
    if (ableToInsert)
    {
        // Make room for new entry by shifting all entries at
        // positions >= newPosition toward the end of the array
        // (no shift if newPosition == itemCount + 1)
        for (int entryPosition = itemCount; entryPosition >= newPosition; entryPosition--)
            items[entryPosition + 1] = items[entryPosition]; // copy the entry right

         // Insert new entry
        items[newPosition] = newEntry;
        itemCount++;  // Increase count of entries
    }  // end if

    return ableToInsert;
}  // end insert

template<class ItemType>
bool ArrayList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        // Remove entry by shifting all entries after the one at
        // position toward the beginning of the array
        // (no shift if position == itemCount)
        for (int entryPosition = position; entryPosition < itemCount; entryPosition++)
            items[entryPosition] = items[entryPosition + 1]; // copy entry on the right to left

        itemCount--;  // Decrease count of entries
    }  // end if

    return ableToRemove;
}  // end remove

template<class ItemType>
void ArrayList<ItemType>::clear()
{
    itemCount = 0;
}  // end clear

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const noexcept(false)
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        return items[position];
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}  // end getEntry

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry)
{
    // if position is in range of list and a real position
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {   // set the item at the position to our new entry
        items[position] = newEntry;
        return items[position];
    }
    else
    {   // throw exception if we cannot get the index
        std::string message = "replace() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}

template<class ItemType>
bool ArrayList<ItemType>::contains(const ItemType& anEntry) const
{   // iterate over items
    for (ItemType item : items)
    {   // for each item, check if its what we're looking for
        if (item == anEntry)
            return true;
    }
    return false;
}