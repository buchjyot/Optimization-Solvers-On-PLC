/*
 *	This file is part of qpOASES.
 *
 *	qpOASES -- An Implementation of the Online Active Set Strategy.
 *	Copyright (C) 2007-2014 by Hans Joachim Ferreau, Andreas Potschka,
 *	Christian Kirches et al. All rights reserved.
 *
 *	qpOASES is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation; either
 *	version 2.1 of the License, or (at your option) any later version.
 *
 *	qpOASES is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *	See the GNU Lesser General Public License for more details.
 *
 *	You should have received a copy of the GNU Lesser General Public
 *	License along with qpOASES; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


/**
 *	\file examples/example1.c
 *	\author Hans Joachim Ferreau
 *	\version 3.0embedded
 *	\date 2007-2014
 *
 *	Very simple example for testing qpOASES (using QProblem class).
 */


#include "qpOASES.h"


/** Example for qpOASES main function using the QProblem class. */
int main( )
{
	USING_NAMESPACE_QPOASES

		
	const int z=50;//no of variables
	int nWSR;
	int i=2,n,p,t=1;
	static Options options;
	static QProblemB example;
	
	real_t xOpt[100];
	real_t yOpt[100+1];
	
	real_t H[100*100];
	real_t g[100];
	real_t lb[100];
	real_t ub[100];

	n=z; // n is no of variables
	/* Setup data of first QP. */
	if (n==2)
	{
		H[0]=202;
		H[1]=-200;
		H[2]=-200;
		H[3]=200;

		g[0]=-2;
		g[1]=0;

		lb[0]=-3.5;
		lb[1]= -3.5;

		ub[0]=3;
		ub[1]=3;
	}
	else
	{
		//Initialize H
				
	H[0]= 202;
	H[1]= -200;
	
	for(;t<=n-2;t++)
	{
		p=1;
	
		for(;p<=n-2;i++)
			{
				H[i]=0;
				p++;
			}

	H[i]=-200;
	H[i+1]=402;
	H[i+2]=-200; 

	i=i+3;
	}

	p=1;
	for(;p<=n-2;i++)
		{
			H[i]=0;
			p++;
		}

	H[i]=-200;
	H[i+1]=200;

		//Initialize g

	for(i=0;i<n-1;i++)
	{
		g[i]=-2;
	}
	g[i]=0;

		//initilaize lb
	for(i=0;i<n;i++)
	{
		lb[i]=-3.5;
	}
	
		//initilaize ub
		for(i=0;i<n;i++)
	{
		ub[i]=3;
	}


//	}

	/* Setting up QProblem object. */
	

	QProblemBCON( &example,n,HST_UNKNOWN );
	Options_setToDefault( &options );
	QProblemB_setOptions( &example,options );

	/* Solve first QP. */
	nWSR = 100;
	QProblemB_init( &example,H,g,lb,ub, &nWSR,0 );

	/* Get and print solution of second QP. */	
	QProblemB_getPrimalSolution( &example,xOpt );
	//QProblem_getDualSolution(   &example,yOpt );
	//printf( "\nxOpt = [ %e, %e, %e, %e];    objVal = %e\n\n", xOpt[0],xOpt[1],xOpt[2],xOpt[3],QProblem_getObjVal( &example ) );
	for(i=0;i<z;i++)
	{
        printf("%.2e \n",xOpt[i]);
	}
	 printf("%e \n",QProblemB_getObjVal( &example ));
	/* Solve second QP. */
/*	nWSR = 10;
	QProblem_hotstart( &example,g_new,lb_new,ub_new,lbA_new,ubA_new, &nWSR,0 );

	/* Get and print solution of second QP. */
/*	QProblem_getPrimalSolution( &example,xOpt );
	QProblem_getDualSolution(   &example,yOpt );
	//printf( "\nxOpt = [ %e, %e ];  yOpt = [ %e, %e, %e ];  objVal = %e\n\n", 
		//	xOpt[0],xOpt[1],yOpt[0],yOpt[1],yOpt[2], QProblem_getObjVal( &example ) );

	QProblem_printOptions( &example );
	
	*/
	return 0;
}


/*
 *	end of file
 */
