#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <map>
#include <cstdlib>
using namespace std;
bool is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}
bool is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}
bool is_number(char c)
{
    return c >= '0' && c <= '9';
}
bool is_upper_or_number(char c)
{
    return is_upper(c) || is_number(c);
}
bool is_letter(char c)
{
    return is_upper(c) || is_lower(c);
}
bool is_between(char c, char begin, char end)
{
    return c >= begin && c <= end;
}

int main()
{
    string s1;
    string s2;
    string s3;
    string s4;

    s1 = "3485djDkxh4hhGE";
    s2 = "2984akDfkkkkggEdsb";
    s3 = "s&hgsfdk";
    s4 = "d&Hyscvnm";

    cin >> s1 >> s2 >> s3 >> s4;

   //"ABCDEFGHIGKLMNOPQRSTUVWXYZ";
    string day;
    string hh;
    string mm;
    bool flag = false; // check day field
    for (int i = 0; i < s1.size() && i < s2.size(); ++i) {

        // skip if flag is true
        if (!flag && is_between(s1[i], 'A', 'G') && (s1[i] == s2[i])) {
            day = s1[i];
            flag = true;
            continue;
        }

        if (flag && (is_between(s1[i], 'A', 'N')|| is_number(s1[i])) && (s1[i] == s2[i])) {
            hh = s1[i];
            break;
        }
    }

    for (int i = 0; i < s3.size() && i < s4.size(); ++i) {
        if (s3[i] && s4[i] && is_letter(s3[i]) && (s3[i] == s4[i])) {
            stringstream ss;
            if (i < 10) {
                ss << "0";
            }
            ss << i;

            mm = ss.str();
            break;
        }
    }

    map<string, string> day_hash;
    day_hash["A"] = "MON";
    day_hash["B"] = "TUE";
    day_hash["C"] = "WED";
    day_hash["D"] = "THU";
    day_hash["E"] = "FRI";
    day_hash["F"] = "SAT";
    day_hash["G"] = "SUN";
    map<string, string> hh_hash;
    hh_hash["0"] =  "00";
    hh_hash["1"] =  "01";
    hh_hash["2"]=  "02";
    hh_hash["3"]=  "03";
    hh_hash["4"]=  "04";
    hh_hash["5"]=  "05";
    hh_hash["6"]=  "06";
    hh_hash["7"]=  "07";
    hh_hash["8"]=  "08";
    hh_hash["9"]=  "09";
    hh_hash["A"]=  "10";
    hh_hash["B"]=  "11";
    hh_hash["C"]=  "12";
    hh_hash["D"]=  "13";
    hh_hash["E"]=  "14";
    hh_hash["F"]=  "15";
    hh_hash["G"]=  "16";
    hh_hash["H"]=  "17";
    hh_hash["I"]=  "18";
    hh_hash["J"]=  "19";
    hh_hash["K"]=  "20";
    hh_hash["L"]=  "21";
    hh_hash["M"]=  "22";
    hh_hash["N"]=  "23";

    cout << day_hash[day] << " " << hh_hash[hh] << ":" << mm << endl;

    return 0;
}
