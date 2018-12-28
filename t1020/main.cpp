#include <iostream>
#include <set>
using namespace std;
string remove(const string& origin, size_t size, size_t pos)
{
	if(pos == 0) return origin.substr(1);
	if(pos >= size) return origin.substr(0, size-1);

	string left = origin.substr(0, pos);
	string right = origin.substr(pos + 1);
	return left+right;
}
int testremove()
{
	string str = "abc";
	string substr0 = remove(str, str.size(), 0);
	string substr1 = remove(str, str.size(), 1);
	string substr2 = remove(str, str.size(), 2);
	string substr3 = remove(str, str.size(), 3);
	cout << substr0<< endl;
	cout << substr1<< endl;
	cout << substr2<< endl;
	cout << substr3<< endl;
}
int exec()
{
  string str;
	getline(std::cin,str);

  int n = str.size();
  set<string> strs;
  for(int i = 0; i < n; i++){
	  char ch = str[i];
	  string substr = remove(str, n, i);
	  strs.insert(substr);
  }

  set<string> strs2 = strs;
  for(auto it = strs.begin(); it != strs.end(); it++){
	  string one = *it;
	  int n = one.size();
	  for(int i = 0; i < n; i++){
		  char ch = one[i];
		  string substr = remove(one, n, i);
		  strs2.insert(substr);
	  }
  }
  cout << strs2.size()+1;
	// cout << endl;
	// for(auto it = strs2.begin(); it != strs2.end(); it++){
	//     cout << *it << endl;
  // }
  return 0;
}
int main()
{
	// testremove();
	exec();
}
