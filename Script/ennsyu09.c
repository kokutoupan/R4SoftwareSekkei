#include <stdio.h>
#include <time.h> // for clock()
#include <stdlib.h>

#define N 1000000       // nの上限
#define STEP (N / 1000) // 経過表示のステップ数

int *data_prime; //配列の先頭アドレス
int data_size;   //配列の大きさ
int data_end;    //配列の最後

int is_prime(int a);          // 関数is_prime()のプロトタイプ宣言
int num_primes(int a, int b); // 関数num_primes()のプロトタイプ宣言

void genarate_primes(int size); //素数の生成

// main関数
int main(void)
{
    clock_t start = clock(); // 開始時間
    int n, m = 0;

    data_prime = (int *)malloc(sizeof(int) * 1000);
    data_size = 1000;
    data_end = 0;
    if (data_prime == NULL)
    {
        exit(1);
    }

    genarate_primes(N*2);

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

    free(data_prime);

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
    // int i, c=0;

    /*
    // 引数aを1～aで割ってみる
    for (i=1; i<=a; i++) {
        if (a%i==0)	c++;	// 割り切れたら(余りが0)カウント
    }

    if (c==2)	return 1;	// 約数が2個だった(aは素数)
    else		return 0;	// aは素数でない
    */
}

//----------------------------------------------
// a～bの範囲の素数の個数を返す関数
//----------------------------------------------
int num_primes(int a, int b)
{
    int i, c = 0;

    // a～bが素数か調べる
    for (i = a; i <= b; i++)
    {
        if (is_prime(i) == 1)
            c++;
    }
    return c; // 素数の個数を返す
}

void genarate_primes(int size)
{
    for (int i = 2; i < size; i++)
    {
        int flag = 1;
        for (int j = 0; j < data_end; j++)
        {
            if (i % data_prime[j] == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            if (data_end >= data_size)
            {
                data_size *= 2;
                int *tmp = (int *)realloc(data_prime, sizeof(int) * data_size);

                if (tmp == NULL)
                {
                    free(data_prime);
                    exit(1);
                }
                data_prime = tmp;
            }
            data_prime[data_end] = i;
            data_end++;
        }
    }
}

/*
M君
1243.927683 sec

*/
