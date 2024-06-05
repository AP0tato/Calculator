#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BinaryTree.cpp"
#include "Parser.cpp"

void write(std::string s, std::string filePath);

int main()
{
    std::ofstream of;
    of.open("./Results.txt", std::ofstream::out | std::ofstream::trunc);
    of.close();

    std::string equ;
    std::vector<std::string> v;
    std::ifstream file("./Input.txt");

    BinaryTree *tree = new BinaryTree("+");
    Parser *p;
    
    while(std::getline(file, equ))
    {
        v = p->parse(equ);
        tree = tree->createTree(v);
        double ans = tree->eval(tree);
        write(std::to_string(ans), "./Results.txt");
    }
    
    return 0;
}

void write(std::string s, std::string filePath)
{
    std::ofstream file;
    file.open(filePath, std::ofstream::app);
    file << s << "\n";
    file.close();
}