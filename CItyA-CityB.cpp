#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>  

using namespace std;
class Graph {
    unordered_map<string, vector<pair<string, int>>> adjList;
public:
    void addEdge(string cityA, string cityB, int cost) {
        adjList[cityA].push_back({cityB, cost});
        adjList[cityB].push_back({cityA, cost});
    }
    void display() {
        for (auto& city : adjList) {
            cout << city.first << " -> ";
            for (auto& neighbor : city.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge("London", "Paris", 2);
    g.addEdge("London", "Berlin", 4);
    g.addEdge("Paris", "Rome", 5);
    g.addEdge("Berlin", "Amsterdam", 3);
    g.addEdge("Rome", "Madrid", 6);
    g.display();
    return 0;
}
