#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;
    int hash();
};

int Card::hash(){
    int valeur {0};
    switch (Card::kind)
    {
    case CardKind::Heart:
        break;
    
    case CardKind::Diamond:
        valeur += 13;
        break;
    
    case CardKind::Club:
        valeur += 26;
        break;
    
    case CardKind::Spade:
        valeur += 39;
        break;
    }
    
    switch (Card::value)
    {
    case CardValue::Ace:
        break;
    case CardValue::Two:
        valeur += 1;
        break;
    case CardValue::Three:
        valeur += 2;
        break;
    case CardValue::Four:
        valeur += 3;
        break;
    case CardValue::Five:
        valeur += 4;
        break;
    case CardValue::Six:
        valeur += 5;
        break;
    case CardValue::Seven:
        valeur += 6;
        break;
    case CardValue::Eight:
        valeur += 7;
        break;
    case CardValue::Nine:
        valeur += 8;
        break;
    case CardValue::Ten:
        valeur += 9;
        break;
    case CardValue::Jack:
        valeur += 10;
        break;
    case CardValue::Queen:
        valeur += 11;
        break;
    case CardValue::King:
        valeur += 12;
        break;    
    
    }
    return valeur;
}
namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        Card c{static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)};
        cards.push_back(c);
    }
    return cards;
}

bool operator==(const Card carte1, const Card carte2)
{
    if (carte1.value == carte2.value && carte1.kind == carte2.kind)
    {
        return true;
    }
    else {
        return false;
    }
    
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

int main(){
    std::vector<Card> cartes {get_cards(100)};
    std::unordered_map<int, int> nombre_carte_dans_liste {};
    for (int i = 0; i < 52; i++)
    {
        nombre_carte_dans_liste.insert({i, 0});
    }
    
    for (Card c : cartes)
    {
        nombre_carte_dans_liste.at(c.hash())++;
    }
    
    for (int i = 0; i < 52; i++)
    {
        std::cout << "La carte " << i << " est " << nombre_carte_dans_liste.at(i) << " fois" << std::endl;
    }
    
    return 0;
}