#include <bits/stdc++.h>
using namespace std;


int main()
{
    int budget=40;
    map<string,vector<float>> m;

    m["TOI"]={3,3,3,3,3,5,6};
    m["Hindu"]={2.5,2.5,2.5,2.5,2.5,4,4};
    m["ET"]={4,4,4,4,4,4,10};
    m["BM"]={1.5,1.5,1.5,1.5,1.5,1.5,1.5};
    m["HT"]={2,2,2,2,2,4,4};

    int n=m.size();

    vector<pair<string,int>> v;
    for(auto it:m)
    {
        float sum=0;
        for(float x:it.second)
        {
            sum+=x;
        }
        v.push_back({it.first,sum});
    }

    vector<vector<string>> ans;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[i].second+v[j].second<=budget)
                ans.push_back({v[i].first,v[j].first});
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<"{\""<<ans[0][0]<<"\",\""<<ans[0][1]<<"\"}";
        if(i!=n-1) cout<<",";
    }
}
