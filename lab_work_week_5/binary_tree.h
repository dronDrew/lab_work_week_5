#pragma once
#include "dependies.h"
class binary_tree
{
    class Element {
    public:
        int counter;
        std::string word;
        Element* leftlives;
        Element* rightlives;
        Element* translation;
        Element(std::string word);
    };
public:
    Element* root;
    binary_tree();
    void InitDictionery();
    void Search(std::string& a);
    void Edit_translation(std::string& a, std::string b);
    void Add_translation(std::string& a, std::string b);
    void Delete_translation(std::string& a);

};

