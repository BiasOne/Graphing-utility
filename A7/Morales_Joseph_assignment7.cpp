#include <iostream>

using namespace std;

class point
{
	//declaring all the private variables to be used by the point class
private:
	//using pairs to store points on the plane
	pair <int, int> pointOne;
	pair <int, int> pointTwo;
	pair <int, int> pointThree;
	int userInput;
	int x;
	int y;

public:
	//default constructor
	point()
	{
		x = 0;
		y = 0;
	}
	//constructor
	point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	//accessor and mutator functions
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y) 
	{
		this->y = y;
	}
	int getX()
	{
		return x;
	}
	int getY() 
	{
		return y;
	}

	//this functions allows the user to select a point and will continue to loop until the user inputs a correct value
	void setPoint() 
	{
		do
		{
			cout << "Which point would you like to set? (1-3)" << endl;
			cin >> userInput;

			if (userInput > 3 || userInput < 1)
			{
				cout << "Please choose a Point between 1 and 3" << endl;
			}

		} while (userInput > 3 || userInput < 1);

		cout << "Enter the x and y coordinates, separated by a space: " << endl;
		//this will take in parameters in multiple ways include if they are separated by a space or a new line
		cin >> x;
		cin >> y;

		cout << "Point " << userInput << "'s coordinates are " << x << ", " << y << endl;
		cout << endl;
		//sets the appropriate value to the paired variables
		if (userInput==1)
		{
			pointOne.first = x;
			pointOne.second = y;
		}
		else if (userInput == 2)
		{
			pointTwo.first = x;
			pointTwo.second = y;
		}
		else if (userInput == 3)
		{
			pointThree.first = x;
			pointThree.second = y;
		}
	
	}
	//this function moves the point to a new location
	void movePoint() 
	{
		int tempX;
		int tempY;

		do
		{
			cout << "Which point would you like to move? (1-3)" << endl;
			cin >> userInput;

			if (userInput > 3 || userInput < 1)
			{
				cout << "Please choose a Point between 1 and 3" << endl;
			}
			else
			{
				cout << "Point " << userInput << "'s coordinates are ";

				if (userInput == 1)
				{
					cout << pointOne.first << ", " << pointOne.second << endl;
					setX(pointOne.first);
					setY(pointOne.second);

				}
				else if (userInput == 2)
				{
					cout << pointTwo.first << ", " << pointTwo.second << endl;
					setX(pointTwo.first);
					setY(pointTwo.second);
				}
				else if (userInput == 3)
				{
					cout << pointThree.first << ", " << pointThree.second << endl;
					setX(pointThree.first);
					setY(pointThree.second);
				}
			}

		} while (userInput > 3 || userInput < 1);
		

		cout << "Enter the amount you would like to move in the x and y direction, followed by a space " << endl;
		cin >> tempX;
		cin >> tempY;

		x += tempX;
		y += tempY;

		if (userInput == 1)
		{
			pointOne.first = x;
			pointOne.second = y;
		}
		else if (userInput == 2)
		{
			pointTwo.first = x;
			pointTwo.second = y;
		}
		else if (userInput == 3)
		{
			pointThree.first = x;
			pointThree.second = y;
		}

		cout << "Point " << userInput << "'s coordinates are now " << x << ", " << y << endl;
		cout << endl;
	}
	//this function rotates the point 90 degrees
	void rotatePoint() 
	{
		int temp;
		do
		{
			cout << "Which point would you like to rotate? (1-3)" << endl;
			cin >> userInput;

			if (userInput > 3 || userInput < 1)
			{
				cout << "Please choose a Point between 1 and 3" << endl;
			}
			else
			{
				cout << "Point " << userInput << "'s coordinates are ";
				//rotates the points 1 2 or 3 - selected by the user
				if (userInput == 1)
				{
					cout << pointOne.first << ", " << pointOne.second << endl;
					setX(pointOne.first);
					setY(pointOne.second);
					temp = x;
					x = y;
					y = temp * -1;
					pointOne.first = x;
					pointOne.second = y;
				}
				else if (userInput == 2)
				{
					cout << pointTwo.first << ", " << pointTwo.second << endl;
					setX(pointTwo.first);
					setY(pointTwo.second);
					temp = x;
					x = y;
					y = temp * -1;
					pointTwo.first = x;
					pointTwo.second = y;
				}
				else if (userInput == 3)
				{
					cout << pointThree.first << ", " << pointThree.second << endl;
					setX(pointThree.first);
					setY(pointThree.second);
					temp = x;
					x = y;
					y = temp * -1;
					pointThree.first = x;
					pointThree.second = y;
				}
			}

		} while (userInput > 3 || userInput < 1);
		
		cout << "Point " << userInput << "'s coordinates are now " << x << ", " << y << endl;
		cout << endl;
		
	}

};


int main() 
{
	char userInput;

	point pointOBJ;
	//asks the user what they would like to do and accepts their input
	do
	{
		cout << "Choose from the following options:" << endl << "s: set a Point's coordinates" << endl << "m: move a Point" << endl << "r: rotate a Point" << endl << "q : quit" << endl;
		cin >> userInput;
		userInput = tolower(userInput);
		//calls the setpoint function
		if (userInput == 's')
		{
			pointOBJ.setPoint();
		}
		//calls the move point function
		else if (userInput == 'm')
		{
			pointOBJ.movePoint();
		}
		//calls the rotate function
		else if (userInput == 'r')
		{
			pointOBJ.rotatePoint();
		}
		else if (userInput == 'q')
		{
			//does nothing
		}
		else 
		{
			cout << "That is not a valid option. " << endl;
		}

	} while (userInput != 'q');


	return 0;
}