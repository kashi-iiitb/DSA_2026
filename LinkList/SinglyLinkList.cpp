#include<iostream>

class sll_node{
  private:
    int data;
    sll_node *next;
  public:
    sll_node(int val){
      data = val;
      next = nullptr;
    }
    sll_node* get_next(){
      return next;
    }
    void set_next(sll_node *ptr){
      next = ptr;
    }
    int get_data(){
      return data;
    }
    void set_data(int val){
      data = val;
    }
};

class LList{
  private:
    sll_node *head;
    //sll_node *tail;
  public:
    LList(){
      head = nullptr;
    }
    void add(int val){
      if(head == nullptr){
        head = new sll_node(val);
        return;
      } else{
        sll_node *tmp = head;
        while(tmp->get_next()){
          tmp = tmp->get_next();
        }
        tmp->set_next(new sll_node(val));
      }
    } //end of add()
    void display_elems(){
      if(head == nullptr){
        std::cout << "Empty List!!\n";
        return;
      }
      sll_node *tmp = head;
      while(tmp){
        std::cout << tmp->get_data() << "\n";
        tmp = tmp->get_next();
      }
    }
    void push_front(int val){
      if(head == nullptr){
        head = new sll_node(val);
        return;
      } else{
        sll_node *tmp = new sll_node(val);
        tmp->set_next(head);
        head = tmp;
      }
    }
    void clear(){
      sll_node *tmp = head;
      while(tmp){
        head = tmp->get_next();
        free(tmp);
        tmp = head;
      }
    }
    //destructor
    /*~LList(){
      clear();
    }*/
    //copy constructor
    //copy assignment operator
};

int main(){
  LList l1;
  l1.add(10);
  l1.add(20);
  l1.add(30);
  l1.add(40);
  l1.add(50);
  l1.add(60);
  l1.push_front(100);
  l1.push_front(200);
  l1.display_elems();
  l1.clear();
  l1.display_elems();
}