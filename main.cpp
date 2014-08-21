#include <iostream>
#include <fstream>

#include "TheaterBase.h"
#include "Ticket.h"
#include "Locat.h"

int main()
{
	TheaterBase myTheater(6,13,3,2);
	char *group1 = "Jack and Rose";
	myTheater.sellTicket(2,20,group1);

	return 0;
}