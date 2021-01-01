#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

/**
 *
 * TORTOISE AND HARE.
 * Detect cycle in a linked list. Algorithm returns node that starts the cycle and length
 * of the cycle.
 *
 * */

struct Node{
    int data;
    Node *next = nullptr;
};

pair<Node *, int> tortoise_and_hare(Node *head){
    Node *tortoise = head, *hare = head;
    bool loop = false;
    while(tortoise && hare && hare->next){
        hare = hare->next->next;
        tortoise = tortoise->next;
        if(tortoise == hare){
            loop = true;
            break;
        }
    }
    if(!loop) return {nullptr, 0}; // there is no loop
    tortoise = head;
    while(hare != tortoise){
        hare = hare->next;
        tortoise = tortoise->next;
    }
    int len = 1;
    hare = tortoise->next;
    while(hare != tortoise){
        hare = hare->next;
        len ++;
    }
    return {tortoise, len};
}