#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct arr{
long long pop;
int pos;};
struct lists{
vector<int> v;
};
bool acompare(arr lhs, arr rhs) { return lhs.pop < rhs.pop; }
int main()
{
    long long t,n,i,j,xx,yy,flag;
    vector<int>::iterator it;
    cin>>t;
    while(t--)
    {
        cin>>n;
        arr x[n];
        lists lis[n];
        long long ans[n];
       // memset(ans,'0',n+1);
        for(i=0;i<n;i++)
        {cin>>x[i].pop;
        x[i].pos=i+1;}
        for(i=0;i<n-1;i++)
        {cin>>xx>>yy;
        lis[xx-1].v.push_back(yy);
        lis[yy-1].v.push_back(xx);}
        sort(x,x+n, acompare);
        for(i=0;i<n;i++)
        {
            sort(lis[i].v.begin(),lis[i].v.end());
        }
         /*testing data structure
         for(i=0;i<n;i++)
        {cout<<x[i].pop<<" "<<x[i].pos<<endl;}
        for(i=0;i<n;i++)
        {
            cout<<i+1<<" ";
            for(it=lis[i].v.begin();it<lis[i].v.end();it++)
            {
                cout<<*it<<" ";
            }cout<<endl;

        }*/
      //Algorithm
      for(i=0;i<n;i++)
      {j=n-1;flag=0;
      do{
      if(!binary_search(lis[i].v.begin(),lis[i].v.end(),x[j].pos)&&i+1!=x[j].pos ){ans[i]=x[j].pos;flag=1;break;}
      else j--;}
      while(j>=0);
      if(flag==0)ans[i]=0;

      }
      for(i=0;i<n-1;i++)
      {
          cout<<ans[i]<<" ";}
          cout<<ans[n-1]<<endl;

    }return 0;
}
