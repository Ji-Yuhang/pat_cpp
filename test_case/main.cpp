#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

void test_case()
{
    std::srand(std::time(0)); //use current time as seed for random generator
    queue<int> Q;
    vector<int> G[101];
    int s_id = 1;
    int mod = rand() % 3 + 1;
    //Node root;
    Q.push(s_id);
    while (!Q.empty()) {
        //s_id++;

        int id = Q.front();
        if (id >= 100) break;
        Q.pop();
        int size = rand() % 3;
        mod--;
        if (mod <= 1) mod = 10;
        int actual_size = 0;
        for (int i = 0; i < size; i++) {
            if (s_id < 100) {
                s_id++;
                G[id].push_back(s_id);
                Q.push(s_id);
                //cout <<s_id <<" ";
                actual_size++;

            }

        }
        //        cout << id << " " << actual_size << " ";
        //        for (auto c_id: G[id]){
        //            cout <<c_id <<" ";
        //        }
        //
        //        cout << "\n";

    }
    int n = s_id;
    int m = 0;
    for (int i = 0; i <= s_id; i++) {
        if (!G[i].empty()) m++;
    }
    cout << n << " " << m << "\n";

    for (int i = 0; i <= s_id; i++) {

        if (!G[i].empty()) {
            auto children = G[i];

            cout << i << " " << children.size() << " ";
            for (auto id : children) {
                cout << id << " ";
            }
            cout << "\n";

        }

    }

}
int main()
{
    test_case();
    return 0;
}
