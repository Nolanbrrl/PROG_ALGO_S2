#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <math.h>
#include <stack>



// EXO 2 //

enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };

struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value)
{
    return {TokenType::OPERAND, value};
}
Token make_token(Operator op)
{
    return {TokenType::OPERATOR, 0, op};
}

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

float calculate (float leftOperand, float rightOperand, Token token) {
    switch(token.op)
        {
        case Operator::ADD:
            return leftOperand + rightOperand;
            
        case Operator::SUB:
            return leftOperand - rightOperand;
            
        case Operator::MUL:
            return leftOperand * rightOperand;
            
        case Operator::DIV:
            return leftOperand / rightOperand;
            
        case Operator::OPEN_PAREN:
            
        case Operator::CLOSE_PAREN:

        case Operator::POW:
            return pow(leftOperand,rightOperand);

        }
}



std::vector<Token> tokenize(std::vector<std::string> const &mots)
{
    std::vector<Token> Tokens{};
    for (size_t i{0}; i < mots.size(); i++)
    {
        if (is_floating(mots[i]))
            Tokens.push_back(make_token(std::stof(mots[i])));
        else if (mots[i] == "+")
        {
            Tokens.push_back(make_token(Operator::ADD));
        }
        else if (mots[i] == "-")
        {
            Tokens.push_back(make_token(Operator::SUB));
        }
        else if (mots[i] == "*")
        {
            Tokens.push_back(make_token(Operator::MUL));
        }
        else if (mots[i] == "/")
        {
            Tokens.push_back(make_token(Operator::DIV));
        }
        else if (mots[i] == "^")
        {
            Tokens.push_back(make_token(Operator::POW));
        }
        else if (mots[i] == "(")
        {
            Tokens.push_back(make_token(Operator::OPEN_PAREN));
        }
        else if (mots[i] == ")")
        {
            Tokens.push_back(make_token(Operator::CLOSE_PAREN));
        }
        else {
            break;
        }
    }
    return Tokens;
}

// changement de la npi_evaluate de l'exo 1 //
float npi_evaluate2(std::vector<Token> const& tokens) {
    std::stack<float> operandStack;
    for (Token const token : tokens) {
       if (token.type == TokenType::OPERAND)
       {
            operandStack.push(token.value);
       }
       else {
            float rightOperand { operandStack.top() };
            operandStack.pop();

            float leftOperand { operandStack.top() };
            operandStack.pop();

            operandStack.push(calculate(leftOperand, rightOperand, token));
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
    float resultat = npi_evaluate2(tokenize(NPI_splitted));
    std::cout << "La chaine NPI donne : " << resultat << std::endl;

    return 0;
}

