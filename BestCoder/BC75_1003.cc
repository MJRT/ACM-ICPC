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
#include<numeric>
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
const int MOD = 1000000007;
const int N = 5 + 10000;
bool vis[N];
int n;
vector<LL> dp[N];
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
        scanf("%d",&n);
        for(int i = 0 ; i <= n ; i++)   dp[i].clear();
        dp[0].push_back(1);
        dp[0].push_back(0);
        dp[0].push_back(0);
        for(int i = 1 ; i < n ; i++)
        {
            dp[i].push_back((dp[i-1][0]*25+dp[i-1][1]*25+dp[i-1][2]*25)%MOD);
            dp[i].push_back(dp[i-1][0]);
            dp[i].push_back(dp[i-1][1]);
        }
        printf("%I64d\n",(dp[n-1][0]*26+dp[n-1][1]*26+dp[n-1][2]*26)%MOD);
    }
    return 0;
}

