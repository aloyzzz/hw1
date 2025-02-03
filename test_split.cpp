/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include "iostream"
#include <ratio>
using namespace std;

void printList(Node* head) {
    while (head) {
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
    Node* prevnode;
    Node* basenode;
    for(int i=0;i<6;i++)
    {
        Node* in = new Node(i,nullptr);
        if(i!=0) prevnode->next = in;
        else basenode=in;
        prevnode = in;
    }
;

    Node* odds = nullptr;
    Node* evens = nullptr;

    // split evens and odds
    split(odds, odds, evens);

    // print
    std::cout << "Odds: ";
    printList(odds);

    std::cout << "Evens: ";
    printList(evens);

    // while (odds) {
    //     Node* temp = odds;
    //     odds = odds->next;
    //     delete temp;
    // }
    // while (evens) {
    //     Node* temp = evens;
    //     evens = evens->next;
    //     delete temp;
    // }
    
    // printList(evens);

}
