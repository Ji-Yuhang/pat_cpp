#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;
// 1016 Phone Bills

struct Record{
    string name;
    string date;
    bool on_or_off;
    //Record():on_or_off(false){}
    friend bool operator<(const Record& a, const Record& b){
        return a.date < b.date;
    }
};
int to_int(string str)
{
    return stoi(str);
}
std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
std::vector<int> split_to_int(const std::string& s, char delimiter)
{
    std::vector<int> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(stoi(token));
    }
    return tokens;
}
int main()
{
    vector<int> rate(25);
    map<string, set<Record> > name_records;
    for (int i = 0;i < 24; i++) cin >> rate[i];
    int n(0);
    cin >> n;
    for (int i = 0;i < n; i++){
//        string name;
//        string date;
        string on_or_off;
        Record r;
        cin >> r.name >> r.date >> on_or_off;
        r.on_or_off = (on_or_off == "on-line");
        auto it = name_records.find(r.name);
        if (it != name_records.end()){
            it->second.insert(r);
        } else {
            set<Record> new_set;
            new_set.insert(r);
            name_records[r.name] = new_set;
        }
    }
    map<string, vector<pair<string, string> > > name_fee_pairs;
    cout <<fixed<<setprecision(2);
    for (auto& name_record: name_records){
        string name = name_record.first;
        set<Record>& records = name_record.second;

        vector<pair<string, string> > fee_pairs;
        string last_online_record;
        for(auto& record: records){
            if (record.on_or_off){
                last_online_record = record.date;
            } else {
                if (!last_online_record.empty()){
                    pair<string, string> dates;
                    fee_pairs.push_back(make_pair(last_online_record, record.date));
                    last_online_record = "";
                }
            }
        }
        //name_fee_pairs[name] = fee_pairs;
        string mouth;
        double total = 0.0f;
        //mouth.begin()
        string from = fee_pairs.front().first;
        mouth = from.substr(0, from.find(':'));
        cout << name <<" "<< mouth<<"\n";

        for(auto& fee_pair: fee_pairs){
            double fee = 0.0f;
            int minutes = 0;
            string from = fee_pair.first;
            string to = fee_pair.second;
//            int f_pos = from.find(':');
//            mouth = from.substr(0, f_pos);
//            from = from.substr(f_pos+1);
//            int t_pos = to.find(':');
//            to = to.substr(t_pos+1);
//            stringstream ss_f(from);
//            int f_d,f_h,f_m;
//            ss_f >>f_d>>f_h>>f_m;
//            stringstream ss_t(to);
//            int t_d,t_h,t_m;
//            ss_t >>t_d>>t_h>>t_m;

//            vector<string> from_s = split(from, ':');
//            vector<string> to_s = split(to, ':');
//            vector<int> fs;
//            vector<int> ts;
//            transform(from_s.begin(), from_s.end(),fs.begin(), to_int);
//            transform(to_s.begin(), to_s.end(),ts.begin(), to_int);

            vector<int> fs = split_to_int(from, ':');
            vector<int> ts = split_to_int(to, ':');
            int f_d,f_h,f_m;
            int t_d,t_h,t_m;
            //mouth =fs[0];
            f_d = fs[1];
            f_h = fs[2];
            f_m = fs[3];
            t_d = ts[1];
            t_h = ts[2];
            t_m = ts[3];
            minutes = (t_d - f_d)* 24*60 + (t_h - f_h)* 60 + (t_m - f_m);
            //minutes = (t_d - f_d)* 24*60 + (t_h - f_h)* 60 + (t_m - f_m);

            for (int i = f_h; i< t_h; i++){
                fee += rate[i] * 60;
            }
            fee -= f_m* rate[f_h];
            fee += t_m * rate[t_h];
            for (int i = f_d; i<t_d;i++){
                for (auto r: rate){
                    fee += r*60;
                }
            }
            int mouth_index = fs[0] - 1;
            //fee = minutes * rate[mouth_index];
            cout << from <<" "<< to <<" "<<minutes<<" $"<< fee/100.0 << "\n";
            total += fee;

        }
        cout <<"Total amount: $"<< total/100.0<<"\n";

    }


    return 0;
}
