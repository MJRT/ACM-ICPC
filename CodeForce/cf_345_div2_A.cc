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
typedef  unsigned long long int ULL;

const int INF = ~0U>>1;

//const int N = 5 + ;
int a,b;
bool x;

LL cnt = 0;

bool solve(int a,int b);

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d",&a,&b);
    if(a>b)swap(a,b);

    cnt = 0;
    while(a > 0 && b > 1)
    {

        b-=2;
        a++;
        cnt++;
        if(a > b) swap(a,b);
    }

    printf("%I64d\n",cnt);

    return 0;
}


