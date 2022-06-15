#include "../inc/Vector_tests.hpp"

void VectorTests() {
    int select;
    std::cout << "Vector\n[0] Construction\n[1] Member_functions\n[2] Iterators\n[3] Relational Operators\n[4] Speed test";
    std::cin >> select;
    switch (select) {
        case 0:
            VectorConstruction();
            break;
        case 1:
            MemberFunctions();
            break;
        case 2:
            IteratorTest();
            break ;
        case 3:
            RelationalOperators();
            break ;
        case 4:
            VSpeedTest();
            break ;
        default:
            std::cout << "!" << std::endl;
            break;
    }
}

void MapTests() {
    int select;
    std::cout << "Map\n[0] Construction\n[1] Member_functions\n[2] Iterators\n[3] Relational Operators\n[4] Speed test\n[5] Undefined Behaviors";
    std::cin >> select;
    switch (select) {
        case 0:
            MapConstruction();
            break;
        case 1:
            mapMemberFunctions();
            break;
        case 2:
            MapIterators();
            break ;
        case 3:
            MapRelationalOperators();
            break ;
        case 4:
            MapSpeed();
            break ;
        case 5:
            MapUndefinedBehaviors();
            break ;
        default:
            std::cout << "!" << std::endl;
            break;
    }
} 

int main() {
    int select;

    std::cout << "[0] Vector\n[1] Map" << std::endl;
    std::cin >> select;
    switch (select)
    {
        case 0:
            VectorTests();
            break;
        case 1:
            MapTests();
            break ;
    
        default:
            std::cout << "!" << std::endl;
            break;
    }
   return 0;
}