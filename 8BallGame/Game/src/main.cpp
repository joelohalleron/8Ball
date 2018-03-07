#include <mbed.h>
#include <MMA7455.h>
#include <LM75B.h>
#include <display.h>
#include <math.h> 
#include <Matrix.h>


//Declare output object for LED1
DigitalOut led1(LED1);

// Initialise Joystick   
typedef enum {JLT = 0, JRT, JUP, JDN, JCR} btnId_t;
static DigitalIn jsBtns[] = {P5_0, P5_4, P5_2, P5_1, P5_3}; // LFT, RGHT, UP, DWN, CTR
bool jsPrsdAndRlsd(btnId_t b);

//Input object for the potentiometer
AnalogIn pot(p15);
float potVal = 0.0;
  
//Object to manage the accelerometer
MMA7455 acc(P0_27, P0_28);
bool accInit(MMA7455& acc); //prototype of init routine
int32_t accVal[3];

//Object to manage temperature sensor
LM75B lm75b(P0_27, P0_28, LM75B::ADDRESS_1);
float tempVal = 0.0;

Display *screen = Display::theDisplay();
    //This is how you call a static method of class Display
    //Returns a pointer to an object that manages the display screen 

//Timer interrupt and handler
void timerHandler(); //prototype of handler function
int tickCt = 0;

//Drawing coordinates
int x = 240, y = 120, dx = 1, dy = 0;

//Test code for physics


typedef struct{
	float x;
	float y;
}Vector2;
	


//Struct for ball object
typedef struct{
	float r;
	Vector2 velocity;
	float x;
	float y;
	float mass;
} Ball;

//Prototype of force function
float computeForce(Ball);

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
};


Ball balls[16] = {};
	
//draw an array of balls
void initializeBalls(){
	for (int i = 0; i < 17; ++i){
		Ball *ball = &balls[i];	
		ball->x = rand() % 400 + 20;
		ball->y = rand() % 260 + 20;
		ball->velocity.x = RandomFloat(0.1,2);
		ball->velocity.y = RandomFloat(0.1,2);
		ball->r = 10;
		
	}
}

void drawBalls(){
		for (int i = 0; i < 17; ++i){
		Ball *ball = &balls[i];	
		screen->fillCircle(ball->x, ball->y, ball->r, RED);
	}
}

void hitBoundary(Ball *ball){
	
	if (26 > ball->x || ball->x > 409  ){
		ball->velocity.x = -ball->velocity.x;
	}
	if(26 > ball->y || ball->y > 229){
		ball->velocity.y = -ball->velocity.y;
	}
}

void detectCollisions(){
	for (int i = 0; i < 17; ++i)
	{
		Ball *ball1 = &balls[i];
		for(int n = 0; n < 17; ++n)
		{
			Ball *ball2 = &balls[n];
			if(pow((ball2->x - ball1->x), 2) + pow((ball2->y - ball1->y), 2) < pow((2*ball1->r),2))
			{
				ball1->velocity
			}
		}
	}
}

void moveballs(int dt){

		for (int i = 0; i < 17; ++i){
			Ball *ball = &balls[i];
			float force = computeForce(*ball);
			Vector2 acceleration = (Vector2){(force.x / ball->mass), (force.y / ball->mass)};
			screen->fillCircle(ball->x, ball->y, ball->r, GREEN);
			hitBoundary(ball);
			ball->velocity.x += acceleration.x * dt;
      ball->velocity.y += acceleration.y * dt;
      ball->x += ball->velocity.x * dt;
      ball->y += ball->velocity.y * dt;
			screen->fillCircle(ball->x, ball->y, ball->r, RED);
		}
};





//End of test code for physics

int main() {
  // Initialise the display
  screen->fillScreen(WHITE);
  screen->setTextColor(BLACK, WHITE);

  //Initialise ticker and install interrupt handler
  Ticker ticktock;
  ticktock.attach(&timerHandler, 1);
  
	//TimeStep
  int dt = 1;
		
	//DrawBoard
	screen->fillRoundRect(20, 20, 420, 240,
      20, BLACK);
	screen->fillRoundRect(25, 25, 410, 230,
      20, GREEN);
	
	//Draw balls initial position
	initializeBalls();
	
  
  while (true) {
		
	  //drawBalls();
		//wait(0.005); //5 milliseconds
		moveballs(dt);

    wait(0.005); //5 milliseconds
  }
}

bool accInit(MMA7455& acc) {
  bool result = true;
  if (!acc.setMode(MMA7455::ModeMeasurement)) {
    // screen->printf("Unable to set mode for MMA7455!\n");
    result = false;
  }
  if (!acc.calibrate()) {
    // screen->printf("Failed to calibrate MMA7455!\n");
    result = false;
  }
  // screen->printf("MMA7455 initialised\n");
  return result;
}

//Definition of timer interrupt handler
void timerHandler() {
  tickCt++;
  led1 = !led1; //every tick, toggle led1
}

/* Definition of Joystick press capture function
 * b is one of JLEFT, JRIGHT, JUP, JDOWN - from enum, 0, 1, 2, 3
 * Returns true if this Joystick pressed then released, false otherwise.
 *
 * If the value of the button's pin is 0 then the button is being pressed,
 * just remember this in savedState.
 * If the value of the button's pin is 1 then the button is released, so
 * if the savedState of the button is 0, then the result is true, otherwise
 * the result is false. */
bool jsPrsdAndRlsd(btnId_t b) {
	bool result = false;
	uint32_t state;
	static uint32_t savedState[4] = {1,1,1,1};
        //initially all 1s: nothing pressed
	state = jsBtns[b].read();
  if ((savedState[b] == 0) && (state == 1)) {
		result = true;
	}
	savedState[b] = state;
	return result;
}

