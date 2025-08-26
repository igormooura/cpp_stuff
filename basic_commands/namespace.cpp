#include <iostream>

namespace first{
    int x = 1; 
}

namespace second { 
    int x = 2;
}


int main(){ 

    using namespace std;

    cout<< first::x << endl;
    
    // cout<< x << endl; x = undefined

    using namespace second; 

    cout<< x << endl;

    return 0; 
}