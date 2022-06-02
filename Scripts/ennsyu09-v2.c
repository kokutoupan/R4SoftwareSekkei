#include <stdio.h>
#include <time.h>		// for clock()
#include <stdlib.h>

#define N 10000		// nの上限
#define STEP (N/1000)	// 経過表示のステップ数

int is_prime(int a);				// 関数is_prime()のプロトタイプ宣言
int num_primes(int a, int b);		// 関数num_primes()のプロトタイプ宣言

int sqrtI(int x)
{
    int i;

    for(i=1;i*(i+2)<x;i+=10);
    for(i-=9;i*(i+2)<x;i++);
    return i-1;
}

// main関数
int main(void)
{
	clock_t start = clock();	// 開始時間
	int n, m=0;

	// nを1～Nまで変化させる	
	for (n=1; n<=N; n++) {

		// nより大きく2n以下の範囲に素数が0個であれば
		//「不成立」と表示して終了
		if (num_primes(n+1, 2*n)==0) {		
			printf("定理は不成立!!\n");
			return 0;
		}

		// STEP毎に表示(進行の確認用)
		if(n-m>=STEP) {
			m += STEP;
			printf("n=%dまで成立 %f sec\n", m, 
			    (double)(clock()-start)/CLOCKS_PER_SEC);
		}
	}

	printf("%dまでの正数で定理は成立\n", N);

	// 経過時間の表示
	printf("%f sec\n", (double)(clock()-start)/CLOCKS_PER_SEC);

	return 0;
}

//----------------------------------------------
// 引数aが素数かどうか判定する関数
//  返り値： 素数 1 , 素数以外 0
//----------------------------------------------

int is_prime(int a)
{
    //予め3,5,7で割り切れるものを排除する
    if(a%3 ==0)
    {
        if(a==3)
            return 1;
        return 0;
    }
    if(a%5 == 0)
    {
        if(a==5)
            return 1;
        return 0;
    }
    if(a%7 == 0)
    {
        if(a==7)
            return 1;
        return 0;
    }

    int n=sqrtI(a);

    //３の倍数は消しているので2,３の倍数以外で比べていく
    for(int i=11;i<n+1;i+=6)
    {
       if(a%i==0)
        {
           return 0;
        }
        else if(a%(i+2)==0)
        {
           return 0;
        }
    }
   return 1;
}

//----------------------------------------------
// a～bの範囲の素数があるかないかを返す関数
//----------------------------------------------
int num_primes(int a, int b)
{
	static int  n=0;

	// a～bが素数か調べる
	if(a<=n && n < b)
	{
		return 1;
	}

	if(b%2==0)
	{
		if(b==2)
		{
			n = b;
			return 1;
		}
		b--;
	}
	
	for(int i= b;i >= a;i-=2)
	{
		if(is_prime(i))
		{
			n=i;
			return 1;
		}
	}

	return 0;
}

/*
M君:
10000までの正数で定理は成立
1158.126529 sec

私の(個数ではなく０か１あるかないかのみをかえすやつ):
10000までの正数で定理は成立
0.002513 sec

(途中の表示なしver)
10000までの正数で定理は成立
0.000117 sec

*/