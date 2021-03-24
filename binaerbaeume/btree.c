//
// Created by Robin Meese on 23.03.21.
//

#include <stdlib.h>
#include <printf.h>
#include "btree.h"
#include "btreenode.h"
#include "frequency.h"

void preorder(BTREE_NODE *node, int level)
{
    if (node == NULL)
        return;
    for (int i = 0; i < level; ++i)
    {
        printf("\t");
    }
    printf("|-- (%#x ", &node->value);
    frequency_print(node->value);
    printf(") \n");
    if (node->leftNode != NULL)
        preorder(node->leftNode, level + 1);
    if (node->rightNode != NULL)
        preorder(node->rightNode, level + 1);
}

BTREE *btree_new(void *data,
                 DESTROY_DATA_FCT destroy_data,
                 PRINT_DATA_FCT print_data)
{
    struct _BTREE *newTree = (BTREE *) malloc(sizeof(BTREE));
    newTree->firstNode = btreenode_new(data);
    newTree->destroy_data = destroy_data;
    newTree->print_data = print_data;
    return newTree;
}

BTREE_NODE *btree_get_root(BTREE *tree)
{
    return tree->firstNode;
}

void btree_print(BTREE *tree)
{
    preorder(tree->firstNode, 0);
}

BTREE *btree_merge(BTREE *left, BTREE *right, void *data)
{
    struct _BTREE *newTree = btree_new(data, left->destroy_data,
                                       left->print_data);
    btreenode_set_left(newTree->firstNode, left->firstNode);
    btreenode_set_right(newTree->firstNode, right->firstNode);
    return newTree;
}

void copy_preorder(BTREE_NODE *nodeToCopy, BTREE_NODE *newNode)
{
    if (nodeToCopy->leftNode != NULL)
    {
        BTREE_NODE *newLeftNode = btreenode_new(nodeToCopy->leftNode->value);
        btreenode_set_left(newNode, newLeftNode);
        copy_preorder(nodeToCopy->leftNode, newLeftNode);
    }
    if (nodeToCopy->rightNode != NULL)
    {
        BTREE_NODE *newRightNode = btreenode_new(nodeToCopy->rightNode->value);
        btreenode_set_right(newNode, newRightNode);
        copy_preorder(nodeToCopy->rightNode, newRightNode);
    }

}

BTREE *btree_clone(BTREE *tree)
{
    struct _BTREE *newTree = btree_new(tree->firstNode->value,
                                       tree->destroy_data, tree->print_data);
    copy_preorder(tree->firstNode, newTree->firstNode);
    return newTree;
}

void delete_node(BTREE_NODE *node, bool destroy_data)
{
    if (destroy_data)
    {
        free(node->value);
    }
    free(node);
}

void delete_in_preorder(BTREE_NODE *node, bool destroy_data)
{
    if (node->leftNode == NULL && node->rightNode == NULL)
    {
        delete_node(node, destroy_data);
    } else if (node->leftNode != NULL && node->rightNode != NULL)
    {
        delete_in_preorder(node->leftNode, destroy_data);
        delete_in_preorder(node->rightNode, destroy_data);
        delete_node(node, destroy_data);
    } else
    {
        if (node->leftNode != NULL)
        {
            delete_in_preorder(node->leftNode, destroy_data);
            delete_node(node, destroy_data);
        } else if (node->rightNode != NULL)
        {
            delete_in_preorder(node->rightNode, destroy_data);
            delete_node(node, destroy_data);
        }
    }
}


void btree_destroy(BTREE **tree, bool destroy_data)
{
    delete_in_preorder((*tree)->firstNode, destroy_data);
}

bool btree_equals(BTREE *tree1, BTREE *tree2)
{
    return btreenode_equals(tree1->firstNode, tree2->firstNode);
}