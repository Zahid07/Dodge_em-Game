//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string.h>
#include<string>
#include<time.h>
#include<fstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

void GameDisplay();

bool b=false;
int level=1; //variable for level

int highscore=0;//varible for score
int temp=0;//used to compare score of the user whenever he gets his life cut
int scores[10];//array to hold all score coming from array
bool goright=false;//user bool
bool goleft=false;//user bool
bool goup=false;//user bool
bool godown=false;//user bool
float x_1 = 905; //user axis
float y_1 = 30;//user axis
int life=3;//user lives
float x_2 = 900; //computer axis
float y_2 = 900; //computer axis
float  arr[1001][1001];//aray used to store all the food places.

int z=1;//variable used for setting food only once later used in the program in the function creatd
bool up=false;//computer bool
bool down=false;//computer bool
bool right_1=false;//computer bool
bool left_1=false;//computer bool
bool in_0=true;//checking if user is in the first loop 
bool in_1=false;//checking if user is in the second loop
bool in_2=false;//checking if user is in the third loop
bool in_3=false;//checking if user is in the fourth loop

bool computer_in_0=false;//checking if computer is in the first loop 
bool computer_in_1=false;//checking if computer is in the second loop
bool computer_in_2=false;//checking if computer is in the third loop
bool computer_in_3=false;//checking if computer is in the fourth loop
bool startmenu=true;// variable to show the start menu

bool endmenu=false;// variable used for end menu
// all variable used with start menu
bool help=false;
bool newgame=false;
bool highest=false;
bool exit_1=false;
//All variavles used woth end menu
bool resume=false;
bool go_out=false;
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}





//function created when help button is pressed


void HELP(){
glClearColor(1/*Red Component*/, 0,	//148.0/255/*Green Component*/,
				0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors

//DrawSquare( 0 , 0 ,1100,colors[WHITE]);
DrawString(300, 8000, 30, 30, "DODGE_EM",colors[MAROON]);

DrawString(4000, 15000, 30, 30, "HELP MENU",colors[MAROON]);
DrawString(4000, 10000, 30, 30, "INSTRUCTIONS",colors[MAROON]);

DrawString(4000, 9000, 30, 30, "You have to Dodge the opponent and take all the food.",colors[MAROON]);
DrawString(4000, 8500, 30, 30, "You total of \"3\" Lives.",colors[MAROON]);
DrawString(4000, 8000, 30, 30, "When ever you hid the other car your score will reset and you",colors[MAROON]);
DrawString(4000, 7500, 30, 30, "          have to start that level from the beginning.",colors[MAROON]);
DrawString(4000, 7000, 30, 30, "Level 1 is the easiest level. The opponent car will not chase you and",colors[MAROON]);
DrawString(4000, 6500, 30, 30, "         just move in the outer circle.",colors[MAROON]);
DrawString(4000, 6000, 30, 30, "Level 2 : The oponent car will start chasing you even if it had to",colors[MAROON]);
DrawString(4000, 5500, 30, 30, "         change its direction for a while..",colors[MAROON]);
DrawString(4000, 5000, 30, 30, "Level 3 : You won't reach there,so don't worry",colors[MAROON]);


DrawString( 600, 100, "Press Back Space to go to main menu", colors[BLACK]);



}

//Function created to sort the scores in the array

void sorting(){
	
	int numberofitems = 10;
	int current;
	int itemtobeinserted;


	for (int i = 1; i < numberofitems; i++)
	{
		itemtobeinserted = scores[i];
		current = i - 1;

		while ((scores[current] < itemtobeinserted) && current> 0)
		{

			scores[current + 1] = scores[current];
			current--;


		}
		
		scores[current + 1] = itemtobeinserted;

	}

	

}




// Function created to read fom the file

void readfromfile()
{
sorting();
DrawSquare( 0 , 0 ,1100,colors[WHITE]);
DrawSquare( 800 , 60 ,120,colors[MISTY_ROSE]);

 DrawString( 600, 100, "Press Back Space to go to main menu", colors[BLACK]);

	string score_1;
	ifstream fin ("high score.txt"); //name of the file it is supposed to read
int hight=750;
int number=1;
	if (fin.is_open())
	{
		while ( getline (fin, score_1) ) //this loop will run depending on the number of lines in the file
		{
			DrawString( 300, hight, Num2Str(number)+" ) ", colors[BLACK]);
			
		  DrawString( 350, hight, score_1, colors[BLACK]);

		  hight-=50;
number++;
		  //HINT: use stoi() to convert string into Integer
		  
		}
		fin.close();
	}
	
	else 
		cout << "Unable to open file"; 

sorting();

}

//Function created to write the array contents in file

void write_file(){
sorting();
ofstream fout;
	fout.open ("high score.txt"); //this function takes the name of the file that you are writing to
	
	for (int i = 0; i < 10; i++){
		fout << scores[i] << endl;
	}
		
	fout.close();

}

//Function created when ever one life is cut

void gobackpiece(){
x_1 = 905; 
y_1 = 30;
x_2 = 900; 
y_2 = 900; 

godown=false;
goup=false;
goright=false;
goleft=true;
up=false;
down=true;
right_1=false;
left_1=false;
sleep(2);

}

//Functoin created to add the users score.

void writescore(){

cout<<"Helllllloooooooooooo"<<endl;


for(int i=0;i<=9;i++)
{

cout<<"Score "<<scores[i]<<"  temp is = "<<temp;
if(scores[i]<temp){
scores[i]=temp;
break;
}
}
sorting();
write_file();
for(int i=0;i<=9;i++)
{

cout<<scores[i]<<endl;
}
}


//Function to reset array whenever the life becomes 0
void resetarray(){

for(int i=80;i<=1000;i+=125)
	{
	for(int j=75;j<=980;j+=105)
	{
		
		arr[i][j]=-100;
			
			
//cout<<"innnnn"<<endl;
			
			
		
			//cout<<"F is = "<<f<<endl<<endl;
	}	

	}


}

int rectY=680;//variable used to control the rectangle created

//Function created to show start menu whenever needed
void STARTMENU(){

if(level==4)
{
DrawRectangle(300, rectY, 350, 60,colors[MISTY_ROSE]);
DrawString( 350, 750, "Congratulations You Have Won! ", colors[BLACK]);
}


if(startmenu==true)
{
	
if(help==false && highest==false && exit_1==false && newgame==false){
DrawSquare( 0 , 0 ,1100,colors[WHITE]);
DrawRectangle(300, rectY, 350, 60,colors[MISTY_ROSE]); 
DrawString( 350, 700, "Start Game (N)", colors[BLACK]);
DrawString( 350, 650, "Highscore (L)", colors[BLACK]);
DrawString( 350, 600, "Help (H)", colors[BLACK]);
DrawString( 350, 550, "exit (E)", colors[BLACK]);}
else if(help==false && highest==false && exit_1==false && newgame==true){
gobackpiece();
newgame=false;
b=false;
}
else if(help==false && highest==false && exit_1==true && newgame==false){
exit(1);
}
else if(help==false && highest==true && exit_1==false && newgame==false){
readfromfile();

}
else if(help==true && highest==false && exit_1==false && newgame==false){
HELP();
}
}


glutPostRedisplay();
}




//Functions created show the pause menu when ever the pause button is presed

void pausemenu(){

	if(b==true){	
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
				0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	if(help==false && highest==false && exit_1==false && newgame==true && resume==false){
DrawSquare( 0 , 0 ,1100,colors[BLACK]);
DrawRectangle(300, rectY, 350, 60,colors[MISTY_ROSE]);
DrawString( 350, 750, "New Game (N)", colors[RED]); 
DrawString( 350, 700, "Resume (S)", colors[RED]);
DrawString( 350, 650, "Highscore (H)", colors[RED]);
DrawString( 350, 600, "Help (L)", colors[RED]);
DrawString( 350, 550, "Exit (E)", colors[RED]);}
else if(help==false && highest==false && exit_1==false && newgame==false && resume==false){
gobackpiece();
}
else if(help==false && highest==false && exit_1==true && newgame==false && resume==false){
exit(1);
}
else if(help==false && highest==true && exit_1==false/* && newgame==false */&& resume==false){
readfromfile();

}
else if(help==true && highest==false && exit_1==false/* && newgame==false*/ && resume==false){
HELP();
}
else if(help==false && highest==false && exit_1==false && newgame==false && resume==true){
	b=false;
}
}


glutPostRedisplay();

}


//Checking in which square is the users car

void checkbox()
{

if((x_1>=25&&x_1<=905) && (y_1>=20 && y_1<=900))
{
//cout<<"in 0"<<endl;
in_0=true;
in_1=false;
in_2=false;
in_3=false;
if((x_1>=153&&x_1<=825) && (y_1>=132 && y_1<=764))
{
//cout<<"in 1"<<endl;
in_0=false;
in_1=true;
in_2=false;
in_3=false;
if((x_1>=257&&x_1<=681) && (y_1>=244 && y_1<=660))
{//cout<<"in 2 "<<endl;
in_0=false;
in_1=false;
in_2=true;
in_3=false;

if((x_1>=377&&x_1<=593) && (y_1>=364 && y_1<=548))
{//cout<<"in 3"<<endl;
in_0=false;
in_1=false;
in_2=false;
in_3=true;
}

}

}


}
// Checking in which box is the oppopnents car

if((x_2>=20&&x_2<=905) && (y_2>=20 && y_2<=900))
{

computer_in_0=true;
computer_in_1=false;
computer_in_2=false;
computer_in_3=false;
if((x_2>=140&&x_2<=790) && (y_2>=132 && y_2<=790))
{
//cout<<"Check computer = "<<endl;
computer_in_0=false;
computer_in_1=true;
computer_in_2=false;
computer_in_3=false;

if((x_2>=257&&x_2<=681) && (y_2>=244 && y_2<=660))
{//cout<<"Check computer = "<<endl;
computer_in_0=false;
computer_in_1=false;
computer_in_2=true;
computer_in_3=false;

if((x_2>=385&&x_2<=557) && (y_2>=364 && y_2<=548))
{
computer_in_0=false;
computer_in_1=false;
computer_in_2=false;
computer_in_3=true;
}

}

}


}




}

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
       
}



