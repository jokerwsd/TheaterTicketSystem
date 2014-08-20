#include <iostream>
#include <vector>

#include "Seat.h"
#include "locat.h"
#include "Post.h"

TheaterBase::TheaterBase(int row,int col, int od_p, int ev_p)
{
	Row = row;
	Col = col;

	Od_p = od_p;
	Ev_p = ev_p;

	map = new Locat*[Row];//Creating 2D array to store the seat information
//if it's a post, mark as false

	for(int i=0;i<Row;i++)
	{
		map[i] = new Locat[Col];
		if(i%2 == 0)
		{
			int j = 1;
			while(j<Col)
			{
				map[i][j].flag = false;
				for(int count = 0; count<Od_p; count++)
				{
					map[i][j+count].flag = true;
				}
			}
		}
		else
		{
			int j = 1;
			while(j<Col)
			{
				map[i][j]->flag = false;
				for(int count = 0; count<Ev_p; count++)
				{
					map[i][j+count].flag = true;
				}
			}
		}
	}
}

Locat TheaterBase::findSeat(int n, int curr)
{
	if(n == Od_p)
	{
		curr = 1;
		for(int i=1; i<Col; i++)
		{
			if(map[curr][i].flag == true)
			{
				map[curr][i].flag == false;
				return map[curr][i];
			}
		}
		curr = curr + 2;

	}
	if(n == Ev_p)
	{
		curr = 2
		for(int i=)

	}
}





















