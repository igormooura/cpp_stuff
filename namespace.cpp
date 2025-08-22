#include <iostream>

namespace first{
    int x = 1; 
}

namespace second { 
    int x = 2;
}


int main(){ 

    std::cout<< first::x << std::endl;
    
    // std::cout<< x << std::endl; x = undefined

    using namespace second; 

    std::cout<< x << std::endl;

    return 0; 
}