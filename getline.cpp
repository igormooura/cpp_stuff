#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string fullname;
    std::string name;

    std::cout << "What's your single name?\n";
    std::cin >> name;

    std::cout << "His single name is: " << name << "\n"; //Aceita a primeira palavra

    // Limpa o '\n' deixado no buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //IA Q FEZ ISSO

    std::cout << "What's your full name?\n";
    std::getline(std::cin, fullname); //aceita texto

    std::cout << "His full name is: " << fullname << std::endl;

    return 0;
}
