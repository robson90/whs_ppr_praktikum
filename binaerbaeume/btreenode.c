//
// Created by Robin Meese on 23.03.21.
//

#include <stdlib.h>
#include "btreenode.h"
#include "frequency.h"

BTREE_NODE *btreenode_new(void *data)
{
    struct _BTREE_NODE *newNode = (BTREE_NODE *) malloc(sizeof(BTREE_NODE));
    newNode->value = data;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;
}

BTREE_NODE *btreenode_get_left(BTREE_NODE *node)
{
    return node->leftNode;
}

BTREE_NODE *btreenode_get_right(BTREE_NODE *node)
{
    return node->rightNode;
}

void *btreenode_get_data(BTREE_NODE *node)
{
    return node->value;
}

bool btreenode_set_left(BTREE_NODE *parent_node, BTREE_NODE *node)
{
    if (parent_node->leftNode == NULL)
    {
        parent_node->leftNode = node;
        return true;
    } else
    {
        return false;
    }
}

bool btreenode_set_right(BTREE_NODE *parent_node, BTREE_NODE *node)
{
    if (parent_node->rightNode == NULL)
    {
        parent_node->rightNode = node;
        return true;
    } else
    {
        return false;
    }
}

bool btreenode_equals(BTREE_NODE *node1, BTREE_NODE *node2)
{
    return frequency_compare(node1->value, node2->value) == 0
           && btreenode_equals(node1->leftNode, node2->leftNode)
           && btreenode_equals(node1->rightNode, node2->rightNode);
}

bool btreenode_is_leaf(BTREE_NODE *node)
{
    return node->leftNode == NULL && node->rightNode == NULL;
}
