// PRIMS
#include <cstring>
#include <iostream>
#include <chrono>
#include <climits>
using namespace std::chrono;
using namespace std;

class Prims
{
public:
    int graph[10][10];
    int v, no_edge, cost_path;
    int V1;

    Prims()
    {
        cost_path = 0;
        no_edge = 0;
    }

    void inputGraph();
    void minCost();
};

void Prims::inputGraph()
{
    cout << "\n Enter The Number of Vertices in Graph: ";
    cin >> V1;
    v = V1;
    cout << "\n Enter The Adjacency Matrix of Graph:" << endl;
    for (int i = 0; i < V1; i++)
    {
        for (int j = 0; j < V1; j++)
        {
            cin >> graph[i][j];
        }
    }
}

void Prims::minCost()
{
    int selected[v] = {0};

    selected[0] = 1;

    cout << " Edge "
         << " : "
         << " Weight " << endl;

    int x, y;
    while (no_edge < V1 - 1)
    {
        int min = 9999999;
        x = 0;
        y = 0;

        for (int i = 0; i < V1; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V1; j++)
                {
                    if (!(selected[j]) && graph[i][j])
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << graph[x][y];
        cout << endl;
        cost_path = cost_path + graph[x][y];
        selected[y] = 1;
        no_edge++;
    }
    cout << " Minimum Cost of Path Using Prims Algorithm : " << cost_path;
}

int main()
{
    Prims p1;
    int a = 1;

    p1.inputGraph();

    cout << "\n -----------------------------------" << endl;
    steady_clock::time_point l1 = steady_clock::now();
    p1.minCost();
    steady_clock::time_point l2 = steady_clock::now();
    duration<double> ltimespan = duration_cast<duration<double>>(l2 - l1);
    cout << "\nTime taken : " << ltimespan.count() << " seconds" << endl;
    return 0;

    // Input: 
    //     Verices: 5 
    //         Matrix : 
    //         0 12 0 25 0 
    //         12 0 11 8 12 
    //         0 11 0 0 17 
    //         25 8 0 0 15 
    //         0 12 17 15 0
    
}
