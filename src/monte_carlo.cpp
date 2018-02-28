/*
 * monte_carlo.cpp
 *
 * This program preforms the monte_carlo algorithm using threads.
 * User is prompted to input how many points they want to add to the algorithm.

 *
 *  Created on: Feb 25, 2018
 *      Author: Jacob Kirby
 *
 *
 */

#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>

#include "makefile.h"

int circle_points = 0, square_points = 0; //keep track of points inside circle and square


int interval;
int counter = 0; //counter used for random seed

int main(){
	//user input
	printf("Enter value of points: ");
	scanf("%d", &interval);
	printf("Number of points = %d \n",interval);

	pthread_t threads[interval]; //thread array

	//create threads
	for(int i = 0; i<interval;i++){
	//	all_threads[i];
		pthread_create(&threads[i], NULL, monte_carlo, (void*)&i);
		//printf("Hello World");
	}

	//join threads
	for(int i = 0; i<interval;i++){
			pthread_join(threads[i], NULL);
	}

	//calculate pi
	double pi = 4.0*circle_points/square_points;
	printf("pi = %f", pi);

	pthread_exit(NULL);
	return 0;
}

void *monte_carlo(void *count){

	double rand_x, rand_y, origin;

	counter++;
	srand(time(NULL)+counter);
	rand_x = ((double)rand() / (RAND_MAX));
	rand_y = ((double)rand() / (RAND_MAX));

	//location of point
	origin = rand_x*rand_x + rand_y*rand_y;

	//if origin is less than 1, then point is within the circle
	if(origin <= 1)
		circle_points++;
	square_points++;
	//}
	return (void *)1;
}
