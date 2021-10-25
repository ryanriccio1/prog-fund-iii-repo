#pragma once
//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
public:
    LinkedList();
    LinkedList(ListInterface<ItemType>& oldList);
    virtual ~LinkedList();

    bool isEmpty() const final;
    int getLength() const final;
    bool insert(int newPosition, const ItemType& newEntry) final;
    bool remove(int position) final;
    void clear() final;

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    ItemType getEntry(int position) const noexcept(false);  // noexcecpt is the C++ 11+ way of throw()

    ItemType replace(int position, const ItemType& newEntry) noexcept(false);
    bool contains(const ItemType& anEntry) const;

private:
    Node<ItemType>* headPtr; // Pointer to first node in the chain;
                             // (contains the first entry in the list)
    int itemCount;           // Current count of list items 

    /**  Locates a specified node in this linked list.
     @pre  position is the number of the desired node;
           position >= 1 and position <= itemCount.
     @post  The node is found and a pointer to it is returned.
     @param position  The number of the node to locate.
     @return  A pointer to the node at the given position. */
    Node<ItemType>* getNodeAt(int position) const;

    /** Gets the pointer to a node with given data.
     @pre target is in a node in this list.
     @post The node is found and a pointer is returned.
     @param target  The data in the node to search for.
     @returns A pointer to the first node with the given data. */
	Node<ItemType>* getPointerTo(const ItemType& target) const;
}; // end LinkedList

#include <cassert>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template <class ItemType>
LinkedList<ItemType>::LinkedList(ListInterface<ItemType>& oldList) : headPtr(nullptr), itemCount(0)
{   // make sure we have data
    if (!oldList.isEmpty())
    {   // loop through old list and insert at new position
        for (int currentItem{ 1 }; currentItem <= oldList.getLength(); currentItem++)
        {
            insert(currentItem, oldList.getEntry(currentItem));
        }
    }
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry 
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

        // Attach new node to chain
        if (newPosition == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }  // end if

        itemCount++;  // Increase count of entries
    }  // end if

    return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType>* curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to delete
            Node<ItemType>* prevPtr = getNodeAt(position - 1);

            // Point to node to delete
            curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }  // end if

        // Return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;

        itemCount--;  // Decrease count of entries
    }  // end if

    return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const noexcept(false)
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}  // end getEntry

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) noexcept(false)
{   // if position in range of list and a real position
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {   // get the pointer to the node
        Node<ItemType>* nodeToModify = getNodeAt(position);
        nodeToModify->setItem(newEntry);    // set the data and return the data written
        return nodeToModify->getItem();
    }
    else
    {   // if not a real position, throw exception
        std::string message = "replace() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}

template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& anEntry) const
{   // if the pointer
    return (getPointerTo(anEntry) != nullptr);
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    // Debugging check of precondition
    assert((position >= 1) && (position <= itemCount));

    // Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}  // end getNodeAt

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getPointerTo(const ItemType& target) const
{   // get the headPtr
    bool found = false;
    Node<ItemType>* curPtr = headPtr;

    // loop through nodes until we either get to the end or find the item we're looking for
    while (!found && (curPtr != nullptr))
    {
        if (target == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    } // end while

    return curPtr;
} // end getPointerTo