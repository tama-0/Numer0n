//
//  main.c
//  Numer0n
//
//  Created by 玉川悠真 on 2018/03/26.
//  Copyright © 2018年 玉川悠真. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"explain.h"

#define N printf("当たり!\n")

int main(void)
{   //宣言
    time_t timer;
    struct tm *local;
    int num[3],ans[3];
    int bite,eat,inp;
    //説明
    if(explain()){
        while(1){
            //初期化
            timer = time(NULL);
            local = localtime(&timer);
            bite = 0;eat = 0;
            for(int i = 0;i <= 2;++i)
            {   num[i] = 0;
                ans[i] = 0;}
            //乱数取得
            ans[0] = (local->tm_hour * local->tm_min * local->tm_sec) % 10;
            ans[1] = (local->tm_hour + local->tm_min * local->tm_sec) % 10;
            ans[2] = (local->tm_hour * local->tm_min + local->tm_sec) % 10;
            //乱数が全て違う数字かどうか
            if(ans[0] != ans[1] && ans[0] != ans[2] && ans[1] != ans[2]){
                printf("一桁のそれぞれ違う数字をいれてください。(例 「(0)12」 「0」で終了)\n");
                while(1){
                    bite = 0;eat = 0;
                    scanf("%d",&inp);
                    //入力された数字が3桁かどうか
                    if(inp < 1000)
                    {
                        //1桁ずつの数字摘出
                        num[0] = (inp - (inp%100))/100;
                        num[1] = ((inp%100) - (inp%10))/10;
                        num[2] = inp%10;
                        //全て0だったら終了
                        if((num[0] == 0) && (num[1] == 0) && (num[2] == 0))exit(0);
                        //入力した数が全て違うかどうか
                        if((num[0] != num[1]) && (num[0] != num[2]) && (num[1] != num[2]))
                        {
                            //bite-eatの判定
                            for(int i = 0;i <= 2;++i)
                            {
                                for(int j = 0;j <= 2;++j)
                                {
                                    if(num[i] == ans[j])
                                    {
                                        if(i == j) eat++;
                                        else bite++;
                                    }
                                }
                            }
                            printf("BITE:%d\nEAT:%d\n",bite,eat);
                            //全て一致したら
                            if(eat == 3){N;break;}
                        }
                        else printf("それぞれ違う数字を入れて下さい。\n");
                    }
                    else printf("3桁で入力して下さい。\n");
                }
            }
        }
    }
}

