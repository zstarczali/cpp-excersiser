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
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> myvector;
    vector<int>::iterator it;
    list<pair<int, int>> collected_items;

    it = myvector.begin();
    
    int numbers_of_lists = 0;
    cin>>numbers_of_lists;
    
    for(int i=0;i<numbers_of_lists;i++)
    {
        int number;
        cin>>number;
        it = myvector.insert(it,number);
    }
    
    sort(myvector.begin(), myvector.end());

    int item=0;
    int index=0;
    int found_items_count=0;

    for(;;)
    {
        it = find(myvector.begin(),myvector.end (), item);
        if(it != myvector.end())
        {
            index = it - myvector.begin();
            myvector.erase(myvector.begin()+index);
            found_items_count++;
        }
        else
        {
            if(found_items_count>1)
            {
                pair<int, int> found_item;
                found_item.first=item;
                found_item.second=found_items_count;
                collected_items.push_back(found_item);
            }
            if(index>=myvector.size())
                break;
            item=myvector.at(index);
            found_items_count=0;
        }
    }

    for (auto const &x: collected_items) 
    {
        auto end = collected_items.back();
        cout<<"("<<x.first<<","<<x.second<<")"<<(end!=x ? "," : ""); 
    }
    return 0;
}