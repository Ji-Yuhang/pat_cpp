#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
struct Grade{
    string id;
    int c;
    int m;
    int e;
    int total;
    Grade():c(0),m(0),e(0),total(0){}
    bool operator==(const Grade& other)
    {
        return this->id == other.id;
    }
};

bool cmp_c(const Grade& a, const Grade& b)
{
    return a.c > b.c;
}
bool cmp_m(const Grade& a, const Grade& b)
{
    return a.m > b.m;
}
bool cmp_e(const Grade& a, const Grade& b)
{
    return a.e > b.e;
}
bool cmp_a(const Grade& a, const Grade& b)
{
    return a.total > b.total;
}
int main()
{
    int n,m;
    //map<string, Grade> grades;
    vector<Grade> grades;
    vector<Grade> grades_c;
    vector<Grade> grades_m;
    vector<Grade> grades_e;
    vector<Grade> grades_a;
    cin >> n>> m;
    for (int i = 0; i< n; i++)
    {
        string id;
        int c,m,e;
        //int a;
        cin >> id  >> c >> m >> e;
        //a = c+m+e / 3;
        Grade g;
        g.id = id;
        g.c = c;
        g.m = m;
        g.e = e;
        g.total = c+m+e;
        //grades.insert(make_pair(id, g));
        grades.push_back(g);
        grades_c.push_back(g);
        grades_m.push_back(g);
        grades_e.push_back(g);
        grades_a.push_back(g);
    }
    vector<string> check_ids;
    for (int i = 0; i < m; i++)
    {
        string id;
        cin >> id;
        check_ids.push_back(id);
    }

    sort(grades_c.begin(), grades_c.end(), cmp_c);
    sort(grades_m.begin(), grades_m.end(), cmp_m);
    sort(grades_e.begin(), grades_e.end(), cmp_e);
    sort(grades_a.begin(), grades_a.end(), cmp_a);
    for(auto id: check_ids){
        Grade s_t;
        s_t.id = id;
        auto it = find(grades.begin(), grades.end(), s_t);//grades.(id);
        if (it == grades.end()){
            cout << "N/A\n";
        } else {
            auto it_c = find(grades_c.begin(),  grades_c.end(), *it);
            while(it_c != grades_c.begin()){
                auto last = it_c - 1;
                if (it_c->c == last->c){
                    it_c = last;
                } else {
                    break;
                }
            }

            auto it_m = find(grades_m.begin(),  grades_m.end(), *it);
            while(it_m != grades_m.begin()){
                auto last = it_m - 1;
                if (it_m->m == last->m){
                    it_m = last;
                } else {
                    break;
                }
            }
            auto it_e = find(grades_e.begin(),  grades_e.end(), *it);
            while(it_e != grades_e.begin()){
                auto last = it_e - 1;
                if (it_e->e == last->e){
                    it_e = last;
                } else {
                    break;
                }
            }
            auto it_a = find(grades_a.begin(),  grades_a.end(), *it);
            while(it_a != grades_a.begin()){
                auto last = it_a - 1;
                if (it_a->total == last->total){
                    it_a = last;
                } else {
                    break;
                }
            }
            int diff_c = distance(grades_c.begin(), it_c) + 1;
            int diff_m = distance(grades_m.begin(), it_m) + 1;
            int diff_e = distance(grades_e.begin(), it_e) + 1;
            int diff_a = distance(grades_a.begin(), it_a) + 1;

            map<int, string> t;
            t.insert(make_pair(diff_a, "A"));
            t.insert(make_pair(diff_c, "C"));
            t.insert(make_pair(diff_m, "M"));
            t.insert(make_pair(diff_e, "E"));
            //cout << diff_c <<" "<< diff_m <<" "<< diff_e <<" "<< diff_a <<"\n";
            for(auto p: t){
                //cout << p.first <<" : "<< p.second<<"\n";
            }
            cout << t.begin()->first<<" "<< t.begin()->second<<"\n";
        }

    }



    return 0;
}
