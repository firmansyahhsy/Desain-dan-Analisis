#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
    int node;
    int bobot;
};

vector<Edge> graph[7]; 
vector<int> dijkstra(int source) {
    vector<int> distances(7, numeric_limits<int>::max());
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distances[node]) continue;

        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i].node;
            int edgeWeight = graph[node][i].bobot;
            int newDistance = dist + edgeWeight;

            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                pq.push(make_pair(newDistance, neighbor));
            }
        }
    }

    return distances;
}

int main() {
   
    graph[1].push_back((Edge){6, 14});
    graph[1].push_back((Edge){2, 7});
    graph[1].push_back((Edge){3, 9});
    graph[2].push_back((Edge){1, 7});
    graph[2].push_back((Edge){3, 10});
    graph[2].push_back((Edge){4, 15});
    graph[3].push_back((Edge){1, 9});
    graph[3].push_back((Edge){2, 10});
    graph[3].push_back((Edge){4, 11});
    graph[3].push_back((Edge){6, 2});
    graph[4].push_back((Edge){2, 15});
    graph[4].push_back((Edge){3, 11});
    graph[4].push_back((Edge){5, 6});
    graph[5].push_back((Edge){4, 6});
    graph[5].push_back((Edge){6, 9});
    graph[6].push_back((Edge){1, 14});
    graph[6].push_back((Edge){3, 2});
    graph[6].push_back((Edge){5, 9});

  
    int sourceNode = 1;
    vector<int> shortestDistances = dijkstra(sourceNode);

    cout << "Rute terpendek dari node " << sourceNode << ":" << endl;
    for (int i = 1; i <= 6; i++) {
        cout << "Ke node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
