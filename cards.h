#pragma once
#include <iostream>
enum Cost
  {
    none=-1,
    none2=-2,
    tw=1,
    tr=2,
    fo=3,
    fi=4,
    si=5,
    se=6,
    ei=7,
    ni=8,
    te=9,
    ja=10,
    qu=11,
    ki=12,
    ace=13,
  };
enum Suit 
  { 
    none1=-2,
    none3=-1,
    hearts=0,
    diamonds=1,
    spades=2,
    clubs=3,
  }; 

char ToChar_(Cost cost);

char ToChar(Suit suit);

class Card
{
  public:
  Suit suit;
  Cost cost;
  Card(Suit suit,Cost cost);
  Card(Cost cost,Suit suit);
  Card(); 
  friend std::ostream& operator << (std::ostream &out,Card &Card);
  };

int RandomInt(int,int);

