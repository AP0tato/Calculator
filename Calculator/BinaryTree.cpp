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

        std::string getRoot() { return root ; }
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
                case '^':
                    return pow(l, r);
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

        BinaryTree* createTree(std::vector<std::string> v)
        {
            std::stack<BinaryTree*> stack;
            BinaryTree *tree = new BinaryTree("+");
            BinaryTree *t = tree;
            stack.push(tree);
            // tree->insertLeft("");
            // tree = tree->getLeft();
            std::string prev = v[0];
            std::string next = v[1];

            for(unsigned int i = 0; i < v.size()-1; i++)
            {
                if(i>0)
                    prev = v[i-1];
                next = v[i+1];
                
                if(v[i]=="(")
                {
                    if(isNumber(prev))
                    {
                        tree->setRoot("*");
                        stack.push(tree);
                        tree->insertLeft(prev);
                        tree->insertRight("");
                        tree = tree->getRight();
                    }
                    else
                    {
                        stack.push(tree);
                        tree->insertLeft("");
                        tree = tree->getLeft();
                    }
                }
                else if(v[i]==")")
                {
                    tree = stack.top();
                    stack.pop();
                }
                else if(v[i]=="^")
                {
                    tree->setRoot("^");
                    stack.push(tree);
                    if(prev!=")")
                        tree->insertLeft(prev);
                    tree->insertRight("");
                    tree = tree->getRight();
                }
                else if(v[i]=="*")
                {
                    tree->setRoot("*");
                    stack.push(tree);
                    if(prev!=")")
                        tree->insertLeft(prev);
                    tree->insertRight("");
                    tree = tree->getRight();
                }
                else if(v[i]=="/")
                {
                    tree->setRoot("/");
                    stack.push(tree);
                    if(prev!=")")
                        tree->insertLeft(prev);
                    tree->insertRight("");
                    tree = tree->getRight();
                }
                else if(v[i]=="+")
                {
                    tree->setRoot("+");
                    stack.push(tree);
                    if(prev!=")")
                        tree->insertLeft(prev);
                    tree->insertRight("");
                    tree = tree->getRight();
                }
                else if(v[i]=="-")
                {
                    tree->setRoot("-");
                    stack.push(tree);
                    if(prev!=")")
                        tree->insertLeft(prev);
                    tree->insertRight("");
                    tree = tree->getRight();
                }
                else
                {
                    if(next!="*"||next!="/"||next!="^"||next!="(")
                    {
                        tree->setRoot(v[i]);
                        tree = stack.top();
                        stack.pop();
                    }
                    else
                    {
                        stack.push(tree);
                        tree->setRoot(next==")"?"*":next);
                        tree->insertLeft(v[i]);
                        tree->insertRight("");
                        tree = tree->getRight();
                    }
                }
            }
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