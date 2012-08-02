#include "../my.h"

typedef struct LNode
{
	LNode() { data = 0; next = NULL;}
	LNode(Elemtype e, LNode* other) { data = e; next = other;}

	Elemtype data;
	struct LNode* next;
}node, *LinkList;

class link_list
{
	public:
		link_list();
		~link_list();

		Status  insert_node(int, Elemtype);
		Status	delete_node(int, Elemtype&);
		void 	printElem(void);
        Status  getElem(int, Elemtype&);
        void    sort(void);
        link_list* unionlist(link_list*);
        LinkList getHeader(void) { return header;}
		int 	getlength(void){ return listlength;}

	private:
		LinkList 	header;
		int 	listlength;
};
