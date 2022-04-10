#include "Engine.h"

void Engine::GenerateMaze()
{
	maze.clear();
	coins.clear();

	//Store the data for the generated maze here
	char generated[31][31]; //Generate a 31 by 31 maze

	//Fill the entire maze with walls
	for(int i = 0; i < 31; i++)
		for(int j = 0; j < 31; j++)
			generated[i][j] = '#';

	//Store the current cell the maze generator is currently on
	std::stack<std::pair<int, int>> frontier;
	//Store the path the maze generator took so far
	std::stack<std::pair<int, int>> path;

	//Start at (29, 15)
	frontier.push( { 29, 15 } );
	path.push( { 29, 15 } );

	//Generate the maze
	while(!path.empty())
	{
		std::pair<int, int> cell = frontier.top();
		frontier.pop();
		//Make sure that the cell isn't out of bounds
		if(cell.first < 0 || cell.first > 30 || cell.second < 0 || cell.second > 30)
			continue;

		//Choose a random direction to go in
		int direction = rand() % 4;

		for(int i = 0; i < 4; i++)
		{
			std::pair<int, int> cell2;

			//Get the cell the generator will go to next
			switch(direction)
			{
			//Move up
			case 0:
				cell2 = { cell.first - 2, cell.second };
				break;
			//Move down
			case 1:
				cell2 = { cell.first + 2, cell.second };
				break;
			//Move left
			case 2:
				cell2 = { cell.first, cell.second - 2 };
				break;
			//Move right
			case 3:
				cell2 = { cell.first, cell.second + 2 };
				break;
			}

			//Make sure that the cell we are going to is within bounds
			if(cell2.first >= 0 && cell2.first <= 30 && cell2.second >= 0 && cell2.second <= 30)
			{
				//Check to see if that cell has been visited yet
				if(generated[cell2.first][cell2.second] == '#')
				{
					//Mark that cell as visited
					generated[cell2.first][cell2.second] = '.';
					//Create a passage to that cell
					generated[(cell.first + cell2.first) / 2][(cell.second + cell2.second) / 2] = '.';

					//Add cell2 to the frontier and path
					frontier.push(cell2);
					path.push(cell2);
					break;
				}
			}

			//If the cell that was chosen was invalid, increment direction by 1 and try again
			direction++;
			direction = direction % 4; //Keep direction in the range 0 - 3
		}

		//Hit a dead end
		if(frontier.empty())
		{
			//Have a coin generate in the dead end
			generated[cell.first][cell.second] = '*';		

			//Store if the generator found a cell that it start again in
			bool found = false;
			while(!path.empty() && !found)
			{
				std::pair<int, int> c = path.top();
				path.pop();

				//Choose a random direction to go in
				int direction = rand() % 4;

				for(int i = 0; i < 4; i++)
				{
					std::pair<int, int> c2;

					switch(direction)
					{
					//Move up
					case 0:
						c2 = { c.first - 2, c.second };
						break;
					//Move down
					case 1:
						c2 = { c.first + 2, c.second };
						break;
					//Move left
					case 2:
						c2 = { c.first, c.second - 2 };
						break;
					//Move right
					case 3:
						c2 = { c.first, c.second + 2 };
						break;
					}

					//Make sure that the cell we are going to is within bounds
					if(c2.first >= 0 && c2.first <= 30 && c2.second >= 0 && c2.second <= 30)
					{
						//Check to see if that cell has been visited yet
						if(generated[c2.first][c2.second] == '#')
						{
							//Mark that cell as visited
							generated[c2.first][c2.second] = '.';
							//Create a passage to that cell
							generated[(c.first + c2.first) / 2][(c.second + c2.second) / 2] = '.';
							frontier.push(c2);
							path.push(c2);
							found = true;
							break;
						}
					}

					direction++;
					direction = direction % 4;
				}
			}
		}
	}

	generated[29][15] = '@'; //(29, 15) is where the player starts
	cameraRotation = 0.0f; //Set camera rotation to be 0 radians
	generated[1][15] = 'E'; //(1, 15) is where the maze ends

	//Print out the maze data
	/*for(int i = 0; i < 31; i++)
	{
		for(int j = 0; j < 31; j++) std::cout << generated[i][j];
		std::cout << std::endl;
	}*/

	//Read the maze data
	for(int i = 0; i < 31; i++)
		for(int j = 0; j < 31; j++)
			switch(generated[i][j])
			{
			//Wall
			case '#':
				maze.push_back(glm::vec3(wallSize * 2.0f * i - 31.0f * wallSize, 0.5f, wallSize * 2.0f * j - 31.0f * wallSize));
				break;
			//Coin
			case '*':
				coins.push_back(glm::vec3(wallSize * 2.0f * i - 31.0f * wallSize, 2.0f, wallSize * 2.0f * j - 31.0f * wallSize));
				break;
			//Exit
			case 'E':
				exitPos = glm::vec3(wallSize * 2.0f * i - 31.0f * wallSize, 2.0f, wallSize * 2.0f * j - 31.0f * wallSize);
				break;
			//Player start position
			case '@':
				cameraPosition = glm::vec3(wallSize * 2.0f * i - 31.0f * wallSize, 2.5f, wallSize * 2.0f * j - 31.0f * wallSize);
				break;
			}
}