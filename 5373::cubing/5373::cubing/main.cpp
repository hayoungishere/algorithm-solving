//
//  main.cpp
//  5373::cubing
//
//  Created by 김하영 on 2019. 3. 19..
//  Copyright © 2019년 HAYOUNG_KIM. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#define FOR(i,n) for(int i=0; i<n; i++)

const string DefB[3][3]={"o","o","o","o","o","o","o","o","o"};
const string DefU[3][3]={"w","w","w","w","w","w","w","w","w"};
const string DefL[3][3]={"g","g","g","g","g","g","g","g","g"};
const string DefF[3][3]={"r","r","r","r","r","r","r","r","r"};
const string DefR[3][3]={"b","b","b","b","b","b","b","b","b"};
const string DefD[3][3]={"y","y","y","y","y","y","y","y","y"};

string B[3][3]={"o","o","o","o","o","o","o","o","o"};
string U[3][3]={"w","w","w","w","w","w","w","w","w"};
string L[3][3]={"g","g","g","g","g","g","g","g","g"};
string F[3][3]={"r","r","r","r","r","r","r","r","r"};
string R[3][3]={"b","b","b","b","b","b","b","b","b"};
string D[3][3]={"y","y","y","y","y","y","y","y","y"};

string preB[3][3];
string preU[3][3];
string preL[3][3];
string preF[3][3];
string preR[3][3];
string preD[3][3];
string sideName[6]={"B","U","L","F","R","D"};


void reDef(){
    FOR(i,3){
        FOR(j,3){
            B[i][j]=DefB[i][j];
            U[i][j]=DefU[i][j];
            L[i][j]=DefL[i][j];
            F[i][j]=DefF[i][j];
            R[i][j]=DefR[i][j];
            D[i][j]=DefD[i][j];
        }
    }
}
void printTOP(){
    FOR(i,3){
        FOR(j,3) cout<<U[i][j];
        cout<<endl;
    }
}

void setPreCube(){
    //직전 큐브 상태를 Pre+side배열에 저장
    FOR(i,3){
        FOR(j,3){
            preB[i][j]=B[i][j];
            preU[i][j]=U[i][j];
            preF[i][j]=F[i][j];
            preD[i][j]=D[i][j];
            preL[i][j]=L[i][j];
            preR[i][j]=R[i][j];
        }
    }
}

void setCurCube(){
    //변경된 큐브 상태를 side=Pre+side 배열의 값으로 저장
    FOR(i,3){
        FOR(j,3){
            B[i][j]=preB[i][j];
            U[i][j]=preU[i][j];
            F[i][j]=preF[i][j];
            D[i][j]=preD[i][j];
            L[i][j]=preL[i][j];
            R[i][j]=preR[i][j];
        }
    }
}

