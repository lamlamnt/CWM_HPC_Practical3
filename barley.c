/**************************************************
 *                                                *
 * First attempt at a code to calcule lost barley *
 * by A. Farmer                                   *
 * 18/05/18                                       *
 *                                                *
 **************************************************/

// Include any headers from the C standard library here
#include <stdio.h>
#include <stdlib.h>
// Define any constants that I need to use here
#define PI 3.14

// This is where I should put my function prototypes
float area_of_circle(float radius); 
float circumference_of_circle(float radius);
float area_rectangle(float length, float width);

// Now I start my code with main()
int main() {

    // In here I need to delare my variables
	int number_of_circles = 0;
	float *radius;
	float total_area = 0;
	int number_of_rings = 0;
	float *radius_ring;

	float length;
	float width;

    // Next I need to get input from the user.
	printf("Enter the number of circles of barley loss:\t");
	scanf("%d", &number_of_circles);
	radius = (float *)malloc(number_of_circles*sizeof(float));
    // I'll do this by using a printf() to ask the user to input the radii.
	printf("\nEnter the radii:\t");
	for(int i = 0; i < number_of_circles; i++){
		scanf("%f",&radius[i]);
	} 

	printf("\nEnter the number of rings of barley loss:\t");
	scanf("%d",&number_of_rings);
	radius_ring = (float *)malloc(number_of_rings*sizeof(float));
	for(int i = 0; i < number_of_rings; i++){
                scanf("%f",&radius_ring[i]);
        }

    // Now I need to loop through the radii caluclating the area for each
	for(int i = 0; i < number_of_circles;i++){
		total_area += area_of_circle(radius[i]);
	}
	for(int i = 0; i<number_of_rings;i++){
		total_area += circumference_of_circle(radius_ring[i]);
	}
	
    // Next I'll sum up all of the individual areas
	free(radius);
	free(radius_ring);
    /******************************************************************
     *                                                                *
     * Now I know the total area I can use the following information: *
     *                                                                *
     * One square meter of crop produces about 135 grams of barley    *
     *                                                                *
     * One kg of barley sells for about 10 pence                      *
     *                                                                *
     ******************************************************************/

    // Using the above I'll work out how much barley has been lost.
	float  loss_in_kg = total_area*0.135;

    // Ask the user for the dimensions of the rectangular field
	printf("\nEnter dimensions of rectangular field (length and then width):\t");
	scanf("%f %f",&length, &width);

    // Finally I'll use a printf() to print this to the screen.
	printf("\nTotal area lossed in m^2 is:\t%f\n", total_area);
	printf("Total loss in kg is:\t\t%f\n", loss_in_kg);
	
   //Prints the total loss of barley as a percentage of barley harvested
	float percentage_loss = total_area/area_rectangle(length,width);
	printf("Percentage loss: %f",percentage_loss);

	return(0);
}

// I'll put my functions here:
float area_of_circle(float radius){
	float area = PI*radius*radius;
	return area;
}

float circumference_of_circle(float radius){
	return 2*PI*radius;
}

float area_rectangle(float length, float width){
	return (length*width);
}
