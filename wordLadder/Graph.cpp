/*
 * File: Graph.cpp
 * Course: CS216-002
 * Project: PA3
 * Purpose: Provide the implementation of Graph class, which is a template class.
 * Contains functions hasEdge, addEdge, and BFS. BFS is the search algorithm used
 * in this project to search for words differing by a single letter.
 */
#ifndef Graph_cpp
#define Graph_cpp

#include <iostream>
#include <queue>
#include "Graph.h"
template<class T>
// default constructor
Graph<T>::Graph()
{
}

template<class T>
// check if an edge exists between v and w
bool Graph<T>::hasEdge(T v, T w) const
{
    if (adjMap.find(v) == adjMap.end())
        return false;
    if (adjMap.at(v).find(w) != adjMap.at(v).end())
        return true;
    else
        return false;
}

template<class T>
// add an edge between v and w to the graph
// note that it is an undirected graph
void Graph<T>::addEdge(T v, T w)
{
    adjMap[v].insert(w);
    adjMap[w].insert(v);
}

template<class T>
// Apply BFS traversal to find the shortest path from the given source s to destination t
// return the distnace from s to t
// if there is no path from s to t, return -1
// store the shortest path distance from the given source s  to vertex w in distance map<w, distance>
// store which next vertex to go through on the shortest path to the given source s in go_through map<w, v>. 
// Here a pair <w, v> in go_through map represents on the shortest path from w to the given source s, it needs to take the path: w-->v...-->s  
int Graph<T>::BFS(T s, T t, map<T, int>& distance, map<T, T>& go_through) const
{
    if ( adjMap.find(s) == adjMap.end() || adjMap.find(t) == adjMap.end())
    {
        cout << "Invalid source Vertex or/and destination Vertex!" << endl;
        return INVALID_VERTEX;
    }

    // Mark all the vertices with current distance to s: -1
    for (auto it = adjMap.begin(); it != adjMap.end(); it++)
    {
        distance[it->first] = NOPATH;
    }

    // Create a queue for BFS
    queue<T> bfs;

    // Enqueue the source s
    bfs.push(s);
    // Mark the distance from the source s to s: 0
    distance[s] = 0;
    // Mark the shortest path to the given source s going through s
    go_through[s] = s;

    T current = bfs.front();
    while(!bfs.empty() && current != t)
    {
        current = bfs.front();
        // Get all adjacent vertices of current Vertex
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        set<T> adjVertices = adjMap.at(current);
        for(auto i  = adjVertices.begin(); i != adjVertices.end(); i++)
        {
            if(distance[*i] == NOPATH)
            {
                distance[*i] = distance[current]+1;
                go_through[*i] = current;
                bfs.push(*i);
            }
        }
        bfs.pop();
    }
    return distance[t];
}

#endif
