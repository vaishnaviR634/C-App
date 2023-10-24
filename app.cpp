#include <string>
int now() {
  return std::chrono::system_clock::now().time_since_epoch() /
         std::chrono::microseconds(1);
}
/*While creating a new node, to get the timestamp use now() function.*/


/*Linked list node stores variables data, timestamp and pointer to next node */
struct LinkedListNode {
  std::string data;
  int timestamp;
  LinkedListNode *next;
};

/*Some of the function signatures which can be used to implement various functions of browser history.
You may or may not use these exact same functions*/

/*Inserts new node with given data after index idx linked list*/
void insert(LinkedListNode **head, int idx, std::string data) {}

/*Delete the node of the linked list which has data matching the given data*/
LinkedListNode *delete_node(LinkedListNode **head, std::string data) {}


/*Browser history:
Creates a new head pointer (which will point to a new linked list)
Each structure variable of BrowserHistory will represent a new browser.
When a url is visted, create a new node corresponding to it in the linked list.
Each node stores url (data), time of visit (timestamp) and 
pointer to the next node (previously visited url in this case) */
struct BrowserHistory {
  LinkedListNode *head;
  LinkedListNode *tail;
  int size;
};



/*This function takes the url of a tab and adds it to the browser history (front of the linked list)
Since a url can only occur once (with the latest timestamp) in the browser history,
its previous occurence (if any) must be deleted*/
void visit_tab(BrowserHistory *bh, std::string url);


/*Two linked lists (corresponding to two browser histories) are given. 
They must be synced (merged into one linked lists) keeping in mind the order of timestamps.
DO NOT change the original linked lists while doing so. */
BrowserHistory* sync_browser(BrowserHistory *bh1, BrowserHistory *bh2);

/*Given a url (keyword), the browser history element (node of the linked list) with that url
 has to be deleted*/ 
void delete_history(BrowserHistory *bh, std::string keyword);

/*Go_back: Visits the second latest (2nd node)
 element of browser history (use visit_tab function)*/
void visit_last_tab(BrowserHistory *bh);

