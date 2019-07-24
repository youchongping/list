#include "user_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv)
{
	ElementType e;
	user_list_init();

	memset(&e,0,sizeof(e));
	memcpy(e.thingname,"maxwell",strlen("maxwell"));
	list_fun.insert_to_list_tail(list,e);
	list_fun.traverse_list(list);

	memset(&e,0,sizeof(e));
	memcpy(e.thingname,"liuyifei",strlen("liuyifei"));
	list_fun.insert_to_list_tail(list,e);
	list_fun.traverse_list(list);
	

	return 0;
	
}
