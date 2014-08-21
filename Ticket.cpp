#include <iostream>
#include <fstream>

#include "Ticket.h"
#include "Locat.h"

using namespace std;

Ticket::Ticket()
{}

Ticket::Ticket(int price, char *name,const Locat &seat)
{
	Price = price;
	Name = name;
	Seat = seat;
}

void Ticket::printTicket()
{
	cout<<"##########-Ticket for "<<this->Name<<"##########"<<endl;
	cout<<"Price: "<<this->Price<<endl;

	cout<<"Your Seat is Row "<<this->Seat.row<<" : Col "<<this->Seat.col<<endl;
	cout<<"Enjoy your time!"<<endl;

	ofstream ticket ("ticket.txt");
	if(ticket.is_open())
	{
		ticket << "##########-Ticket for "<<this->Name<<"##########\n";
		ticket << "Price: "<<this->Price<<"\n";
		ticket << "Your Seat is Row "<<this->Seat.row<<" : Col "<<this->Seat.col<<"\n";
		ticket << "Enjoy your time!\n";
	}
	ticket.close();
}