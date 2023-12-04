#pragma once
#include<iostream>
using namespace std;


typedef struct TreeNode{
    int data;
    int height;
    TreeNode *lChild;
    TreeNode *rChild;


}NODE;

void AVLInsert(NODE **node, int data);

void inOrder(NODE **node);