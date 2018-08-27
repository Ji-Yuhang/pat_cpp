#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
// 1003 Emergency (25)

map<int, int> find_near_citys(const map<pair<int, int>, int>& citys, int city_id)
{
    map<int, int> near_citys;

    map<pair<int, int>, int>::const_iterator it = citys.begin();
    for( ; it != citys.end(); it++){
        int city_a = it->first.first;
        int city_b = it->first.second;
        int length = it->second;
        int other_city_id = 0;

        if (city_a == city_id || city_b == city_id) {
            if (city_a == city_id){
                other_city_id = city_b;
            }
            if (city_b == city_id){
                other_city_id = city_a;
            }
            near_citys.insert(make_pair(other_city_id, length));

        }
    }
    //near_citys.insert(make_pair(near_city_id, length));
    return near_citys;
}

void save_city_path(vector<vector<int> >& paths,int tail_city_id, int city_id)
{
    if (paths.empty()) {
        vector<int> new_path;
        new_path.push_back(tail_city_id);

        paths.push_back(new_path);
    }
    vector<vector<int> >::iterator it = paths.begin();
    for( ;it != paths.end(); it++){
        if ( !it->empty() && it->back() == tail_city_id && find( it->begin(), it->end(), city_id) == it->end()){
            vector<int> new_path = *it;
            new_path.push_back(city_id);

            paths.push_back(new_path);
//            for (int i = 0; i < new_path.size(); ++i){
//                cout << new_path.at(i) << " ";
//            }
//            cout << endl;
        }
    }
}
vector<vector<int> > find_paths_with_tail(const vector<vector<int> >& paths, int tail_city_id, int city_id)
{
    vector<vector<int> > result;
    vector<vector<int> >::const_iterator it = paths.begin();
    for(; it != paths.end(); it++){
        if ( !it->empty() && it->back() == tail_city_id && find( it->begin(), it->end(), city_id) == it->end())
        {
            result.push_back(*it);
        }
    }
    return result;
}

void build_roads(const map<pair<int, int>, int>& citys, int tail_city_id, int target_city_id, vector<vector<int> >& paths)
{
//    cout << "build_roads( tail_city_id:"<< tail_city_id<<" target_city_id:"<< target_city_id<< " paths.size:"<< paths.size()<< endl;
    //map<vector<int>, int> roads_with_length;

//    int current_city_id = 0;
    map<int, int> near_citys = find_near_citys(citys, tail_city_id);
    map<int, int>::iterator it = near_citys.begin();
    for( ; it != near_citys.end(); it++){
        int city_id = it->first;
        int length = it->second;

        //             save_city_path(paths, tail_city_id, city_id);
        {

            if (paths.empty()) {
                vector<int> new_path;
                new_path.push_back(tail_city_id);

                paths.push_back(new_path);
            }
            if (false){
                vector<vector<int> > possible_paths = paths;
                int index = 0;
                vector<vector<int> >::iterator it = possible_paths.begin();
                for( ;it != possible_paths.end(); it++){
                    //if ( !it->empty() && it->back() == tail_city_id && find( it->begin(), it->end(), city_id) == it->end()){
                        vector<int> new_path = *it;
                        new_path.push_back(city_id);

    //                    vector<vector<int> >::iterator erase_it = find( paths.begin(), paths.end(), *it);
    //                    if (erase_it != paths.end()){
    //                        paths.erase(erase_it);
    //                    }
                        paths.push_back(new_path);

                        if (city_id != target_city_id){
                            build_roads(citys, city_id, target_city_id, paths);
                        }
                    //}
                    index++;
                }
            } else {
                vector<vector<int> > need_copy_paths = find_paths_with_tail(paths, tail_city_id, city_id);

                vector<vector<int> >::iterator it = need_copy_paths.begin();
                for( ;it != need_copy_paths.end(); it++){
                    if ( !it->empty() && it->back() == tail_city_id && find( it->begin(), it->end(), city_id) == it->end()){
                        vector<int> new_path = *it;
                        new_path.push_back(city_id);
                        paths.push_back(new_path);

                        if (city_id != target_city_id){
                            build_roads(citys, city_id, target_city_id, paths);
                        }
                    }

                }
            }


        }

    }
}

int main_old()
{
//    5 6 0 2
//    1 2 1 5 3
//    0 1 1
//    0 2 2
//    0 3 1
//    1 2 1
//    2 4 1
//    3 4 1

// 2 4

    int city_count = 0;
    int road_count = 0;
    int current_city_id = 0;
    int target_city_id = 0;

    cin >> city_count >> road_count >> current_city_id >> target_city_id;

    map<int, int> teams;
    for(int i = 0; i < city_count; ++i){
        int city_id = i;
        int city_team_member_count = 0;
        cin >> city_team_member_count;
        teams[city_id] = city_team_member_count;
    }
    // <int, map<int, int> >
    // <city_a, map<city_b, length> >
    //map<int, map<int, int> > citys;
    map<pair<int, int>, int> citys;
    for(int i = 0; i < road_count; ++i){
        int city_a = 0;
        int city_b = 0;
        int length_between_city_a_b = 0;

        cin >> city_a >> city_b >> length_between_city_a_b;

        pair<int, int> city_pair = make_pair(city_a, city_b);
        citys.insert(make_pair(city_pair, length_between_city_a_b));

        pair<int, int> same_pair = make_pair(city_b, city_a);
        citys.insert(make_pair(same_pair, length_between_city_a_b));
    }

    map<vector<int>, pair<int, int> > path_detail;

    int tail_city_id = current_city_id;
    vector<vector<int> > paths;
    if (paths.empty()) {
        vector<int> new_path;
        new_path.push_back(tail_city_id);

        paths.push_back(new_path);
    }
    build_roads(citys, tail_city_id, target_city_id, paths);
    {
        vector<vector<int> >::iterator it = paths.begin();
        for(; it != paths.end(); it++){
            if (it->front() == current_city_id && it->back() == target_city_id){
                int member_count = 0;
                int length = 0;

                for (int i = 0; i < it->size(); ++i){
                    member_count += teams[it->at(i)];
                }
                for (int i = 0; i < it->size() - 1; ++i){
                    int city_a = it->at(i);
                    int city_b = it->at(i+1);
                    length += citys[make_pair(city_a, city_b)];
                }
                path_detail[*it] = make_pair(length, member_count);
            }
        }
    }
    {
        int min_length = 0;
        map<vector<int>, pair<int, int> >::iterator it = path_detail.begin();
        for(; it != path_detail.end(); it++){
            int length = it->second.first;
            int member_count = it->second.second;
            if (min_length == 0){
                min_length = length;
            } else {
                min_length = min(min_length, length);
            }
        }
        int path_count = 0;
        int max_member_count = 0;
        it = path_detail.begin();
        for(; it != path_detail.end(); it++){
            int length = it->second.first;
            int member_count = it->second.second;

            if (length == min_length){
                path_count++;
                max_member_count = max(member_count, max_member_count);
            }
        }
        cout << path_count << " " << max_member_count;

    }

    return 0;
}
