#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

class GeneticAlgorithmTSP {
private:
    vector<vector<int>> graph;
    int populationSize;
    double mutationRate;
    int generations;

public:
    GeneticAlgorithmTSP(vector<vector<int>> graph, int populationSize = 10, double mutationRate = 0.01, int generations = 100) {
        this->graph = graph;
        this->populationSize = populationSize;
        this->mutationRate = mutationRate;
        this->generations = generations;
    }

    vector<int> greedyPath(vector<vector<int>>& graph, int start) {
        int n = graph.size();
        vector<int> path;
        vector<bool> visited(n, false);
        int current = start;

        path.push_back(current);
        visited[current] = true;

        while (path.size() < n) {
            int nextCity = -1;
            int minDist = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && graph[current][i] < minDist) {
                    minDist = graph[current][i];
                    nextCity = i;
                }
            }
            current = nextCity;
            visited[current] = true;
            path.push_back(current);
        }

        return path;
    }

    vector<vector<int>> initialPopulation() {
        vector<vector<int>> population;
        int n = graph.size();

        for (int i = 0; i < populationSize; ++i) {
            population.push_back(greedyPath(graph, i % n));
        }

        return population;
    }

    double distance(int city1, int city2) {
        return graph[city1][city2];
    }

    double fitness(const vector<int>& route) {
        double totalDistance = 0;
        for (int i = 0; i < route.size() - 1; ++i) {
            totalDistance += distance(route[i], route[i + 1]);
        }
        totalDistance += distance(route.back(), route[0]);
        return 1 / totalDistance;
    }

    vector<int> selection(const vector<vector<int>>& population) {
        vector<pair<double, vector<int>>> rankedRoutes;
        for (const auto& route : population) {
            rankedRoutes.emplace_back(fitness(route), route);
        }
        sort(rankedRoutes.rbegin(), rankedRoutes.rend());
        return rankedRoutes[0].second;
    }

    vector<int> breed(const vector<int>& parent1, const vector<int>& parent2) {
        int start = rand() % parent1.size();
        int end = rand() % parent1.size();
        if (start > end) {
            swap(start, end);
        }

        vector<int> child(parent1.size(), -1);
        for (int i = start; i <= end; ++i) {
            child[i] = parent1[i];
        }

        int j = 0;
        for (int i = 0; i < parent2.size(); ++i) {
            if (find(child.begin(), child.end(), parent2[i]) == child.end()) {
                while (child[j] != -1) {
                    ++j;
                }
                child[j] = parent2[i];
            }
        }

        return child;
    }

    void mutate(vector<int>& route) {
        for (int i = 0; i < route.size(); ++i) {
            if ((double)rand() / RAND_MAX < mutationRate) {
                int j = rand() % route.size();
                swap(route[i], route[j]);
            }
        }
    }

    void evolve() {
        vector<vector<int>> population = initialPopulation();
        for (int i = 0; i < generations; ++i) {
            vector<int> bestRoute = selection(population);
            cout << "Generation " << i + 1 << ", Best route: ";
            for (int city : bestRoute) {
                cout << city << " ";
            }
            cout << "Distance: " << 1 / fitness(bestRoute) << endl;

            vector<vector<int>> newPopulation;
            newPopulation.push_back(bestRoute);
            for (int j = 1; j < populationSize; ++j) {
                int parent1Index = rand() % population.size();
                int parent2Index = rand() % population.size();
                vector<int> child = breed(population[parent1Index], population[parent2Index]);
                mutate(child);
                newPopulation.push_back(child);
            }
            population = newPopulation;
        }
    }
};

int main() {
    srand(time(0));

    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the distance matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    GeneticAlgorithmTSP tspGA(graph);
    tspGA.evolve();

    return 0;
}

