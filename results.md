## The output and correctness of each algorithm

### BFS/Dijkstra's
They do keep track of distance map/vector and previous map. BFS does push adjacent nodes to queue if not seen before. Dijkstra's does push adjacent nodes to priority queue if not visited before and distance vector is updated


### PageRank
It was implemented by converting adjacency list to adjacency matrix. Then applying Google’s formula for improved importance matrix. After formula was applied the steady-state of the probability matrix was calculated.

## Testing
Various Testcases were created for all algorithms. Utility functions were created to test if the algorithms did indeed provide the expected result. Also, edge cases and malformed input handling were tested,  

## The answer to your leading question
Our leading question was to find the shortest travel distance and least connected travel between Chicago and the five best vacation spots. Also a side goal was set to calculate the largest airports based on number of connections.

We did answer this problem by first passing the CSV in to the program and parsing it to store in a graph structure. We have implemented required structs and maps for an adjacency list and indexing helper to enable graph functionality. Furthermore, to search the graph to find the shortest travel distance and least connected travel between Chicago and the five best vacation spots we have implemented BFS and Dijkstra's algorithms.

We have discovered that most of the shortest travel routes will not be different whether they are based on connections or distance. Also it has been revealed that airport location rather than the Airport code as key for graph would allow for user to pick route from any two locations. Furthermore we have discovered that calculation of travel distance is not important to flyers alone. It should be rather used to convey other travel factors such as time or C02 emissions.
