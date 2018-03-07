#include <display.h>
#include <std.h>

#define NUM_BALLS 1

//Two dimensional Vector
typedef struct{
	float x;
	float y;
} Vector2D;

//Two dimensional Ball
typedef struct{
	Vector2D position;
	Vector2D velocity;
	float mass;
} Ball;

Ball balls[NUM_BALLS];

Display *screen = Display::theDisplay();

void CalculatePositions() {
	for (int i=0; i < NUM_BALLS; ++i) {
   	Ball *ball = &balls[i];
		screen->fillCircle(ball->position.x, ball->position.y, 4, RED);
	}
}

// Initializes all balls with random positions, zero velocities and 1kg mass.
void InitializeBalls() {
    for (int i = 0; i < NUM_BALLS; ++i) {
        balls[i].position = (Vector2D){arc4random(50), arc4random(50)};
        balls[i].velocity = (Vector2D){0, 0};
        balls[i].mass = 1;
    }
}

// Just applies Earth's gravity force (mass times gravity acceleration 9.81 m/s^2) to each particle.
Vector2D ComputeForce(Ball *ball) {
    return (Vector2D){0, ball->mass * -9.81};
}

void RunSimulation() {
    float totalSimulationTime = 10; // The simulation will run for 10 seconds.
    float currentTime = 0; // This accumulates the time that has passed.
    float dt = 1; // Each step will take one second.
    
    InitializeBalls();
    CalculatePositions();
    
    while (currentTime < totalSimulationTime) {
        // We're sleeping here to keep things simple. In real applications you'd use some
        // timing API to get the current time in milliseconds and compute dt in the beginning 
        // of every iteration like this:
        // currentTime = GetTime()
        // dt = currentTime - previousTime
        // previousTime = currentTime
        sleep(dt);

        for (int i = 0; i < NUM_BALLS; ++i) {
            Ball *ball = &balls[i];
            Vector2D force = ComputeForce(particle);
            Vector2D acceleration = (Vector2D){force.x / Ball->mass, force.y / Ball->mass};
            Ball->velocity.x += acceleration.x * dt;
            Ball->velocity.y += acceleration.y * dt;
            Ball->position.x += Ball->velocity.x * dt;
            Ball->position.y += Ball->velocity.y * dt;
        }
        
        CalculatePositions();
        currentTime += dt;
    }
}