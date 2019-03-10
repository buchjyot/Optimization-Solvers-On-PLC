
#ifndef AMPL
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <signal.h>
#include <setjmp.h>
#include <math.h>
#include <sys/types.h>

#ifdef linux
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#endif
#include <sys/stat.h>
#include <fcntl.h>

#include "pswarm.h"


extern struct Stats stats;



/**********************************************/
/*                                            */
/* User defined global variables              */
/*                                            */
/**********************************************/

# define DIM 2 /* number of variables */
# define CONS 0 /* no linear constraints */


/**********************************************/
/*                                            */
/* End of user defined global variables       */
/*                                            */
/**********************************************/


/*******************************************************/
/*                                                     */
/* User define objective function                      */
/*                                                     */
/*******************************************************/

//void objfun(int n, int m, double *x, double *fx)
void objfun(int n, int m, double *x, double *lb, double *ub, double *fx)
{
  int i, j;

  for(j=0;j<m;j++){
	  fx[j]=0.0;
	  for(i=0;i<n;i++){
		fx[j]+=100*pow((x[j*n+i+1]-pow(x[j*n+i],2.0)),2.0)+pow(1-x[j*n+i],2.0);
	  }
  }

}

/*******************************************************/
/*                                                     */
/* End of user define objective function               */
/*                                                     */
/*******************************************************/



/*******************************************************/
/*                                                     */
/* User define problem data                            */
/*                                                     */
/*******************************************************/



void set_problem_dimension(int *n, int *lincons)
{

  *n=DIM; /* problem dimension -- number of variables */
  *lincons=CONS; /* number of linear constraints */
}


void set_problem(double *x, double *lb, double *ub, double *A, double *b)
{

  /* initial guess */
  int i,n;

  n=DIM;
  
/* initial guess */
  for(i=0;i<n;i++) // n will be passed as set_problem function argument
	 x[i]=0.5;


  /* lower bounds */
  for(i=0;i<n;i++)
	 lb[i]=-3.5;


  /* upper bounds */
 for(i=0;i<n;i++)
	 ub[i]=3.0; 
}

/*******************************************************/
/*                                                     */
/* End of user define problem data                     */
/*                                                     */
/*******************************************************/


/*******************************************************/
/*                                                     */
/* User initialize problem data                        */
/*                                                     */
/*******************************************************/

#ifdef MPI


void user_init_MPI(int MPI_myrank)
{

  /* use this function if some global data must be initialized */

  
  
}
#else
void user_init()
{

  /* use this function if some global data must be initialized */

 
  
}
#endif


/*******************************************************/
/*                                                     */
/* End of user initialize problem data                 */
/*                                                     */
/*******************************************************/



#endif /* AMPL */
