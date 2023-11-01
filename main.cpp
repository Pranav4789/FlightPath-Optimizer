#include "open_flights.h"

int contains(std::vector<std::string> vct, std::string str) {
    int c = 0;
    for (std::string s : vct) {
        if (s == str) 
            return c;
        c++;
    }
    return -1;
}

int main() {
    std::vector<std::string> codes = {"CHC", "CDG", "OGG", "BOB", "PPT"};
    std::vector<std::string> destinations = {"South", "Paris", "Maui", "Bora", "Tahiti"};
    AirportMap test("/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/airports.dat",
                   "/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/entry/routes.dat");

    std::cout << "Hello. According to US News, the top 5 travel destinations are South Island, Paris, Maui, Bora Bora, and Tahiti" << '\n';
    while (true) {
        std::cout << "\nChoose which location out of the top 5 travel destinations you would like to fly to from Chicago: ";

        std::string str;  

        while(!(cin >> str) || (contains(destinations, str) == -1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << '\n' << "Please choose one of: South Island, Paris, Maui, Bora Bora, or Tahiti \n Your destination: ";
        }
        int codeIdx = contains(destinations, str);
        std::cout << '\n' << "From Chicago to " << str << " the shortest flight in terms of connections is: " << '\n';

        std::vector<std::string> bfs = test.bfsShortestPath("ORD", codes[contains(destinations, str)]);
        for (size_t i=0;i<bfs.size();i++) {
            std::cout << test.airportIndex[bfs[i]].name;
            if (i != bfs.size() - 1) std::cout << " ->> ";
        }
        std::cout << '\n' << "Number of Connections: " << bfs.size() << '\n';

        std::cout << '\n' << "The shortest flight in terms of distance is: " << '\n';

        double dist = 0;
        std::vector<std::string> djik = test.djikstrasShortestPath("ORD", codes[contains(destinations, str)], dist);
        for (size_t i=0;i<djik.size();i++) {
            std::cout << test.airportIndex[djik[i]].name;
            if (i != djik.size() - 1) std::cout << " ->> ";
        }
        std::cout << '\n' << "Travel Distance: " << dist << '\n';

        if (bfs == djik) {
            std::cout << "\nThe flight with the fewest connection and least miles traveled are the same!" << '\n';
        } else if (bfs.size() == djik.size()) {
            std::cout << "\nBoth flights have the fewest connections but the second path is shorter!" << '\n';
        } else {
            std::cout << "\nThe first route might have less connections but the second path is shorter!" << '\n';
        }
        std::cout << "\nWould you like to check another location - y/n ?  ";

        while (!(cin >> str) || (str != "y" && str != "n")) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout  << "What do you mean? ";
        }
        if (str == "n") break;
    }
    std::cout << '\n' << "The five most important airports in the world according to Google's Pagerank algorithm are... \n";

    std::vector<string> m = test.pagerank();
    
    for (size_t i=0;i<m.size();i++) {
            std::cout << i+1 << ": " << test.airportIndex[m[i]].name << '\n';
    }
}
