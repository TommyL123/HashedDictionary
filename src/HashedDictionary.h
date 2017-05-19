
#pragma once

#include "DictionaryInterface.h"
#include "HashedEntry.h"
#include <exception>
#include <unordered_map>
#include <vector>


#define DEFAULT_SIZE 101

/**
 *
 * This Hash table is of fixed max size 101 - which is a prime number (why?)
 */
template<class KeyType, class ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType> {
private:
    HashedEntry<KeyType, ItemType> **hashTable;  // Array of pointers to entries
    int itemCount;
    int hashTableSize; //Default value should be assigned to 101

    int getHashIndex(const KeyType &itemKey) const;

    void destroyDictionary();

public:

    HashedDictionary();

    virtual ~HashedDictionary();

    void clear() override;

    bool isEmpty() const override;

    int getNumberOfItems() const override;

    bool add(const KeyType &searchKey, const ItemType &newItem) override;

    bool remove(const KeyType &searchKey) override;

    ItemType getItem(const KeyType &searchKey) const override;

    bool contains(const KeyType &searchKey) const override;

    void traverse(void (*visit)(ItemType &)) const override;

    std::vector<ItemType> toVector() const override;

    HashedEntry<KeyType, ItemType>& operator[](KeyType key);


};

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType &key) const {
    //DO NOT MODIFY
    return static_cast<int>(key % hashTableSize);
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::destroyDictionary() {


    for (int i = 0; i < hashTableSize; i++) //implement a for loop to set the integer i of the hashtable array to null pointer

    {
        hashTable[i] = nullptr;

    }

    itemCount = 0;

}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
        : itemCount(0), hashTableSize(DEFAULT_SIZE) {
    //DO NOT MODIFY
    hashTable = new HashedEntry<KeyType, ItemType> *[DEFAULT_SIZE];
    for (int i = 0; i < DEFAULT_SIZE; i++)
        hashTable[i] = nullptr;
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary() {
    //DO NOT MODIFY
    destroyDictionary();
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear() {
    //DO NOT MODIFY
    destroyDictionary();
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const {

    if (getNumberOfItems() == 0) // If hashed dictionary for sure equals 0 then return true if not return false

    {
        return true;

    }

    else

    {

        return false;
    }

}

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const {

    int x = 0;

    for (int y = 0; y < hashTableSize; y++) //nested for loop to get number of items, traverse through and adds y and x integers

    {

        if (hashTable[y] != nullptr)

        {

            x++;

            while (hashTable[y] -> getNext() != nullptr)

            {

                x++;

            }
        }
    }
    return x++;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType &searchKey, const ItemType &newItem) {

    HashedEntry < KeyType, ItemType > *entryToAddPtr = new HashedEntry < KeyType, ItemType > (searchKey, newItem);

    int hashIndex = getHashIndex(searchKey);
    if (hashTable[hashIndex] == nullptr)
    {
        hashTable[hashIndex] = entryToAddPtr;
    }
    else
    {
        entryToAddPtr->setNext(hashTable[hashIndex]);
        hashTable[hashIndex] = entryToAddPtr;
    }
    return true;
}




template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType &searchKey) {

    bool removal = false;

    int hashIndex = getHashIndex(searchKey);

    if(hashTable[hashIndex] != nullptr) //if else statement to remove entries in the hashedDictionary
    {
        if (searchKey == hashTable[hashIndex] -> getKey())
        {
            hashTable[hashIndex] = hashTable[hashIndex] -> getNext();

            removal = true;
        }
        else
        {
            auto prevPtr = hashTable[hashIndex];
            auto curPtr = prevPtr -> getNext();
            while ((curPtr != nullptr) && !removal)
            {
                if (searchKey == curPtr ->getKey())
                {
                    prevPtr -> setNext(curPtr -> getNext());
                    removal = true;
                }
                else
                {
                    prevPtr = curPtr;
                    curPtr = curPtr -> getNext();
                }
            }
        }

    }
    return removal;



}

template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType &searchKey) const {

    while (hashTable[searchKey] == nullptr)

    {

        throw std::exception(); //throw an exception for searchKey in hash table
    }

    return hashTable [getHashIndex (searchKey)] -> getItem();

}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType &searchKey) const {

    return hashTable [searchKey] != nullptr;  //returns the hashtable searchKey if it does not equal the nullptr

}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void (*visit)(ItemType &)) const {
    //DO NOT MODIFY
    for (int index = 0; index < hashTableSize; index++) {
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[index];
        while (chainPtr != nullptr) {
            ItemType currentItem = chainPtr->getItem();
            visit(currentItem);
            chainPtr = chainPtr->getNext();
        }
    }
}

template<class KeyType, class ItemType>
std::vector<ItemType> HashedDictionary<KeyType, ItemType>::toVector() const {
    //DO NOT MODIFY
    std::vector<ItemType> returnVector;
    for (int index = 0; index < hashTableSize; index++) {
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[index];
        while (chainPtr != nullptr) {
            ItemType currentItem = chainPtr->getItem();
            returnVector.push_back(currentItem);
            chainPtr = chainPtr->getNext();
        }
    }
    return returnVector;
};

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>& HashedDictionary<KeyType, ItemType>::operator[](KeyType searchKey){
    //DO NOT MODIFY
    int itemHashIndex = getHashIndex(searchKey);
    HashedEntry<KeyType, ItemType> *chainPtr = hashTable[itemHashIndex];

    // Short circuit evaluation is important here
    while ((chainPtr != nullptr) && (searchKey != chainPtr->getKey())) {
        chainPtr = chainPtr->getNext();
    } // end while

    if (chainPtr == nullptr)
        throw std::exception();

    return *chainPtr;
}
