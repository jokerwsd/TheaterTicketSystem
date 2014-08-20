#ifndef _SEAT_H
#define _SEAT_H

#include "locat.h"

class Seat : public Locat
{
	public:
		int findRow(int curr_row);
		int findCol(int curr_col);
};

#endif