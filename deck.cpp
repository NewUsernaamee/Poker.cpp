#include <Deck.h>
#include <Cards.h>

void Deck::Shufle()
  {
    for (int i = 0; i < 52; i++)
    {
      Card remember = card[i];
      int x = RandomInt(0,51);
      card[i] = card[x];
      card[x] = remember;
    }
  } 

std::ostream& operator << (std::ostream &out,Deck &Deck)
{
  for (int i = 0; i < 52; i++)
 {
   out << Deck.card;
   if (i==12 || i==25 || i==38)
   {
    std::cout << "\n"; 
   }
  }
  return out;
}

Deck::Deck()
{
  int q=0; 
  for(Suit s=hearts;s<=clubs;s=Suit(s+1))
  {
    for(Cost z=tw;z<=ace;z=Cost(z+1))
    { 
      card[q]= Card(s,z);
      q=q+1;
    }
  }
  card[q]= Card(clubs,ace);
}