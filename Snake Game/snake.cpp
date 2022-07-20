#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <vector>

using std::cout;
using namespace std;

const int HEIGHT = 25, WIDTH = 50;

// Snake Class
class Snake {
private:
    COORD pos;
    int len;
    int vel;
    char direction;
    vector <COORD> body;
public:
    Snake(COORD pos, int vel) : pos(pos), vel(vel), direction('N'), len(1) {
		body.push_back(pos);
	};
    void moveSnake();
    COORD getSnakePos();
    void changeDir(char dir);
    bool eatenFood(const COORD& foodPos);
    void grow();
    vector<COORD> getSnakeBody();
    bool bodyCollison();
};

vector<COORD> Snake::getSnakeBody() {
	return body;
}

bool Snake::bodyCollison(){
	for(int i = 0; i < body.size() - 1; i++){
		if(pos.X == body[i].X && pos.Y == body[i].Y){
			return true;
		}
	}
	return false;
}

void Snake::moveSnake(){
    switch (direction) {
        case 'U': pos.Y -= vel; break;
        case 'D': pos.Y += vel;break;
        case 'L': pos.X -= vel;break;
        case 'R': pos.X += vel;break;
    }
    if(pos.X >= WIDTH-1) pos.X = 1;
    else if (pos.X < 1) pos.X = WIDTH - 1;
    
	if(pos.Y >= HEIGHT-1) pos.Y = 1;
	else if (pos.Y < 1) pos.Y = HEIGHT - 1;
	
	body.push_back(pos);
	if(body.size() > len){
		body.erase(body.begin());
	}
}

COORD Snake::getSnakePos() {
    return pos;
}

void Snake::changeDir(char dir) {
    direction = dir;

}

bool Snake::eatenFood(const COORD& foodPos){
	return (pos.X == foodPos.X && pos.Y == foodPos.Y);
}

void Snake::grow(){
	len++;
}

// Snake Class Ends


// Food Class

class Food {
private:
	COORD pos;
public:
	Food();
	COORD getFoodPos();
	void genFood();

};

Food::Food(){
	genFood();
}

void Food::genFood(){
	pos.X = rand()%(WIDTH-2) + 1;
	pos.Y = rand()%(HEIGHT-2) + 1;
}

COORD Food::getFoodPos(){
	return pos;
}
// Food class ends





Snake snake({1,1}, 1);
Food food;

void board(){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD({0,0}));
    COORD snakePos = snake.getSnakePos();
    COORD foodPos = food.getFoodPos();
    vector<COORD> snakeBody = snake.getSnakeBody();
    for(int i =0; i < HEIGHT; i++){
        for(int j =0; j < WIDTH; j++){
        	
            if(i == 0 || i == HEIGHT -1) cout << "#";
            else if (j == 0 || j == WIDTH - 1) cout << "#";
            else if(i == snakePos.Y && j == snakePos.X) cout << "0";
            else if (i == foodPos.Y && j == foodPos.X) cout << "1";
            else {
            	bool bodyPart = false;
            	for(int k = 0; k<snakeBody.size(); k++){
            		if(i == snakeBody[k].Y && j == snakeBody[k].X){
            			if(k == snakeBody.size() - 1) cout << "0";
            			else cout << "o";
            			bodyPart = true;
            			break;
					}
				}
				
				if(!bodyPart) cout << " ";
			}
            
            
            
            
        }
        cout << "\n";
    }
}

int main() {
	srand(time(0));
    // turn off cursor  visibility
    
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    while(true){
        board();
        if(kbhit()){
            switch(getch()){
                case 'w': snake.changeDir('U'); break;
                case 's': snake.changeDir('D'); break;
                case 'a': snake.changeDir('L');break;
                case 'd': snake.changeDir('R'); break;
            }
        }
        snake.moveSnake();
        if(snake.bodyCollison()){
        	board();
        	cout << "\n GAME OVER!\n";
        	break;
		}
        if(snake.eatenFood(food.getFoodPos())){
        	food.genFood();
        	snake.grow();
		}
    }
    return 0;
}
