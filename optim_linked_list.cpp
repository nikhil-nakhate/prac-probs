#include <bits/stdc++.h>

using namespace std;
class LinkedListNode{
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val){
    if(head == NULL) {
        head = new LinkedListNode(val);
        tail = head;
    }
    else {
        LinkedListNode *node = new LinkedListNode(val);
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    LinkedListNode* res;
    
    int _head_size = 0;
    int _head_item;
    LinkedListNode* _head = NULL;
    LinkedListNode* _head_tail = NULL;
    cin >> _head_size;
    int _head_i;
    for(_head_i = 0; _head_i < _head_size; _head_i++) { 
        cin >> _head_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
      if(_head_i == 0) {
      	_head = _insert_node_into_singlylinkedlist(_head, _head_tail, _head_item);
      	_head_tail = _head;
    	}
      else {
  	    _head_tail = _insert_node_into_singlylinkedlist(_head, _head_tail, _head_item);
      }
    }
    
    res = optimal(_head);
    while (res != NULL) {
        fout << res->val << endl;
    	    
        res = res->next;
    }
    
    fout.close();
    return 0;
}


LinkedListNode* optimal(LinkedListNode* head) {


}

LinkedListNode* optimal(LinkedListNode* head) {
  int memo[101] = {};
  LinkedListNode * result_head = NULL;
  LinkedListNode * result_tail = NULL;
  
  if(head == NULL) return NULL;
  
  result_tail  = _insert_node_into_singlylinkedlist(result_head, result_tail, head->val);
  memo[head->val] = 1;
 // cout<<"debug: "<<head->val<<endl;
  
  LinkedListNode *iter = head->next;
  
  while(iter != NULL) {
      //cout<<"iter="<<iter->val<<endl;
      int val = iter->val;
     
      if(memo[val] == 0) {
          //Add val to result list
          result_tail  = _insert_node_into_singlylinkedlist(result_head, result_tail, iter->val);
          //cout<<"debug: "<<val<<endl;
          memo[val] = 1;
      }
      
      iter = iter->next;
  }

  return result_head;
}