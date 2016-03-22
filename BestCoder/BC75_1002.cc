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
#define BUG() cout << "There is BUG No." << BUGs++ <<endl
#define Whats(x)          cout << "{ "<< #x << " }" << " is " << "*** "<< x << " ***" << "  index:" << INDEX++ <<endl
#define Show(x,s,l)      {cout << #x << ": "; for(int i = s ; i < s+l ; i++) cout << x[i] << " ";  cout << "\n";}
#define Show2(x,s,l,h)   {cout << #x << ": " << l-s << "*" <<h-s <<"\n"; for(int j = s ; j < s+h ; j++){for(int i = s ; i < s+l ; i++) cout << x[j][i] << " ";cout << "\n";};  cout << "\n";}

typedef  long long int LL;
const int INF = ~0U>>1;

const int N = 5 + 10;
bool vis[N];
int a[N],k;

bool check(int x,int y)
{
    vis[x] = 1;
    if(vis[y] || x == y) return 0;

    switch(x)
    {
        case 1 : if((y == 3 && !vis[2]) || (y==7 && !vis[4])|| (y==9 && !vis[5]))    return 0;else break;
        case 2 : if( y == 8 && !vis[5])                                              return 0;else break;
        case 3 : if((y == 1 && !vis[2]) || (y==7 && !vis[5])|| (y==9 && !vis[6]))    return 0;else break;
        case 4 : if( y == 6 && !vis[5])                                              return 0;else break;
        case 6 : if( y == 4 && !vis[5])                                              return 0;else break;
        case 7 : if((y == 1 && !vis[4]) || (y==3 && !vis[5])|| (y==9 && !vis[8]))    return 0;else break;
        case 8 : if( y == 2 && !vis[5])                                              return 0;else break;
        case 9 : if((y == 1 && !vis[5]) || (y==3 && !vis[6])|| (y==7 && !vis[8]))    return 0;else break;
    }
    return 1;
}

bool solve()
{
    for(int i = 0 ; i < k-1 ; i++)
        if(!check(a[i],a[i+1]))
            return 0;
    return 1;
}


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
        memset(vis,0,sizeof(vis));
        scanf("%d",&k);

        bool flag = 1;
        for(int i = 0 ; i < k ; i++)
        {
            scanf("%d",&a[i]);
            if(!a[i] || a[i] >9 )    flag = 0;
        }
        if(k <= 3 ) flag = 0;

        if(flag && solve())     puts("valid");
        else                    puts("invalid");
    }
    return 0;
}


