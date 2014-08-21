#ifndef _TBASE_H
#define _TBASE_H

#include "Locat.h"
#include "Ticket.h"

class TheaterBase
{
	private:
		int Row;
		int Col;

		int Od_p;
		int Ev_p;

		int price;

		char *name;

		Locat **_map;

		Ticket ticket;

	public:
		TheaterBase(int Row,int Col,int Od_p,int Ev_p);
		Locat findSeat(int p_num, int start);
		Ticket sellTicket(int p_num, int price, char *name);
};

#endif
