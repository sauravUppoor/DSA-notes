// generating a tree in a simple way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rand(2, 20);
    printf("%d\n", n);
    for(int i = 2; i <= n; ++i) {
        printf("%d %d\n", rand(1, i - 1), i);
				/*
        printf("%d %d\n", 1, i); //Star tree 
        printf("%d %d\n", i-1, i);//Linear Tree
        printf("%d %d\n", i/2, i);//Binary Tree
        */
    }
}
