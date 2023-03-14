#include <cstdlib>

#include <iostream>

#include <ctime>

//стоимость карт\/
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
//масти карт\/
  enum Suit 
  { 
    none1=-2,
    none3=-1,
    hearts=0,
    diamonds=1,
    spades=2,
    clubs=3,
  }; 
//структура карта\/
  struct Card
  { Suit suit;
    Cost cost;
    Card(Suit suit,Cost cost);
    Card();
  };

  Card::Card()
  : suit(clubs)
  , cost(ace)
  {}
  
  Card::Card(Suit suit_, Cost cost_)
    : suit(suit_)
    , cost(cost_)
  {}

//структура колода\/
  struct Deck
  {
    Card card[52];
    Deck();
    Deck(Deck *deck);
  };

  Deck::Deck()
  { int q=0; 
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

//структура часть колоды\1/
struct PartDeck
{
  int size;
  Card *value;
  Card card[7];
  PartDeck(Deck * deck);
  PartDeck();
  PartDeck(int size);
};

PartDeck::PartDeck(int size__)
: value(nullptr)
, size(size__)
{value=new Card[size];}


PartDeck::PartDeck(Deck * deck)
{ for (int i=0; i<7;++i)
  {
    *(deck+i)->card=card[i];
  }
}

PartDeck::PartDeck()
{ 
  
    for(int q=0; q<7; q++)
  { 
    card[q]= Card(none1,none2);
  }
  
}
//создание карты\/
Card CreateNewCard (Cost cost,Suit suit)
{Card card(suit,cost);
  card.cost=cost;
  card.suit=suit;
  return card;
}
//создание псевдослучайного числа\/
int RandomInt (int min,int max)
{ int x;
x = min +std::rand()/((RAND_MAX + 1u)/(max-min));
return x;
}
// распечатка масти карты\/
void Print(Suit suit)
{
  switch (suit)
  {
  case hearts:
  std:: cout << "H";
    break;
  
  case diamonds:
  std:: cout << "D";
    break;
    case spades:
  std:: cout << "S";
    break;
    case clubs:
  std:: cout << "C";
    break;
      case none1:
  std:: cout << " ";
    break;
       case none3:
  std:: cout << " ";
    break;

  }
}
//распечатка стоимости карты\/
void Print(Cost cost)
{
  switch (cost)
  {

   case none:
  std:: cout << " ";
    break;
  
  case tw:
  std:: cout << "2";
    break;
    case tr:
  std:: cout << "3";
    break;
    case fo:
  std:: cout << "4";
    break;
    case fi:
  std:: cout << "5";
    break;
    case si:
  std:: cout << "6";
    break;
    case se:
  std:: cout << "7";
    break;
    case ei:
  std:: cout << "8";
    break;
    case ni:
  std:: cout << "9";
    break;
    case te:
  std:: cout << "10";
    break;
    case ja:
  std:: cout << "J";
    break;
    case qu:
  std:: cout << "Q";
    break;
    case ki:
  std:: cout << "K";
    break;
    case ace:
  std:: cout << "A";
    break;
       case none2:
  std:: cout << " ";
    break;

  }
}
//распечатка карты\/
void Print(Card c)
{ 
  Print(c.suit);
  std:: cout<< "_";
  Print(c.cost);
  std:: cout<< "  ";
}
//распечатка полной колоды\/
void Print (Deck deck)
{
  for (int i = 0; i < 52; i++)
  {
    Print(deck.card[i]);
    if (i==12 || i==25 || i==38)
    {
      std::cout << "\n";
    }
    
  }  
}
// вывод 7 нижних карт\/
void TakeSeven(PartDeck deck)
{   Deck deck1[7];
  for (int i = 0; i <7 ; i++)
  {   
      deck1->card[i]=deck.card[i];
    Print(deck.card[i]);
    
  }  

}
//создание колоды\/
Deck CreateDeck()
{ int q=0; 

Deck deck;

 for(Suit s=hearts;s<=clubs;s=Suit(s+1))
 {
  for(Cost z=tw;z<=ace;z=Cost(z+1))
  { 

    
    deck.card[q]=CreateNewCard(z,s);
    q=q+1;
  
  }
 }

 deck.card[q]=CreateNewCard(ace,clubs);
 return deck;
}
//перемешивание колоды\/
Deck ShafleDeck(Deck deck)
{
  
  for (int i = 0; i < 52; i++)
  {   Card remember=deck.card[i];
    int x=RandomInt(0,51);
    deck.card[i]=deck.card[x];
    deck.card[x]=remember;
  }
  return deck;
}
//взятие 7 карт\/
PartDeck TakePartDeck(Deck deck)
{ PartDeck top7;
  for (int i = 0; i < 7; i++)
  {
   top7.card[i]=deck.card[i];
  }

return top7;
}
//сортировка\/
PartDeck Boble(PartDeck deck7)
{
Card temp;
int size=7;
  for (int i = 0; i < size - 1; i++) 
  {
    for (int j = 0; j < size - i - 1; j++) 
    {
      if (deck7.card[j].cost > deck7.card[j + 1].cost) 
      {
        
          temp = deck7.card[j];
          deck7.card[j] = deck7.card[j + 1];
          deck7.card[j + 1] = temp;
      }
    }
  }
  return deck7;
}
//проверка на 4\/(возвращает поломанный массив)
PartDeck Check4 (PartDeck deck7)
{
int countOf4=0;
  for ( int i = 0; i < 4; i++)
  {
    if (deck7.card[i].cost==deck7.card[i+1].cost && deck7.card[i].cost==deck7.card[i+2].cost && deck7.card[i].cost==deck7.card[i+3].cost)
    {
      countOf4=countOf4+1;
      deck7.card[i].cost=none;
      deck7.card[i+1].cost=none2;
      deck7.card[i+2].cost=none;
      deck7.card[i+3].cost=none2;

    }
  }
  std:: cout <<"\n" <<"number of \"four of kind\" = " << countOf4;
  return deck7;
}
//проверка на 3\/(возвращает поломанный массив)
PartDeck Check3 (PartDeck deck7)
{
  
int countOf3=0;
  for ( int i = 0; i < 5; i++)
  {
    if (deck7.card[i].cost==deck7.card[i+1].cost && deck7.card[i].cost==deck7.card[i+2].cost)
    {
      countOf3=countOf3+1;
      deck7.card[i].cost=none;
      deck7.card[i+1].cost=none2;
      deck7.card[i+2].cost=none;
    }
  }
  std:: cout <<"\n" <<"number of \"three of kind\" = " << countOf3;
  return deck7;

}
//проверка на 2\/
void Check2 (PartDeck deck7)
{
  
int countOf2=0;
  for ( int i = 0; i < 6; i++)
  {
    if (deck7.card[i].cost==deck7.card[i+1].cost )
    {
      countOf2=countOf2+1;
    }
  }
std:: cout <<"\n" <<"number of \"Pairs\" = " << countOf2 << "\n";
}
//копирует колоду для других операций\/
PartDeck CopyDeck(PartDeck deck7)
{  
PartDeck Copy;
  for (int i = 0; i < 7; i++)
  {
     Copy.card[i]=deck7.card[i];
  }
  return Copy;
}
// проверяет на стрит \/
void IsFlesh(PartDeck deck7)
{
  for (int i = 0; i < 3; i++)
  {
    if (deck7.card[i].suit==deck7.card[i+1].suit && deck7.card[i].suit==deck7.card[i+2].suit && deck7.card[i].suit==deck7.card[i+3].suit && deck7.card[i].suit==deck7.card[i+4].suit)
    {
      std:: cout << "FLESH!!!!!\n";
      deck7.card[i+1].suit=none1;
      deck7.card[i+2].suit=none3;
    } 
  }
}
// создаёт часть колоды с флешем и стритом\/
PartDeck CreateStreetFlesh (PartDeck deck7)
{ int q=0;
  for (Cost i = tw; i <=ni ; i=Cost(i+1))
  {
    deck7.card[q]=CreateNewCard(i,spades);
    q+=1;
  }
  deck7.card[q]=CreateNewCard(ei,spades);
  return deck7;
}
//Проверяет на стрит\/
void CheckStreet (PartDeck deck7)
{
  for (int i = 0; i < 6; i++)
  {  
    if (int(deck7.card[i+1].cost-deck7.card[i].cost)==1 && int(deck7.card[i+2].cost-deck7.card[i+1].cost)==1 && int(deck7.card[i+3].cost-deck7.card[i+2].cost)==1 && int(deck7.card[i+4].cost-deck7.card[i+3].cost)==1)
    {
      std:: cout <<"STREET!!!\n";
      deck7.card[i+1].cost=none;
      deck7.card[i+3].cost=none2;
    }
  }
  
}

PartDeck CreateStreet(PartDeck deck7)
{ int q=0;
  for (Cost i = tw; i <=ni ; i=Cost(i+1))
  {
    deck7.card[q]=CreateNewCard(i,spades);
    q+=1;
  }
  deck7.card[q]=CreateNewCard(ei,spades);
  deck7.card[1].suit=diamonds;
  deck7.card[4].suit=hearts;
  return deck7;

}
//запуск в режиме обычной проверки\/
void start1 (void)
{
Deck deck=Deck();
deck=ShafleDeck(deck);
PartDeck topSeven=TakePartDeck(deck);
TakeSeven(topSeven);
std:: cout << "\n";
//-----------------------------------------------------
topSeven= Boble(topSeven);
TakeSeven(topSeven);
PartDeck Copy=CopyDeck(topSeven);
topSeven=Check4(topSeven);
topSeven=Check3(topSeven);
Check2(topSeven);
topSeven=Copy;
CheckStreet(topSeven);
IsFlesh(topSeven);
}
//проверка со стритом и флешем
void start2(void)
{
  PartDeck topSeven=CreateStreetFlesh(topSeven);
  CheckStreet(topSeven);
  IsFlesh(topSeven);
  TakeSeven(topSeven);


}

void start3(void)
{
  PartDeck topSeven=CreateStreet(topSeven);
  CheckStreet(topSeven);
  IsFlesh(topSeven);
  TakeSeven(topSeven);


}

void begin(int x)
{switch (x)
{
case 1 :
  start1();
  break;
case 2 :
  start2();
  break;
  case 3 :
  start3();
  break;
default:
  break;
}}

int main()
{ 
std::srand(time(0));

int x;
std :: cout << "enter 1 if you want to check random generation\nenter 2 if you want to check function of street and flesh\nenter 3 if you want to check function of street\n"; 
std :: cin >> x;
begin(x);

}