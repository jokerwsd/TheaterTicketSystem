#ifndef _TBASE_H
#define _TBASE_H

#include "Seat.h"
#include "Post.h"
#include "Ticket.h"

class TheaterBase
{
	private:
		int Row;
		int Col;

		int Od_p;
		int Ev_p;

		Locat **map;

		Seat seat;
		Post post;
		Ticket ticket;

	public:
		TheaterBase TheaterBase(int Row,int Col,int Od_p,int Ev_p);
		Locat findSeat(int p_num, int start);
		Ticket sellTicket(int p_num);
};

#endif
