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
#define BUG() cout << "There is BUG No." << BUGs++ <<endl
#define Whats(x) cout << "{ "<< #x << " }" << " is " << "*** "<< x << " ***" << "  index:" << INDEX++ <<endl
#define Show(x,s,l)         cout << #x << ": "; for(int i = s ; i < s+l ; i++) cout << x[i] << " ";  cout << "\n"
typedef  long long int LL;
const int INF = ~0U>>1;

const int N = 100000;
int a[N];
int vis[N];

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(!vis[i])
        {
            int w = i;
            vis[i] = 1;
            for(int j = w+1 ; j < n ; j++)
            {
                if(!vis[j] && a[j]> a[w])
                {
                    cnt++;
                    w = j;
                    vis[j] = 1;
                }
            }

        }
    }
    printf("%d\n",cnt);
    return 0;
}

