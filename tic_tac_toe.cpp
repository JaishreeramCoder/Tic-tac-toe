#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
void newgame();
void update(ll pos,char key,vector<vll>& a);
void print(vector<vll>&a);
bool check(vector<vll>&a);

int main(){
    while(1){
        char ch;
        cout<<"Do you want to play a newgame ?"<<endl;
        cout<<"Press 'y' for yes and 'n' for no "<<endl;
        cin>>ch;
        if(ch=='y'){
            newgame();
        }
        else{
            break;
        }
    }
}


void newgame(){
    cout<<"Enter the size of grid on which you want to play : "<<endl;
    ll n;
    cin>>n;
    vector<vll>a(n+1,vll(n+1));
    ll val=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=val++;
        }
    }
    string p1,p2;
    cout<<"Enter the name of player 1 : ";
    cin>>p1;
    cout<<endl;
    cout<<"Enter the name of player 2 : ";
    cin>>p2;
    cout<<endl;
    ll cnt=n*n;
    char key='X';
    print(a);
    while(cnt--){
        string p;
        if(key=='X'){
            p=p1;
        }
        else{
            p=p2;
        }
        cout<<p<<" select the row and column : "<<endl;
        ll row, col;
        cin>>row>>col;
        ll pos=(row-1)*n+col;
        if(!((row>=1&&row<=n)&&(col>=1&&col<=n))){
            cout<<"Invalid row and column "<<endl;
            cnt++;
            continue;
        }
        update(pos,key,a);
        if(key=='X')
            key='0';
        else
            key='X';
        print(a);
        if(check(a)){
            cout<<p<<" has won the game!! "<<endl<<endl;
            break;
        }
    }
}

void print(vector<vll>&a){
    ll n=a.size()-1;
    cout<<"Now grid looks like :"<<endl<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            cout<<"   |";
        }
        cout<<endl;
        for(int j=1;j<n;j++){
            if(a[i][j]==-1)
                cout<<" "<<'X'<<" |";
            else if(a[i][j]==0){
                cout<<" "<<a[i][j]<<" |";
            }
            else{
                cout<<" "<<" "<<" |";
            }
        }
        if(a[i][n]==-1)
            cout<<" "<<'X'<<" "<<endl;
        else if(a[i][n]==0){
            cout<<" "<<a[i][n]<<" "<<endl;
        }
        else{
            cout<<" "<<" "<<" "<<endl;
        }
        if(i<n){
            for(int j=1;j<n;j++){
                cout<<"___|";
            }
            cout<<"___"<<endl;
        }
        else{
            for(int j=1;j<n;j++){
                cout<<"   |";
            }
            cout<<endl;
        }
    }
}

void update(ll pos,char key,vector<vll>&a){
    ll n=a.size()-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==pos){
                if(key=='X')
                    a[i][j]=-1;
                else{
                    a[i][j]=0;
                }
                return;
            }
        }
    }
    cout<<"Above position is already filled !.. Select some other position "<<endl;
}
 

bool check(vector<vll>&a){
    ll n=a.size()-1;
    for(int i=1;i<=n;i++){
        ll isp=0;
        for(int j=1;j<=n;j++){
            if(a[i][j]!=a[i][1]){
                isp=1;
                break;
            }
        }
        if(isp==0){
            return true;
        }
    }
    for(int j=1;j<=n;j++){
        ll isp=0;
        for(int i=1;i<=n;i++){
            if(a[i][j]!=a[1][j]){
                isp=1;
                break;
            }
        }
        if(isp==0){
            return true;
        }
    }
    ll isp=0;
    for(int i=1;i<=n;i++){
        if(a[i][i]!=a[1][1]){
            isp=1;
            break;
        }
    }
    if(isp==0){
        return true;
    }
    isp=0;
    for(int i=1;i<=n;i++){
        if(a[i][n-i+1]!=a[1][n]){
            isp=1;
            break;
        }
    }
    if(isp==0){
        return true;
    }
    return false;
}