#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data =  data;
        next = NULL;
    }
};

struct LinkedList{
    Node* head;
    LinkedList(){
        head = NULL;
    }

    int length(){
        int len = 0;
        Node* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }

    void push_front(int data){
        Node* n = new Node(data);
        n->next = head;
        head = n;
    }

    void push_back(int data){
        Node* n = new Node(data);
        if(head==NULL){
            head = n;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    int search_pos(int data){
        int pos = 0;
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data==data){
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    Node* get_list_ptr(int data){
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data==data){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void insert_after(Node* prev, int data){
        Node* temp = head;
        Node* n = new Node(data);
        while(temp!=NULL){
            if(temp==prev){
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        }
    }

    /*
        Always think of 3 things while removing a node from Linked List : 
            1. Deleting middle element : Let the selected element be curr and have prev and attach curr->next to prev->next before deleting the node
            2. Deleting first element : head = head->next and delete the character.
            3. Deleting last element : last element contains NULL in it's next of the node. Have a prev pointer to make prev->next as NULL
    */

    void remove(int data){
        if(head==NULL){
           cout << "Empty List, Illegal Delete Attempted!!" << endl;
            return;
        }
        else if(head->data==data){
           Node* temp = head;
           head = head->next;
           delete(temp); 
        }
        else{//middle or last or no element at all
            Node* curr = head;
            Node* prev = NULL;
            while(curr->next!=NULL){
                if(curr->data==data){
                    prev->next = curr->next;
                    delete(curr);
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
            if(curr->data==data){//last
                prev->next = NULL;
                delete(curr);
            }
            else{ // no element
                cout << "Element " << data << " not found in the list" << endl;
            }
        }
    }

    void print(){
        cout << "Linked List : ";
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clear(){
        while(head!=NULL){
            Node* temp = head;
            head = head->next;
            delete(temp);
        }
    }

    void print_reverse_util(Node* head){
        if(head==NULL){
            return;
        }
        print_reverse_util(head->next);
        cout << head->data << " ";
    }

    void print_reverse(){
        cout << "Linked List in reverse : ";
        this->print_reverse_util(this->head);
        cout << endl;
    }

    void reverse_list(){
        Node* prev=NULL, *curr = head, *nxt = NULL;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next=prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }

    void reverse(){
        this->reverse_util(this->head);
    }

    Node* reverse_util(Node* curr){
        if(curr==NULL){
            return NULL;
        }
        else if(curr->next==NULL){
            head = curr;
            return curr;
        }
        Node* nxt = reverse_util(curr->next);
        nxt->next = curr;
        curr->next = NULL;
        return curr;
    }
};


int main(){
    LinkedList l1;
    int x;
    while(cin >> x && x>=0){
        l1.push_back(x);
    }
    l1.print();
    cout << "Value to delete : ";
    int de;
    cin >> de;
    l1.remove(de);
    l1.print();
    cout << "Insert data : ";
    int ins;
    cin >> ins;
    cout << "after value : ";
    int val;
    cin >> val;
    l1.insert_after(l1.get_list_ptr(val), ins);
    l1.print();
    l1.reverse();
    l1.print();
    cout << "Lenght of the list : " << l1.length() << endl;
    l1.print_reverse();
    l1.clear();
    cout << "Lenght of the list : " << l1.length() << endl;
    return 0;
}