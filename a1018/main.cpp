#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
//#include <multimap>
using namespace std;
//1018 Public Bike Management
static int max_c;
static int capacity[502] = {0};
struct Edge{
    int a;
    int b;
    int time;
};

int node_need(const vector<int>& parents, int node, int s)
{
    int total_need = 0;
    //int last_need = 0;
    do {
        int need = max_c / 2 - capacity[node];
        if (need + total_need < 0) need = 0;

        total_need += need;
        //if(need < 0 && total_need < 0) need = 0;
        //total_need += need;
        node = parents[node];
        //last_need = need;
    } while(node != s);
    return max(total_need,0);
}
int node_remain(const vector<int>& parents, int node, int s, int remain)
{
    vector<int> path;
    while(node != s) {
        path.push_back(node);
        node = parents[node];
    }
    reverse(path.begin(), path.end());
    for (auto i: path){
        int need = max_c / 2 - capacity[i];
        remain -= need;
    }
    return remain;
}
void print_path(const vector<int>& parents, int node, int s)
{
    if (s == node){
        cout <<node;
    } else if (node == -1){
        cout <<"ERROR";
    } else {
        print_path(parents, parents[node], s);
        cout<< "->" << node;
    }
}

int main()
{
    int n,t,m;

    cin >> max_c>> n >> t >> m;
    //vector<Edge> edges[m];
    map<int , vector<Edge> > adjs;
    for (int i = 1; i <= n; i++){
        cin >> capacity[i];
    }
    for (int i = 0; i < m; i++){
        Edge edge;
        cin >> edge.a >> edge.b >> edge.time;
        adjs[edge.a].push_back(edge);
        adjs[edge.b].push_back(edge);
    }
    vector<bool> visited(n+1, false);
    const int INF = 999999999;
    vector<int> distance(n+1, INF);
    vector<int> parent(n+1, -1);
    int s = 0;
    distance[s] = 0;
    queue<int> que;
    que.push(s);
    //vector<vector<int> > paths;
    int min_distance = INF;
    multimap<int, vector<int> > paths;
    while(!que.empty()){
        int top = que.front(); que.pop();
        if (visited[top]) continue;

        for(Edge& e: adjs[top]){
            int adj = e.a + e.b - top;
            //distance[adj] = min(distance[top] + e.time, distance[adj]);
            if (distance[adj] >= distance[top] + e.time){
                distance[adj] = distance[top] + e.time;
                parent[adj] = top;
                if (adj == t){
                    paths.insert(make_pair(distance[adj], parent));
                    min_distance = min(min_distance, distance[adj]);
                }
            }
            if (!visited[adj]){
                que.push(adj);
            }
        }
        visited[top] = true;
    }

    int min_need = INF;
    int min_back = INF;
    vector<int> min_need_path;
    auto range = paths.equal_range(min_distance);
    for(auto it = range.first; it != range.second; it++ ){
        int need = node_need(it->second, t, s);
        int remain = node_remain(it->second, t, s, need);
        if (need < min_need){
            min_need = need;
            min_back = remain;
            min_need_path = it->second;
        }
        else if (need == min_need && remain < min_back){
            min_back = remain;
            min_need_path = it->second;
        }

//        if (need >= 0 && need <= min_need){
//            min_need = need;
//            min_need_path = it->second;
//        }
//        if (need <= 0 && need > min_back)
//        {
//            min_back = need;
//            min_need_path = it->second;
//        }
        //cout << "\n";
    }
    cout << max(min_need,0) << " ";
    print_path(min_need_path, t, s);
    cout << " "<< min_back;

    return 0;
}
