#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void DFS_insert(vector<int> G[], int id, int ignore_id, set<int>& a_set)
{
    if (a_set.find(id) != a_set.end()) return;
    if (id == ignore_id) return;
    a_set.insert(id);

    for(int i = 0; i < G[id].size(); i++){
        if (ignore_id == G[id][i]) continue;
        DFS_insert(G, G[id][i], ignore_id, a_set);
    }

}

int main2()
{
    int n,m,k;
    cin >> n >>m >> k;
    //bool g[1000][1000] = {false};
    vector<int> G[1000];
    set<int> nodes;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a>>b;
        //g[a][b] = true;
        //g[b][a] = true;
        G[a].push_back(b);
        G[b].push_back(a);
        nodes.insert(a);
        nodes.insert(b);
    }
    //int checks[] = {0};
    vector<int> checks;
    for (int i = 0; i < k; i++)
    {
        int id;
        cin >> id;
        checks.push_back(id);
    }
    for(int city: checks)
    {
        int count = 0;
        vector<set<int> > sets;
        //set<int> a_set;
        for(int i = 0; i < 1000; i++){
            if(i == city)  continue;
            if (nodes.find(i) == nodes.end()) continue;
            //if (G[i].empty()) continue;
            bool have_inserted = false;
            for(auto& a_set: sets){
                if (a_set.find(i) != a_set.end()){
                    //a_set.insert(id);
                    have_inserted = true;
                    DFS_insert(G, i, city, a_set);
                }
            }
            if (!have_inserted){
                set<int> new_set;
                //new_set.insert(i);

                DFS_insert(G, i, city, new_set);
                sets.push_back(new_set);
            }
        }
        if (false)
        {
            cout<<"----------";
            for(auto s: sets){
                cout<<"\nSet: ";
                for(auto i: s){
                    cout <<i<<" ";
                }
                cout<<"\n";
            }
        }
        int alone_node_count = n - nodes.size();

        cout << sets.size() - 1 + alone_node_count<<"\n";
        //cout<<"----------\n";
    }

    return 0;
}
