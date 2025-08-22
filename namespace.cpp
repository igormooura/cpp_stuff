#include <iostream>

namespace first{
    int x = 1; 
}

namespace second { 
    int x = 2;
}


int main(){ 

    std::cout<< first::x << std::endl;
    
    using namespace second; 

    std::cout<< x << std::endl;

    return 0; 
}