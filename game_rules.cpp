#include <hand.h>
#include <game_rules.h>
#include <cards.h>
Hand GameRules::IsFlesh()
{ 
  for (int i = 0; i < 3; i++)
  {
    if (hand.card[i].suit==hand.card[i+1].suit && hand.card[i].suit==hand.card[i+2].suit && hand.card[i].suit==hand.card[i+3].suit && hand.card[i].suit==hand.card[i+4].suit)
    {
      std:: cout << "FLESH!!!!!\n";
      hand.card[i+1].suit=none1;
      hand.card[i+2].suit=none3;
    } 
  }
}

Hand GameRules::CheckStreet ()
{
  for (int i = 0; i < 6; i++)
  { 
    if (int(hand.card[i+1].cost-hand.card[i].cost)==1 && int(hand.card[i+2].cost-hand.card[i+1].cost)==1 && int(hand.card[i+3].cost-hand.card[i+2].cost)==1 && int(hand.card[i+4].cost-hand.card[i+3].cost)==1)
    {
      std:: cout <<"STREET!!!\n";
      hand.card[i+1].cost=none;
      hand.card[i+3].cost=none2;
    }
  }
  return hand;
}

void GameRules::Check2 ()
{
  int countOf2=0;
  for ( int i = 0; i < 6; i++)
  {
    if (hand.card[i].cost==hand.card[i+1].cost )
    {
      countOf2=countOf2+1;
    }
  }
  std:: cout <<"\n" <<"number of \"Pairs\" = " << countOf2 << "\n";
}

Hand GameRules::Check4 ()
{
  int countOf4=0;
  for ( int i = 0; i < 4; i++)
  {
    if (hand.card[i].cost==hand.card[i+1].cost && hand.card[i].cost==hand.card[i+2].cost && hand.card[i].cost==hand.card[i+3].cost)
    {
      countOf4=countOf4+1;
      hand.card[i].cost=none;
      hand.card[i+1].cost=none2;
      hand.card[i+2].cost=none;
      hand.card[i+3].cost=none2;
    }
  }
  std:: cout <<"\n" <<"number of \"four of kind\" = " << countOf4;
  return hand;
}

Hand GameRules::Check3 ()
{
  int countOf3=0;
  for ( int i = 0; i < 5; i++)
  {
    if (hand.card[i].cost==hand.card[i+1].cost && hand.card[i].cost==hand.card[i+2].cost)
    {
      countOf3=countOf3+1;
      hand.card[i].cost=none;
      hand.card[i+1].cost=none2;
      hand.card[i+2].cost=none;
    }
  }
  std:: cout <<"\n" <<"number of \"three of kind\" = " << countOf3;
  return hand;
}

void GameRules::Check2 ()
{
  int countOf2=0;
  for ( int i = 0; i < 6; i++)
  {
    if (hand.card[i].cost==hand.card[i+1].cost )
    {
      countOf2=countOf2+1;
    }
  }
  std:: cout <<"\n" <<"number of \"Pairs\" = " << countOf2 << "\n";
}

GameRules::GameRules(Hand hand)
{ for (int x=0;x<7;x++)
    {
    *this->hand.card=hand.card[x];
    }
}