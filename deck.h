#pragma once
#include <iostream>
#include "Cards.h"
class Deck
{ public:
  Card card[52];
  Deck();
  Deck(Deck *deck);
  void Shufle();
  friend std::ostream& operator << (std::ostream &out,Deck &Deck);
};
