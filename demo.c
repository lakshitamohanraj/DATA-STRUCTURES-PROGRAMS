/*
The program must accept an integer N as the input. 
The program must print the desired pattern as shown in the Example Input/Output section.
 Boundary Condition(s): 
2 <= N <= 100 
Input Format: 
The first line contains N. 
Output Format: 
The lines contain the desired pattern as shown in the Example Input/Output section.
 Example Input/Output 1:
 Input: 5
 Output: 
####*#### 
###*-*### 
##*-*-*## 
#*-*-*-*# 
*-*-*-*-* 
#*-*-*-*# 
##*-*-*## 
###*-*### 
####*#### 
Example Input/Output 2: 
Input: 8 Output:
#######*####### 
######*-*######
#####*-*-*#####
####*-*-*-*#### 
###*-*-*-*-*### 
##*-*-*-*-*-*## 
#*-*-*-*-*-*-*# 
*-*-*-*-*-*-*-* 
#*-*-*-*-*-*-*# 
##*-*-*-*-*-*##
###*-*-*-*-*### 
####*-*-*-*#### 
#####*-*-*##### 
######*-*######
#######*#######
*/
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    // Upper part of the pattern
    for (int i = 0; i < N; i++) {
        int numHashes = N - i - 1;
        int numDashes =  i;

        for (int j = 0; j < numHashes; j++) {
            printf("#");
        }
        printf("*");
        for (int j = 0; j < numDashes; j++) {
            printf("-*");
        }
        //printf("*");
        for (int j = 0; j < numHashes; j++) {
            printf("#");
        }
        printf("\n");
    }

    // Lower part of the pattern
    for (int i = N ; i > 1; i--) {
        int numHashes = N - i + 1;
        int numDashes = i-2;

        for (int j = 0; j < numHashes; j++) {
            printf("#");
        }
        printf("*");
        for (int j = 0; j < numDashes; j++) {
            printf("-*");
        }
        //printf("*");
        for (int j = 0; j < numHashes; j++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
