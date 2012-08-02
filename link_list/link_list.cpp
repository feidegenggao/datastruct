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
    //insert e before the i'th elem, i between 0 to listlent + 1
	if ((i < 0) || (i > listlength + 1))
	{
		std::cerr<<"i is illegal"<<std::endl;
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
    //delete the i'th elem
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

Status link_list::getElem(int loc, Elemtype& elm)
{
    if ((loc <= 0) || (loc > listlength))
    {
        cerr<<"loc is illegal"<<endl;
        return ERROR;
    }

    node* p = header;
    while (loc > 0)
    {
        loc--;
        p = p->next;
    }
    elm = p->data;
    return SUCCESS;
}

void link_list::sort(void)
{
    int cycle = listlength;
    for (; cycle > 0; cycle--)
    {
        node* maxpointer = header->next;
        node* p = header;

        for (int incycle = cycle; incycle > 0; incycle--)
        {
            p = p->next;
            if ( p->data > maxpointer->data)
            {
                maxpointer = p;
            }
        }

        cout<<"***********************sort-start*******************************"<<endl;
        cout<<"p->data:"<<p->data<<"\tmaxpointer->data:"<<maxpointer->data<<endl;
        cout<<"<<<<<<<<<<<<<<<>>>>>>>>>>>>>"<<endl;
        printElem();

        Elemtype temp = maxpointer->data;
        maxpointer->data = p->data;
        p->data = temp;

        printElem();
        cout<<"***********************sort-end*******************************"<<endl;
    }
    cout<<"+++++++++++++++++++++++++++++"<<endl;
    printElem();
}

link_list* link_list::unionlist(link_list* secondlist)
{
    //union this list and secondlist, the result is this list become biger,
    //and some elem is the elem of secondlist

    node* pfir = header->next;
    node* psec = secondlist->getHeader()->next;

    int n = listlength;
    while (n > 1)
    {
        pfir = pfir->next;
        n--;
    }
    pfir->next = psec;
    listlength += secondlist->getlength();
    cout<<"UNION"<<endl;
    printElem();

    sort();

    return this;
}
