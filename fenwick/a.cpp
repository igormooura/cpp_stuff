#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> fen;


void update(int i, int add){
    while(i < fen.size()){ 
        fen[i] += add; 
        i += (i & (-i));
    }
}

int sum(int i){
    int s = 0;
    while(i > 0){ 
        s+= fen[i];
        i -= (i & (-i));
    }

    return s;
}

void build(){
    fen = v;

    for(int i = 1; i < fen.size(); i++){ 
         int p = i + (i & (-i));
         if(p < fen.size()){
            fen[p] += fen[i];
         }
    }

}




int main(){
    int a; 
    cin >> a;
     v.resize(a + 1);;

    for(int i = 1; i <= a; i++){ 
        cin >> v[i];
    }

    build();

    cout << sum(5) << endl;

}