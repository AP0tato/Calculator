#include <string>
#include <vector>
#include <stack>

#pragma once

class BinaryTree
{
    BinaryTree *left;
    BinaryTree *right;
    std::string root;

    public:
        BinaryTree() { left = nullptr; right = nullptr; }
        BinaryTree(std::string r) { left = nullptr; right = nullptr; root=r; }
        BinaryTree(std::string ro, BinaryTree *l, BinaryTree *r) { left = l; right = r; root = ro; }

        std::string getRoot() { return root; }
        void setRoot(std::string r) { root = r; }

        BinaryTree* getLeft() { return left; }
        BinaryTree* getRight() { return right; }

        double eval(BinaryTree *tree)
        {
            BinaryTree *left = tree->getLeft();
            BinaryTree *right = tree->getRight();
            std::string op;
            double l, r;

            if(left && right)
            {
                op = tree->getRoot();
                l = eval(left);
                r = eval(right);
                switch (op[0])
                {
                case '*':
                    return l*r;
                case '/':
                    return l/r;
                case '+':
                    return l+r;
                case '-':
                    return l-r;
                }
            }
            else
                return std::stod(tree->getRoot());
            return 0.0;
        }

        BinaryTree* parse(std::vector<std::string> v)
        {
            std::stack<BinaryTree*> stack;
            BinaryTree *tree = new BinaryTree("+");
            BinaryTree *t = tree;
            stack.push(tree);
            stack.push(tree);
            tree->insertLeft("");
            tree = tree->getLeft();

            for(unsigned int i = 0; i < v.size(); i++)
            {
                if(v[i]==")")
                {
                    tree->setRoot(v[i-1]);
                    tree = stack.top();
                    stack.pop();
                }
                else if(v[i]=="(")
                {
                    if(tree->getLeft()==nullptr)
                    {
                        tree->insertLeft("");
                        stack.push(tree);
                        tree = tree->getLeft();
                    }
                    else
                    {
                        tree->insertRight("");
                        stack.push(tree);
                        tree = tree->getRight();
                    }
                }
                else if((v[i]=="*") || (v[i]=="/"))
                {
                    tree->setRoot(v[i]);
                    if((v[i+2]=="*") || (v[i+2]=="/"))
                    {
                        tree->insertRight("");
                        tree->insertLeft(v[i-1]);
                        tree = tree->getRight();
                    }
                    else if(tree->getLeft()==nullptr)
                    {
                        tree->insertLeft(v[i-1]);
                        if(isNumber(v[i+1]))
                            tree->insertRight(v[i+1]);
                    }
                    else
                        tree->insertRight(v[i+1]);

                    if ( (!((v[i+2]=="*") || (v[i+2]=="/"))) && v[i+1]!="(")
                    {
                        tree = stack.top();
                        stack.pop();
                    }
                }
                else if((v[i]=="+") || (v[i]=="-"))
                {
                    tree->setRoot(v[i]);
                    if(tree->getLeft()==nullptr)
                        tree->insertLeft(v[i-1]);
                    if(v[i+1]==")")
                        tree->insertRight(v[i+1]);
                    else 
                        tree->insertRight("");
                    tree = tree->getRight();
                }
            }
            if(!tree->getRight())
                tree->insertRight("0");

            return t;
        }        

        void insertLeft(std::string val)
        {
            BinaryTree *node = new BinaryTree(val);
            if(left==nullptr)
                left=node;
            else
            {
                node->left = left;
                left = node;
            }
        }

        void insertRight(std::string val)
        {
            BinaryTree *node = new BinaryTree(val);
            if(right==nullptr)
                right=node;
            else
            {
                node->right = right;
                right = node;
            }
        }

        bool isOperator(char c)
        {
            std::string op = "+-*/^";
            for(short i = 0; i < op.length(); i++)
            {
                if(c==op[i])
                    return true;
            }
            return false;
        }

        bool isOperator(std::string c)
        {
            std::string op = "+-*/^";
            for(short i = 0; i < op.length(); i++)
            {
                if(c[0]==op[i])
                    return true;
            }
            return false;
        }

        bool isNumber(std::string in)
        {
            char curr = in[0];
            unsigned int i = 0;
            bool isNum = true;

            while(i<in.length())
            {
                if(!( ((curr-'0'>=0 && curr-'0'<=9) || curr=='.') )) 
                    isNum = false;
                curr=in[i];
                i++;
            }

            return isNum;
        }
};