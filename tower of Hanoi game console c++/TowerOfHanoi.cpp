#include "toh.h"
#include <ctime>
#include <iostream>
#include<Windows.h>

using namespace std;
/*
    The towers of Hanoi problem involves moving a number of disks (in different
   sizes) from one tower (or called “peg”) to another. GIVEN: Assume there are
   three towers available. a set of discs on the first pole, discs of different
   sizes, the smallest discs at the top GOAL: move all the discs from the left
   pole to the right one. CONDITIONS: Only one disk can be moved at each time.
    A disc can be placed either on an empty pole or on top of a larger disc.
   The constraint is that the larger disk can never be placed on top of a
   smaller disk. Add timer to the game You can use numbers in place of disks
*/
struct node1 {
  int Disk1;
  node1 *next1;
};
node1 *top1 = NULL;
int TowerLength = 3;

struct node2 {
  int Disk2;
  node2 *next2;
};
node2 *top2 = NULL;


struct node3 {
  int Disk3;
  node3 *next3;
};
node3 *top3 = NULL;


void push1(int data) {
  node1 *newnode1 = new node1;
  newnode1->Disk1 = data;
  newnode1->next1 = NULL;
  if (top1 == NULL) {
    top1 = newnode1;
  } else {
    newnode1->next1 = top1;
    top1 = newnode1;
  }
}
int pop1() {
  if (top1 != NULL) {
    node1 *p1 = top1;
    top1 = top1->next1;
    return (p1->Disk1);
    delete (p1);
  }
  return NULL;
}
void push2(int data) {
  node2 *newnode2 = new node2;
  newnode2->Disk2 = data;
  newnode2->next2 = NULL;
  if (top2 == NULL) {
    top2 = newnode2;
  } else {
    newnode2->next2 = top2;
    top2 = newnode2;
  }
}
int pop2() {
  if (top2 != NULL) {
    node2 *p2 = top2;
    int a = p2->Disk2;
    top2 = top2->next2;
    delete (p2);
    return a;
  }
  return NULL;
}

void push3(int data) {
  node3 *newnode3 = new node3;
  newnode3->Disk3 = data;
  newnode3->next3 = NULL;
  if (top3 == NULL) {
    top3 = newnode3;
  } else {
    newnode3->next3 = top3;
    top3 = newnode3;
  }
}
int pop3() {
  if (top3 != NULL) {
    node3 *p3 = top3;
    top3 = top3->next3;
    return (p3->Disk3);
    delete (p3);
  }
  return NULL;
}

void display1() {
  cout << endl;
  node1 *p1 = top1;
  cout << "TOWER1-> "
       << "\t";
  if (p1 == NULL) {
    for (int i = 0; i < TowerLength; i++)
      std::cout << "_ \t";
  }
  while (p1 != NULL) {
    cout << p1->Disk1 << "\t";
    p1 = p1->next1;
  }
  cout << endl;
}
void display2() {
  node2 *p2;
  p2 = top2;
  cout << "TOWER2-> "
       << "\t";
  if (p2 == NULL) {
    for (int i = 0; i < TowerLength; i++)
      std::cout << "_ \t";
  }
  while (p2 != NULL) {
    cout << p2->Disk2 << "\t";
    p2 = p2->next2;
  }
  cout << endl;
}
void display3() {
  node3 *p3;
  p3 = top3;
  cout << "TOWER3-> "
       << "\t";
  if (p3 == NULL) {
    for (int i = 0; i < TowerLength; i++)
      std::cout << "_ \t";
  }
  while (p3 != NULL) {
    cout << p3->Disk3 << "\t";
    p3 = p3->next3;
  }
  cout << endl;
  cout << endl;
}
/*CHECK IF MOVED DISK IS LESS THAN THE PREVIOUS DISK IN THE TOWER*/
bool isLess1(node1 *b, int movedDisk) {
  if (b->Disk1 >= movedDisk)
    return true;
  else
    return false;
}
bool isLess2(node2 *b, int movedDisk) {
  if (b->Disk2 >= movedDisk)
    return true;
  else
    return false;
}
bool isLess3(struct node3 *b, int movedDisk) {
  if (b->Disk3 >= movedDisk)
    return true;
  else
    return false;
}
// End of comparison

