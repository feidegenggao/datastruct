#include 	"link_list.h"

int main()
{
	link_list* testlink = new link_list();
    link_list* firstlink = new link_list();
    link_list* secondlink = new link_list();

    int i;
    for (i = 0; i < 6; i++)
        testlink->insert_node(i, i+1);

	testlink->printElem();
    testlink->sort();
	testlink->printElem();

    cout<<"BEFORE UNION,first:"<<endl;
    for (i = 0; i < 6; i += 2)
        firstlink->insert_node(firstlink->getlength(), i+1);

    firstlink->printElem();

    cout<<"BEFORE UNION,second:"<<endl;
    for (i = 0; i < 6; i += 2)
        secondlink->insert_node(secondlink->getlength(), i+8);

    secondlink->printElem();

    firstlink->unionlist(secondlink);
    cout<<"AFTER UNION"<<endl;
    firstlink->printElem();


    Elemtype getelm;
    if (SUCCESS == testlink->getElem(2, getelm))
        cout<<"2's elm:"<<getelm<<endl;
    if (SUCCESS == testlink->getElem(4, getelm))
        cout<<"4's elm:"<<getelm<<endl;

	testlink->printElem();
	
	Elemtype temp_elem;
	testlink->delete_node(0, temp_elem);
	testlink->delete_node(1, temp_elem);
	testlink->delete_node(2, temp_elem);
	testlink->delete_node(3, temp_elem);

	testlink->printElem();

	return 0;
}
