#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>

enum position { left, center, right };
using std::cout;
using std::cin;
using std::endl;

int tree_part();

int converter(int output);

void game_loop(int* tree);

void print(int& player, int* tree);

int main()
{
	srand(time(NULL));
	int inp;
	int treePart[5];

	for (int i = 1; i < 5; i++)
		treePart[i] = tree_part();

	cout << "Timberman" << endl;
	cout << "1. Play" << endl;
	cout << "2. Exit" << endl;
	cin >> inp;

	if (inp == 1)
		game_loop(treePart);
	cout << endl << "Game over!" << endl;

	return 0;
}

void game_loop(int* tree)
{
	int player_pos = left;

	while (player_pos != tree[0])
	{
		print(player_pos, tree);

		player_pos = _getch();
		player_pos = (player_pos == 224) ? _getch() : player_pos;
		player_pos = converter(player_pos);

		for (int i = 0; i < 4; i++)
			tree[i] = tree[i+1];
		tree[4] = tree_part();
	}

	print(player_pos, tree);
}

void print(int& player, int* tree)
{
	system("cls");

	for (int i = 4; i > 0; i--)
		if (tree[i] == left)
			cout << "## " << endl;
		else if (tree[i] == right)
			cout << " ##" << endl;
		else
			cout << " # " << endl;

	if (player == tree[0])
		if (player == left)
			cout << "X# ";
		else
			cout << " #X";

	else if (player == left)
		if (tree[0] == center)
			cout << "@# ";
		else
			cout << "@##";

	else if (player == right)
		if (tree[0] == center)
			cout << " #@";
		else
			cout << "##@";

	
}

int tree_part()
{
	int output = rand() % 3;

	return output;
}

int converter(int output)
{
	if (output == 75)
		return left;
	else if (output == 77)
		return right;
	else
		return 3;
}