void toTower1(struct arg *move) {
  // OK
  node2 *s2 = top2;
  s2 = (node2 *)move;
  if (top2 == s2 && top2 != NULL) {
    if (top1 == NULL) {
      push1(pop2());
    } else if (isLess1(top1, top2->Disk2)) {
      push1(pop2());
    }
  }
  // OK
  node3 *s3 = top3;
  s3 = (node3 *)move;
  if (top3 == s3 && top3 != NULL) {
    if (top1 == NULL) {
      push1(pop3());
    } else if (isLess1(top1, top3->Disk3)) {
      push1(pop3());
    }
  }
}
void toTower2(struct arg *move) {
  // OK
  node1 *s1 = top1;
  s1 = (node1 *)move;
  if (top1 == s1 && top1 != NULL) {
    if (top2 == NULL) {
      push2(pop1());
    } else if (isLess2(top2, top1->Disk1)) {
      push2(pop1());
    }
  }
  // OK
  node3 *s3 = top3;
  s3 = (node3 *)move;
  if (top3 == s3 && top3 != NULL) {
    if (top2 == NULL) {
      push2(pop3());
    } else if (isLess2(top2, top3->Disk3)) {
      push2(pop3());
    }
  }
}
void toTower3(struct arg *move) {
  // OK
  node1 *s1 = top1;
  s1 = (node1 *)move;
  if (top1 == s1 && top1 != NULL) {
    if (top3 == NULL) {
      push3(pop1());
    } else if (isLess3(top3, top1->Disk1)) {
      push3(pop1());
    }
  }
  // OK
  node2 *s2 = top2;
  s2 = (node2 *)move;
  if (top2 == s2 && top2 != NULL) {
    if (top3 == NULL) {
      push3(pop2());
    } else if (isLess3(top3, top2->Disk2)) {
      push3(pop2());
    }
  }
}

void generateGame(int sz);
void playTheGame() {

  generateGame(3);
  system("cls");
    HANDLE console_color;
  console_color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(console_color, 15);
  ascii_art("Towers of Hanoi");
  cout << "\t\t";
  std::cout << " \t Play the game and be the winner\n"
            << "\t Initially you have this disk Values. then move them to "
               "Tower 3 as they are listed here. \n"
            << "\t they listed left to right as top bottom respectively"
            << std::endl;
  display1();
  display2();
  display3();
  std::cout << "\t Do you wanna play?  Y/N" << std::endl;
  char ch;
  ch = getch();
  if (ch == 'Y' || ch == 'y') {
    system("cls");
    std::cout << "Here is instruction to play the game: \n"
                 "step1. choose tower to move from \n"
                 "step2. choose where to move the disk"
              << std::endl;
    std::cout << "MISSION: move the values in TOWER1 to "
                 "TOWER3 as they are listed in TOWER1."
              << std::endl;
    std::cout << "\t\t how many disk do you wanna play? for defualt press N else Y"
              << std::endl;
    char ch = getch();
    if (ch == 'Y' || ch == 'y') {
      std::cout << "how many disk do you wanna play? \n Enter num" << std::endl;
      int sz;
      cin >> sz;
      generateGame(sz);
    }
    std::cout << "\t\t\t START THE GAME NOW\n\n" << std::endl;

    system("pause");
    char c;
    int TurnCounter = 0;
    std::clock_t start;
    double duration;
    start = std::clock();
    while (c != '7') {
      if (top1 == NULL && top2 == NULL) {
        system("cls");
        cout << endl;
         system("color 09");
        ascii_art("you win the game!!");
        display1();
        display2();
        display3();
        duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
        std::cout << "you took " << duration << "seconds" << std::endl;
        std::cout << "you finished it in " << TurnCounter << " turns"
                  << std::endl;
        system("pause");
        break;
      }
      system("cls");
        system("color 09");
      std::cout << "1. Move from TOWER_1 to TOWER_2 \n"
                   "2. Move from TOWER_1 to TOWER_3 \n"
                   "3. Move from TOWER_2 to TOWER_1 \n"
                   "4. Move from TOWER_2 to TOWER_3 \n"
                   "5. Move from TOWER_3 to TOWER_1 \n"
                   "6. Move from TOWER_3 to TOWER_2 \n"
                   "7. to exit \n"
                << std::endl;
      display1();
      display2();
      display3();
      c = getch();
      switch (c) {
      case '1':
        toTower2((arg *)top1);
        break;
      case '2':
        toTower3((arg *)top1);
        break;
      case '3':
        toTower1((arg *)top2);
        break;
      case '4':
        toTower3((arg *)top2);
        break;
      case '5':
        toTower1((arg *)top3);
        break;
      case '6':
        toTower2((arg *)top3);
        break;
      case '7':
        break;
      default:
        break;
      }
      TurnCounter++;
    }
  }
}
void finaly() {
  system("color 0A");
  ascii_art("thank you very much");
}
void generateGame(int sz) {
  TowerLength=sz;
  int n = 100;
  pop1(); pop1(); pop1();
  for (int i = 0; i < sz; i++) {
    push1(n);
    if (sz > 5) {
      n = n - 10;
    } else
      n = n - 20;
  }
}
int main() {
  playTheGame();
  finaly();
  return 0;
}
