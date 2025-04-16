/**********************************************************
 * This file is generated by 20-sim C++ Code Generator
 *
 *  file:  test_LoopController.cpp
 *  subm:  LoopController
 *  model: RELbotSimple
 *  expmt: RELbotSimple
 *  date:  April 16, 2025
 *  time:  9:33:41 AM
 *  user:  Vakgroep RaM
 *  from:  -
 *  build: 5.1.4.13773
 **********************************************************/

/* This file is a demo application of how the submodel function can
 * be used. It uses the global time variables that are used by both
 * the submodel and the integration method.
 *
 * PLEASE NOTE: THIS IS AN EXAMPLE WHERE ALL INPUTS ARE ZERO !
 * USE YOUR OWN INPUTS INSTEAD!! ALSO THE SUBMODEL MIGHT SIMPLY
 * NOT WORK CORRECTLY WITH INPUTS THAT ARE ZERO.
 */

#include <stdio.h>

/* 20-sim submodel class include file */
#include "LoopController.h"

/* the main function */
int main()
{
	XXDouble u [4 + 1];
	XXDouble y [2 + 1];

	/* initialize the inputs and outputs with correct initial values */
	u[0] = 0.0;		/* PosLeft */
	u[1] = 0.0;		/* PosRight */
	u[2] = 0.0;		/* SetVelLeft */
	u[3] = 0.0;		/* SetVelRight */

	y[0] = 0.0;		/* SteerLeft */
	y[1] = 0.0;		/* SteerRight */


	LoopController my20simSubmodel;

	/* initialize the submodel itself and calculate the outputs for t=0.0 */
	my20simSubmodel.Initialize(u, y, 0.0);
	printf("Time: %f\n", my20simSubmodel.GetTime() );

	/* simple loop, the time is incremented by the integration method */
	while (my20simSubmodel.state != LoopController::finished)
	{
		/* call the submodel to calculate the output */
		my20simSubmodel.Calculate (u, y);
		printf("Time: %f\n", my20simSubmodel.GetTime() );
	}

	/* perform the final calculations */
	my20simSubmodel.Terminate (u, y);

	/* and we are done */
	return 0;
}

