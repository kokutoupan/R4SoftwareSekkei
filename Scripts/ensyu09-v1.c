#include <stdio.h>
#include <time.h> // for clock()

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 1000000       // nの上限
#define STEP (N / 1000) // 経過表示のステップ数

//bool *prime; //配列の先頭アドレス

int sqrtI(int x)
{
    int i;

    for(i=1;i*(i+2)<x;i+=10);
    for(i-=9;i*(i+2)<x;i++);
    return i-1;
}

int is_prime(int a);          // 関数is_prime()のプロトタイプ宣言
int num_primes(int a, int b); // 関数num_primes()のプロトタイプ宣言

//void genarate_primes(int size); //素数の生成

typedef struct{
    int min;
    int max;
    int count;
}hani_sosu_num;

//hani_sosu_num zennkai;

// main関数
int main(void)
{
    clock_t start = clock(); // 開始時間
    int n, m = 0;

    //genarate_primes(N*2);

    // nを1～Nまで変化させる
    for (n = 1; n <= N; n++)
    {

        // nより大きく2n以下の範囲に素数が0個であれば
        //「不成立」と表示して終了
        if (num_primes(n + 1, 2 * n) == 0)
        {
            printf("定理は不成立!!\n");
            return 0;
        }

        // STEP毎に表示(進行の確認用)
        if (n - m >= STEP)
        {
            m += STEP;
            printf("n=%dまで成立 %f sec\n", m,
                   (double)(clock() - start) / CLOCKS_PER_SEC);
        }
    }

    //free(prime);

    printf("%dまでの正数で定理は成立\n", N);

    // 経過時間の表示
    printf("%f sec\n", (double)(clock() - start) / CLOCKS_PER_SEC);
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
// a～bの範囲の素数の個数を返す関数
//----------------------------------------------
int num_primes(int a, int b)
{
    static hani_sosu_num zennkai={0,0,0};
    int i, c = 0,differentCount=0;
    
    int start;

    //前回の範囲とかぶっているときはそれを利用する
    if( a <=zennkai.min && zennkai.min<=b || a<=zennkai.max&&zennkai.max<=b){
        int difarenceMin,difarenceMax;

        difarenceMin=a-zennkai.min;
        difarenceMax =b-zennkai.max;

        
        if(difarenceMin>0){
            start=zennkai.min;
            if(start%2==0)
            {
                if(a<=2&&b>=2)
                {
                    c++;
                    start=3;
                }
                else
                    start++;
            }
            // a～bが素数か調べる(偶数は、素数ではないのは自明なので省く
            for(int i=start;i <a;i+=2)
            {
                if(is_prime)differentCount--;
            }
        }
        else if(difarenceMin<0)
        {
            start = a;
            if(start%2==0)
            {
                start++;
            }
            for(int i=start;i <zennkai.min;i+=2)
            {
                if(is_prime)differentCount++;
            }
        }

        if(difarenceMax>0){
            start=zennkai.max;
            if(start%2==0)
            {
                if(start==2)
                {
                    differentCount++;
                }
                start++;
            }
            // a～bが素数か調べる(偶数は、素数ではないのは自明なので省く
            for(int i=start;i <b;i+=2)
            {
                if(is_prime)differentCount++;
            }
        }
        else if(difarenceMax<0&&a!=b)
        {
            start = b;
            if(start%2==0)
            {
                start++;
            }
            for(int i=start;i <zennkai.max;i+=2)
            {
                if(is_prime)differentCount--;
            }
        }
        
        c=differentCount+zennkai.count;
    }
    else//被りがなかった際の処理
    {
        start=a;

        if(start%2==0)
        {
            if(a<=2&&b>=2)
            {
                c++;
                start=3;
            }
            else
                start++;
        }
        if(start ==1)
        {
            c++;
            start=3;
        }
        // a～bが素数か調べる(偶数は、素数ではないのは自明なので省く
        for (i = start; i <= b; i+=2)
        {
            
            // if(i == 2)
            //     c++;
            // else if(i%2 ==0)
            //     continue;
                
            if(is_prime(i))
                c++;
        }

    }
    


    zennkai.min =a;
    zennkai.max =b;
    zennkai.count=c;
    return c; // 素数の個数を返す
}


// void genarate_primes(int size)
// {
//     //bool *seet =(bool*)malloc(sizeof(bool)*size);
    
//     prime=(bool*)malloc(sizeof(bool)*size/2+1);
//     if(prime ==NULL)
//     {
//         exit(1);
//     }
    
//     for(int i = 0;i<size/2+1;i++)
//     {
//         *(prime +i)=true;
//     }

//     prime[0]=false;

//     for(int i= 5; i<size/2+1;i+=2)
//     {
//         if(!*(prime+i/2))continue;

//         for(int q =i*3;q <size;q +=i*2)
//         {
//             *(prime +q/2)=false;
//         }
//     }

//     /*確認
//     for(int i=1;i<100;i++)
//     {
//         if(i%2!=0&&is_prime(i))
//             printf("%d\n",i);
//     }
//     */
// }


/*
M君:
10000までの正数で定理は成立
1158.126529 sec

私の:
1000000までの正数で定理は成立
0.015775 sec

途中経過なしver
1000000までの正数で定理は成立
0.010776 sec

10000までの正数で定理は成立
0.007335 sec
*/