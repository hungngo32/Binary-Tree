#pragma once
#include <iostream>
using namespace std;
struct NODE
{
	int data;
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;
void khoiTaoCay(TREE &p);
void themNode(TREE &p, int x);
void Menu(TREE& p);