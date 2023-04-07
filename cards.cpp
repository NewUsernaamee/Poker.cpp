#include <Cards.h>
#include <iostream> 
std::ostream& operator << (std::ostream &out,Card &Card)
{
  out<<ToChar_(Card.cost) << "_";
  out<<ToChar(Card.suit) << "  ";
  return out;
}    


Card::Card()
: suit(none1)
, cost(none)
{}
  
Card::Card(Suit suit_, Cost cost_)
: suit(suit_)
, cost(cost_)
{}

Card::Card(Cost cost_,Suit suit_)
: suit(suit_)
, cost(cost_)
{}

char ToChar(Suit suit)
{
  switch (suit)
  {
    case hearts:
     return 'H'; break;
    case diamonds:
     return 'D'; break;
    case spades:
     return 'S'; break;
    case clubs:
     return 'C'; break;
    case none1:
     return ' '; break;
    case none3:
     return ' '; break;
  }
return ' ';        
}
