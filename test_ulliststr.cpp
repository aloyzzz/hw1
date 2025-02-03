#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr* list = new ULListStr();
    for(int i=0;i<50;i++)
    {
        string number = to_string(i);
        string test = "test "+number;
        cout<<"Pushing "<<test<<endl;
        list->push_back(test);
    }
    // for(int i=0;i<50;i++)
    // {
    //     list->pop_front();
    //     if(i%10==0)
    //     {
    //         cout<<list->front()<<endl;
    //         cout<<list->get(11)<<endl;
    //         cout<<list->get(10)<<endl;
    //         cout<<list->get(9)<<endl;
    //         cout<<list->get(8)<<endl;

    //     }
    // }
    for(int i=49;i>=0;i--)
    {
        string number = to_string(i);
        string test = "test "+number;
        cout<<"Pushing "<<test<<endl;
        list->pop_front();
        cout<<list->get(11)<<endl;
        // cout<<list->get(21)<<endl;
    }

    // for(int i=0;i<7;i++)
    // {
    //     cout<<list->back()<<endl;
    //     list->pop_back();
    // }
    // cout<<list->size()<<endl;
    // for(int i=0;i<13;i++)
    // {
    //     cout<<list->back()<<endl;
    //     list->pop_back();
    // }
    // list->push_back("a");
    cout<<list->get(9)<<endl;
    // cout<<list->get(1)<<endl;
    // cout<<list->get(2)<<endl;
    cout<<list->size()<<endl;


}
