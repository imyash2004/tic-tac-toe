// Online C++ compiler to run C++ program online
#include<iostream>
#include <bits/stdc++.h> 
#include <string>
#include <vector>
using namespace std;
vector<vector<char> > a={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int column;
char tic='x';
bool draw=false;
void displayboard(){
    
    cout<<"     "<<"  |  "<<"   |  "<<"      "<<endl;
    cout<<"     "<<a[0][0]<<" |  "<<a[0][1]<<"  | "<<a[0][2]<<"      "<<endl;
    cout<<"     "<<"  |  "<<"   |  "<<"      "<<endl;
    cout<<"_____________________"<<endl;
    cout<<"     "<<"  |  "<<"   |  "<<"      "<<endl;
    cout<<"     "<<a[1][0]<<" |  "<<a[1][1]<<"  | "<<a[1][2]<<"      "<<endl;
    cout<<"     "<<"  |  "<<"   |  "<<"      "<<endl;
    cout<<"_____________________"<<endl;
    cout<<"     "<<"  |  "<<"   |  "<<"      "<<endl;
    cout<<"     "<<a[2][0]<<" |  "<<a[2][1]<<"  | "<<a[2][2]<<"      "<<endl;
    cout<<"     "<<"  |  "<<"   |  "<<"      "<<endl;

}
void playerchance(){
    int row;
    int digit;
    if (tic=='x'){
        cout<<"player 1->"<<"Enter the digit as mentioned in board:"<<endl;
        cin>>digit;
    }
    else{
        cout<<"player 2->"<<"Enter the digit as mentioned in board:"<<endl;
        cin>>digit;
    }
    switch(digit){
        case 1:
        row=0;
        column=0;
        break;
        case 2:
        row=0;
        column=1;
        break;
        case 3:
        row=0;
        column=2;
        break;
        case 4:
        row=1;
        column=0;
        break;
        case 5:
        row=1;
        column=1;
        break;
        case 6:
        row=1;
        column=2;
        break;
        case 7:
        row=2;
        column=0;
        break;
        case 8:
        row=2;
        column=1;
        break;
        case 9:
        row=2;
        column=2;
        break;
        default:
        cout<<"invalid number:"<<endl;

    }
    if (tic=='x' && a[row][column]!='x' && a[row][column]!='o'){
        a[row][column]='x';
        tic='o';
    }
    else if(tic=='o'&& a[row][column]!='x' && a[row][column]!='o'){
        a[row][column]='o';
        tic='x';
    }
    else{
        cout<<"please enter correct digit"<<endl;
        playerchance();
    }
    
}

void playerdetail(){
    string name;
    cout<<"Enter the name of 1st player:"<<endl;
    cin>>name;
    string name2;
    cout<<"Enter the name of 2nd player:"<<endl;
    cin>>name2;
    cout<<"Player 1 name is :"<<name<<endl;
    cout<<"Player 2 name is :"<<name2<<endl;
}
bool checkwin(){
    for(int i=0;i<3;i++){
        if(a[0][i]==a[1][i] && a[1][i]==a[2][i] || a[i][0]==a[i][1] && a[i][1]==a[i][2]){
            return true;
        }
    }
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2] || a[0][2]==a[1][1] && a[1][1]==a[2][0]){
        return true;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]!='x' && a[i][j]!='o'){
                return false;
            }
        }
    }
    draw=true;
    return true;
}
int main(){
    playerdetail();
    while(!checkwin()){
        displayboard();
        playerchance();
        checkwin();
    }
    if(tic=='x' && draw==false){
        cout<<"player 2 wins"<<endl;

    }
    else if(tic=='o' && draw==false){
        cout<<"player 1 wins"<<endl;
    }
    else{
        cout<<"draw"<<endl;
    }
    return 0;
}