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
#define Whats(x)        cout << "{ "<< #x << " }" << " is " << "*** "<< x << " ***" << "  index:" << INDEX++ <<endl
#define Show(x,s,l)      {cout << #x << ": "; for(int i = s ; i < s+l ; i++) cout << x[i] << " ";  cout << "\n";}
#define Show2(x,s,l,h)   {cout << #x << ": " << l-s << "*" <<h-s <<"\n"; for(int j = s ; j < s+h ; j++){for(int i = s ; i < s+l ; i++) cout << x[j][i] << " ";cout << "\n";};  cout << "\n";}


typedef  long long int LL;
const int INF = ~0U>>1;

const int N = 5 + 100000;
bool vis[N];

int a[6];
int d[6][6];

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case;
    LL MOD = 1e9+7;
    scanf("%d",&Case);
    while(Case--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 0 ; i < 6 ; i++)
        {
            scanf("%d",&a[i]);
        }

        for(int i = 0 ; i < 6 ; i++)
        {
            for(int j = 0 ; j < 6 ; j++)
            {
                if((i&1)&&(j==i-1))   d[i][j]=d[j][i]=1;
                else                  d[i][j]=d[j][i]=abs(a[i]-a[j]);
            }
        }



        for(int k = 0 ; k < 6 ; k++)
            for(int i = 0 ; i < 6 ; i++)
                for(int j = 0 ; j < 6 ; j++)
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);


        LL res = 0;
        for(LL k = 1 ; k <= m ; k++)
        {
            int s,t;
            scanf("%d%d",&s,&t);
            LL mm = abs(t-s);
            for(int i = 0 ; i < 6 ; i++)
                for(int j = 0 ; j < 6 ; j++)
                        if(i != j)
                            mm = min(mm,0LL+abs(a[i]-s)+d[i][j]+abs(t-a[j]));
            res = (res + mm*k)%MOD;
        }

        printf("%I64d\n",res);

    }
    return 0;
}
