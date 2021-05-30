#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'preprocessDate' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY dates as parameter.
 */

string getMonthByName(const string & monthName)
{
    static const map<string, string> months
    {
        { "Jan", "1" },
        { "Feb", "2" },
        { "Mar", "3" },
        { "Apr", "4" },
        { "May", "5" },
        { "Jun", "6" },
        { "Jul", "7" },
        { "Aug", "8" },
        { "Sep", "9" },
        { "Oct", "10" },
        { "Nov", "11" },
        { "Dec", "12" }
    };
    const auto iter(months.find(monthName));
    return (iter != end(months)) ? iter->second : "";
}

vector<string> preprocessDate(vector<string> dates) {
    vector<string> converted_dates;

    for (auto date : dates)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(date);
        
        string day, month, year;

        tokenStream>>day>>month>>year;
        month=getMonthByName(month);
        day.erase(remove_if(day.begin(), day.end(), [](char c) { return isalpha(c); }), day.end());
        
        ostringstream stringStream;
        stringStream<<year<<"-"<<(month.length()==1 ? "0"+month : month)<<"-"<<(day.length()==1 ? "0"+day : day);
        string converted_date = stringStream.str();

        converted_dates.push_back(converted_date);
    }
    
    return converted_dates;
}
int main()