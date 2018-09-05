#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <tuple>
#include <queue>
using namespace std;
// 1030 Travel Plan

typedef int Color;

static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

const int INF = numeric_limits<int>::max();

struct Edge{
    int a;
    int b;
    int dis;
    int cost;
};

vector<vector<Edge> > G;
vector<Color> colors;
vector<int> distances;
vector<int> parents;
vector<int> costs;
int source;
int target;
vector<int> path;
void dfs(int node)
{
    colors[node] = GRAY;
    for(auto edge: G[node]){
        int adj = edge.a + edge.b - node;
        int new_distance = distances[node] + edge.dis;
        int new_cost = costs[node] + edge.cost;


        if (colors[adj] == WHITE){
            distances[adj] = new_distance;
            costs[adj] = new_cost;
            parents[adj] = node;
            dfs(adj);
        }
        if (new_distance <= distances[adj]){
            distances[adj] = new_distance;
            parents[adj] = node;
            if (new_cost <= costs[adj]){
                costs[adj] = new_cost;
                parents[adj] = node;
                if (adj == target){
                    path = parents;
                }
            }
        }


//        if (colors[adj] == WHITE){
//            parents[adj] = node;
//            distances[adj] = new_distance;
//            costs[adj] = new_cost;
//            dfs(adj);
//        } else {
//            if (new_distance <= distances[adj]){
//                distances[adj] = new_distance;
//                if (new_cost <= costs[adj]){
//                    costs[adj] = new_cost;
//                    if (adj == target){
//                        path = parents;
//                    }
//                }
//            }
//        }



//        if ( new_distance <= distances[adj]){
//            distances[adj] = new_distance;
//            parents[adj] = node;
//            //costs[adj] = new_cost;
//            if (tie(new_distance, new_cost) < tie(distances[adj], costs[adj])){
//                distances[adj] = new_distance;
//                costs[adj] = new_cost;
//                if (adj == target){
//                    path = parents;
//                }
//            }
//        }
    }
    if (node == target){
        path = parents;
        int temp = node;
        while(temp != -1){
            cout << temp << " ";
            temp = parents[temp];
        }
        cout << "\n";
    }

    colors[node] = BLACK;
}
void dijkstra()
{
    queue<int> que;
    que.push(source);
    colors[source] = GRAY;
    while(!que.empty()){
        int node = que.front();
        que.pop();
        for(auto edge: G[node]){
            int adj = edge.a + edge.b - node;
            int new_distance = distances[node] + edge.dis;
            int new_cost = costs[node] + edge.cost;


             if (colors[adj] == WHITE){
                colors[adj] = GRAY;
                distances[adj] = new_distance;
                costs[adj] = new_cost;
                parents[adj] = node;
                que.push(adj);
            }
            for (auto adj_e: G[adj]){
                  int adj_adj = adj_e.a + adj_e.b - adj;
                int adj_new_distance = distances[adj] + adj_e.dis;
                int adj_new_cost = costs[adj] + adj_e.cost;
                if (adj_new_distance <= distances[adj_adj]){
                    distances[adj_adj] = adj_new_distance;
                    parents[adj_adj] = adj;
                    if (adj_new_cost <= costs[adj_adj]){
                        costs[adj_adj] = adj_new_cost;
                        parents[adj_adj] = adj;
                        if (adj_adj == target){
                            path = parents;
                        }
                    }
                }
            }

        }
        colors[node] = BLACK;
        //cout << "pop: "<< node << "\n";
//        if (node == target){
//            path = parents;
//            int temp = node;
//            while(temp != -1){
//                cout << temp << " ";
//                temp = parents[temp];
//            }
//            cout << "\n";
//        }
    }
}

int main()
{

    int n,m;
    cin >> n >> m >>source >>target;

    G.resize(n);
    colors.resize(n);
    distances.resize(n);
    parents.resize(n);
    costs.resize(n);
    fill(colors.begin(), colors.end(), WHITE);
    fill(distances.begin(), distances.end(), INF);
    fill(parents.begin(), parents.end(), -1);
    fill(costs.begin(), costs.end(), INF);

    for (int i = 0; i < m; i++){
        Edge e;
        cin >> e.a >>e.b >>e.dis >>e.cost;
        G[e.a].push_back(e);
        G[e.b].push_back(e);
    }

    distances[source] = 0;
    costs[source] = 0;
    //dfs(source);
    dijkstra();
    vector<int> sqe_path;
    int node = target;
    while(node != -1){
        sqe_path.insert(sqe_path.begin(),node);
        //cout << node << " ";
        node = parents[node];
    }
    for(auto node: sqe_path){
        cout << node << " ";
    }
    cout << distances[target]<< " "<< costs[target];



    return 0;
}