/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */








	
//Checking if the collision happened between the opponent and the users car and gettin gthe highscore between 3 lifes here

void checkcollision(){

if((x_1>=x_2-50 && x_1<=x_2+50) && (y_1>=y_2-50&& y_1<=y_2+50)  )
{

if ((goright==true && left_1==true)   || (goleft==true && right_1==true) || (godown==true && up==true)  ||(goup==true && down==true))
{
if(life<=3){
//cout<<"Yes"<<endl;

life=life-1;;

cout<<"highscore is = "<<highscore<<endl;
if(highscore>temp)
{


temp=highscore;
cout<<"Temp is = "<<temp<<endl;
}
cout<<"Temp outside is = "<<temp<<endl;
resetarray();

x_1=x_1;
y_1=y_1;
x_2=x_2;
y_2=y_2;

if(level==1)
{

highscore=0;
}
if(level==2)
{
highscore=64;
}
if(level==3)
{
highscore=128;
}
system("cls");

gobackpiece();
}
}
}

}
		
		//Functions created to check if the car is at the same place as the food and changing levels here

void checkcar()
{


for(int i=80;i<=1000;i+=125)
	{
	for(int j=75;j<=980;j+=105)
	{
		if(j>=400&&j<=500){}else
		if((i>=x_1  &&  i<=x_1+100)  &&  (j>y_1-5 && j<=y_1+70))
		{
				if(arr[i][j]!=-1)
			highscore++;
			arr[i][j]=-1;
			
			
//cout<<"innnnn"<<endl;
			
			
		}
			//cout<<"F is = "<<f<<endl<<endl;
	}	

	}




if(highscore==64)
{

level=2;
resetarray();
gobackpiece();
sleep(2);
highscore=0;
//life=3;
//once++;

}


if(highscore==128)
{

level=3;
resetarray();
gobackpiece();
sleep(2);
highscore=64;
//life=3;
//once++;

}

if(highscore==192)
{

startmenu=true;
level=4;
sleep(2);
STARTMENU();
//life=3;
//once++;

}
}

// seed the random numbers generator by current time (see the documentation of srand for further help)...




/*
 * Main Canvas drawing function.
 * */
//Board *b;

int once=0; // variable used for pause menu


