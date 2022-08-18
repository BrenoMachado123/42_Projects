#include "../inc/Vector_tests.hpp"

void VectorTests(int choice = -1)
{
    int select;
    std::cout << "Vector\n[0] Construction\n[1] Member_functions\n[2] Iterators\n[3] Relational Operators\n[4] Speed test\n";
    if (choice != -1)
        select = choice;
    else
        std::cin >> select;
    switch (select)
    {
    case 0:
        VectorConstruction();
        break;
    case 1:
        MemberFunctions();
        break;
    case 2:
        IteratorTest();
        break;
    case 3:
        RelationalOperators();
        break;
    case 4:
        VSpeedTest();
        break;
    default:
        std::cout << "!" << std::endl;
        break;
    }
}

void MapTests(int choice = -1)
{
    int select;
    std::cout << "Map\n[0] Construction\n[1] Member_functions\n[2] Iterators\n[3] Relational Operators\n[4] Speed test\n";
    if (choice != -1)
        select = choice;
    else
        std::cin >> select;
    switch (select)
    {
    case 0:
        MapConstruction();
        break;
    case 1:
        mapMemberFunctions();
        break;
    case 2:
        MapIterators();
        break;
    case 3:
        MapRelationalOperators();
        break;
    case 4:
        MapSpeed();
        break;
    default:
        std::cout << "!" << std::endl;
        break;
    }
}

void StackTests(int choice = -1)
{
    int select;
    std::cout << "Map\n[0] Construction\n[1] Member_functions\n[2] Relational Operators\n";
    if (choice != -1)
        select = choice;
    else
        std::cin >> select;
    switch (select)
    {
    case 0:
        StackConstruction();
        break;
    case 1:
        StackMemberFunctions();
        break;
    case 2:
        StackRelationalOperators();
        break;
    default:
        std::cout << "!" << std::endl;
        break;
    }
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int select;
    int second = -1;

    std::cout << (FT == 42 ? "ft" : "std") << std::endl;
    std::cout << "[0] Vector\n[1] Map\n[2] Stack\n"
              << std::endl;
    if (argc >= 3)
    {
        std::string first_choice(argv[1]);
        std::string second_choice(argv[2]);
        select = std::atoi(first_choice.c_str());
        second = std::atoi(second_choice.c_str());
        std::cout << select << std::endl;
        std::cout << second << std::endl;
    }
    else
        std::cin >> select;

    switch (select)
    {
    case 0:
        VectorTests(second);
        break;
    case 1:
        MapTests(second);
        break;
    case 2:
        StackTests(second);
        break;

    default:
        std::cout << "!" << std::endl;
        break;
    }
    return 0;
}