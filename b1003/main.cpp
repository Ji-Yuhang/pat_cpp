#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <set>
using namespace std;

string left_a(const string& str)
{
    size_t pos = str.find('P');
    if (pos == string::npos || pos == 0){
        return "";
    } else {
        string left_A = str.substr(0, pos);
        return left_A;
    }
}
string next_str(const string& str, const string& left_a){
    string next = str;
    next += left_a;
    string::size_type pos = str.find('T');
    next.insert(pos, "A");
    return next;
}

void fuck(set<string>& results, const string& str, int max_size = 100)
{
    if (str.size() <= max_size){
        results.insert(str);
    }
    string next = str;
    string left;
    while(next.size() <= max_size){
        results.insert(next);
        left = left_a(next);
        next = next_str(next, left);
    }

//    set<string> temp;
//    for(auto one: results){
//        string left = left_a(one);
//        string next = next_str(one, left);
//        if (next.size() <= max_size){
//            temp.insert(next);
//        }
////        cout<<"fuck: " << one << "  : "<< next<<"\n";
////        if (one == "PAT"){
////            cout<<"fuck: " << one << " : "<< next<<"\n";
////        }
//    }
//    results.insert(temp.begin(), temp.end());

}

int main()
{
    int n(0);
    cin >> n;
    int max_size(-1);
    vector<string> strs;
    for(int i=0; i< n;i++){
        string str;
        cin >> str;
        strs.push_back(str);
        int str_size = str.size();
        max_size = max(max_size, str_size);
    }
    set<string> all_may_results;
    //all_may_results = may_strs(max_size+1);
    string init = "PAT";
    all_may_results.insert(init);
    fuck(all_may_results, init, max_size);
    //string temp4 = "PAT";
    while(init.size() <= max_size){
        string temp = init;
        while(temp.size() <= max_size){
            temp = next_str(temp, "A");
            //all_may_results.insert(temp);
            fuck(all_may_results, temp, max_size);
        }

        init.insert(0, "A");
        init.push_back('A');

        //all_may_results.insert(init);
        fuck(all_may_results, init, max_size);
    }
    //cout << all_may_results.size() << "\n";

    for (auto one: all_may_results){
        //cout << one << "\n";
    }
//    cout << all_may_results.size() << "\n";


    for(auto str: strs){
        auto it = find(all_may_results.begin(), all_may_results.end(), str);
        if (it != all_may_results.end()){
            cout <<"YES\n";
        } else {
            cout <<"NO\n";
        }
    }
    //system("pause");



    return 0;
}
