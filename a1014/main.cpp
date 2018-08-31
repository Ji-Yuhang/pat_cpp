#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;
struct Customer{
    int id;
    int process;
    int remain;
    int begin_time;
    int end_time;
    bool sorry;
    Customer():id(-1),process(0),remain(0),begin_time(-1),end_time(-1),sorry(false){}
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
    }
    int number = 0;

    for(int j=0; j<m; j++){
        for (int i = 0; i<n;i++){
            //if (j == 0){
                customers[number].remain = customers[number].process;
                customers[number].begin_time = 0;
            //}

            windows[i].push_back(customers[number]);
            number++;
        }
    }
    for (int i = number; i< k; i++){
        unserverd_ids.insert(i);
    }

    for (int time = 1; time <= 9*60; time++){
        if (false){
           cout <<"------------------ "<<time<<"------------------\n";
            for (int i =0; i< n; i++){
                if(windows[i].empty()) continue;
                for (auto it = windows[i].begin(); it!=windows[i].end(); it++){
                    cout<< "("<< it->id<<":"<<it->remain<<")";
                }
                cout<<"\n";
            }
        }


        for (int i =0; i< n; i++){
            if (!windows[i].empty()){
                Customer& c = windows[i].front();
                if (c.id == -1) continue;
                c.remain--;
                if (c.remain <= 0){
                    customers[c.id].end_time = time;
                    //cout <<"!remove "<< c.id <<" : "<< time<< "\n";
                    windows[i].pop_front();
                }
            }
        }

        int min_size = m+1;
        do{
            min_size = m+1;
            int min_window = 0;
            for (int i =0; i< n; i++){
                int size = windows[i].size();
                if (size < min_size){
                    min_size = size;
                    min_window = i;
                }
            }
            if (min_size < m){
                if (!unserverd_ids.empty()){
                    int id = *unserverd_ids.begin();
                    Customer temp;
                    temp.id = id;

                    auto it = find(customers.begin(), customers.end(), temp);
                    if (it == customers.end()){
                        unserverd_ids.erase(id);
                        continue;
                    }
                    customers[id].begin_time = time;
                    customers[id].remain = customers[id].process;
                    windows[min_window].push_back(customers[id]);
                    unserverd_ids.erase(id);
                } else {
                    break;
                }
            }
        } while(min_size < m);
    }
        for (int id: asks){
            if (id - 1 < 0) continue;
            auto& c = customers[id - 1];
            if (c.id != -1 ){
                if (c.end_time == -1)
                {
                    cout <<"Sorry\n";
                }
                else{
                    int h = 8;
                    int m = 0;
                    m = c.end_time % 60;
                    h += c.end_time / 60;
                    string str;
                    if(h <10){str+="0";}
                    str+=to_string(h);
                    str+=":";
                    if(m <10){str+="0";}
                    str+=to_string(m);
//                    cout << h<<":"<<m;

                    cout <<str<<"\n";//<<" "<< c.id <<" : "<<c.end_time;
                }
            }
        }
    return 0;
}
