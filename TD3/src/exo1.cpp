#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <math.h>
#include <stack>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}


bool is_floating(std::string const& chaine) {
    for (char c : chaine) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

float calculate (float leftOperand, float rightOperand, char op) {
    switch(op)
        {
        case '+':
            return leftOperand + rightOperand;
        case '-':
            return leftOperand - rightOperand;
        case '*':
            return leftOperand * rightOperand;
        case '/':
            return leftOperand / rightOperand;

        case '^':
            return pow(leftOperand,rightOperand);
        }
}

float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> operandStack;
    for (std::string const token : tokens) {
        if (is_floating(token)) {
            operandStack.push(stof(token));
        } 
        else {
            float rightOperand { operandStack.top() };
            operandStack.pop();

            float leftOperand { operandStack.top() };
            operandStack.pop();

            char op { token[0] };
            operandStack.push(calculate(leftOperand, rightOperand, op));
        }
    }
    float resultat { operandStack.top() };
    operandStack.pop();
    if (operandStack.empty() == false)
    {
        std::cout << "ERROR" << std::endl;
    }
    
    return resultat;
}

int main()
{
    std::string chaineNPI {};
    std::cout << "Veuillez entrez votre expression en NPI : " << std::endl;
    std::getline(std::cin, chaineNPI);

    std::vector<std::string> NPI_splitted {split_string(chaineNPI)};

    float resultat = npi_evaluate(NPI_splitted);
    std::cout << "La chaine NPI donne : " << resultat << std::endl;

    return 0;
}