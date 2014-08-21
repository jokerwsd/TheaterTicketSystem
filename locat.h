#ifndef _LOCAT_H
#define _LOCAT_H

class Locat
{		
	public:
		int row;
		int col;
		bool flag;//false means there is a post not a seat

		Locat();

		Locat(int Row,int Col,bool Flag);// This function could return 
		//either in the location is seat or post
};

#endif