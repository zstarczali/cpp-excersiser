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

using namespace std;

int main() { 
    int current_max=0;
    int max = 0;
    int root_counter = 0;
    string input_str;
    
    cin>>input_str;
    if(input_str.empty()){
        cout<<-1;
        return 0;
    }
    
    for(int i=0;i<input_str.length();i++){
        if(input_str[i]=='(')
        {  
            if(current_max+1==1)
            {
                root_counter++;     
                if(root_counter>1){
                    cout<<-1;
                    return 0;     
                }
            }
            current_max++;
            if (current_max > max)
                max = current_max;
        }
        if(input_str[i]==')')
        {
            if (current_max > 0)
                current_max--;
            else
            {
                cout<<-1;
                return 0;               
            }
        }
    }
    
    if (current_max != 0)
        cout<<-1;
    else 
        cout<<max; 
        
    return 0;
}