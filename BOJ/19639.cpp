#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> enemy, healPack;

int checkPossibility(int M)
{
    long long totalDamage = 0, totalHealth = (long long)M;

    for (vector<int>::iterator it = enemy.begin(); it != enemy.end(); it++) 
        totalDamage += (long long)(*it);

    for(vector<int>::iterator it = healPack.begin(); it != healPack.end(); it++)
        totalHealth += (long long)(*it);

    if(totalHealth <= totalDamage) {
        printf("0\n");
        return -1;
    }

    return 0;
}

int main()
{
    int X, Y, M, temp;
    int x = 0, y = 0;
    long long total;

    scanf("%d %d %d", &X, &Y, &M);
    for(int i = 0; i < X; i++) {
        scanf("%d", &temp);
        enemy.push_back(temp);
    }
   for(int i = 0; i < Y; i++) {
        scanf("%d", &temp);
        healPack.push_back(temp);
    }

    if (checkPossibility(M) < 0) // 해당 케이스의 해결 여부 체크
        return 0;

    while(1) {
        if(x == X && y == Y) // 적을 모두 쓰러뜨리고, 아이템을 모두 소비했으면 종료
            break;

        if(x < X && 0 < M - enemy[x]) { // 적을 처치할만큼 피가 남아있고 적이 남아 있으면 적 처치
            M -= enemy[x];
            printf("-%d\n", ++x);
        }
        else if(y < Y) { // 남은 아이템이 있으면 아이템 소비
            M += healPack[y];
            printf("%d\n", ++y);
        }
    }
    
    return 0;
}