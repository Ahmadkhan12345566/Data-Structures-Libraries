#ifdef linklist.h
#define linklsit.h
#endif // linklist

typedef int T;
namespace linklist {
	// Node
	struct node {
		T data;
		node* next;
	};


	void Add(node* head , T data) {
		node* p = new struct node;
		p->data = data;
		p->next = nullptr;
		node* q = head;
		while (q)
		{
			if (q->next == nullptr) {
				q->next = p;
			}
			else
			{
				q = q->next;
			}
		}

		
	
}