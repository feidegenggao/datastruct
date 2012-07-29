#include 	"link_list.h"

int main()
{
	link_list* testlink = new link_list();

	testlink->insert_node(0, 1);
	testlink->insert_node(1, 2);
	testlink->insert_node(2, 3);

	testlink->printElem();
	
	Elemtype temp_elem;
	testlink->delete_node(0, temp_elem);
	testlink->delete_node(1, temp_elem);
	testlink->delete_node(2, temp_elem);
	testlink->delete_node(3, temp_elem);

	testlink->printElem();

	return 0;
}
