#include <iostream>
#include <vector>
#include <conio.h>  // For _kbhit() and _getch()
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

const int width = 20;  // Game field width
const int height = 10;  // Game field height
int frogX, frogY;  // Frog's position
int score = 0;  // Score based on how high the frog jumps
bool gameOver = false;
vector<int> platforms(height, 0);  // Stores platform positions at different levels

// Draw the game field
void draw() {
    system("cls");  // Clear the console

    for (int i = 0; i < width + 2; i++) cout << "#";  // Top boundary
    cout << endl;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0) cout << "#";  // Left boundary

            if (x == frogX && y == frogY)
                cout << "F";  // Draw frog
            else if (x == platforms[y])
                cout << "-";  // Draw platform
            else
                cout << " ";

            if (x == width - 1) cout << "#";  // Right boundary
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) cout << "#";  // Bottom boundary
    cout << endl;

    // Display score
    cout << "Score: " << score << endl;
}

// Initialize platforms randomly
void generatePlatforms() {
    for (int i = 0; i < height; i++) {
        platforms[i] = rand() % width;  // Place platform at a random x position
    }
}

// Move platforms down as frog jumps up
void movePlatformsDown() {
    for (int i = height - 1; i > 0; i--) {
        platforms[i] = platforms[i - 1];  // Move each platform down
    }
    platforms[0] = rand() % width;  // New platform appears at the top
}

// Update game state based on user input
void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':  // Move left
            if (frogX > 0) frogX--;
            break;
        case 'd':  // Move right
            if (frogX < width - 1) frogX++;
            break;
        }
    }
}

// Update game logic
void logic() {
    // Check if frog landed on a platform
    if (frogY < height - 1 && frogX == platforms[frogY + 1]) {
        frogY++;  // Frog lands safely on the next platform
        score++;  // Increase score for landing on a platform
    } else {
        frogY--;  // Frog continues falling if not on a platform
    }

    // If frog reaches the bottom of the screen without landing on a platform, game over
    if (frogY < 0) {
        gameOver = true;
    }

    // When frog reaches the top of the screen, move platforms down
    if (frogY == height - 1) {
        movePlatformsDown();
        frogY = height - 2;  // Move frog slightly down to continue jumping
    }
}

// Main game loop
int main() {
    srand(time(0));  // Seed for random number generation

    frogX = width / 2;  // Start frog in the middle of the screen
    frogY = height - 1;
    generatePlatforms();  // Create initial platforms

    while (!gameOver) {
        draw();
        input();
        logic();
    }

    cout << "Game Over! Final Score: " << score << endl;
    return 0;
}

