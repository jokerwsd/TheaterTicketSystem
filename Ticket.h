#ifndef _TICKET_H
#define _TICKET_H


#include "Locat.h"

class Ticket
{
	private:
		int Price;
		char *Name;
		Locat Seat;


	public:
		Ticket();
		Ticket(int price, char *name,const Locat& seat);
		void printTicket();
		
};

#endif
