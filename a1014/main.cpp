#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;
struct Customer{
    int id;
    int ask;
    int process;
    int remain;
    int begin_time;
    int end_time;
    bool sorry;
    Customer():id(-1),ask(-1),process(0),remain(0),begin_time(-1),end_time(-1),sorry(false){}
    bool operator ==(const Customer& other){
        return this->id == other.id && this->id != -1;
    }
};
int main()
{
    int n,m,k,q;
    cin >> n >> m >> k >> q;
    vector<int> times(k);
    vector<int> asks(q);
    vector<Customer> customers(k);
    vector<deque<Customer> > windows(n);
    set<int> unserverd_ids;
    set<int> sorry_ids;


    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        times[i] = t;
        customers[i].id = i;
        customers[i].process = t;
    }
    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        asks[i] = t;
        customers[i].ask = t;
    }
    int number = 0;
    for (int i = 0; i<n;i++){
        for(int j=0; j<m; j++){
            if (j == 0){
                customers[number].remain = customers[number].process;
                customers[number].begin_time = 0;
            }

            windows[i].push_back(customers[number]);
            number++;
        }
    }
    for (int i = number; i< k; i++){
        unserverd_ids.insert(i);
    }
    for (int time = 1; time <= 9*60; time++){
        for (auto& c: customers){
            if (c.id != -1 && time > c.ask && c.ask != -1 && c.begin_time != -1&& c.end_time == -1){
                if (c.id <= 0){
                    cout <<"bug";
                }
                c.sorry = true;
                sorry_ids.insert(c.id);
                unserverd_ids.erase(c.id);
                //if (find(unserverd_ids))
                for (int i =0; i< n; i++){
                    Customer temp;
                    temp.id = c.id;

                    auto it = find(windows[i].begin(), windows[i].end(), temp);
                    if (it != windows[i].end()){
                        windows[i].erase(it);
                    }
                    //windows[i].push(customers[number]);
                }
            }
        }
        for (int i =0; i< n; i++){
            if (windows[i].empty()) continue;

            Customer& c = windows[i].front();
            if (c.id == -1) continue;
            c.remain--;
            if (c.remain <= 0){
                // TODO: remove
                //c.end_time = time;
                customers[c.id].end_time = time;
                cout << c.id <<" : "<< time<< "\n";
                windows[i].pop_front();
                // TODO: add new customer
            }
            //windows[i].push(customers[number]);
        }

        int min_size = m+1;
        while(min_size < m){
            int min_window = 0;
            for (int i =0; i< n; i++){
                int size = 0;
                for (auto it = windows[i].begin(); it!=windows[i].end(); it++){
                    if (it->id != -1 && !it->sorry){
                        size++;
                    }
                }
                if (size < min_size){
                    min_size = size;
                    min_window = i;
                }
            }
            if (min_size < m){
                if (!unserverd_ids.empty()){
                    int id = *unserverd_ids.begin();
                    customers[id].begin_time = time;
                    customers[id].remain = customers[id].process;
                    windows[min_window].push_back(customers[id]);
                    unserverd_ids.erase(id);
                }
            }
        }

    }
    //for (int i = 0; i< k; i++){
        for (auto& c: customers){
            if (c.id != -1 && c.ask != -1){
                if (c.sorry)
                {
                    cout <<"\nSorry";
                }
                else{
                    cout <<"\n"<< c.id <<" : "<<c.end_time;
                }
            }
        }
    //}




    return 0;
}
