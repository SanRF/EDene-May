//
//  BinaryTree.h
//  BinaryTree
//
//  Created by Vicente Cubells Nonell on 06/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef BinaryTree_BinaryTree_h
#define BinaryTree_BinaryTree_h

#include "BNode.h"
#include <vector>

namespace vcn {

    template <class T>
    class BinaryTree {
    private:
        BNode<T> * root = nullptr;
        
    public:
        BinaryTree() {}
        virtual ~BinaryTree();
        
        bool empty();
        
        void clear();
        void clear(BNode<T> * node);
        
        BNode<T> * getRoot() const;
        void setRoot(BNode<T> * node);
        
        bool insert(BNode<T> * parent, T value);
        bool insert(BNode<T> * parent, BNode<T> * value);
        
        void preOrder() const;
        void preOrder(BNode<T> * node) const;
        
        void inOrder() const;
        void inOrder(BNode<T> * node) const;
        
        void postOrder() const;
        void postOrder(BNode<T> * node) const;
        
        void isLeaf() const;
        void isLeaf(BNode<T> * node) const;
        
        void ancestors(BNode<T> * node) const;
        
        void reflexion() const;
        void reflexion(BNode<T> * node) const;
        
        bool simetria();
        std::vector<T> getFami(std::vector<T> fami, BNode<T> * node, int niv, int lvl);
        
    };
    
    
    template <class T>
    BinaryTree<T>::~BinaryTree()
    {
        clear();
    }
    
    template <class T>
    bool BinaryTree<T>::empty()
    {
        return root == nullptr;
    }
    
    template <class T>
    void BinaryTree<T>::clear()
    {
        clear(root);
    }
    
    template <class T>
    void BinaryTree<T>::clear(BNode<T> * node)
    {
        if (node) {
            clear(node->getLeft());
            clear(node->getRight());
            
            delete node;
        }
    }
    
    template <class T>
    BNode<T> * BinaryTree<T>::getRoot() const
    {
        return root;
    }
    
    template <class T>
    void BinaryTree<T>::setRoot(BNode<T> * node)
    {
        if (!empty()) {
            node->setLeft(root);
            root->setParent(node);
            root = node;
        }
        else {
            root = node;
        }
    }
    
    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, T value)
    {
        BNode<T> * node = new BNode<T>(value);
        bool inserted = insert(parent, node);
        
        if (!inserted) delete node;
        
        return inserted;
    }
    
    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * value)
    {
        bool inserted = false;
        
        if (empty() || !parent) {
            setRoot(value);
            inserted = true;
        }
        else {
            if (!parent->getLeft()) {
                parent->setLeft(value);
                value->setParent(parent);
                inserted = true;
            }
            else if (!parent->getRight()) {
                parent->setRight(value);
                value->setParent(parent);
                inserted = true;
            }
        }
        
        return inserted;
    }
    
    template <class T>
    void BinaryTree<T>::preOrder() const
    {
        preOrder(root);
    }
    
    template <class T>
    void BinaryTree<T>::preOrder(BNode<T> * node) const
    {
        if (node) {
            /* Procesar el nodo */
            std::cout << *node << " ";
            
            /* Invocar a los hijos */
            preOrder(node->getLeft());
            preOrder(node->getRight());
  
        }
    }
    
    template <class T>
    void BinaryTree<T>::inOrder() const
    {
        inOrder(root);
    }
    
    template <class T>
    void BinaryTree<T>::inOrder(BNode<T> * node) const
    {
        if (node) {
            
            /* Invocar al hijo izquierdo */
            inOrder(node->getLeft());
            
            /* Procesar el nodo */
            std::cout << *node << std::endl;
            
            /* Invocar al hijo derecho */
            inOrder(node->getRight());
        }
    }
    
    template <class T>
    void BinaryTree<T>::postOrder() const
    {
        postOrder(root);
    }
    
    template <class T>
    void BinaryTree<T>::postOrder(BNode<T> * node) const
    {
        if (node) {
            /* Invocar a los hijos */
            postOrder(node->getLeft());
            postOrder(node->getRight());
            
            /* Procesar el nodo */
            std::cout << *node << std::endl;
        }
    }
    
    template <class T>
    void BinaryTree<T>::isLeaf() const
    {
        isLeaf(root);
    }
    
    template <class T>
    void BinaryTree<T>::isLeaf(BNode<T> * node) const
    {
        if (node) {
            if (!node->getLeft() && !node->getRight()) {
                std::cout << *node << std::endl;
            }
            else {
                isLeaf(node->getLeft());
                isLeaf(node->getRight());
            }
        }
    }
    
    template <class T>
    void BinaryTree<T>::ancestors(BNode<T> * node) const
    {
        if (node) {
            std::cout << *node << " -> ";
            ancestors(node->getParent());
        }
    }
    
    template<class T>
    void BinaryTree<T>::reflexion() const
    {
        reflexion(root);
    }
    
    template<class T>
    void BinaryTree<T>::reflexion(BNode<T> * node) const
    {
        if (node) {
            reflexion(node->getLeft());
            reflexion(node->getRight());
            
            BNode<T> *aux = node->getRight();
            node->setRight(node->getLeft());
            node->setLeft(aux);
        }
        
    }
    
    template<class T>
    bool BinaryTree<T>::simetria()
    {
        std::vector<T> fami;
        int lvl = 1;
        bool esSim = true;
        
        do
        {
            fami.clear();
            fami = this->getFami(fami,root,0,lvl);
            
            if (!fami.empty())
            {
                std::cout << std::endl;
                if (fami.size() % 2 == 0)
                {
                    for (int i = 0; i < fami.size()/2; i++){
                        if (fami[i] != fami[i+ fami.size()/2])
                            esSim = false;
                    }
                }else{
                    esSim = false;
                }
            }
            
            lvl++;
            
        }while (!fami.empty());
        
        return esSim;
    }
    
    
    
    
    template<class T>
    std::vector<T> BinaryTree<T>::getFami(std::vector<T> fami, BNode<T> * node, int niv, int lvl)
    {
        if (node && niv < lvl) {
            
            std::vector<T> izq = getFami(fami,node->getLeft(),(niv+1),lvl);
            std::vector<T> der = getFami(fami,node->getRight(),(niv+1),lvl);
            if (!izq.empty()) fami.insert( fami.end(), izq.begin(), izq.end() );
            if (!der.empty()) fami.insert( fami.end(), der.begin(), der.end() );
        }else{
            if (lvl == niv && node)
                fami.push_back(node->getInfo());
        }
        
        return fami;
        
    }

 
}

#endif
