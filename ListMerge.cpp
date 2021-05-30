#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <memory>

using namespace std;

int main() {    
    vector<int> myvector;
    vector<int>::iterator it;

    it = myvector.begin();
    
    int numbers_of_lists = 0;
    cin>>numbers_of_lists;
    
    for(int i=0;i<numbers_of_lists;i++){
        int list_length=0;
        cin>>list_length;
        
        for(int k=0;k<list_length;k++){
            int number;
            cin>>number;
            it = myvector.insert ( it , number );
        }
    }
  
    sort(myvector.begin(), myvector.end());
       
    for (auto x : myvector)
    {
        auto a = myvector.back();
        cout << x << (a!=x ? "," : "");
    }
 
    return 0;
}