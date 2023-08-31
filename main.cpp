#include<iostream>
#include<ctime>
#include<random>
using namespace std;
char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' '};
void showboard();
void player1Choice();
void player2Choice();
void computerChoice();
int countBoard(char symbol);
char checkWinner();
void computerVsPlayer();
void playerVsPlayer();
int menu();
int main() {
	bool flag = false;
	showboard();
	while (true) {
		system("cls");
		switch (menu()) {
		case 1:
			computerVsPlayer();
			flag = true;
			break;
		case 2:
			playerVsPlayer();
			flag = true;
			break;
		case 3:
			exit(0);
		default:
			cout << "Pls Enter Valid choice:";
		}
		if (flag)
			break;
	}
	return 0;
}
int menu() {
	int ch;
	cout << "\t1.Computer VS Player" << endl;
	cout << "\t2.Player VS Player" << endl;
	cout << "\t3.EXIT" << endl;
	cout << "\tEnter your choice:";
	cin >> ch;
	return ch;
}
void playerVsPlayer() {
	string player1, player2;
	cout << "Enter Player1 Name:";
	cin >> player1;
	cout << "Enter Palyer2 Name:";
	cin >> player2;
	while (true) {
		system("cls");
		showboard();
		if (countBoard('X') == countBoard('O')) {
			cout << player1 << " 's trun." << endl;
			player1Choice();
		}
		else {
			cout << player2 << " 's trun." << endl;
			player2Choice();
		}
		char winner = checkWinner();
		if (winner == 'X') {
			system("cls");
			showboard();
			cout << player1 << " won the game!" << endl;
			break;
		}
		else if (winner == 'O') {
			system("cls");
			showboard();
			cout << player2 << " won the game!" << endl;
			break;
		}
		else if (winner == 'D') {
			system("cls");
			showboard();
			cout << "Match Draw!" << endl;
			break;
		}
	}
}
void computerVsPlayer() {
	string playerName;
	cout << "Enter Your Name:";
	cin >> playerName;
	while (true) {
		system("cls");
		showboard();
		if (countBoard('X') == countBoard('O')) {
			cout << playerName << " 's truns" << endl;
			player1Choice();
		}
		else {
			computerChoice();
		}
		char winner = checkWinner();
		if (winner == 'X') {
			system("cls");
			showboard();
			cout << playerName << " won the game" << endl;
			break;
		}
		else if (winner == 'O') {
			system("cls");
			showboard();
			cout << "Computer won the game" << endl;
			break;
		}
		else if (winner == 'D') {
			system("cls");
			showboard();
			cout << "Game is draw" << endl;
			break;
		}

	}
}
char checkWinner() {
	/*
	* 0 1 2
	* 3 4 5
	* 6 7 8
	*/
	//checking winner in horizontal
	if (board[0] == board[1] and board[1] == board[2] and board[0] != ' ')
		return board[0];
	if (board[3] == board[4] and board[4] == board[5] and board[3] != ' ')
		return board[3];
	if (board[6] == board[7] and board[7] == board[8] and board[6] != ' ')
		return board[6];

	//checking winner in vertically
	if (board[0] == board[3] and board[3] == board[6] and board[3] != ' ')
		return board[0];
	if (board[1] == board[4] and board[4] == board[7] and board[1] != ' ')
		return board[1];
	if (board[2] == board[5] and board[5] == board[8] and board[2] != ' ')
		return board[2];
	//checking winner in diagonal
	if (board[0] == board[4] and board[4] == board[8] and board[0] != ' ')
		return board[0];
	if (board[2] == board[4] and board[4] == board[6] and board[2] != ' ')
		return board[2];
	if (countBoard('X') + countBoard('O') < 9)
		return 'C';
	return 'D';
}
void computerChoice() {
	srand(time(0));
	int choice;
	do {
		choice = rand() % 10;
		if (choice == 9)
			choice -= 1;

	} while (board[choice]!= ' ');
	board [choice] = 'O';
}
void player1Choice() {
	while (true) {
		cout << "Select your position(1-9): ";
		int choice;
		cin >> choice;
		choice -= 1;
		if (choice < 0 or choice>8) {
			cout << "Pls Select valid Choice (1-9):" << endl;
		}
		else if (board[choice] != ' ') {
			cout << "Pls Select an Empty position:" << endl;
		}
		else {
			board[choice] = 'X';
			break;
		}
	}
}
void player2Choice() {
	while (true) {
		cout << "Select your position(1-9): ";
		int choice;
		cin >> choice;
		choice -= 1;
		if (choice < 0 or choice>8) {
			cout << "Pls Select valid Choice (1-9):" << endl;
		}
		else if (board[choice] != ' ') {
			cout << "Pls Select an Empty position:" << endl;
		}
		else {
			board[choice] = 'O';
			break;
		}
	}
}
int countBoard(char symbol) {
	int total = 0;
	for (int i = 0; i < 9; i++) {
		if (board[i] == symbol)
			total += 1;
	}
	return total;
}
void showboard() {
	cout << "   " << "    |   " << "    |   " << endl;
	cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl;
	cout << "   " << "    |   " << "    |   " << endl;
	cout << "--------------------------" << endl;
	cout << "   " << "    |   " << "    |   " << endl;
	cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
	cout << "   " << "    |   " << "    |   " << endl;
	cout << "--------------------------" << endl;
	cout << "   " << "    |   " << "    |   " << endl;
	cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << endl;
	cout << "   " << "    |   " << "    |   " << endl;
}