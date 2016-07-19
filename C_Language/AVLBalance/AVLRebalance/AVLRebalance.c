//
//  AVLRebalance.c
//  AVLRebalance
//
//  Created by SonChangWoo on 2016. 7. 20..
//  Copyright © 2016년 SonChangWoo. All rights reserved.
//
#include <stdio.h>
#include "AVLRebalance.h"
#include "BinaryTree.h"

BTreeNode * RotateLL(BTreeNode * bst) {
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    
    ChangeLeftSubTree(pNode, GetLeftSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);
    
    return cNode;
}

BTreeNode * RotateRR(BTreeNode * bst) {
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    
    ChangeRightSubTree(pNode, GetRightSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);
    
    return cNode;
}

BTreeNode * RotateLR(BTreeNode * bst) {
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    
    ChangeLeftSubTree(pNode, RotateRR(cNode));
    return RotateLL(pNode);
}

BTreeNode * RotateRL(BTreeNode * bst) {
    BTreeNode * pNode;
    BTreeNode * cNode;
    
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    
    ChangeRightSubTree(pNode, RotateLL(cNode));
    return RotateRR(pNode);
}

int GetHeight(BTreeNode * bst) {
    int leftH;
    int rightH;
    
    if (bst == NULL) {
        return 0;
    }
    
    leftH = GetHeight(GetLeftSubTree(bst));
    rightH = GetHeight(GetRightSubTree(bst));
    
    if (leftH > rightH) {
        return leftH + 1;
    } else {
        return rightH+1;
    }
}

int GetHeightDiff(BTreeNode * bst) {
    int lsh;
    int rsh;
    
    if (bst == NULL) {
        return 0;
    }
    
    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));
    
    return lsh-rsh;
}

BTreeNode * Rebalnce(BTreeNode ** pRoot) {
    int hDiff = GetHeightDiff(*pRoot);
    
    if (hDiff > 1) {
        if (GetHeightDiff(GetLeftSubTree(*pRoot)) >0) {
            *pRoot = RotateLL(*pRoot);
        } else {
            *pRoot = RotateLR(*pRoot);
        }
    }
    
    if (hDiff < -1) {
        if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0) {
            *pRoot = RotateRR(*pRoot);
        } else {
            *pRoot = RotateRL(*pRoot);
        }
    }
    
    return *pRoot;
}
