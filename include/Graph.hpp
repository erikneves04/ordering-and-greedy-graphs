#pragma once

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>

#include "Vertex.hpp"
#include "LinkedList.hpp"
#include "GraphOrderer.hpp"

/**
 * @brief Structure representing a graph and its dependencies (such as vertices and other properties).
 */
class Graph
{
    private:
        LinkedList<Vertex*>* _vertices;
        GraphOrderer* _orderer;

    public:
        /**
         * @brief Default constructor for the Graph class.
         * @param sortOption Character defining the sorting method to be used.
         */
        Graph(char sortOption);

        /**
         * @brief Destructor responsible for freeing the memory allocated for a graph.
         */
        ~Graph();

        /**
         * @brief Adds a new vertex to this graph.
         *
         * @param vertex A pointer to the new vertex.
         */
        void AddVertex(Vertex* vertex);

        /**
         * @brief Adds an edge between two vertices in the graph.
         *
         * @param vertex1 A pointer to the first vertex.
         * @param vertex2 A pointer to the second vertex.
         */
        void AddEdge(Vertex* vertex1, Vertex* vertex2);

        /**
         * @brief Returns the vertices belonging to this graph.
         * 
         * @return A pointer to the linked list with the vertices.
         */
        LinkedList<Vertex*>* GetVertices();

        /**
         * @brief Returns the vertex at the specified position.
         * 
         * @param index The desired position.
         * 
         * @return A pointer to the desired vertex.
         */
        Vertex* GetVertex(int index);

        /**
         * @brief Checks if this graph is "greedy". That is, all vertices have a connection
         * with all colors smaller than their own coloring.
         * 
         * @return true if "greedy," false otherwise.
         */
        bool IsGreedy();

        /**
         * @brief Returns a string with the vertices ordered according to the selected sorting method.
         * 
         * @return A string with the ordered vertices.
         */
        std::string OrderedVertices();

        /**
         * @brief Updates the coloring of a specific vertex in the graph.
         *
         * @param index Target position.
         * @param color New coloring.
         */
        void SetVertexColor(int index, int color);

        /**
         * @brief Counts the vertices in this graph.
         *
         * @return The number of vertices present.
         */
        int VertexCount();

        /**
         * @brief Counts the edges of all vertices in this graph.
         *
         * @return The number of edges present.
         */
        int EdgeCount();

        /**
         * @brief Builds a graph based on the information provided by the standard input, 
         * following the structure of the provided documentation.
         *
         * @return A pointer to the vertex with the new information.
         */
        static Graph* BuildFromIoStream();

        /**
         * @brief Prints the graph information to the standard output.
         */
        void Print();
};

#endif