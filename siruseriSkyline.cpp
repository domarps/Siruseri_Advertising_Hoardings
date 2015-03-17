#include <iostream>
#include <algorithm>
#include <vector>

#define N_MAX 100000

using namespace std;

vector<int> parent;
vector<int> rank;
//vector<int> length;
vector<int> ht;
vector<int> wt;

class skyscraper
{
  public:
         int height;
         int width;
};


struct sortH
{
      int i,height;
      bool operator<(const sortH& p)const
       {
                return (height  > p.height);
        }
};

void make_set(int x,int height,int width)
{
    parent[x] = x;
    rank[x]   = 0;
    //length[x] = 1; 
    ht[x] = height; 
    wt[x] = width; 
}
int find(int x)
{
    if(parent[x] != x) 
    {
       parent[x] = find(parent[x]);
    }
    return parent[x];
}
void set_union(int x,int y)
{
   int root_x,root_y;
   root_x = find(x);
   root_y = find(y);
   if(rank[root_x] < rank[root_y])
   {
          parent[root_x] = root_y;
   }
   else
   {
          parent[root_y] = root_x;
          rank[root_x] += (rank[root_x] == rank[root_y]);
   }
}

int main()
{
    int N,i,j,k,l,x,y,z;
    int H;
    int W;
    int Amax,LA,RA,A,S;
    cin >> N;
    //Union of children
    parent.resize(N);
    rank.resize(N);
    ht.resize(N);
    wt.resize(N);
    ////////////////////////
    
    sortH p[N];
    vector<skyscraper> skyline(N);
    
    for(i = 0; i < N; i++)
    {
       cin >> skyline[i].width;
       cin >> skyline[i].height;
       p[i].height = skyline[i].height;
       p[i].i = i;
       make_set(i,skyline[i].height,skyline[i].width);
    }
    sort(p,p+N); 
    H = p[0].height;
    W = skyline[p[0].i].width;
    Amax = H * W;
    for(i = 1; i < N; i++)
    {
      
      j =  p[i].i;
      k =  j-1;
      l =  j+1;
      S =  skyline[j].height * skyline[j].width;    
      x =  skyline[j].height;
      y =  skyline[k].height; 
      z =  skyline[l].height;
      if(x < y)
      {
          set_union(k,j);
          ht[k] =  x;
          wt[k]+= skyline[k].width;
          LA = ht[k] * wt[k];
      }    
      if(x < z)
      {
          set_union(l,j);
          ht[l] = x; 
          wt[l] += skyline[l].width;
          RA = ht[l] * wt[l];
      }
      if(S < LA) S = LA;
      if(S < RA) S = RA;

      if(Amax < S) Amax = S; 
      
    }  
//    if(skyline[j].height
//  }
//    for(int i = 0; i < N; i++)
//    {
//       cout << skyline[i].height << ' ' << skyline[i].width << endl;
//    }
//    for(int i = 0; i < N; i++)
//    {
       cout << Amax <<  endl;
//    }
}
