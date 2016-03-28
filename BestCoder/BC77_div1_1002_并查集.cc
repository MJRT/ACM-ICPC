//MJRT
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//////////////////////
#include<iostream>
#include<algorithm>
#include<string>
#include <iterator>
#include<sstream>
#include<functional>
#include<numeric>
///////////////////////
#include<vector>
#include<map>
#include <stack>
#include<queue>
#include<set>
#include <bitset>
#include <list>
///////////////////////
//#include<ext/pb_ds/priority_queue.hpp> //pd_bs库,hdu&&poj不支持
using namespace std;
#define lowbit(x) ((x)&(-x))
static int INDEX = 0,BUGs = 0;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
template<class T> T MAX(T a, T b) { return a > b ? a : b; }
template<class T> T MIN(T a, T b) { return a < b ? a : b; }
template<class T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<class T> T LCM(T a, T b) { return a / GCD(a,b) * b;    }
#define BUG() cout << "There is BUG No." << BUGs++ <<endl
#define Whats(x)          cout << "{ "<< #x << " }" << " is " << "*** "<< x << " ***" << "  index:" << INDEX++ <<endl
#define Show(x,s,l)      {cout << #x << ": "; for(int i = s ; i < s+l ; i++) cout << x[i] << " ";  cout << "\n";}
#define Show2(x,s,l,h)   {cout << #x << ": " << l-s << "*" <<h-s <<"\n"; for(int j = s ; j < s+h ; j++){for(int i = s ; i < s+l ; i++) cout << x[j][i] << " ";cout << "\n";};  cout << "\n";}

typedef  long long int LL;
const int INF = 0x3f3f3f3f;

const int N =  500010;
bool vis[N];
char maze[510][510];

int pre[N];
int rk[N];

int find(int x);
bool join(int x,int y);
void init(int n);
bool same(int x,int y);

int m,n;

int ID(int x,int y)
{
    return (x-1)*m+y;
}

int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
int dy[8] = {-1, 0 ,1,-1,1,-1,0,1};

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case;
    scanf("%d",&Case);
    while(Case--)
    {
        scanf("%d%d",&n,&m);
        init(500010);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%s",maze[i]+1);
        }

        int s = 0 ,e = n*m+1 ;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                if(maze[i][j] == '1' && j == 1)          join(s,ID(i,j));
                if(maze[i][j] == '1' && j == m)          join(e,ID(i,j));

                if(maze[i][j] == '1')
                {
                    for(int k = 0 ; k < 8 ; k++)
                    {
                        int nx = i+dx[k] ,ny = j+dy[k];
                        if(1 <= nx && nx <= n && 1 <= ny && ny <= m && maze[nx][ny] == '1')
                            join(ID(i,j),ID(nx,ny));
                    }
                }

            }
        }

        int q,flag = -1;
        scanf("%d",&q);
        if(same(s,e)) flag = 0;
        for(int i = 1 ; i <= q ; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            if(flag > 0)  continue;
            maze[++x][++y] = '1';
            if(y == 1)          join(s,ID(x,y));
            if(y == m)          join(e,ID(x,y));
            for(int k = 0 ; k < 8 ; k++)
            {
                int nx = x+dx[k] ,ny = y+dy[k];
                if(1 <= nx && nx <= n && 1 <= ny && ny <= m && maze[nx][ny] == '1')
                join(ID(x,y),ID(nx,ny));
            }

            if(same(s,e)) flag = i;
        }

        printf("%d\n",flag);

    }

    return 0;
}

void init(int n)
{
    for(int i = 0 ; i <= n ; i++)   pre[i] = i;
    memset(rk,0,sizeof(rk));
}

int find(int x)
{
    return x^pre[x]?pre[x]=find(pre[x]):x;
}

bool join(int x,int y)
{
    int fx = find(x),fy = find(y);

    if(fy == fx) return 0;

    if(rk[fx] > rk[fy]) pre[fy] = fx;
    else
    {
        pre[fx] = fy;
        if(rk[fx] == rk[fy])    rk[fy]++;
    }
    return 1;
}

bool same(int x,int y)
{
    return find(x) == find(y);
}
