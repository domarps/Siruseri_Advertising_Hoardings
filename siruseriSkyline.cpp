// (IARCS IOI Training Camp 2006, Preyas Popat)
// Problem Statement = http://www.iarcs.org.in/inoi/online-study-material/problems/advertising-hoardings-soln.php#solution

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
  bool operator<(const skyscraper &s2) const 
  {
      return height >  s2.height;
  }
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
    int Amax,max_start,max_end;
    int curr_i,curr_A,current_width,current_height;
    int high_i,low_i;
    int root_element;
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
       current_width = 0;
       
       cin >> skyline[i].width;
       cin >> skyline[i].height;
       p[i].height = skyline[i].height;
       p[i].i = i;
       make_set(i,skyline[i].height,skyline[i].width);
    }
    sort(p,p+N); 
    Amax   =   0;
    high_i =   N;
    low_i  =   -1;
    for(i = 1; i < (N-1); i++) //please take note. 
    {
      current_width  = 0; 
      
      j =  p[i].i;
      k =  j-1;
      l =  j+1;
      x =  skyline[j].height;
      y =  skyline[k].height; 
      z =  skyline[l].height;
      if(x <= y)
      {
          set_union(k,j);
      }    
      if(x <= z)
      {
          set_union(l,j);
      }
      //Whatever shit happened up here, happened 
      //Now we just may have a parent here for element i
      curr_i = j;//fix me
      root_element = find(curr_i);
      current_height = skyline[j].height;
      while(curr_i > 0 && root_element == find(curr_i))
      {
         current_width += skyline[curr_i].width;
         //cout << skyline[curr_i].height << '\t';
         if(current_height > skyline[curr_i].height) current_height = skyline[curr_i].height;  
         curr_i--;
      }
      low_i = curr_i; //Lower Boundary Found!!
      curr_i = j+1;//fix me
      while(curr_i < N && root_element == find(curr_i))
      { 
         current_width += skyline[curr_i].width;
         //cout << skyline[curr_i].height << '\t';
         if(current_height > skyline[curr_i].height) current_height = skyline[curr_i].height;  
         curr_i++;
      }
//      cout << endl;
      high_i = curr_i; //Higher Boundary Found Like a Boss
      curr_A = current_height * current_width;
//      cout << j << ' ' << current_height << ' ' << current_width << endl;
      if(curr_A > Amax)
      {
         Amax = curr_A;
         max_start = high_i;
         max_end   = low_i;
      }
    }  
    cout << Amax << endl;
}
