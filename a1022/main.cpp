#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
// 1022 Digital Library

struct Book{
    string id;
    string title;
    string author;
    vector<string> keys;
    string publisher;
    string year;
};
//Line #1: the 7-digit ID number;
//Line #2: the book title -- a string of no more than 80 characters;
//Line #3: the author -- a string of no more than 80 characters;
//Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
//Line #5: the publisher -- a string of no more than 80 characters;
//Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
int main()
{
    int n,m;
    string n_str;
    getline(cin, n_str);
    n = stoi(n_str);
    //map<string, Book> books;
    vector<Book> books;
    for (int i = 0; i < n; i++){
        Book book;
        getline(cin, book.id);
        getline(cin, book.title);
        getline(cin, book.author);
        string keys_str;
        getline(cin, keys_str);
        stringstream ss(keys_str);
        string key;
        while(getline(ss, key, ' ')){
            book.keys.push_back(key);
        }
        getline(cin, book.publisher);
        getline(cin, book.year);
        //books[book.id] = book;
        books.push_back(book);
    }
    string m_str;
    getline(cin, m_str);
    m = stoi(m_str);
    vector<pair<int, string> > querys;
    for (int i = 0; i < m; i++){
        string str;
        getline(cin, str);

        int type;
        string query_str;
        auto index = str.find(':');
        type = stoi(str.substr(0, index));
        while(str[index] == ':' || isspace(str[index])){
            index++;
        }
        query_str = str.substr(index);
        querys.push_back(make_pair(type, query_str));
    }
    map<pair<int, string>, set<string> > result;
    for (int i = 0; i < books.size(); i++){
        Book& book = books[i];

        for (auto query : querys){
            int type = query.first;
            string query_str = query.second;

            if(type == 1 && book.title == query_str){
                 result[query].insert(book.id);
            } else if(type == 2 && book.author == query_str){
                 result[query].insert(book.id);
            } else if(type == 3 ){
                vector<string> keys = book.keys;
                vector<string>::iterator it = find(keys.begin(), keys.end(), query_str);
                if (it != keys.end())
                    result[query].insert(book.id);
            } else if(type == 4 && book.publisher == query_str){
                 result[query].insert(book.id);
            } else if(type == 5 && book.year == query_str){
                 result[query].insert(book.id);
            }

        }
    }
    for (auto query : querys){
        int type = query.first;
        string query_str = query.second;
        cout << type <<": "<< query_str <<"\n";
        if (result[query].empty()) cout << "Not Found" <<"\n";
        for(auto id: result[query]){
            cout << id <<"\n";
        }
    }


    return 0;
}