void rotateCW(int index){
    int row=0;
    switch(index){
        case 0:
            for(int i=2; i>=0; i--){
                for(int j=0; j<3; j++){
                    preB[j][i]=B[row][j];
                }
                row++;
            }
            break;
        case 1:
            for(int i=2; i>=0; i--){
                for(int j=0; j<3; j++){
                    preU[j][i]=U[row][j];
                }
                row++;
            }
            break;
        case 2:
            for(int i=2; i>=0; i--){
                for(int j=0; j<3; j++){
                    preL[j][i]=L[row][j];
                }
                row++;
            }
            break;
        case 3:
            for(int i=2; i>=0; i--){
                for(int j=0; j<3; j++){
                    preF[j][i]=F[row][j];
                }
                row++;
            }
            break;
        case 4:
            for(int i=2; i>=0; i--){
                for(int j=0; j<3; j++){
                    preR[j][i]=R[row][j];
                }
                row++;
            }
            break;
        case 5:
            for(int i=2; i>=0; i--){
                for(int j=0; j<3; j++){
                    preD[j][i]=D[row][j];
                }
                row++;
            }
            break;
    }
}
void rotateCCW(int index){
    int row=0;
    switch(index){
        case 0:
            FOR(i,3){
                row=0;
                for(int j=2; j>=0; j--){
                    preB[j][i]=B[i][row];
                    row++;
                }
            }
            break;
        case 1:
            FOR(i,3){
                row=0;
                for(int j=2; j>=0; j--){
                    preU[j][i]=U[i][row];
                    row++;
                }
            }
            break;
        case 2:
            FOR(i,3){
                row=0;
                for(int j=2; j>=0; j--){
                    preL[j][i]=L[i][row];
                    row++;
                }
            }
            break;
        case 3:
            FOR(i,3){
                row=0;
                for(int j=2; j>=0; j--){
                    preF[j][i]=F[i][row];
                    row++;
                }
            }
            break;
        case 4:
            FOR(i,3){
                row=0;
                for(int j=2; j>=0; j--){
                    preR[j][i]=R[i][row];
                    row++;
                }
            }
            break;
        case 5:
            FOR(i,3){
                row=0;
                for(int j=2; j>=0; j--){
                    preD[j][i]=D[i][row];
                    row++;
                }
            }
            break;
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    
    int cnt;
    bool clock=true; //default = clock wise
    string side;
    
    FOR(i,n){
        cin>>cnt;
        FOR(j,cnt){
            cin>>side;
            if(side.substr(1,1)=="+") clock=true;
            else if(side.substr(1,1)=="-") clock=false;
            else return -1;
            
            side=side.substr(0,1);
            
            setPreCube();
            
            if(side=="B"){
                if(clock){rotateCW(0);
                    preU[0][0] = R[0][2];
                    preU[0][1] = R[1][2];
                    preU[0][2] = R[2][2];
                    
                    preL[0][0] = U[0][0];
                    preL[1][0] = U[0][1];
                    preL[2][0] = U[0][2];
                    
                    preD[2][0] = L[0][0];
                    preD[2][1] = L[1][0];
                    preD[2][2] = L[2][0];
                    
                    preR[0][2] = D[2][0];
                    preR[1][2] = D[2][1];
                    preR[2][2] = D[2][2];
                }
                else{
                    rotateCCW(0);
                    preU[0][0] = L[2][0];
                    preU[0][1] = L[1][0];
                    preU[0][2] = L[0][0];
                    
                    preL[0][0] = D[2][0];
                    preL[1][0] = D[2][1];
                    preL[2][0] = D[2][2];
                    
                    preD[2][0] = R[2][2];
                    preD[2][1] = R[1][2];
                    preD[2][2] = R[0][2];
                    
                    preR[0][2] = U[0][0];
                    preR[1][2] = U[0][1];
                    preR[2][2] = U[0][2];
                }
                setCurCube();
            }else if(side=="U"){
                if(clock){
                    rotateCW(1);
                    preB[2][0] = L[0][2];
                    preB[2][1] = L[0][1];
                    preB[2][2] = L[0][0];
                    
                    preR[0][0] = B[2][2];
                    preR[0][1] = B[2][1];
                    preR[0][2] = B[2][0];
                    
                    preF[0][0] = R[0][0];
                    preF[0][1] = R[0][1];
                    preF[0][2] = R[0][2];
                    
                    preL[0][0] = F[0][0];
                    preL[0][1] = F[0][1];
                    preL[0][2] = F[0][2];
                }
                else{
                    rotateCCW(1);
                    preB[2][0] = R[0][2];
                    preB[2][1] = R[0][1];
                    preB[2][2] = R[0][0];
                    
                    preR[0][0] = F[0][0];
                    preR[0][1] = F[0][1];
                    preR[0][2] = F[0][2];
                    
                    preF[0][0] = L[0][0];
                    preF[0][1] = L[0][1];
                    preF[0][2] = L[0][2];
                    
                    preL[0][2] = B[2][0];
                    preL[0][1] = B[2][1];
                    preL[0][0] = B[2][2];
                }
                setCurCube();
            }else if(side=="L"){
                if(clock){
                    rotateCW(2);
                    FOR(k,3){
                        preB[k][0]= D[k][0];
                        preU[k][0]= B[k][0];
                        preF[k][0]= U[k][0];
                        preD[k][0]= F[k][0];
                    }
                }
                else{
                    rotateCCW(2);
                    FOR(k,3){
                        preB[k][0]= U[k][0];
                        preU[k][0]= F[k][0];
                        preF[k][0]= D[k][0];
                        preD[k][0]= B[k][0];
                    }
                }
                setCurCube();
            }else if(side=="F"){
                if(clock){rotateCW(3);
                    preU[2][0] = L[2][2];
                    preU[2][1] = L[1][2];
                    preU[2][2] = L[0][2];
                    
                    preR[0][0] = U[2][0];
                    preR[1][0] = U[2][1];
                    preR[2][0] = U[2][2];
                    
                    preD[0][0] = R[2][0];
                    preD[0][1] = R[1][0];
                    preD[0][2] = R[0][0];
                    
                    preL[0][2] = D[0][0];
                    preL[1][2] = D[0][1];
                    preL[2][2] = D[0][2];
                }
                else{
                    rotateCCW(3);
                    preU[2][0] = R[0][0];
                    preU[2][1] = R[1][0];
                    preU[2][2] = R[2][0];
                    
                    preR[0][0] = D[0][2];
                    preR[1][0] = D[0][1];
                    preR[2][0] = D[0][0];
                    
                    preD[0][0] = L[0][2];
                    preD[0][1] = L[1][2];
                    preD[0][2] = L[2][2];
                    
                    preL[0][2] = U[2][2];
                    preL[1][2] = U[2][1];
                    preL[2][2] = U[2][0];
                }
                setCurCube();
            }else if(side=="R"){
                if(clock){rotateCW(4);
                    FOR(k,3){
                        preB[k][2]= U[k][2];
                        preU[k][2]= F[k][2];
                        preF[k][2]= D[k][2];
                        preD[k][2]= B[k][2];
                    }
                }
                else{
                    rotateCCW(4);
                    FOR(k,3){
                        preB[k][2]= D[k][2];
                        preU[k][2]= B[k][2];
                        preF[k][2]= U[k][2];
                        preD[k][2]= F[k][2];
                    }
                }
                setCurCube();
            }else{ //side=="D"
                if(clock){
                    rotateCW(5);
                    preB[0][0] = R[2][2];
                    preB[0][1] = R[2][1];
                    preB[0][2] = R[2][0];
                    
                    preL[2][0] = B[0][2];
                    preL[2][1] = B[0][1];
                    preL[2][2] = B[0][0];
                    
                    preF[2][0] = L[2][0];
                    preF[2][1] = L[2][1];
                    preF[2][2] = L[2][2];
                    
                    preR[2][0] = F[2][0];
                    preR[2][1] = F[2][1];
                    preR[2][2] = F[2][2];
                }
                else{
                    rotateCCW(5);
                    preB[0][0] = L[2][2];
                    preB[0][1] = L[2][1];
                    preB[0][2] = L[2][0];
                    
                    preL[2][0] = F[2][0];
                    preL[2][1] = F[2][1];
                    preL[2][2] = F[2][2];
                    
                    preF[2][0] = R[2][0];
                    preF[2][1] = R[2][1];
                    preF[2][2] = R[2][2];
                    
                    preR[2][0] = B[0][2];
                    preR[2][1] = B[0][1];
                    preR[2][2] = B[0][0];
                }
                setCurCube();
            }
        }//end of for(j)
        printTOP();
        
        reDef();
        
    }//end of for(i)

    return 0;
}
