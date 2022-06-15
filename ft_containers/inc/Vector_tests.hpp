#ifndef __VECTOR_TESTS_HPP__
# define __VECTOR_TESTS_HPP__

#ifndef FT
# define container ft
#  include <vector.hpp>
#  include <map.hpp>
#  include <stack.hpp>
# define FT 1
#else
# define container std
#  include <vector>
#  include <map>
#  include <stack>
# endif

#include <iostream>

void VectorConstruction();
void MemberFunctions();
void IteratorTest();
void RelationalOperators();
void VSpeedTest();

void MapConstruction();
void mapMemberFunctions();
void MapIterators();
void MapRelationalOperators();
void MapUndefinedBehaviors();
void MapSpeed();

#endif