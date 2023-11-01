#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <locale>

#include "open_flights.h"

TEST_CASE("Constructor airportIndex", "[Constructor][Airports]") {
  AirportMap test1("/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/airportTest.dat", 
                     "/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/routeTest.dat");
                     
  airport gka = {0,"Goroka Airport", -6.081689834590001, 145.391998291, "GKA"};
  airport mag = {1,"Madang Airport", -5.20707988739, 145.789001465, "MAG"};
  airport hgu = {2,"Mount Hagen Kagamuga Airport", -5.826789855957031, 144.29600524902344, "HGU"};
  airport lae = {3,"Nadzab Airport", -6.569803, 146.725977, "LAE"};
  airport pom = {4,"Port Moresby Jacksons International Airport", -9.443380355834961, 147.22000122070312, "POM"};
  airport wwk = {5,"Wewak International Airport", -3.58383011818,143.669006348, "WWK"};
  airport uak = {6,"Narsarsuaq Airport", 61.1604995728,-45.4259986877, "UAK"};
  airport goh = {7,"Godthaab / Nuuk Airport", 64.19090271,-51.6781005859, "GOH"};
  airport sfj = {8,"Kangerlussuaq Airport", 67.0122218992,-50.7116031647, "SFJ"};
  airport thu = {9,"Thule Air Base", 76.5311965942,-68.7032012939, "THU"};
  airport eve = {10,"Harstad/Narvik Airport", 68.491302490234,16.678100585938, "EVE"};
  REQUIRE(gka == test1.airportIndex["GKA"]);
  REQUIRE(mag == test1.airportIndex["MAG"]);
  REQUIRE(hgu==test1.airportIndex["HGU"]);
  REQUIRE(lae==test1.airportIndex["LAE"]);
  REQUIRE(pom == test1.airportIndex["POM"]);
  REQUIRE(wwk == test1.airportIndex["WWK"]);
  REQUIRE(uak == test1.airportIndex["UAK"]);
  REQUIRE(goh == test1.airportIndex["GOH"]);
  REQUIRE(sfj == test1.airportIndex["SFJ"]);
  REQUIRE(thu == test1.airportIndex["THU"]);
  REQUIRE(eve == test1.airportIndex["EVE"]);
}
TEST_CASE("Constructor adjecencyMatrix", "[Constructor][Routes]") {
  AirportMap test1("/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/airportTest.dat", 
                     "/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/routeTest.dat");
  vector<adjacent>  gka = {{"MAG",test1.findDistance("GKA", "MAG")},
                           {"HGU",test1.findDistance("GKA", "HGU")},
                           {"LAE",test1.findDistance("GKA", "LAE")},
                           {"POM",test1.findDistance("GKA", "POM")}};
  vector<adjacent>  mag = {{"HGU",test1.findDistance("MAG", "HGU")},
                           {"LAE",test1.findDistance("MAG", "LAE")}};
  vector<adjacent>  hgu = {{"MAG",test1.findDistance("MAG", "HGU")}, 
                           {"THU",test1.findDistance("THU", "HGU")}};
  vector<adjacent>  lae = {{"SFJ",test1.findDistance("LAE", "SFJ")}};
  vector<adjacent>  pom = {{"SFJ",test1.findDistance("POM", "SFJ")}};
  vector<adjacent>  wwk = {{"UAK",test1.findDistance("WWK", "UAK")}};
  vector<adjacent>  uak = {{"WWK",test1.findDistance("WWK", "UAK")}};
  vector<adjacent>  goh = {};
  vector<adjacent>  sfj = {{"MAG",test1.findDistance("SFJ", "MAG")}};
  vector<adjacent>  thu = {{"MAG",test1.findDistance("THU", "MAG")},
                           {"HGU",test1.findDistance("THU", "HGU")}};
  vector<adjacent>  eve = {};
  REQUIRE(gka == test1.adjacencyList["GKA"]);
  REQUIRE(mag == test1.adjacencyList["MAG"]);
  REQUIRE(hgu == test1.adjacencyList["HGU"]);
  REQUIRE(lae == test1.adjacencyList["LAE"]);
  REQUIRE(pom == test1.adjacencyList["POM"]);
  REQUIRE(wwk == test1.adjacencyList["WWK"]);
  REQUIRE(uak == test1.adjacencyList["UAK"]);
  REQUIRE(goh == test1.adjacencyList["GOH"]);
  REQUIRE(sfj == test1.adjacencyList["SFJ"]);
  REQUIRE(thu == test1.adjacencyList["THU"]);
  REQUIRE(eve == test1.adjacencyList["EVE"]);
}

