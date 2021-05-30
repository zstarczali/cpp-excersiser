#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
void superStack(vector <string> operations) {
    int n = operations.size();
    vector<int> stack(n), inc(n);

    int k=0;
    for (string op : operations) 
    {
        stringstream strin(op);
        
        string optype;
        strin>>optype;
        if (optype=="push") 
        {
            int x;
            strin>>x;
            stack[k++]=x;
        }
        if (optype=="pop") 
        {
            if(--k) inc[k-1]+=inc[k];
            inc[k]=0;
        }
        if (optype=="inc") 
        {
            int x, y;
            strin>>x>>y;
            inc[x-1]+=y;
        }

        if (not k) 
        {
            // the printf faster than the cout
            printf("EMPTY\n");
        }
        else 
        {
            // the printf faster than the cout
            printf("%d\n",stack[k-1]+inc[k-1]);
        }
    }
}

int main()