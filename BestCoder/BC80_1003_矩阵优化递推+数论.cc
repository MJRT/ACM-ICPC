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

const int  N = 5 + 1000;
//bool vis[N];

typedef  long long int LL;

const int M = 4;//！！初值M需修改！！
LL MOD ;

struct Matrix
{
	LL mat[M][M];
	//double mat[M][M];
	int row;//行
	int col;//列
	Matrix(int row,int col):row(row),col(col){}

    Matrix operator * (const Matrix & r) const
    {
        Matrix res(row,r.col);
        if(col != r.row)    return res;

        for(int i = 0 ; i < row ; i++)
            for(int j = 0 ; j < r.col; j++)
            {
                res.mat[i][j] = 0;
                for(int k = 0 ; k < col ; k++)
                    res.mat[i][j] = (res.mat[i][j]+mat[i][k]*r.mat[k][j]) % MOD;
            }
        return res;
    }

    Matrix operator ^ (LL n) const
    {
        Matrix res(row,col) , x= (*this);
        memset(res.mat,0,sizeof(res.mat));
        for(int i = 0 ; i < res.row ;i++)
            res.mat[i][i] = 1;

        for( ; n ; n>>=1)
        {
            if(n&1)    res = res*x;
            x = x*x;
        }
        return res;
    }


    void in()
    {
        for(int i = 0 ; i < row ; i++)
            for(int j = 0 ; j < col ; j++)
                scanf("%lld",&mat[i][j]);
    }

    void out()
    {
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
                printf("%6lld",mat[i][j]);
            puts("");
        }
    }
};


LL PowMod(LL x, LL n, LL mod)
{
    LL res = 1;
    for(x %= mod ; n ; n>>=1)
    {
        if (n&1)  res = (res * x) % mod;
        x = (x * x) % mod;
    }
    return res;
}

LL n,a,b,c,p;
Matrix m(3,3);

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
        scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&p);
        MOD = p-1;

        memset(m.mat,0,sizeof(m.mat));
        m.mat[0][0] = c;
        m.mat[0][1] = m.mat[1][0] =m.mat[2][0] =m.mat[2][2] = 1;
        LL t1 = PowMod(a,b,MOD+1);

        if(n == 1)          puts("1");
        else if(n == 2)     printf("%I64d\n",t1);
        else
        {
            m = m^(n-2);
            LL t2 = (m.mat[0][0] + m.mat[2][0])%MOD;
            printf("%I64d\n",PowMod(t1,t2,MOD+1));
        }
    }
    return 0;
}
