//
//  main.cpp
//  16234::moving
//
//  Created by 김하영 on 2019. 3. 19..
//  Copyright © 2019년 HAYOUNG_KIM. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int N,L,R; //N<=50

struct cube{
    int value;
    bool top=false; //false 닫힌 상태 <-> true 열린 상태
    bool bottom=false;
    bool right=false;
    bool left=false;
};

cube arr[52][52];

void checkBoundary(cube arr[][50]){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==1 || i==N || j==1 || j==N){
               //boundary
                if(i==1 && j==1){
                    
                }
            }
            else{
                if(abs(arr[i][j].value-arr[i-1][j].value)>=L && abs(arr[i][j].value-arr[i-1][j].value)<=R){
                    arr[i][j].left=true;
                }
                else if(abs(arr[i][j].value-arr[i+1][j].value)>=L && abs(arr[i][j].value-arr[i+1][j].value)<=R){
                    arr[i][j].right=true;
                }
                else if(abs(arr[i][j].value-arr[i][j-1].value)>=L && abs(arr[i][j].value-arr[i][j-1].value)<=R){
                    arr[i][j].top=true;
                }
                else if(abs(arr[i][j].value-arr[i][j+1].value)>=L && abs(arr[i][j].value-arr[i][j+1].value)<=R){
                    arr[i][j].bottom=true;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>N>>L>>R;

 
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            cin>>arr[i][j].value;
    }
    
    
    return 0;
}
