#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <iGraphics.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400
#define BLOCK_SIZE 20
#define MAX_BLOCKS 100

typedef struct {
	int x, y;
} Block;

Block worm[MAX_BLOCKS];
int wormSize;
int direction; // 0: right, 1: up, 2: left, 3: down
int foodX, foodY;
bool gameOver;

void initializeGame() {
	wormSize = 3;
	direction = 0;
	gameOver = false;

	// Initial position of the worm
	for (int i = 0; i < wormSize; i++) {
		worm[i].x = 100 + i * BLOCK_SIZE;
		worm[i].y = 100;
	}

	// Place initial food
	srand(time(0));
	foodX = rand() % (WINDOW_WIDTH / BLOCK_SIZE) * BLOCK_SIZE;
	foodY = rand() % (WINDOW_HEIGHT / BLOCK_SIZE) * BLOCK_SIZE;
}

void updateGame() {
	if (!gameOver) {
		// Move the worm
		for (int i = wormSize - 1; i > 0; i--) {
			worm[i] = worm[i - 1];
		}

		// Update the head of the worm based on the direction
		if (direction == 0) worm[0].x += BLOCK_SIZE;
		else if (direction == 1) worm[0].y += BLOCK_SIZE;
		else if (direction == 2) worm[0].x -= BLOCK_SIZE;
		else if (direction == 3) worm[0].y -= BLOCK_SIZE;

		// Check if the head of the worm collides with the body
		for (int i = 1; i < wormSize; i++) {
			if (worm[0].x == worm[i].x && worm[0].y == worm[i].y) {
				gameOver = true;
			}
		}

		// Check if the head of the worm collides with the walls
		if (worm[0].x < 0 || worm[0].x >= WINDOW_WIDTH || worm[0].y < 0 || worm[0].y >= WINDOW_HEIGHT) {
			gameOver = true;
		}

		// Check if the head of the worm collides with the food
		if (worm[0].x == foodX && worm[0].y == foodY) {
			wormSize++;
			// Place new food
			foodX = rand() % (WINDOW_WIDTH / BLOCK_SIZE) * BLOCK_SIZE;
			foodY = rand() % (WINDOW_HEIGHT / BLOCK_SIZE) * BLOCK_SIZE;
		}
	}
}

void drawGame() {
	// Draw worm
	iSetColor(0, 255, 0);
	for (int i = 0; i < wormSize; i++) {
		iFilledRectangle(worm[i].x, worm[i].y, BLOCK_SIZE, BLOCK_SIZE);
	}

	// Draw food
	iSetColor(255, 0, 0);
	iFilledRectangle(foodX, foodY, BLOCK_SIZE, BLOCK_SIZE);

	// Draw game over message
	if (gameOver) {
		iSetColor(255, 0, 0);
		iText(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2, "Game Over", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void iDraw() {
	iClear();
	drawGame();
}

void iSpecialKeyboard(unsigned char key) {
	// Handle arrow keys to change direction
	if (key == GLUT_KEY_RIGHT && direction != 2) direction = 0;
	else if (key == GLUT_KEY_UP && direction != 3) direction = 1;
	else if (key == GLUT_KEY_LEFT && direction != 0) direction = 2;
	else if (key == GLUT_KEY_DOWN && direction != 1) direction = 3;
}

void iIdle() {
	updateGame();
	iDelayMS(100); // Adjust the delay for smoother animation
}

int main() {
	iInitialize(WINDOW_WIDTH, WINDOW_HEIGHT, "Strike Worm Game");
	initializeGame();
	iSetSpecialKeyboardCallback(iSpecialKeyboard);
	iSetIdleCallback(iIdle);
	return 0;
}