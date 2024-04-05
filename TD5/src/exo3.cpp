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
    
    default:
        break;
    }
}
namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.emplace_back(static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13));
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

int main(){

    return 0;
}