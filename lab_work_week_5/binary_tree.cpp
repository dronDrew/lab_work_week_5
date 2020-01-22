#include "binary_tree.h"
binary_tree::Element::Element(std::string word) {
    this->word = word;
    this->counter = 0;
    this->leftlives = nullptr;
    this->rightlives = nullptr;
    this->translation = nullptr;
}
binary_tree::binary_tree() {
    this->root = nullptr;
}
void binary_tree::InitDictionery() {
    std::ifstream file;
    file.open("dictionary.txt");
    if (file.is_open()) {
        std::string angl;
        while (!file.eof()) {
            file >> angl;
            if (this->root == nullptr) {
                root = new Element(angl);
            }
            else {
                unsigned char a = angl[0];
                if (a < 122) {
                    Element* temp = root;
                    while (temp->rightlives != nullptr) {
                        temp = temp->rightlives;
                    }
                    temp->rightlives = new Element(angl);
                    file >> angl;
                    temp->leftlives = new Element(angl);
                    temp->rightlives->translation = temp->leftlives;
                }
                else {
                    Element* temp = root;
                    while (temp->leftlives != nullptr) {
                        temp = temp->leftlives;
                    }
                    temp->leftlives = new Element(angl);
                    file >> angl;
                    temp->rightlives = new Element(angl);
                    temp->leftlives->translation = temp->rightlives;
                }
            }
        }
    }
    else {
        std::cout << "file not opened\n";
    }
}
void binary_tree::Search(std::string& a) {
    unsigned char point = a[0];
    Element* temp = root;
    if (point < 122) {
        while (temp != nullptr) {
            if (temp->word == a) {
                temp->counter++;
                std::cout << temp->word << " - ";
                Element* tran = temp->translation;
                while (tran != nullptr)
                {
                    std::cout << " " << tran->word;
                    tran = tran->translation;
                }
                std::cout << std::endl;
                break;
            }
            temp = temp->rightlives;
        }
    }
    else {
        Element* temp = root;
        while (temp != nullptr) {
            if (temp->word == a) {
                temp->counter++;
                std::cout << temp->word << " - ";
                Element* translation = temp->translation;
                while (translation !=nullptr)
                {
                    std::cout<<"  "<< translation->word;
                    translation = translation->translation;
                }
                std::cout << std::endl;
                break;
            }
            temp = temp->leftlives;
        }
    }
}
void binary_tree::Edit_translation(std::string& a, std::string b) {
        unsigned char point = a[0];
        Element* temp = root;
        if (point < 122) {
            while (temp != nullptr) {
                if (temp->word == a) {
                    temp->translation->word = b;
                }
                temp = temp->rightlives;
            }
        }
        else {
            Element* temp = root;
            while (temp != nullptr) {
                if (temp->word == a){
                temp->translation->word = b;
                }
                temp = temp->leftlives;
            }
        }
}
void binary_tree::Add_translation(std::string& a, std::string b) {
    unsigned char point = a[0];
    Element* temp = root;
    if (point < 122) {
        while (temp != nullptr) {
            if (temp->word == a) {
                Element* tran = temp->translation;
                while (tran->translation != nullptr)
                {
                    tran = tran->translation;
                }
                tran->translation = new Element(b);
            }
            temp = temp->rightlives;
        }
    }
    else {
        Element* temp = root;
        while (temp != nullptr) {
            if (temp->word == a) {
                Element* tran = temp->translation;
                while (tran->translation != nullptr)
                {
                    tran = tran->translation;
                }
                tran->translation = new Element(b);
            }
            temp = temp->leftlives;
        }
    }
}
void binary_tree::Delete_translation(std::string& a) {
    unsigned char point = a[0];
    Element* temp = root;
    if (point < 122) {
        while (temp != nullptr) {
            if (temp->word == a) {
                delete temp->translation;
                temp->translation = nullptr;
            }
            temp = temp->rightlives;
        }
    }
    else {
        Element* temp = root;
        while (temp != nullptr) {
            if (temp->word == a) {
                delete temp->translation;
                temp->translation = nullptr;
            }
            temp = temp->leftlives;
        }
    }
}