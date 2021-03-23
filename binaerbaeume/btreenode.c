//
// Created by Robin Meese on 23.03.21.
//

#include <stdlib.h>
#include "btreenode.h"

BTREE_NODE *btreenode_new(void *data) {
    struct _BTREE_NODE *newNode = (struct BTREE_NODE*)malloc(sizeof(BTREE_NODE));
    newNode->value = data;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;
}

bool btreenode_set_left(BTREE_NODE *parent_node, BTREE_NODE *node) {
    if (parent_node->leftNode == NULL) {
        parent_node->leftNode = node;
        return true;
    } else {
        return false;
    }
}

bool btreenode_set_right(BTREE_NODE *parent_node, BTREE_NODE *node) {
    if (parent_node->rightNode == NULL) {
        parent_node->rightNode = node;
        return true;
    } else {
        return false;
    }
}