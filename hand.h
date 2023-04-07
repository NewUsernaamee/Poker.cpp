#pragma once
#include "Cards.h"
#include "Deck.h"
#include "iostream"
class Hand
{ public:
  Card card[7];
  int size;
  Card *value;
  
  Hand(Deck * deck);
  Hand();
  Hand(int size);
  ~Hand();
  friend std::ostream& operator << (std::ostream &out,Hand &PartDeck);
Hand &operator =(Card &card1);

Hand CreateStreetFlesh ();

void TakeHand(Deck deck);

Hand CreateStreet();

Hand Boble();
Hand CopyHand(Hand deck7);

};