void GameDisplay()/**/{
if(startmenu==true)   // conditoin to check whether to call start menu or not
{
STARTMENU();

}
else 
if(b==true){  //conditoin to check whether the game is pause or not
//newgame=false;
pausemenu();


}
	else{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
string Num2Str(int highscore);
string score= "Score = " + Num2Str(highscore);
if (newgame==true&& once==0){

resetarray();
gobackpiece();
highscore=0;
life=3;
once++;
}







	// calling some functions from util.cpp file to help students
DrawString( 50, 1000, score, colors[MISTY_ROSE]);
DrawString( 900, 1000, "Level = "+Num2Str(level), colors[MISTY_ROSE]);
	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Squareat 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	// Drawing opponent car
	
	float width = 20; 
	float height = 15;
	float* color = colors[RED]; 
	float radius = 5.0;
	DrawRoundRect(x_2,y_2,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x_2+width*3,y_2,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x_2+width*3,y_2+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x_2,y_2+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x_2, y_2+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x_2+width, y_2+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x_2+width*3, y_2+height*2, width, height, color, radius/2); // body right rect




	//drawing own car
	
	float width_1 = 20; 
	float height_1 = 15;
	float* color_1 = colors[MISTY_ROSE]; 
	float radius_1 = 5.0;
	DrawRoundRect(x_1,y_1,width_1,height_1,color_1,radius_1); // bottom left tyre
	DrawRoundRect(x_1+width_1*3,y_1,width_1,height_1,color_1,radius_1); // bottom right tyre
	DrawRoundRect(x_1+width_1*3,y_1+height_1*4,width_1,height_1,color_1,radius_1); // top right tyre
	DrawRoundRect(x_1,y_1+height_1*4,width_1,height_1,color_1,radius_1); // top left tyre
	DrawRoundRect(x_1, y_1+height_1*2, width_1, height_1, color_1, radius_1/2); // body left rect
	DrawRoundRect(x_1+width_1, y_1+height_1, width_1*2, height_1*3, color_1, radius_1/2); // body center rect
	DrawRoundRect(x_1+width_1*3, y_1+height_1*2, width_1, height_1, color_1, radius_1/2); // body right rect

	// Drawing Arena
	int gap_turn = 120;
	int sx = 20;
	int sy = 10;
	int swidth = 970/2 - gap_turn/2; // half width
	int sheight = 5;
	float *scolor = colors[RED];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+970, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+970, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	
	
	// Drawing second smaller Arena
	 gap_turn = 120;
	 sx = 255;
	 sy = 230;
	 swidth = 510/2 - gap_turn/2; // half width
	 sheight = 5;
	float *scolor_1 = colors[RED];
	DrawRectangle(sx, sy+8, swidth, sheight, scolor_1); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy+8, swidth, sheight, scolor_1); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor_1); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor_1); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+510, swidth, sheight, scolor_1); // top left
	DrawRectangle(sx, sy+510, swidth, sheight, scolor_1); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor_1); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor_1); // left down



// Drawing  smaller Arena
	 gap_turn = 120;
	 sx = 380;
	 sy = 350;
	 swidth = 280/2 - gap_turn/2; // half width
	 sheight = 5;
	float *scolor_2 = colors[RED];
	DrawRectangle(sx, sy+8, swidth, sheight, scolor_2); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy+8, swidth, sheight, scolor_2); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor_2); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor_2); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+280, swidth, sheight, scolor_2); // top left
	DrawRectangle(sx, sy+280, swidth, sheight, scolor_2); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor_2); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor_2); // left down

if(once==0)
{
sleep(2);
}
// Drawing smallest smaller Arena
	 gap_turn = 0;
	 sx = 500;
	 sy = 455;
	 swidth = 40/2 - gap_turn/2; // half width
	 sheight = 5;
	float *scolor_3 = colors[RED];
	DrawRectangle(sx, sy+8, swidth, sheight, scolor_3); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy+8, swidth, sheight, scolor_3); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor_3); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor_3); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+37, swidth, sheight, scolor_3); // top left
	DrawRectangle(sx, sy+37, swidth, sheight, scolor_3); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor_3); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor_3); // left down


// Drawing outer Arena
	 gap_turn = 120;
	 sx = 150;
	 sy = 120;
	 swidth = 720/2 - gap_turn/2; // half width
	 sheight = 5;
	
	DrawRectangle(sx, sy+8, swidth, sheight, scolor_1); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy+8, swidth, sheight, scolor_1); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor_1); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor_1); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+720, swidth, sheight, scolor_1); // top left
	DrawRectangle(sx, sy+720, swidth, sheight, scolor_1); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor_1); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor_1); // left down
	




//float  arr[1001][1001];
//bool in =false;

//	for(int i=80;i<=1000;i+=125)
//	{
//	for(int j=75;j<=980;j+=105)
//	{
//		if(j==525)
//		{
		
//		arr[i][j]=-1;
//		}
//		else
//		arr[i][j]=j;

	//}	

	//}

	checkcar();
//Drawing dots here

for(int k=80;k<=1000;k+=125)
					{
						for(int l=75;l<=980;l+=105)
							{
							if(l>=400&&l<=500){}else
								if( arr[k][l] ==-1 /*|| arr[k][l] == 0 || arr[k][l]==2*/)
								{
										// highscore++;
										//	f++;
								//glutDisplayFunc(GameDisplay);
									
								}
									else
									{
									DrawCircle(k,l,10,colors[RED]);
										//glutDisplayFunc(GameDisplay);
									}
							}
						//cout<<"This is f "<<f<<endl<<endl<<endl;
					}
	
string lifes="life = " + Num2Str(life);
DrawString( 500, 1000, lifes, colors[MISTY_ROSE]);


if (life==0){
x_1=x_1;
y_1=y_1;
x_2=x_2;
y_2=y_2;
level=1;

writescore();
cout<<"highscore"<<highscore<<endl;
write_file();
b=true;
startmenu=true;
STARTMENU();

}

}
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */


// function to control movement of users car

void owncarmove(){



if(goright==true)
{

x_1+=8;

}
else
if(goleft==true)
{

x_1-=8;

}
else
if(goup==true)
{

y_1+=8;

}
else
if(godown==true)
{

y_1-=8;

}

//cout<<"x1 = "<<x_1<<" &  y1 = "<<y_1<<endl;


}


//function to check where the car should move
void moveup(){
goup=true;
godown=false;
goright=false;
goleft=false;

}

void moveright(){
goup=false;
godown=false;
goright=true;
goleft=false;

}

void moveleft(){
goup=false;
godown=false;
goright=false;
goleft=true;

}

