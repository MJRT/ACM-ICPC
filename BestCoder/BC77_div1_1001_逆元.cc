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
const int MOD = 1e9+7;
const int N = 5 + 1000;
bool vis[N];
int cnt[N];
LL fact[N];


LL PowerMod(LL num, LL n, LL mod)
{
    LL res = 1;
    num = num % mod;

    while(n)
    {
        if (n&1)
            res = (res * num) % mod;
        num = (num * num) % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int Case;
    char s[N];
    scanf("%d",&Case);
    fact[0] = 1;
    for(int i = 1 ; i < N ; i++) fact[i] = (fact[i-1]*i)%MOD;
    while(Case--)
    {
        scanf("%s",s);
        int l = strlen(s);
        memset(cnt,0,sizeof(cnt));

        for(int i = 0 ; i < l ; i++)
        {
            cnt[s[i]-'a' ]++;
        }

        int flag = 0 ;
        if(l&1)
        {

            for(int i = 0 ; i < 26 ; i++)
                if(cnt[i]&1)
                {
                    flag ++;
                }
        }
        else
        {
            flag = 1;
            for(int i = 0 ; i< 26 ; i++)
                if(cnt[i]&1)
                {
                    flag = 0;
                    break;
                }
        }

        if(flag != 1)
        {
            puts("0");
            continue;
        }

        l = 0;
        for(int i = 0 ; i < 26 ; i++)
        {
            cnt[i]/=2;
            l += cnt[i];
        }


        LL res = fact[l];
        for(int i = 0 ; i < 26 ; i++ )
        {
            if(cnt[i])
            {
                LL inv = PowerMod(fact[cnt[i]],MOD-2,MOD);
                res = (res*inv)%MOD;
            }
        }

        printf("%lld\n",res);
    }
    return 0;
}

