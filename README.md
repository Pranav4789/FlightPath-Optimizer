## Github Organization
**File Locations** 

 Code: Files for the algorithms are at Lumen_cs225final_project/src/ 
 
 Tests: The test files are located at Lumen_cs225final_project/tests/  
 
 Data: Data files are located at Lumen_cs225final_project/entry/ 
 
 The written report: Lumen_cs225final_project/results.md/ 
 
 The presentation video: https://www.youtube.com/watch?v=LsKwNEGi-R4

    
## Setup Instructions

Clone the Lumen_cs225final_project folder to your cs225 development folder

Access the terminal on the root directory and enter the following commands
    
$ mkdir build

$ cd build

$ cmake ..

$ make

## Using The Program

To compile the program, the user can use the command "**make**" in the terminal in the build directory.
After compiling the user will be able to either run the executable or fun the test suite.

Running the command "**./main**" while still in the build directory terminal will run the executable.
 - The user is greeted and prompted to enter one of the five top travel destinations that are given.
 - By entering one of the following: "**South Island**", "**Paris**", "**Maui**", "**Bora Bora**", or "**Tahiti**", the user will then be shown the flight route from O'hare Airport to the respective destination with the least connections and the route with the least travel distance.
 - Based on the two routes the program will output a comparison of the routes for further clarification. 
 - After this information the user can choose to continue to pick destinations after being prompted to check another location by entering "**y**".
 - If "**n**" is entered then the program will continue and display the top five airports in the dataset according to Google's pagerank algorithm
 - The executable will output the shortest flight in terms of distance and the least connected destination.
 
 Running the command "**./test**" while still in the build directory terminal will run the test suite.
  - The test suite goes through each algorithm and makes sure that it stays consistent with examples of various graphs
  - Test data files that include faulty data are given to make sure that the parsing is consistent and obtains all information
  - Algorithms are tested for accuracy and ability to scale to large data set




