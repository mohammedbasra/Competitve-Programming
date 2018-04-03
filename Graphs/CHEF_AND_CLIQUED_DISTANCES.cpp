#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long m,n,k,s,x,t,i,j,a,b,c,V,U,W,position;
    cin>>t;
    while(t--)
    {   cin>>n>>k>>x>>m>>s;
        long long distance[n];
        long long small=LONG_LONG_MAX;
        for(i=0;i<n;i++)
        {distance[i]=LONG_LONG_MAX;}
        priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > pq;


if(s>=1&&s<=k){
            vector<pair<long long,long long> > v[n];
            vector<pair<long long,long long> >::iterator it;
             for(i=0;i<k;i++)
            {if((s-1)!=i){v[s-1].push_back(make_pair(x,i));
                        v[i].push_back(make_pair(x,s-1));}}
            for(i=0;i<m;i++)
            {
                cin>>a>>b>>c;
                v[a-1].push_back(make_pair(c,b-1));
                v[b-1].push_back(make_pair(c,a-1));
            }

            pq.push(make_pair(0,s-1));
            distance[s-1]=0;


            while(!pq.empty())
            {
                U=pq.top().second;

                pq.pop();
                 for(it=v[U].begin();it!=v[U].end();it++)
                 {
                     V=(*it).second;
                     W=(*it).first;


                  if (distance[V] > distance[U] + W)
            {
                distance[V] = distance[U] + W;
                pq.push(make_pair(distance[V], V));
            }
            }
            }
            cout<<distance[0];
            for(i=1;i<n;i++)
            {
                cout<<" "<<distance[i];
            }cout<<endl;

        }

           else{ vector<pair<int,int> > v[n];
            vector<pair<int,int> >::iterator it;
            vector<int> B;
            for(i=0;i<m;i++)
            {
                cin>>a>>b>>c;
                if(a>=1&&a<=k)B.push_back(a-1);
                if(b>=1&&b<=k)B.push_back(b-1);
                v[a-1].push_back(make_pair(c,b-1));
                v[b-1].push_back(make_pair(c,a-1));
            }


            pq.push(make_pair(0,s-1));
            distance[s-1]=0;


            while(!pq.empty())
            {
                U=pq.top().second;

                pq.pop();
                 for(it=v[U].begin();it!=v[U].end();it++)
                 {
                     V=(*it).second;
                     W=(*it).first;


                  if (distance[V] > distance[U] + W)
            {
                distance[V] = distance[U] + W;
                pq.push(make_pair(distance[V], V));
            }
            }
            }

            for(i=0;i<B.size();i++)
            {
                if(small>distance[B[i]]){small=distance[B[i]];position=B[i];}
            }
            for(i=0;i<k;i++)
            {
                if(i!=position){v[position].push_back(make_pair(x,i));
                         v[i].push_back(make_pair(x,position));}

            }
            for(i=0;i<n;i++)
            {
                distance[i]=LONG_LONG_MAX;
            }
            pq.push(make_pair(0,s-1));
            distance[s-1]=0;


            while(!pq.empty())
            {
                U=pq.top().second;

                pq.pop();
                 for(it=v[U].begin();it!=v[U].end();it++)
                 {
                     V=(*it).second;
                     W=(*it).first;


                  if (distance[V] > distance[U] + W)
            {
                distance[V] = distance[U] + W;
                pq.push(make_pair(distance[V], V));
            }
            }
            }
            cout<<distance[0];
           for(i=1;i<n;i++)
           {
               cout<<" "<<distance[i];
           }cout<<endl;

        }
    }

    return 0;
}