void movedown(){
goup=false;
godown=true;
goright=false;
goleft=false;

}
void NonPrintableKeys(int key, int x, int y) {

	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
               { 
           if(in_0==true)
        {
        if((x_1>=889 && x_1<=913)  && (y_1>=430 && y_1<=470))
        {


        for(int i=0;i<=3;i++){
        moveleft();
        owncarmove();
        }
        }
        }

        if(in_1==true)
        {
        if((x_1>=777 && x_1<=793)  && (y_1>=430 && y_1<=470))
        {


        for(int i=0;i<=3;i++){
        moveleft();
        owncarmove();   
        }

        }


        if((x_1>=145 && x_1<=161)  && (y_1>=430 && y_1<=470))
        {


        for(int i=0;i<=3;i++){
        moveleft();
        owncarmove();
        }

        }   
        }
        if(in_2==true)
        {
        if((x_1>=673 && x_1<=689)  && (y_1>=438 && y_1<=478))
        {


        for(int i=0;i<=3;i++){
        moveleft();
        owncarmove();
        }

        }

        if((x_1>=257 && x_1<=281)  && (y_1>=438 && y_1<=478))
        {
        //cout<<"Here"<<endl;

        for(int i=0;i<=6;i++){
        moveleft();
	
        owncarmove();
        

        }   

        }

       	

        }

        if(in_3==true)
        	{
       	 if((x_1>=300 && x_1<=500)  && (y_1>=438 && y_1<=478))
       		 {cout<<"Left = "<<endl;
        	//cout<<"Here"<<endl;
        		for(int i=0;i<=3;i++){
        		moveleft();
        		owncarmove();
        					}
        	}
        	}
    
  // x_1-=8;
   //cout<<"x1 = "<<x_1<<" &  y1 = "<<y_1<<endl;

   
                }   
           
      else if (key
	    		== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
                {

             	if(in_0==true){
                if((x_1>=17 && x_1<=49)  && (y_1>=430 && y_1<=470))
                    {


                    for(int i=0;i<=3;i++){
                    moveright();
                    owncarmove();
                    }

                    }
                        }

                        if(in_1==true)
                        {

                            if((x_1>=145 && x_1<=161)  && (y_1>=430 && y_1<=470))
                                {


                                for(int i=0;i<=3;i++){
                                moveright();
                                owncarmove();
                                }

                                }

                              if((x_1>=777 && x_1<=793)  && (y_1>=438 && y_1<=470))
        {


        for(int i=0;i<=4;i++){
        moveright();
        owncarmove();
        }
        }
                        }

        if(in_2==true){
        if((x_1>=257 && x_1<=281)  && (y_1>=438 && y_1<=478))
        {
        //cout<<"Here"<<endl;
        for(int i=0;i<=3;i++){
        moveright();
        owncarmove();
        }

       }

                        if((x_1>=673 && x_1<=689)  && (y_1>=438 && y_1<=478))
                        {


                        for(int i=0;i<=4;i++){
                        moveright();
                        owncarmove();   
                        }

                        }
                        }

                        if(in_3==true)
                    {

                    if((x_1>=553 && x_1<=577)  && (y_1>=438 && y_1<=478))
                    {


                    for(int i=0;i<=3;i++){
                    moveright();
                    owncarmove();
                    }

                    }

                    }

                   // x_1+=8;

                    //cout<<"x1 = "<<x_1<<" &  y1 = "<<y_1<<endl;



                        } else if (key
                                == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

                    if(in_0==true){

                    if((x_1>=449 && x_1<=481)  && (y_1>=14 && y_1<=60))
                    {
                    cout<<"Here"<<endl;
                    for(int i=0;i<=3;i++){
                    moveup();
                    owncarmove();
                    }


                    }
                    }

                    if(in_1==true){

                    if((x_1>=449 && x_1<=481)  && (y_1>=142 && y_1<=166))
                    {

                    for(int i=0;i<=2;i++){
                    moveup();
                    owncarmove();
                    }
                    }

                    if((x_1>=449 && x_1<=481)  && (y_1>=750 && y_1<=766))
                     {


                                            for(int i=0;i<=4;i++){
                    moveup();
                    owncarmove();
                    }

                                        }
                    }

                    if(in_2==true){

                    if((x_1>=457 && x_1<=497)  && (y_1>=246 && y_1<=278))
                    {

                    for(int i=0;i<=4;i++){
                    moveup();
                    owncarmove();
                    }
                    }

                    if((x_1>=457 && x_1<=497)  && (y_1>=638 && y_1<=662))
                                        {


                                            for(int i=0;i<=4;i++){
                    moveup();
                    owncarmove();
                    }
                                        }



                    }

                    if(in_3==true)
        	{
       	 if((x_1>=457 && x_1<=497)  && (y_1>=526 && y_1<=542))
       		 {cout<<"Left = "<<endl;
        	//cout<<"Here"<<endl;
        		for(int i=0;i<=3;i++){
        		moveup();
        		owncarmove();
        					}
        	}
        	}
if(startmenu==true && b==false)
{

if(rectY>=500&& rectY<=650)
rectY+=50;
}
if(b==true)
{

if(rectY>=500&& rectY<=700)
rectY+=50;

}

    // y_1+=8;
      //          cout<<"x1 = "<<x_1<<" &  y1 = "<<y_1<<endl;
                        }

                        else if (key
                            == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {


                                    if(in_0==true)
                                    {
                                        if((x_1>=449 && x_1<=489)  && (y_1>=854 && y_1<=905))
                                        {
                                         for(int i=0;i<=2;i++){
                                            movedown();
                                            owncarmove();
                                            }

                                        }
                                    }

                                    if(in_1==true)
                                        {
                                        if((x_1>=449 && x_1<=489)  && (y_1>=750 && y_1<=766))
                                        {


                                            for(int i=0;i<=2;i++){
                                            movedown();
                                            owncarmove();
                                            }

                                        }

                    if((x_1>=449 && x_1<=489)  && (y_1>=142 && y_1<=166))
                    {

                    for(int i=0;i<=2;i++){
                    movedown();
                    owncarmove();
                    }

                                    }
                                        }


                    if(in_2==true)
                                        {
                                        if((x_1>=457 && x_1<=497)  && (y_1>=638 && y_1<=662))
                                        {


                                            for(int i=0;i<=2;i++){
                    movedown();
                    owncarmove();
                    }
                                        }

                    if((x_1>=457 && x_1<=497)  && (y_1>=246 && y_1<=278))
                    {

                    for(int i=0;i<=4;i++){
                    movedown();
                    owncarmove();
                    }

                                    }
                                        }
}
if (key
                            == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
                    if(in_3==true)
                    {

                    if((x_1>=457 && x_1<=497)  && (y_1>=374 && y_1<=382))
                    {

                    for(int i=0;i<=4;i++){
                    movedown();
                    owncarmove();
                    }


}

                    



          //   y_1-=8;
            // cout<<"x1 = "<<x_1<<" &  y1 = "<<y_1<<endl;
                      }}
            //            } else 
 if (key
                             == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
 if(startmenu==true && b==false)
 {

 if(rectY>=550 && rectY<=680)
 rectY-=50;
 }


if(b==true)
{

if(rectY>=550&& rectY<=730)
rectY-=50;

}
 }

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	glutDisplayFunc(GameDisplay);
	glutPostRedisplay();

                                        
}

/*This function is called (automatically) whenever any gotoable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

void PrintableKeys(unsigned char key, int x, int y) {


	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit_1 the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B')
			{

	
		cout << "b pressed" << endl;

	}
if(key==8)
{
if(b==true && (highest==true || help==true))
{
highest=false;help=false;
pausemenu();

}

if(startmenu==true && (highest==true || help==true))
{
highest=false;help=false;
STARTMENU();
}

}


	
if (key == 's' || key =='S')
{


b=false;
}

//if (key == 'N' || key == 'n')
//{startmenu=false;
//endmenu=false;
// create another bool for window and when that true thn newgame ==true..
//	newgame=true;
//once=0;


		//do something if b is pressed
		//cout << "b pressed" << endl;
//}
if(startmenu==true && (key=='N' || key=='n') && help==false && highest==false && exit_1==false)
	{
		newgame=true;
startmenu=false;

// create another bool for window and when that true thn newgame ==true..
endmenu=false;
b=false;
once=0;


	}
if(startmenu==true && (key=='H' || key=='h') && newgame==false && highest==false && exit_1==false)
	{
		help=true;
	}
if(startmenu==true && (key=='Y' || key=='y') && help==false && newgame==false && exit_1==false && highest==true)
	{
		highest=false;
		STARTMENU();

	}

if(startmenu==true && (key=='L' || key=='l') && help==false && newgame==false && exit_1==false)
	{
		highest=true;

	}
if(startmenu==true && (key=='e' || key=='E') && help==false && highest==false && newgame==false)
	{
		exit_1=true;
	}
if(startmenu==false && (key=='P' || key=='p'))
	{
		b=true;	
	}
	if(startmenu==false && b==true)
		{
			if(b==true && key=='N' && help==false && highest==false && exit_1==false)
	{
		newgame=true;
gobackpiece();
once=0;
b=false;


	}
if(b==true && (key=='H'||key=='h')  && newgame==false && highest==false && exit_1==false)
	{
		help=true;
	}
if(b==true && (key=='N'||key=='n')  && help==false && highest==false && exit_1==false)
	{
				newgame=true;
b=false;

// create another bool for window and when that true thn newgame ==true..
endmenu=false;

once=0;

	}
if(b==true && (key=='Y' || key=='y') &&  highest==true)
	{
		highest=false;
		pausemenu();

	}
if(b==true && (key=='L'||key=='l') && help==false && newgame==false && exit_1==false)
	{
		highest=true;

	}
if(b==true && (key=='E' || key=='e') && help==false && highest==false && newgame==false)
	{
		exit_1=true;
	}
if(b==true && (key=='S'||key=='s') && help==false && highest==false && newgame==false)
	{
		b=false;
	}
		}

if(key==13)
{


if(startmenu==true){


if(rectY>=650 && rectY<=700)
{
startmenu=false;
// create another bool for window and when that true thn newgame ==true..
endmenu=false;
b=false;
once=0;



newgame=true;
startmenu=false;
// create another bool for window and when that true thn newgame ==true..
endmenu=false;
b=false;
once=0;



}

if(rectY>=600 && rectY<=650)
{
highest=true;
}

if(rectY>=550 && rectY<=600)
{
help=true;
}

if(rectY>=500 && rectY<=550)
{
exit(1);
}
}

if(b==true){

if(rectY>=700 && rectY<=730)
{
startmenu=false;
// create another bool for window and when that true thn newgame ==true..
endmenu=false;
b=false;
once=0;



newgame=true;
startmenu=false;
// create another bool for window and when that true thn newgame ==true..
endmenu=false;
b=false;
once=0;



}

if(rectY>=650 && rectY<=700)
{
b=false;
}

if(rectY>=600 && rectY<=650)
{
highest=true;
}

if(rectY>=550 && rectY<=600)
{
help=true;
}

if(rectY>=500 && rectY<=550)
{
exit(1);
}

}



}

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */


/*void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}*/



/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;

	
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {


	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
				
		

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */



//Moving computer car

void  movecomp(){


if(right_1==true)
{

if(level==3)
{
x_2+=8;
}else
x_2+=6;

}
else
if(left_1==true)
{

if(level==3)
{
x_2-=8;
}else
x_2-=6;

}
else
if(up==true)
{

if(level==3)
{
y_2+=8;
}
else
y_2+=6;

}
else
if(down==true)
{

if(level==3)
{
y_2-=8;
}
else
y_2-=6;

}




//cout<<" computer x = "<<x_2<<"    computer  y = "<<y_2<<endl;



}


//Getting where the food are and get scores from the file

void for_food(){

//for(int i=80;i<=1000;i+=125)
//	{
//	for(int j=75;j<=980;j+=105)
//	{
//		if(j<=400 || j>=500)
//		{
		
//		arr[i][j]=j;
//		}
//		else
//		arr[i][j]=-1;

//	}	

//	}


for(int i=80;i<=1000;i+=125)
	{
cout<<" i = "<<i<<" ";
	for(int j=75;j<=980;j+=105)
	{
		
		cout <<"j ="<<j<<" ";

	}	
cout<<endl;
	}
int i=0;
string score;
	ifstream fin ("high score.txt"); //name of the file it is supposed to read
	if (fin.is_open())
	{
		while ( getline (fin, score) ) //this loop will run depending on the number of lines in the file
		{
		  scores[i]=stoi(score);
cout<<stoi(score)<<endl;
		  i++;
		  //HINT: use stoi() to convert string into Integer
		  
		}
		fin.close();
	}
	sorting();
for(int j=0;j<=9;j++)
{

cout<<scores[i]<<endl;
}
write_file();

}
////////////////////////////////////////////////CHECKING MOVEMENT OF COMPUTER AND USER FROM HERE ONWARDS/////////////////////////////////////

//For computer to go down when called

void go_down_1(){

if(x_2<480 )
{
down=false;
up=false;
right_1=true;
left_1=false;
}

if(x_2>=480 && x_2<=490)
{

down=true;
up=false;
right_1=false;
left_1=false;
}


}

//For computer to go left when called
void turnleft_1(){

if(y_2>440 )
{
down=true;
up=false;
right_1=false;
left_1=false;
}


if(y_2>=444 && y_2<=460)
{

down=false;
up=false;
right_1=false;
left_1=true;
}


}

//For computer to go right when called

void turnright_1(){

if(y_2>=20 && y_2<=460)
{
down=false;
up=true;
right_1=false;
left_1=false;
}


if(y_2>=444 && y_2<=460)
{

down=false;
up=false;
right_1=true;
left_1=false;
}

}

//For computer to go up when called

void go_up_1(){

if(x_2>470 )
{
down=false;
up=false;
right_1=false;
left_1=true;
}

if(x_2>=478 && x_2<=490)
{

down=false;
up=true;
right_1=false;
left_1=false;
}


}

//Going to 1st square to 2nd square

void go_toin_1(){

if(x_2>=889 && x_2<=905)
{

turnleft_1();
cout<<"Left"<<endl;
}
else if((x_2>=110 && x_2<=809) && (y_2>=852 && y_2<=900) ){
go_down_1();

}else
if(x_2>=25 && x_2<=49)
{

turnright_1();
cout<<"right"<<endl;
}else
if((x_2>=129 && x_2<=809) && (y_2>=20 && y_2<=60) )
{

go_up_1();
}

//setmode();
}



void go_down_2(){

//cout<<"In down"<<endl;
	if(x_2<480 )	
	{
	if(go_out==true){
	down=false;
	up=false;
	right_1=false;
	left_1=true;
	}
	else
	{
	down=false;
	up=false;
	right_1=true;
	left_1=false;

	
	}	
	}

if(x_2>=473 && x_2<=480)
{
if(go_out==true)
{
down=false;
up=true;
right_1=false;
left_1=false;
}else
{
down=true;
up=false;
right_1=false;
left_1=false;
}

go_out=false;
}
}

void turnleft_2(){  

//cout<<"In left "<<endl;
if(y_2>=440 && y_2<=764)
{

down=true;
up=false;
right_1=false;
left_1=false;

}


if(y_2>=444 && y_2<=460)
{
down=false;
up=false;
right_1=false;
left_1=true;
}

go_out=false;

}


void turnright_2(){

//cout<<"In right "<<endl;
if(y_2>=148 && y_2<452)

{
down=false;
up=true;
right_1=false;
left_1=false;

}


if(y_2>=452 && y_2<=460)
{

down=false;
up=false;
right_1=true;
left_1=false;


}
//if(go_out==true){
//cout<<"True 1"<<endl;
//}else
//cout<<"False 1"<<endl;

go_out=false;
}

void go_up_2(){
if (computer_in_0==true && in_0==true)
{
go_out=false;

}
if(x_2>480 )
{
//cout<<"In up "<<endl;
if(go_out==true){

down=false;
up=false;
right_1=true;
left_1=false;

}else{
down=false;
up=false;
right_1=false;
left_1=true;
}
}
if(x_2>=470 && x_2<=490)
{
if(go_out==true){
down=true;
up=false;
right_1=false;
left_1=false;



}else{
down=false;
up=true;
right_1=false;
left_1=false;
}
}
go_out=false;

}








//Going to second loop or square.
void go_toin_2(){

if(x_2>=777 && x_2<=793)
{

turnleft_2();

}
else if((x_2>=193 && x_2<=785) && (y_2>=748 && y_2<=764) ){
go_down_2();

}else
if(x_2>=130 && x_2<=161)
{

turnright_2();
}else
if((x_2>=193 && x_2<=785) && (y_2>=140 && y_2<=164) )
{

go_up_2();
}
go_out=false;
//setmode();

}






//for smaller 3
void go_down_3(){

if(x_2<=480 )
{
down=false;
up=false;
right_1=true;
left_1=false;
}

if(x_2>=480 && x_2<=490)
{

down=true;
up=false;
right_1=false;
left_1=false;
}


}

void turnleft_3(){

if(y_2>440 && y_2<=756)
{
down=true;
up=false;
right_1=false;
left_1=false;
}


if(y_2>=444 && y_2<=460)
{

down=false;
up=false;
right_1=false;
left_1=true;
}


}


void turnright_3(){

if(y_2<444)
{
down=false;
up=true;
right_1=false;
left_1=false;
}


if(y_2>=444 && y_2<=460)
{

down=false;
up=false;
right_1=true;
left_1=false;
}

}

void go_up_3(){

if(x_2>=537 )
{
down=false;
up=false;
right_1=false;
left_1=true;
}

if(x_2>=470 && x_2<=490)
{

down=false;
up=true;
right_1=false;
left_1=false;
}


}




void go_toin_3(){

if(x_2>=673 && x_2<=681)
{

turnleft_3();

}
else if((x_2>=257 && x_2<=681) && (y_2>=636 && y_2<=668) ){
go_down_3();

}else
if(x_2>=249 && x_2<=281)
{

turnright_3();
}else
if((x_2>=249 && x_2<=681) && (y_2>=238 && y_2<=284) )
{
//cout<<"Go up "<<endl;
go_up_3();
}



//setmode();



}






void in0(){

	//cout<<"Hello"<<endl;
if((x_2>=895 && x_2<=910) && ((y_2>=15&& y_2<=28) || (y_2>=440&& y_2<=460)))
{
right_1=false;
up=true;
down=false;
left_1=false;

//cout<<"Go up"<<endl;
}

if( ((x_2>=900 && x_2<=905) ||(x_2>=465 && x_2<=481)) && ((y_2>=890&& y_2<=900)|| (y_2>=868&& y_2<=890)) )
{
right_1=false;
up=false;
down=false;
left_1=true;
//cout<<"Go left"<<endl;
}

if( (x_2>=10 && x_2<=40) &&( (y_2>=860&& y_2<=900) || (y_2>=444&& y_2<=465)))
{
right_1=false;
up=false;
down=true;
left_1=false;

//cout<<"Go down"<<endl;
}


if( ((x_2>=20 && x_2<=36) || (x_2>=460 && x_2<=470))&& (y_2>=10&& y_2<=28) )
{
right_1=true;
up=false;
down=false;
left_1=false;
//cout<<"Go right"<<endl;
}


}

void in_00(){

	//cout<<"Hello"<<endl;
if(((x_1>=10&& x_1<=42) || (x_1>=420&& x_1<=500))&& (y_1>=868&& y_1<=908) )
{
goright=true;
goup=false;
godown=false;
goleft=false;

//cout<<"right = "<<endl;
}

if( (((x_1>=889 && x_1<=913) )&& ((y_1>=860 && y_1<=908)     || (y_1>=438 && y_1<=470))  ) )
{
goright=false;
goup=false;
godown=true;
goleft=false;

}

if( (x_1>=21 && x_1<=40) &&( (y_1>=10&& y_1<=880)))
{
goright=false;
goup=true;
godown=false;
goleft=false;
//cout<< " x1 = "<<x_1<<endl;

}


if( (x_1>=40 && x_1<=905) && (y_1>=10&& y_1<=44) )
{
goright=false;
goup=false;
godown=false;
goleft=true;
//cout<<"y1 is "<<y_1;
}


}

void in1(){


//cout<<"Hello in 1 "<<endl;
if((x_2>=777 && x_2<=804) && (y_2>=140&& y_2<=764))
{
right_1=false;
up=true;
down=false;
left_1=false;
}

if( (x_2>=161&& x_2<=793) && ((y_2>=756&& y_2<=764) ) )
{
right_1=false;
up=false;
down=false;
left_1=true;
}

if( (x_2>=140 && x_2<=160) && ((y_2>=740&& y_2<=764) || (y_2>=444&& y_2<=468))  )
{
right_1=false;
up=false;
down=true;
left_1=false;
}


if( ((x_2>=140 && x_2<=161) || (x_2>=457 && x_2<=489)) && (y_2>=140&& y_2<=156) )
{
right_1=true;
up=false;
down=false;
left_1=false;

}


}

void in_01(){


//cout<<"Hello in 1 "<<endl;
if(((x_1>=153 && x_1<=785)  || (x_1>=400 && x_1<=500 ))&& (y_1>=748&& y_1<=764))
{
goright=true;
goup=false;
godown=false;
goleft=false;
//cout<<"right"<<endl;
}

if(((x_1>=777 && x_1<=793))&& ((y_1>=180&& y_1<=764) ) )
{
goright=false;
goup=false;
godown=true;
goleft=false;
//cout<<"down"<<endl;
}

if( (x_1>=153 && x_1<=168) && ((y_1>=140&& y_1<=740) ))
{
goright=false;
goup=true;
godown=false;
goleft=false;
//cout<<"up"<<endl;
}


if( ((x_1>=169 && x_1<=793)) && (y_1>=140&& y_1<=164) )
{
goright=false;
goup=false;
godown=false;
goleft=true;

//cout<<"left"<<endl;
}


}


void in_02(){


//cout<<"Hello in 1 "<<endl;
if(((x_1>=257 && x_1<=681)  || (x_1>=400 && x_1<=500 ))&& (y_1>=636&& y_1<=668))
{
goright=true;
goup=false;
godown=false;
goleft=false;
//cout<<"right"<<endl;
}

if(((x_1>=673 && x_1<=689))&& ((y_1>=276&& y_1<=668) ) )
{
goright=false;
goup=false;
godown=true;
goleft=false;
//cout<<"down"<<endl;
}

if( (x_1>=257 && x_1<=289) && ((y_1>=244&& y_1<=644) ))
{
goright=false;
goup=true;
godown=false;
goleft=false;
//cout<<"up"<<endl;
}


if( ((x_1>=289 && x_1<=793)) && (y_1>=244&& y_1<=276) )
{
goright=false;
goup=false;
godown=false;
goleft=true;

//cout<<"left"<<endl;
}


}

void in_03(){


//cout<<"Hello in 1 "<<endl;
if(((x_1>=377 && x_1<=577)  || (x_1>=400 && x_1<=500 ))&& (y_1>=500&& y_1<=600))
{
goright=true;
goup=false;
godown=false;
goleft=false;
cout<<"right"<<endl;
}

if(((x_1>=553 && x_1<=577))&& ((y_1>=364&& y_1<=542) ) )
{
goright=false;
goup=false;
godown=true;
goleft=false;
//cout<<"down"<<endl;
}

if( (x_1>=377 && x_1<=409) && ((y_1>=366&& y_1<=530) ))
{
goright=false;
goup=true;
godown=false;
goleft=false;
cout<<"up"<<endl;
}


if( ((x_1>=385 && x_1<=577)) && (y_1>=366&& y_1<=382) )
{
goright=false;
goup=false;
godown=false;
goleft=true;

//cout<<"left"<<endl;
}


}
void in2(){



//cout<<"Hello in 2 "<<endl;
if((x_2>=673 && x_2<=689) && (y_2>=44&& y_2<=660))
{
right_1=false;
up=true;
down=false;
left_1=false;
}

if( (x_2>=257&& x_2<=681) && (y_2>=644&& y_2<=660) )
{
right_1=false;
up=false;
down=false;
left_1=true;
}

if( (x_2>=249 && x_2<=281) && ((y_2>=644&& y_2<=660) || (y_2>=444&& y_2<=468))  )
{
right_1=false;
up=false;
down=true;
left_1=false;
}


if( ((x_2>=257 && x_2<=281) || (x_2>=457 && x_2<=489)) && (y_2>=244&& y_2<=276) )
{
right_1=true;
up=false;
down=false;
left_1=false;

}

}


void in3(){

//cout<<"Hello in 3 "<<endl;
if((x_2>=546 && x_2<=593) && (y_2>=364&& y_2<=556))
{
right_1=false;
up=true;
down=false;
left_1=false;
cout<<" up "<<endl;
}

if( (x_2>=401&& x_2<=569) && (y_2>=516&& y_2<=556) )
{
right_1=false;
up=false;
down=false;
left_1=true;
}

if( (x_2>=377 && x_2<=401) && ((y_2>=500&& y_2<=572) || (y_2>=372&& y_2<=478))  )
{
right_1=false;
up=false;
down=true;
left_1=false;
}


if( ((x_2>=377 && x_2<=546)) && (y_2>=372&& y_2<=382) )
{
right_1=true;
up=false;
down=false;
left_1=false;


}

}

void right_2(){
if(y_2>440 && y_2<=756)
{

down=true;
up=false;
right_1=false;
left_1=false;


}


if(y_2>=444 && y_2<=460)
{

down=false;
up=false;
right_1=true;
left_1=false;



}

}

void down_2(){

if(x_2>=456){

down=false;
up=false;
right_1=false;
left_1=true;

}

if(x_2>=465 && x_2<=473)
{
down=true;
up=false;
right_1=false;
left_1=false;

}


}


void left_2(){

if(y_2<=460){
down=false;
up=true;
right_1=false;
left_1=false;

}

if(y_2>=444 && y_2<=460){

down=false;
up=false;
right_1=false;
left_1=true;

}
}


void up_10(){
if(x_2<=456){

down=false;
up=false;
right_1=true;
left_1=false;

}

if(x_2>=465 && x_2<=473)
{
down=false;
up=true;
right_1=false;
left_1=false;

}






}


void go_out_2(){

if(x_2>=777 && x_2<=793)
{

right_2();

}

if((x_2>=153 && x_2<777) && (y_2>=140 && y_2<=164))
{
down_2();

}

if(x_2>=140 && x_2<=161)
{
left_2();
}

if((x_2>=153 && x_2<777) && (y_2>=748 && y_2<=764))
{
up_10();
}


}
void right_3(){
if(y_2>440 && y_2<=668)
{

down=true;
up=false;
right_1=false;
left_1=false;


}


if(y_2>=444 && y_2<=460)
{

down=false;
up=false;
right_1=true;
left_1=false;



}

}

void down_3(){

if(x_2>513){

down=false;
up=false;
right_1=false;
left_1=true;

}

if(x_2>=457 && x_2<=473)
{
down=true;
up=false;
right_1=false;
left_1=false;

}


}

void left_3(){

if(y_2<=444){
down=false;
up=true;
right_1=false;
left_1=false;

}

if(y_2>=444 && y_2<=460){

down=false;
up=false;
right_1=false;
left_1=true;

}
}

void up_13(){

if(x_2<=465){

down=false;
up=false;
right_1=true;
left_1=false;

}

if(x_2>=465 && x_2<=473)
{
down=false;
up=true;
right_1=false;
left_1=false;

}



}

void go_out_3(){

if(x_2>=673 && x_2<=689)
{

right_3();

}

if((x_2>=249 && x_2<=681) && (y_2>=244 && y_2<=284))
{
//cout<<"down 3"<<endl;
down_3();

}

if(x_2>=257 && x_2<=281)
{
left_3();
}

if((x_2>=249 && x_2<=681) && (y_2>=636 && y_2<=668))
{
up_13();
}


}

void right_4(){
if(y_2>440 && y_2<=556)
{

down=true;
up=false;
right_1=false;
left_1=false;


}


if(y_2>=444 && y_2<=460)
{

down=false;
up=false;
right_1=true;
left_1=false;



}

}

void down_4(){

if(x_2>513){

down=false;
up=false;
right_1=false;
left_1=true;

}

if(x_2>=457 && x_2<=473)
{
down=true;
up=false;
right_1=false;
left_1=false;

}


}
void left_4(){

if(y_2<=444){
down=false;
up=true;
right_1=false;
left_1=false;

}

if(y_2>=444 && y_2<=460){

down=false;
up=false;
right_1=false;
left_1=true;

}
}

void up_14(){

if(x_2<=465){

down=false;
up=false;
right_1=true;
left_1=false;

}

if(x_2>=465 && x_2<=473)
{
down=false;
up=true;
right_1=false;
left_1=false;

}



}


void go_out_4(){

if(x_2>=553 && x_2<=577)
{

// right_4();

}

if((x_2>=377 && x_2<=577) && (y_2>=364 && y_2<=380))
{
//cout<<"down 3"<<endl;
down_4();

}

if(x_2>=377 && x_2<=409)
{
left_4();
}

if((x_2>=377 && x_2<=577) && (y_2>=508 && y_2<=556))
{
up_14();
}


}




void movement()
{


if(level==1)
{
in0();
}
else
{
if (computer_in_0==true && in_0==true)
{
go_out=false;
//cout<<"Both in zero "<<endl;
in0();
}


 if (computer_in_1==true && in_1==true)
{
go_out=false;
in1();
} if (computer_in_2==true && in_2==true)
{
go_out=false;
in2();
} if (computer_in_3==true && in_3==true)
{
go_out=false;
in3();
}
if(computer_in_1==false && computer_in_0==true && computer_in_2==false && computer_in_3==false)
{
//cout<<"Here"<<endl;
}
if(in_1==true && computer_in_0==true)
{
//cout<<"go to 1"<<endl;
go_out=false;
go_toin_1();
}

if(in_2==true && computer_in_2==false)
{go_out=false;

go_toin_1();
go_toin_2();
}

if(in_3==true && computer_in_3==false)
{go_out=false;
go_toin_1();
go_toin_2();
go_toin_3();
}
//cout<<"here "<<endl;

if(in_0==true && computer_in_1==true)
{
//cout<<"go to 0"<<endl;
go_out=false;
go_out_2();
}

if(in_1==true && computer_in_2==true)
{
//cout<<"go to 0"<<endl;

go_out_2();
go_out_3();

}

if(in_2==true && computer_in_3==true){


go_out_2();
go_out_3();
go_out_4();

}


}


}


void owncar(){





if(in_0==true){

in_00();
}

if(in_1==true){

in_01();
}

if(in_2==true){

in_02();
}

if(in_3==true){

in_03();
}



}

//////////////////////////////////////////////////ENDS HERE//////////////////////

// This function sits idle and calls whatevers needed
void idle(){
if(b==false){
if(startmenu==false){
checkbox();
//border();
movement();
owncar();
//temp=highscore;
checkcollision();
go_out=false;
movecomp();
owncarmove();
if(z==1)
for_food();

if(z==1)
z++;
}
}

//cout<<"This is try 1 "<<try1<<endl;

glutDisplayFunc(GameDisplay);
glutPostRedisplay();

}

int main(int argc, char*argv[]) {



	//b = new Board(60, 60); // create a new board object to use in the Display Function ...
	
	int width = 1000, height = 1100; // i have set my window size to be 800 x 600

	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
		
		 
		

	//NonPrintableKeys(c,&x_1,&y=1);
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.

	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);


	glutIdleFunc(idle);


	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();

	return 1;
}
#endif /* AsteroidS_CPP_ */
