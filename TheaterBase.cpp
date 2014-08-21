#include <iostream>
#include <vector>

#include "TheaterBase"
#include "locat.h"
#include "Ticket.h"

TheaterBase::TheaterBase(int row,int col, int od_p, int ev_p)
{
	Row = row;
	Col = col;

	Od_p = od_p;
	Ev_p = ev_p;

	_map = new Locat*[Row];
/*Creating 2D array to store the seat information
if it's a post, mark the flag as false

The seat map may look like this when od_p = 2, ev_p = 3:

0:*111*111*111*
1:*11*11*11*11*
2:*111*111*111*
3:*11*11*11*11*
4:*111*111*111*
5:*11*11*11*11*

1 means it's seat
* means it's post
*/

	for(int i=0;i<Row;i++)
	{
		_map[i] = new Locat[Col];

			int j = 1;
			while(j<Col)
			{
				_map[i][j].flag = false;
				_map[i][j].row = i;
				_map[i][j].col = j;
				if(i%2 == 0)//Constructing the odd lines with seat and post information
				{
					for(int count = 1; count<=Od_p; count++)
					{
						_map[i][j+count].flag = true;
						_map[i][j+count].row = i;
						_map[i][j+count].col = j + count;
					}
				}
				else//constructing the even lines with seat and post information
				{
					for(int count = 0; count<Ev_p; count++)
					{
						_map[i][j+count].flag = true;
						_map[i][j+count].row = i;
						_map[i][j+count].col = j + count;
					}
				}
			}
		}		
	}
}

Locat TheaterBase::findSeat(int n, int curr)
{

	if(n == 0) return;

	if(n%Od_p == 0)//in order to find best matching seat
	{
		while(curr%2==0)
		{
			for(int i=1; i<Col; i++)
			{
				if(_map[curr][i].flag == true)
				{
					int count = 0;
					while(count < Od_p)
					{
						_map[curr][i+count].flag == false;
						Ticket ticket(price,*name,_map[curr][i]);
						ticket.printTicket();
					}
					n = n - Od_p;
					findSeat(n,curr);
					return _map[curr][i-count];					
				}
			}
			curr = curr + 2;
		}
		curr = curr + 1;
	}

	if(n%Ev_p == 0)
	{
		while(curr%2==1)
		{
			for(int i=1; i<Col; i++)
			{
				if(_map[curr][i].flag == true)
				{
					int count = 0;
					while(count < Ev_p)
					{
						_map[curr][i+count].flag == false;
						Ticket ticket(price,*name,_map[curr][i]);
						ticket.printTicket();
					}
					n = n - Ev_p;
					findSeat(n,curr);

					return _map[curr][i-count];					
				}
			}
			curr = curr + 2;
		}
		curr = curr + 1;
	}

	for(int i=1;i<col;i++)
	{
		if(_map[curr][i].flag == true)
		{
			_map[curr][i].flag == false;
			Ticket ticket(price,*name,_map[curr][i]);
			ticket.printTicket();
		}
		n--;
		findSeat(n,curr);
		return _map[curr][i];	
	}

}

Ticket TheaterBase::sellTicket(int p_num, int price, char *name)
{
		this->price = price;
		this->name = name;
		this.findSeat(p_num,1);
}



















