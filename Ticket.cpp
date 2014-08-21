#include <iostream>
#include <fstream>

#include "Ticket.h"
#include "Locat.h"

using namespace std;

Ticket::Ticket(int price, char *name, Locat seat)
{
	Price = price;
	Name = name;
	Seat = seat;
}

void Ticket::printTicket()
{
	cout<<"##########-Ticket for "<<this->name<<"##########"<<endl;
	cout<<"Price: "<<this->price<<endl;

	cout<<"Your Seat is Row "<<this->Seat.row<<" : Col "<<this->Seat.col<<endl;
	cout<<"Enjoy your time!"<<endl;

	ofstream ticket ("ticket.txt");
	if(ticket.is_open())
	{
		ticket << "##########-Ticket for "<<this->name<<"##########\n";
		ticket << "Price: "<<this->price<<"\n";
		ticket << "Your Seat is Row "<<this->Seat.row<<" : Col "<<this->Seat.col<<"\n";
		ticket << "Enjoy your time!\n";
	}
	ticket.close();
}