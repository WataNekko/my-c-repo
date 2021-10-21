#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// global parameters
const int HEIGHT = 699;
const int WIDTH = 964;
const int CHANNEL = 3;



//==================================== begin meta-code ==============================

void read_color_image(unsigned char color_image[HEIGHT][WIDTH][CHANNEL], char *file_name)
{
	// ...
	int height, width, channel;
	unsigned char *temp = stbi_load(file_name, &width, &height, &channel, 0);
	if (temp == NULL) {
		printf("Unable to load image.\n");
		exit(1);
	}
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			for (int k = 0; k < CHANNEL; k++) {
				color_image[i][j][k] = temp[i * WIDTH * CHANNEL + j * CHANNEL + k];
			}
		}
	}
	stbi_image_free(temp);
}

void save_color_image(unsigned char color_image[HEIGHT][WIDTH][CHANNEL], char *file_name)
{
	// ...
	unsigned char *temp = (unsigned char *)malloc(HEIGHT * WIDTH * CHANNEL);
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			for (int k = 0; k < CHANNEL; k++) {
				temp[i * WIDTH * CHANNEL + j * CHANNEL + k] = color_image[i][j][k];
			}
		}
	}
	stbi_write_png(file_name, WIDTH, HEIGHT, CHANNEL, temp, WIDTH * CHANNEL);
	free(temp);
}

void save_gray_image(unsigned char gray_image[HEIGHT][WIDTH], char *file_name)
{
	// ...
	unsigned char *temp = (unsigned char *)malloc(HEIGHT * WIDTH);
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			temp[i * WIDTH + j] = gray_image[i][j];
		}
	}
	stbi_write_png(file_name, WIDTH, HEIGHT, 1, temp, WIDTH);
	free(temp);
}

//==================================== end meta-code ==============================


//==================================================================================
//==================================== your code here ==============================
//==================================================================================

// some doc
void to_grayscale(unsigned char result[HEIGHT][WIDTH], unsigned char color_img[HEIGHT][WIDTH][CHANNEL])
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			// transform to grayscale
			result[i][j] = 0.3 * color_img[i][j][0] + 0.59 * color_img[i][j][1] + 0.11 * color_img[i][j][2];
		}
	}
}

// Subtracts color_img2 from color_img1 and stores the absolute value in result.
// 
// >> insert other remarks here...
void subtract_img(unsigned char result[HEIGHT][WIDTH][CHANNEL], unsigned char color_img1[HEIGHT][WIDTH][CHANNEL], unsigned char color_img2[HEIGHT][WIDTH][CHANNEL])
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			for (int k = 0; k < CHANNEL; k++) {
				result[i][j][k] = abs(color_img1[i][j][k] - color_img2[i][j][k]);
			}
		}
	}
}

// Creates a mask from a grayscale image using a given predicate function.
// 
// Parameters:
//     result - the result array to store the mask into.
//     gray_img - a grayscale image as input
//     predicate - a pointer to a function that accepts a grayscale pixel as input and returns a boolean value (zero or non-zero) for masking.
// 
void mask(unsigned char result[HEIGHT][WIDTH], unsigned char gray_img[HEIGHT][WIDTH], int (*predicate)(unsigned char))
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			// stores 255 in result if the pixel satifies the condition, otherwise 0.
			result[i][j] = predicate(gray_img[i][j]) ? 255 : 0;
		}
	}
}

// condition for the mask
int is_greater_than_40(unsigned char pixel_value)
{
	return pixel_value > 40;
}

// Combines two images into one using a mask. If an entry in the mask contains a
// non-zero value, the pixel from color_img1 with the same location as the entry is
// copied to result, otherwise the pixel from color_img2 is copied.
void combine_color_img(unsigned char result[HEIGHT][WIDTH][CHANNEL], unsigned char mask[HEIGHT][WIDTH], unsigned char color_img1[HEIGHT][WIDTH][CHANNEL], unsigned char color_img2[HEIGHT][WIDTH][CHANNEL])
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			for (int k = 0; k < CHANNEL; k++) {
				result[i][j][k] = mask[i][j] ? color_img1[i][j][k] : color_img2[i][j][k];
			}
		}
	}
}

int main()
{
	// Allocates memory for 2 color images and a 1-channel image.
	void *mem = malloc(HEIGHT * WIDTH * (2 * CHANNEL + 1));
	if (mem == NULL) {
		printf("Not enough memory.\n");
		return 1;
	}

	// a 3-channel image
	unsigned char (*img3ch_a)[WIDTH][CHANNEL] = mem;
	// another 3-channel image adjacent to the previous one
	unsigned char (*img3ch_b)[WIDTH][CHANNEL] = img3ch_a + HEIGHT;
	// a 1-channel image adjacent to the previous two, used for grayscale and masking
	unsigned char (*img1ch)[WIDTH] = (unsigned char (*)[WIDTH])(img3ch_b + HEIGHT);

	// loads the two image for background subtraction
	read_color_image(img3ch_a, "pg4.jpg");
	read_color_image(img3ch_b, "background4.jpg");

	// subtracts the background and saves
	subtract_img(img3ch_b, img3ch_a, img3ch_b);
	to_grayscale(img1ch, img3ch_b);
	save_gray_image(img1ch, "subtraction.jpg");

	// creates the mask
	mask(img1ch, img1ch, is_greater_than_40);
	save_gray_image(img1ch, "mask.jpg");

	// creates a new image with the new background
	read_color_image(img3ch_b, "weather_forecast.jpg"); // loads the new background
	combine_color_img(img3ch_a, img1ch, img3ch_a, img3ch_b);
	save_color_image(img3ch_a, "new_img.jpg");

	free(mem);
	printf("Done.\n");

	return 0;
}
