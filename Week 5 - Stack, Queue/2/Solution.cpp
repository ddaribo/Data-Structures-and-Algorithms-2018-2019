#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//Mai tryabva output-a da e reverse-nat
struct StackElement {
    int data;
    StackElement* next;
};
struct LinkedStack
{
    StackElement* top;

    LinkedStack()
    {
        top = nullptr;
    }

    void push(int x) {
        StackElement* p = new StackElement;
        p->data = x;
        p->next = top;
        top = p;
    }
    bool empty()
    {
        return top == nullptr;
    }

    int pop() {
        if (empty())
        {
            return -1;
        }

        StackElement* p = top;
        top = top->next;
        int x = p->data;
        delete p;
        return x;
    }

    void reverse()
    {
        StackElement *prev, *curr, *succ;
        prev = top;
        curr = prev->next;
        prev->next = nullptr;
        while (curr != nullptr)
        {
            succ = curr->next;
            curr->next = prev;
            prev = curr;
            curr = succ;
        }
        top = prev;
    }
};




int main() {
    int n;
    cin >> n;
    string command = "";
    int num;

    LinkedStack stones;
    int size = 0;

    while (n > 0)
    {
        cin >> command;
        cin >> num;

        if (command == "white")
        {
            stones.push(num);
            size++;
        }
        else if (command == "green")
        {
            long sum = 0;
            while (num > 0)
            {
                sum += stones.pop();
                size--;
                num--;
            }
            size++;
            stones.push(sum);
        }
        else if (command == "blue")
        {
            int max = stones.pop();
            size--;
            num--;
            while (num > 0)
            {
                int curr = stones.pop();
                size--;
                if (curr > max)
                {
                    max = curr;
                }
                num--;
            }
            stones.push(max);
            size++;
        }
        n--;
    }

    stones.reverse();

    for (int i = 0; i < size; i++)
    {
        int curr = stones.pop();
        cout << curr << " ";
    }

    return 0;
}
