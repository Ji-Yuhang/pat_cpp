#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int a[1001][1001] = {0};
bool visited[1001] = {false};

void dfs(int id){
    visited[id] = true;
    for (int i = 0; i < 1001; i++){
        if (visited[i] == false && a[id][i] == 1){
            dfs(i);
        }
    }
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    set<int> ids;
    for (int i = 0; i < m; i++){
        int c,d;
        cin >>c>>d;
        a[c][d] = 1;
        a[d][c] = 1;

        ids.insert(c);
        ids.insert(d);

    }
    for (int i = 0; i< k; i++){
        int id;
        cin >> id;
        fill(begin(visited), end(visited), false);
        visited[id] = true;
        int count = 0;
        for (int j = 0; j < 1001; j++){
            if (visited[j] == false && ids.find(j) != ids.end()){
                dfs(j);
                count++;
            }

        }
        cout << count -1<<"\n";
    }
    return 0;
}
