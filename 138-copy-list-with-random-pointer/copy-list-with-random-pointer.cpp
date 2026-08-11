/*
class Node {
public:
    int val;
    Node* next;
    Node* random;
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step 1 = create a deep copy without the random pointer
        Node* temp = head;
        Node* dummy = new Node(10);
        Node* tc = dummy;
        while(temp!=NULL){
            Node* a = new Node(temp->val);
            tc->next = a;
            tc = tc->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;
        // step 2 create alternate connection
        Node* a = head;
        Node* b = duplicate;
        dummy =new Node(1);
        Node* td = dummy;
        while(a){
            td->next = a;
            a = a->next;
            td = td->next;
            td->next = b;
            b = b->next;
            td = td->next;   
        }
        dummy = dummy->next;

        // assigning the random pointers

        Node* t1 = dummy;
        
        while(t1!=NULL){
            Node* t2 = t1->next;
            if(t1->random) t2->random = t1->random->next;
            t1 = t1->next->next;
        }
        //removing the connection
        Node* d1 = new Node(1);
        Node* d2 = new Node(2);
        t1 = d1;
        Node* t2 = d2;
        Node* t = dummy;
        while(t){
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;


    }
};