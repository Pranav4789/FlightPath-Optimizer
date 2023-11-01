#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>



using namespace std;

struct airport {
    int index;
    string name;
    double latitude;
    double longitude;
    string code;

    bool operator==(const airport& a) const {
        return (a.index == index &&
            a.name == name &&
            a.latitude == latitude &&
            a.longitude == longitude &&
            a.code == code);
    }
};

struct adjacent {
    string code;
    double distance;

    bool operator==(const adjacent& a) const {
        return (code == a.code && distance == a.distance);
    }
};

class AirportMap {
    public:
        /** 
        * Default constructor for AirportMap
        * Initializes map to empty
        */
        AirportMap() = default;

        /** 
        * @param airports A string holding file name of open_flights data file for airports
        * @param routes A string holding file name of open_flights data file for routes
        * Parses through airport file and then route file to initialize airport dictionaries and adjacency list
        * If a route includes airport not in airport file, data is ommitted
        */
        AirportMap(const string& airports, const string& routes);

        /**
         * airportIndex Maps airport code to airport object holding more specific information
        */
        unordered_map<string, airport> airportIndex;

        /**
         * adjacencyList Maps airport code to adjacent object holding airport code and distance from key airport
        */
        unordered_map<string, vector<adjacent>> adjacencyList;

        /**
         * idx_ Vector of airport codes to aid in conversion to adjacency matrix
        */
        vector<string> idx_;

        /**
         * Prints list of all airports with airport name followed by its respective code
         * Print order is based on order of airports in idx_
        */
        void printAirports();

        /**
         * Prints list of all airports with airport name followed by adjacent airports and their respective distance
         * Print order is based on order of airports in adjacencyList
        */
        void displayAdjList();

        /** 
        * @param start A string code for source airport
        * @param dest A string code for destination airport
        * @return A double for distance in miles or Km
        */
        double findDistance(string start, string dest);

        /** 
        * @param start A string code for source airport
        * @param dest A string code for destination airport
        * @return A vector for shortest path of travel between start and destination
        * Shortest path is based on number of connections
        */
        vector<string> bfsShortestPath(const string& start, const string& dest);

        /** 
        * @param start A string code for source airport
        * @param dest A string code for destination airport
        * @param distance A double reference for the calculated distance to be stored
        * @return A vector for shortest path of travel between start and destination
        * Shortest path is based on distance of travel
        */
        vector<string> djikstrasShortestPath(const string& start, const string& dest, double& distance);

        /**
         * @return A vector of the top 5 or less airports using their codes
         * Calculates ranking based on Google Pagerank algorithm and improved matrix formula
        */
        vector<string> pagerank();
    private:
        /** 
        * @param code A string code for source airport
        * @return A boolean for whether the source airport is include in the map
        */
        bool VertexInGraph(string code);

        size_t numAirports = 0;
        
};

class PriorityQueue {
    public:
        PriorityQueue() = default;
        void push(pair<string, double> element);
        pair<string, double> front();
        void pop();
        bool empty() {return q_.empty(); };
        void print();

    private:
        vector<pair<string, double>> q_;

};