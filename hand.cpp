#include <Hand.h>
#include<Cards.h>
#include<Deck.h>

std::ostream& operator << (std::ostream &out,Hand &Hand)
  {
    for (int i = 0; i <7; i++)
    {
      out << Hand.card[i];
    }  
    return out;
  }

Hand& Hand::operator =(Card &card1)
{
  card->suit=card1.suit;
  card->cost=card1.cost;
  return *this;
}





void Hand::TakeHand(Deck deck)
{ 
  for (int i = 0; i < 7; i++)
  {
    card[i]=deck.card[i];
  }
}



Hand Hand::CreateStreet()
{ 
  int q=0;
  for (Cost i = tw; i <=ni ; i=Cost(i+1))
  {
    card[q]=Card(i,spades);
    q+=1;
  }
  card[q]=Card(ei,spades);
  card[1].suit=diamonds;
  card[4].suit=hearts;
  return *this;
}

Hand Hand::Boble()
{
  Card temp;
  int size=7;
  for (int i = 0; i < size - 1; i++) 
  {
    for (int j = 0; j < size - i - 1; j++) 
    {
      if (card[j].cost > card[j + 1].cost) 
      {
        temp = card[j];
        card[j] = card[j + 1];
        card[j + 1] = temp;
      }
    }
  }
  return *this; 
}

Hand Hand::CopyHand(Hand deck7)
{  
  for (int i = 0; i < 7; i++)
  {
     card[i]=deck7.card[i];
  }
  return deck7;
}

Hand::~Hand()
{
  delete[]value;
}

Hand::Hand(int size__)
: value(nullptr)
, size(size__)
{value=new Card[size];}

Hand::Hand(Deck * deck)
{ for (int i=0; i<7;++i)
  {
    *(deck+i)->card=card[i];
  }
}

Hand::Hand()
{ 
  for(int q=0; q<7; q++)
  { 
    card[q]= Card(none1,none2);
  }
}
Hand Hand::CreateStreetFlesh ()
{ 
  int q=0;
  for (Cost i = tw; i <=ni ; i=Cost(i+1))
  {
    card[q]=Card(spades,i);
    q+=1;
  }
  card[q]=Card(ei,spades);
  return *this;
}