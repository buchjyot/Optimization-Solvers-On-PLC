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

	
	const int q=200; //maximum dimention for H matrices
	const int k=3; //no of variables = 4k+4 //passed in CBP project
	int nWSR;
	int i,n,j;
	static Options options;
	static QProblemB example;
	
	real_t xOpt[200];
	//real_t yOpt[30+1];
	real_t H[200*200];
	real_t g[200];
	real_t lb[200];
	real_t ub[200];
		
	n=3*k+3;

	for(i=0;i<q;i++)
	{	H[i]=0; //initilize all with 0
	g[i]=0;
	ub[i]=0;
	lb[i]=0;
		xOpt[i]=0;
	}
	
	//initilize H
	for(i=0;i<=k;i++)
	{
		
		for(j=0;j<3;j++)
		{
			if(j==0)
			{
				H[4*n*i+4*i+j]=6;             //first row
				H[(4*n*i)+n+((4*i)+j)]=-2;         //second row
				H[(4*n*i)+2*n+((4*i)+j)]=-2;        //third row
			}

			if(j==1)
			{
				H[(4*n*i)+(4*i)+j]=-2;
				H[(4*n*i)+n+((4*i)+j)]=6;
				H[(4*n*i)+2*n+((4*i)+j)]=-2;
			}

			if(j==2)
			{
				H[(4*n*i)+(4*i)+j]=-2;
				H[(4*n*i)+n+((4*i)+j)]=-2;
				H[(4*n*i)+2*n+((4*i)+j)]=6;
			}

			
	}

	}

	//initilize g
	for(i=0;i<n;i++)
	{
		g[i]=2;
			
	}

	//initilaize lb and ub
	for(i=0;i<n;i++)
	{
		lb[i]=-5;
		ub[i]=5;
	}

	/* Setting up QProblem object. */
	

	QProblemBCON( &example,n,HST_UNKNOWN );
	Options_setToDefault( &options );
	QProblemB_setOptions( &example,options );

	/* Solve first QP. */
	nWSR = 500;
	QProblemB_init( &example,H,g,lb,ub,&nWSR,0 );

	/* Get and print solution of second QP. */	
	QProblemB_getPrimalSolution( &example,xOpt );
	//QProblem_getDualSolution(   &example,yOpt );
	//printf( "\nxOpt = [ %e, %e, %e, %e];    objVal = %e\n\n", xOpt[0],xOpt[1],xOpt[2],xOpt[3],QProblem_getObjVal( &example ) );
	for(i=0;i<n;i++)
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

