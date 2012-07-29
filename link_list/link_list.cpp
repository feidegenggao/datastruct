#include 	"link_list.h"

link_list::link_list()
{
	listlength = 0;
	header = new LNode();
}

link_list::~link_list()
{
	node* p = header->next;

	while(p)
	{
		node* temp = p->next;
		delete p;
		p = temp;
	}
}

Status link_list::insert_node(int i, Elemtype e)
{
	if (i > listlength)
	{
		std::cerr<<"i is greater than listlength"<<std::endl;
		return ERROR;
	}
	else
	{
		node* p = header;
		while ( i > 1)
		{
			p = p->next;
			i--;
		}
		node* new_node = new LNode(e, p->next);
		p->next = new_node;
		listlength++;
		return SUCCESS;
	}
}

Status link_list::delete_node(int i, Elemtype& e)
{
	if ((i <= 0) || (i > listlength))
	{
		std::cerr<<"i is greater than listlength OR i is invaild"<<std::endl;
		return ERROR;
	}
	else
	{
		node* p = header;
		while ( i > 1)
		{
			p = p->next;
			i--;
		}
		node* temp = p->next;
		p->next = p->next->next;
		listlength--;
		e = temp->data;
		delete temp;

		return SUCCESS;
	}
}

void link_list::printElem()
{
	node* p = header->next;
	int loc = 1;
	while(p)
	{
		std::cout<<"The "<<loc<<" elem is "<<p->data<<std::endl; 
		p = p->next;
		loc++;
	}
}
