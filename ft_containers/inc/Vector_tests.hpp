#ifndef __VECTOR_TESTS_HPP__
#define __VECTOR_TESTS_HPP__

#ifndef FT
#define container std
#include <vector>
#include <map>
#include <stack>
#define FT 1
#else
#define container ft
#include <vector.hpp>
#include <map.hpp>
#include <stack.hpp>
#endif

#include <iostream>
#include <cstdlib>

void VectorConstruction();
void MemberFunctions();
void IteratorTest();
void RelationalOperators();
void VSpeedTest();

void MapConstruction();
void mapMemberFunctions();
void MapIterators();
void MapRelationalOperators();
void MapSpeed();

void StackConstruction();
void StackMemberFunctions();
void StackRelationalOperators();

#endif
