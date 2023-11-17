#pragma once

#ifndef LISTORDERER_HPP
#define LISTORDERER_HPP

#include "Vertex.hpp"
#include "LinkedList.hpp"

/**
 * @brief Exception thrown when the option indicating the chosen sorting method
 * is invalid.
 */
class invalid_orderer_option_exception
{};

/**
 * @brief Structure representing a graph orderer. It provides various sorting methods, and only one of them
 * should be selected by the character provided in the constructor of this class.
 */
class GraphOrderer
{
    private:
        char _option;
        LinkedList<Vertex*>* (*_ordererMethod)(LinkedList<Vertex*>* list);

        /**
         * @brief Applies the BubbleSort method to sort a list.
         * 
         * @param list The list to be sorted.
         * @return A pointer to the sorted list.
        */
        static LinkedList<Vertex*>* BubbleSort(LinkedList<Vertex*>* list);

        /**
         * @brief Applies the SelectionSort method to sort a list.
         * 
         * @param list The list to be sorted.
         * @return A pointer to the sorted list.
        */
        static LinkedList<Vertex*>* SelectionSort(LinkedList<Vertex*>* list);

        /**
         * @brief Applies the InsertionSort method to sort a list.
         * 
         * @param list The list to be sorted.
         * @return A pointer to the sorted list.
        */
        static LinkedList<Vertex*>* InsertionSort(LinkedList<Vertex*>* list);

        /**
         * @brief Applies the QuickSort method to sort a list.
         * 
         * @param list The list to be sorted.
         * @return A pointer to the sorted list.
        */
        static LinkedList<Vertex*>* QuickSort(LinkedList<Vertex*>* list);

        /**
         * @brief Applies the MergeSort method to sort a list.
         * 
         * @param list The list to be sorted.
         * @return A pointer to the sorted list.
        */
        static LinkedList<Vertex*>* MergeSort(LinkedList<Vertex*>* list);

        /**
         * @brief Applies the HeapSort method to sort a list.
         * 
         * @param list The list to be sorted.
         * @return A pointer to the sorted list.
        */
        static LinkedList<Vertex*>* HeapSort(LinkedList<Vertex*>* list);

        /**
         * @brief Applies the CustomSort (customized, can contain elements from various
         * distinct sources) method to sort a list.
         * 
         * @param list The list to be sorted.
         * @return A pointer to the sorted list.
        */
        static LinkedList<Vertex*>* CustomSort(LinkedList<Vertex*>* list);

        /**
         * @brief Sets the sorting method to be called by the Sort function. It initializes a function pointer
         * that will receive the chosen method.
         * 
         * @param option Chosen sorting method.
        */
        void SelectSortMethod(char option);

    public:
        /**
         * @brief Constructor responsible for initializing the data of this orderer.
         * 
         * @param option Chosen sorting method.
        */
        GraphOrderer(char option);

        /**
         * @brief Method responsible for applying the previously chosen method to a list.
         * 
         * @param list The list to be sorted.
         * @return A pointer to the sorted list.
        */
        LinkedList<Vertex*>* Sort(LinkedList<Vertex*>* list);
};

#endif