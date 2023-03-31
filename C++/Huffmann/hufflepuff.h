#pragma once
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <unordered_map>
#include "Node.h"

class HuffmanTree {
private:
    Node* root;
    std::unordered_map<char, int> FrequencyTable; // Cria a tabela de frequência de caracteres do dado a ser comprimido

    void CreateFrequencyTable(const std::string& data);
    void BuildTree();
    void BinaryMap(std::unordered_map<char, std::string>& binary, Node* node, std::string current_codeword);

public:

    HuffmanTree(const std::string& data);
    ~HuffmanTree();

    std::unordered_map<char, std::string> get_codewords();

    std::string encode(const std::string& data);
    std::string decode(const std::string& encoded_data);

    void Deforest(Node* node);
};

#endif
