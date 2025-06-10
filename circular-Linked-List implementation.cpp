#include<iostream>
#include<limits>
class Node{
    public:
        int key;
        int data;
        Node* next;
        Node(){
            key = 0;
            data = 0;
            next  = nullptr;
        }
        Node(int k, int d){
            key = k;
            data = d;
            next = nullptr; 
        }
};
class circularLinkedList{
    public:
        int count;
        Node* head;
        circularLinkedList(){
            head = nullptr;
            count = 0;
        }
        circularLinkedList(Node* n){
            head = n;
            n->next = nullptr;
            count = 1;
        }
        ~circularLinkedList(){
            Node*  temp;
            while(count>0){
                temp = head;
                head = head->next;
                delete temp;
                count--;
            }
        }
        Node* keyExist(int k){
            Node* temp = head;
            Node* found = nullptr;
            if(head == nullptr){
                return found;
            }
            do{
                if(temp->key == k){
                    found = temp;
                    break;
                }
                temp = temp->next; 
            }while(temp!=head);
            return found;
        }
        bool isEmpty(){
            return head == nullptr;
        }
        void append(Node* n){
            if(keyExist(n->key)!=nullptr){
                std::cout<< "the key node already exist in the list"<<std::endl;
                return;
            }
            if(isEmpty()){
                head = n;
                n->next = head;
            }
            else{
                Node* temp = head;
                while(temp->next!=head){
                    temp = temp->next;
                }
                temp->next = n;
                n->next = head;
            }
            count++;
        }
        void prepend(Node* n){
            if(keyExist(n->key)!=nullptr){
                std::cout<< "The key node already exist in the list"<<std::endl;
                return;
            }
            if(isEmpty()){
                head = n;
                n->next = head;
            }
            else{
                Node* temp = head;
                while(temp->next!=head){
                    temp = temp->next;
                }
                n->next = head;
                head = n;
                temp->next = head;
            }
            count++;
        }
        void insertAfterKey(int k, Node* n){
            if(keyExist(n->key)!=nullptr){
                std::cout<< "The key node already exist in the list"<<std::endl;
                return;
            }
            Node* current = keyExist(k);
            if(current==nullptr){
                std::cout<< "The node key you are looking for doesnt exist in the list"<<std::endl;
            }
            else{
                if(current->next == head){
                    current->next = n;
                    n->next = head;
                }
                else{
                    n->next = current->next;
                    current->next = n;
                }
                count++;
            }
        }
        void deleteKey(int k){
            Node* current = keyExist(k);
            if(current == nullptr){
                std::cout<< "The key node you are looking for drosnt exist in the list"<<std::endl;
                return;
            }
            Node* tail = head;
            Node* prev = nullptr;
            while(tail->next!=head){
                prev = tail;
                tail = tail->next;
            }
            if(current == head){
                head = head->next;
                tail->next = head;
            }
            else if(current->next == head){
                prev->next = head;
            }
            else{
                prev = head;
                while(prev->next!=current){
                    prev = prev->next;
                }
                prev->next = current->next;
            }
            delete current;
            count--;
        }
        void update(int k, int d2){
            Node* temp = keyExist(k);
            if(temp== nullptr){
                std::cout<< "The node you are looking for doesnt exist"<<std::endl;
            }
            else{
                temp->data = d2;
            }
        }
        int Count(){
            return count;
        }
        void display(){
            Node* temp = head;
            std::cout<< "Head -->";
            do{
                std::cout<< " ("<<temp->key<< " , "<<temp->data<<" )-->";
                temp = temp->next;
            }while(temp!=head);
            std::cout<< " Head"<<std::endl;
        }
        void reverse(){
            int size = count;
            Node*  temp = head;
            Node* rev = head;
            int tem;
            if(isEmpty()){
                std::cout<< "The list is empty"<<std::endl;
                return;
            }
            else{
                while(size!= count/2){
                    for(int i=1;i<size;i++){
                        rev = rev->next;
                    }
                    tem = temp->data;
                    temp->data = rev->data;
                    rev->data = tem;
                    tem = temp->key;
                    temp->key = rev->key;
                    rev->key = tem;
                    rev = head;
                    temp = temp->next;
                    size--;
                }
            }
        }
        void sort(){
            if(isEmpty()){
                std::cout<< "The list is empty"<<std::endl;
                return;
            }
            else{
                int temp;
                Node* current = head;
                Node* after = head;
                for(int i=1;i<=count;i++){
                    for(int j=i;j<=count;j++){
                        if(current->data>after->data){
                            temp = current->data;
                            current->data = after->data;
                            after->data = temp;
                            temp = current->key;
                            current->key = after->key;
                            after->key = temp;
                        }
                        after = after->next;
                    }
                    current = current->next;
                    after = current;
                }
            }
        }
        Node* findMiddle(){
            int size = count/2;
            Node*  temp = head;
            for(int i=1;i<=size;i++){
                temp = temp->next;
            }
            return temp;
        }
};
int valid(int num){
    while(true){
        std::cin>>num;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<< "Invalid input! please try again"<<std::endl;
        }
        else{
            return num;
        }
    }
}
int main(){
    circularLinkedList c;
    int op,k,d, key1,data1;
    bool leave = false;
    while(leave == false){
        std::cout<< "#####################operations##################"<<std::endl;
        std::cout<< "1.Does the node exist in the list?\n2.Is the list empty?\n3.Append a node\n4.Prepend a node\n5.Insert a node after a key\n6.Delete a key\n7.Update a node\n8.How many nodes are in the list?\n9.Display the list\n10.Reverse the list\n11.Sort the list\n12.Find the middle node\n13.Exit"<<std::endl;
        std::cout<< "Enter the numebr of the operation"<<std::endl;
        op = valid(op);
        while(op>13  || op<1){
            std::cout<<"Invalid number of opeartions! Please t4ry again"<<std::endl;
            op = valid(op);
        }
        Node* n = new Node();
        switch(op){
            case 1:
                std::cout<< "Enter the key you are looking for: ";
                key1 = valid(key1);
                n = c.keyExist(key1);
                if(n ==nullptr){
                    std::cout<< "The key doesnt exist in the list "<<std::endl;
                }
                else{
                    std::cout<< "( "<<n->key<< " , "<<n->data<<" )"<<std::endl;
                }
                break;
            case 2:
                std::cout<< "Is the list empty? "<<c.isEmpty()<<std::endl;
                 break;
            case 3:
                std::cout<< "Enter the key: ";
                k = valid(k);
                std::cout<< "Enter the data: ";
                data1 = valid(data1);
                n->key = k;
                n->data = data1;
                c.append(n);
                break;
            case 4:
                std::cout<< "Enter the key:";
                k = valid(k);
                std::cout<< "Enter the data: ";
                data1 = valid(data1);
                n->key = k;
                n->data = data1;
                c.prepend(n);
                break;
            case 5: 
                std::cout<< "Enter the key: ";
                k = valid(k);
                std::cout<< "Enter the data: ";
                data1 = valid(data1);
                n->key = k;
                n->data = data1;
                std::cout<< "Enetr the key you want to insert after:";
                key1 = valid(key1);
                c.insertAfterKey(key1,n);
                break;
            case 6:
                std::cout<< "Enter the key value of the node you want to delete:";
                key1= valid(key1);
                c.deleteKey(key1);
                break;
            case 7:
                std::cout<< "Enetr the key value of the node you want to update:";
                key1 = valid(key1);
                std::cout<< "Enter the new value of data:";
                data1 = valid(data1);
                c.update(key1 , data1);
                break;
            case 8:
                std::cout<<"There are "<<c.Count()<<" nodes in the list"<<std::endl;
                break;
            case 9:
                c.display();
                break;
            case 10:
                c.reverse();
                break;
            case 11:
                c.sort();
                break;
            case 12:
                n = c.findMiddle();
                if(n == nullptr){
                    std::cout<< "The list is empty"<<std::endl;
                }
                else{
                    std::cout<< "middle node: ("<<n->key << " , "<<n->data<<" )"<<std::endl;
                }
                break;
            case 13:
                leave = true;
                std::cout<< "Bye!"<<std::endl;
                break;
        }
    }
    return 0;
}