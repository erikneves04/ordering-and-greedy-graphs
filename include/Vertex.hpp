#pragma once

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "LinkedList.hpp"

#define UNDEFINED_COLOR (-1)

/**
 * @brief Exception thrown when an invalid change is made to the vertex color.
 * Invalid changes include assigning a value less than zero.
 */
class invalid_color_change_exception
{};

/**
 * @brief Exception thrown when there is an attempt to assign a color to a vertex that
 * is already adjacent to another vertex with the same color.
 */
class unavailable_color_exception
{};

/**
 * @brief Structure representing a vertex and its dependencies (such as id, adjacencies, and color).
 */
class Vertex
{
    private:
        int _id;
        int _color;
        LinkedList<Vertex*>* _adjacentVertices;

    public:
        /**
         * @brief Default constructor for the Vertex class.
         *
         * Creates a new vertex with default data and an id.
         */
        Vertex(int id);

        /**
         * @brief Destructor for the Vertex class.
         *
         * Responsible for freeing the memory allocated for this vertex.
         */
        ~Vertex();

        /**
         * @brief Returns the id of the vertex.
         *
         * @return The identifier of this vertex.
         */
        int GetId();

        /**
         * @brief Updates the color of this vertex.
         *
         * @param color The new color.
         */
        void SetColor(int color);

        /**
         * @brief Returns the color of the vertex.
         *
         * @return The current color of this vertex.
         */
        int GetColor();

        /**
         * @brief Adds an edge between the current vertex and another vertex.
         *
         * @param vertex The destination vertex of the edge.
         */
        void AddAdjacentVertex(Vertex* vertex);
        
        /**
         * @brief Checks if a second vertex is adjacent to this one.
         *
         * @param vertex A pointer to the vertex for checking.
         * 
         * @return true if adjacent, false otherwise.
         */
        bool IsAdjacent(Vertex* vertex);
        
        /**
         * @brief Checks if any adjacent vertices have the specified color.
         *
         * @param color The desired color.
         * 
         * @return true if any adjacent vertex has the color, false otherwise.
         */
        bool HasAdjacentColor(int color);

        /**
         * @brief Returns the vertices adjacent to this one.
         * 
         * @return A pointer to the linked list of adjacencies.
         */
        LinkedList<Vertex*>* GetAdjacentVertices();

        /**
         * @brief Checks if this is a "greedy" vertex. That is, it verifies if this vertex is adjacent
         * to at least one representative of all colors smaller than its own.
         * 
         * @return true if greedy, false otherwise.
         */
        bool IsGreedy();

        /**
         * @brief Compares two vertices, initially based on color and uses the identifier as a tiebreaker.
         * 
         * @return true if this vertex is "greater than" the other, false otherwise.
         */
        bool IsBiggerThan(Vertex* other);

        /**
         * @brief Compares two vertices, initially based on color and uses the identifier as a tiebreaker.
         * 
         * @return true if this vertex is "less than" the other, false otherwise.
         */
        bool IsLessThan(Vertex* other);

        /**
         * @brief Compares two vertices, initially based on the identifier as a criterion.
         * 
         * @return true if this vertex is "equal to" the other, false otherwise.
         */
        bool Equals(Vertex* other);

        /**
         * @brief Compares two vertices, initially based on color and uses the identifier as a tiebreaker.
         * 
         * @return true if this vertex is "greater than or equal to" the other, false otherwise.
         */
        bool IsBiggerThanOrEqual(Vertex* other);

        /**
         * @brief Compares two vertices, initially based on color and uses the identifier as a tiebreaker.
         * 
         * @return true if this vertex is "less than or equal to" the other, false otherwise.
         */
        bool IsLessThanOrEqual(Vertex* other);
};

#endif