/*
 * File:   main.cpp
 * Author: admin
 *
 * Created on 3 sierpieñ 2016, 00:15
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


using namespace std;
int TAB_CNT = 15;


void gen_tab(int *tab, int cnt, int range)
{
    for(int i=0; i<cnt; i++, tab++)
        *tab = rand()%range;
}


typedef struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;
    int counter;

}
 tnode;


void pass_node_from_left(tnode *node)
{
    static int i = 0;
    
    if (node->left != 0)
        pass_node_from_left(node->left);
    cout << i++ << ": " << node->value << endl;
    if (node->right !=0 )
        pass_node_from_left(node->right);
    return;

}


tnode *clear_tnode_ptrs(tnode *node)
{
    node->left = 0;
    node->right = 0;
    return node;
}


void cmp_ins_node(tnode *node, int value)
{
    cout << node->value << " ";
    if (node->value > value)
    {
        cout << " L ";
        if (node->left == 0)
        {
            node->left = new tnode;
            node->left->value = value;
            clear_tnode_ptrs(node->left);
            cout << value << endl;
        }
        else
            cmp_ins_node(node->left, value);
    }
    else
    {
        cout << " R ";
        if (node->right == 0)
        {
            node->right = new tnode;
            node->right->value = value;
            clear_tnode_ptrs(node->right);
            cout << value << endl;
        }
        else
            cmp_ins_node(node->right, value);
    }
}


void delete_tree(tnode *node)
{
    if (node->left != 0)
        delete_tree(node->left);
    if (node->right != 0)
        delete_tree(node->right);
    delete node;
}


void gen_tree(tnode *tree_head, int *tab, int cnt)
{
    tree_head->value = *tab;
    clear_tnode_ptrs(tree_head);
    if (cnt<2)
        return;
    for(int i=1; i<cnt; i++)
    {
        cout << i << ": ";
        cmp_ins_node(tree_head, tab[i]);
    }
    pass_node_from_left(tree_head);
    //for(int i=0; i<TAB_CNT; i++)
      //  cout << tree[i].left << " ";
    //cout << endl;
}


int main()
{
    int tab[TAB_CNT];
    tnode *tree_head = new tnode;



    if (tree_head == 0)
        return 0;
    cout << typeid(tree_head).name() << endl;
    cout << typeid(tab[0]).name() << endl;


   srand(time(NULL));


   gen_tab(tab, TAB_CNT, 100);


   for(int i=0; i<TAB_CNT; i++)
        cout << tab[i] << " ";
    cout << endl;


   gen_tree(tree_head, tab, TAB_CNT);


   delete_tree(tree_head);


   return 0;
}
