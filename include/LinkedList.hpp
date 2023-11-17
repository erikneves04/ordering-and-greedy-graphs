#pragma once

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

/**
 * @brief Exception thrown when an operation is performed on an empty list, or invalid access
 * to an item occurs.
 *
 * This class represents a custom exception thrown when an operation is performed
 * on an empty list where the operation is not valid in such a context.
 */
class element_not_found_exception
{};

/**
 * @brief Structure representing a node in a data structure (shared with list, queue, and stack).
 *
 * This structure is used to create nodes in a structure. Each node contains an element
 * of data of type DataType, a reference to the next node, and a reference to the previous node
 * in the list.
 *
 * @tparam DataType The data type to be stored in a node.
 */
template <class DataType> 
struct Node
{
    DataType data;
    Node* next;
    Node* previous;
};

/**
 * @file LinkedList.hpp
 * @brief Class representing a linked list in C++.
 *
 * This class implements a doubly linked list to store data of type DataType.
 * The list can grow dynamically and allows for insertion, removal, access, and checking for the presence
 * of elements. It keeps track of the size and stores references to the beginning and end
 * of the list.
 *
 * @tparam DataType The data type of the elements in the list.
 */
template <class DataType> 
class LinkedList
{
    protected:
        Node<DataType>* _head;
        Node<DataType>* _tail;

        int _size;

        int _lastGetIndex = -1;
        Node<DataType>* _lastGetNode = nullptr;

        /**
         * @brief Gets the element at the specified position in the list, with a linear search
         * that can be started from either the first or last element, depending on
         * the most efficient path.
         *
         * @param index The position of the desired element in the list.
         * @return The node of the element at the specified position.
         */
        Node<DataType>* LinearGet(int index)
        {
            Node<DataType>* current;

            if (index <= _size / 2)
            {
                current = _head;
                for (int i = 0; i < index; i++)
                {                    
                    current = current->next;
                }
            }
            else
            {
                current = _tail;
                for (int i = _size - 1; i > index; i--)
                {
                    current = current->previous;
                }
            }

            _lastGetIndex = index;
            _lastGetNode = current;

            return current;
        }

    public:

        /**
         * @brief Default constructor for the LinkedList class.
         *
         * Creates a new instance of LinkedList with an empty list.
         */
        LinkedList()
        {
            _head = nullptr;
            _tail = nullptr;
            _size = 0;
        };

        /**
         * @brief Destructor for the LinkedList class.
         *
         * Frees the memory allocated for the elements of the list and destroys the list instance.
         */
        ~LinkedList()
        {
            auto current = _head;

            for(int i = 0; i < _size; i++)
            {
                auto next = current->next;

                if (current == nullptr)
                    break;

                delete current;
                current = next;
            }
        }

        /**
         * @brief Returns the current size of the list.
         *
         * @return The number of elements in the list.
         */
        int Length()
        {
            return _size;
        }

        /**
         * @brief Inserts a new element at the end of the list.
         *
         * @param data The element to be inserted into the list.
         */
        void Insert(DataType data)
        {
            Node<DataType>* newNode = new Node<DataType>();
            newNode->data = data;

            newNode->next = nullptr;
            newNode->previous = _tail;

            if (_size == 0)
            {
                _head = newNode;
                _tail = newNode;
            }
            else
            {
                _tail->next = newNode;
                _tail = newNode;
            }

            _size++;
        }

        /**
         * @brief Gets the element at the specified position in the list. This method does
         * internal management to improve access performance to the elements,
         * evaluating from which point of the list it is more viable to start the search and storing
         * information in a cache-like format to allow iterations to have O(1) complexity.
         *
         * @param index The position of the desired element in the list.
         * @return The element at the specified position.
         * @throw element_not_found_exception If the list is empty or the index is invalid.
         */
        DataType Get(int index)
        {
            return GetNode(index)->data;
        }

        /**
         * @brief Returns the last element of the list.
         *
         * @return The last element in the list.
         * @throw element_not_found_exception If the list is empty.
         */
        DataType Last()
        {
            if (Empty())
                throw element_not_found_exception();

            return _tail->data;
        }

        /**
         * @brief Checks if the list is empty.
         *
         * @return true if the list is empty, false otherwise.
         */
        bool Empty()
        {
            return _size == 0;
        }

        /**
         * @brief Checks if the list contains a specific element.
         *
         * @param data The element to be searched for in the list.
         * @return true if the element is present in the list, false otherwise.
         */
        bool Contains(DataType data)
        {
            auto current = _head;

            while (current != nullptr)
            {
                if (current->data == data)
                    return true;

                current = current->next;
            }

            return false;
        }

        /**
         * @brief Gets the element at the specified position in the list.
         * 
         * @param index The position of the desired element in the list.
         * @return The node of the element at the specified position.
        */
        Node<DataType>* GetNode(int index)
        {
            if (index < 0 || index >= _size)
                throw element_not_found_exception();

            if (_lastGetIndex == -1)
                return LinearGet(index);
                
            if (_lastGetIndex == index) 
                return _lastGetNode;

            if (_lastGetIndex == index - 1)
            {
                _lastGetIndex = index;
                _lastGetNode = _lastGetNode->next;

                return _lastGetNode;
            }

            if (_lastGetIndex == index + 1)
            {
                _lastGetIndex = index;
                _lastGetNode = _lastGetNode->previous;

                return _lastGetNode;
            }
            
            return LinearGet(index);
        }

        /**
         * @brief Inverts the content of two nodes.
         *
         * @param first The first node.
         * @param second The second node.
         */
        void InvertNodeContent(Node<DataType>* first, Node<DataType>* second)
        {
            if (first == nullptr || second == nullptr)
                return;

            DataType temp = first->data;

            first->data = second->data;
            second->data = temp;
        }

        /**
         * @brief Sets the content of a node.
         *
         * @param node The node to be updated.
         * @param newData The new data.
         */
        void SetNodeContent(Node<DataType>* node, DataType newData)
        {
            if (node == nullptr)
                return;

            node->data = newData;
        }
};

#endif