TEST_CASE("BFS Shortest Path", "[BFS][ShortestPath]") {
  AirportMap test1;
  test1.airportIndex = {{"0", {0, "0", 0, 0, "0"}},
                        {"1", {0, "1", 0, 0, "1"}}, 
                        {"2", {0, "2", 0, 0, "2"}}, 
                        {"3", {0, "3", 0, 0, "3"}},
                        {"4", {0, "4", 0, 0, "4"}},
                        {"5", {0, "5", 0, 0, "5"}},
                        {"6", {0, "6", 0, 0, "6"}},
                        {"7", {0, "7", 0, 0, "7"}}};

  test1.idx_ = {"0", "1", "2", "3", "4", "5", "6", "7"};

  test1.adjacencyList = {{"0", {{"1", 1}, {"3", 1}}},
                         {"1", {{"0", 1}, {"2", 1}}},                           //  [1] --- [0]     [7] --- [6]
                         {"2", {{"1", 1}}},                                     //   |       |    /  |    /  |
                         {"3", {{"0", 1}, {"4", 1}, {"7", 1}}},                 //   |       |  /    |  /    |
                         {"4", {{"3", 1}, {"5", 1}, {"6", 1}, {"7", 1}}},       //  [2]     [3] --- [4] --- [5]
                         {"5", {{"4", 1}, {"6", 1}}},
                         {"6", {{"4", 1}, {"5", 1}, {"7", 1}}},
                         {"7", {{"3", 1}, {"4", 1}, {"6", 1}}}};

  vector<string> t1 = {"2", "1", "0", "3"};
  REQUIRE(test1.bfsShortestPath("2", "3") == t1);

  vector<string> t2 = {"0", "3", "7"};
  REQUIRE(test1.bfsShortestPath("0", "7") == t2);
}

TEST_CASE("Djikstras Shortest Path", "[Djikstras][ShortestPath]") {
  AirportMap test1;
  test1.airportIndex = {{"0", {0, "0", 0, 0, "0"}},
                        {"1", {1, "1", 0, 0, "1"}}, 
                        {"2", {2, "2", 0, 0, "2"}}, 
                        {"3", {3, "3", 0, 0, "3"}},
                        {"4", {4, "4", 0, 0, "4"}},
                        {"5", {5, "5", 0, 0, "5"}},
                        {"6", {6, "6", 0, 0, "6"}},
                        {"7", {7, "7", 0, 0, "7"}}};

  test1.idx_ = {"0", "1", "2", "3", "4", "5", "6", "7"};

  test1.adjacencyList = {{"0", {{"1", 1}, {"3", 1}}},
                         {"1", {{"0", 1}, {"2", 1}}},                           //  [1] --1- [0]      [7] --3- [6]
                         {"2", {{"1", 1}}},                                     //   |        |      / |      / |
                         {"3", {{"0", 1}, {"4", 1}, {"7", 3}}},                 //   1        1    3   1    1   1
                         {"4", {{"3", 1}, {"5", 4}, {"6", 1}, {"7", 1}}},       //   |        |  /     |  /     |
                         {"5", {{"4", 4}, {"6", 1}}},                           //  [2]      [3] --1- [4] --4- [5]
                         {"6", {{"4", 1}, {"5", 1}, {"7", 3}}},
                         {"7", {{"3", 3}, {"4", 1}, {"6", 3}}}};
  double dist1 = 0;                       
  vector<string> t1 = {"2", "1", "0", "3", "4", "7"};
  REQUIRE(test1.djikstrasShortestPath("2", "7", dist1) == t1);
  REQUIRE(dist1 == 5);

  double dist2 = 0; 
  vector<string> t2 = {"3", "4", "6", "5"};
  REQUIRE(test1.djikstrasShortestPath("3", "5", dist2) == t2);
  REQUIRE(dist2 == 3);
}

TEST_CASE("Short PageRank", "[Pagerank]") {
  AirportMap test1;
  test1.airportIndex = {{"0", {0, "0", 0, 0, "0"}},
                        {"1", {1, "1", 0, 0, "1"}}, 
                        {"2", {2, "2", 0, 0, "2"}}, 
                        {"3", {3, "3", 0, 0, "3"}},};

  test1.idx_ = {"0", "1", "2", "3"};
                                                                  //    [0] ---> [1]
  test1.adjacencyList = {{"0", {{"1", 1}, {"2", 1}}},             //     ^     /
                         {"1", {{"2", 1}}},                       //     |   /
                         {"2", {{"0", 1}}},                       //     v v
                         {"3", {{"2", 1}}}};                      //    [2] <--- [3]                       
  vector<string> t1 = {"2", "0", "1", "3"};
  REQUIRE(test1.pagerank() == t1);
}

TEST_CASE("Medium PageRank", "[Pagerank]") {
  AirportMap test1;
  test1.airportIndex = {{"0", {0, "0", 0, 0, "0"}},
                        {"1", {1, "1", 0, 0, "1"}}, 
                        {"2", {2, "2", 0, 0, "2"}}, 
                        {"3", {3, "3", 0, 0, "3"}},
                        {"4", {4, "4", 0, 0, "4"}},
                        {"5", {5, "5", 0, 0, "5"}}};

  test1.idx_ = {"0", "1", "2", "3", "4", "5"};

  test1.adjacencyList = {{"0", {{"1", 1}}},
                         {"1", {{"2", 1}}},                    // [0]--->[1]--->[2]
                         {"2", {{"4", 1}}},                    //         ^      |
                         {"3", {{"1", 1}}},                    //         |      v
                         {"4", {{"3", 1}, {"5", 1}}},          //        [3]<---[4]--->[5]
                         {"5", {}}};                  
  vector<string> t1 = { "4", "2", "1", "5", "3"};
  REQUIRE(test1.pagerank() == t1);

}