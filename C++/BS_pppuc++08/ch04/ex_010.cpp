// *********************************************************************************
// Bjarne Strousstrup
// Programming: Principles and Practice Using C++
// Ex 9
// P. 127
// *********************************************************************************
// Write a program that plays the game "Rock, Paper, Scissors."
// Use a switch statement to solve this exercise.
// Also, the machine should give random answers.
// (i.e., select the next rock, paper or scissors randomly.)
// real randomness is too hard to provide just now, so just build a vector 
// with a sequence of values to be used as "the next value".
// If you build the vector into the program, it will always play the same game,
// so maybe you should let the user enter some values.
// Try variations to make it less easy for the user to guess which 
// move the machine will make next.
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
	// set computer moves
	cout << "Setting computer moves..\n";
	cout << "How many different moves (at least one) should the game have?\n";
	int num_moves = 0;
	cin >> num_moves;
	if (num_moves<1){
		cout << "Error: number of moves must be at least 1\n";
		exit(1);
	}
	cout << "Please enter " << num_moves << " values from 0 to 9 randomly ordered.\n";
	vector<int> next;
	int temp;
	for (int i=0; i<num_moves; ++i) {
		int temp;
		cin >> temp;
		if (temp>=0 && temp<=9) {
			next.push_back(temp);
		}
		else {
			cout << "Invalid input\n";
			--i;
		}
	}

	// print the user input
	//for (int i=0; i<next.size(); ++i){
	//	cout << "next[" << i << "]: " << next[i] << endl;
	//}

	// ********************* PLAY GAME *********************************
	cout << "*** STARTING GAME ***\n";
	cout << "Enter Rock, Paper, Scissors to play!\n";
	cout << next.size() << " moves to be played!\n";

	string user_move;
	int count = 0;
	int p_score = 0;
	int c_score = 0;
	int null = 0;
	int ties = 0;

	while (true) {
		if (count>=next.size()) {
			cout << "\n*** SCORE ***\n";
			cout << "Player: " << p_score << endl << "Computer: " << c_score << endl << "Ties: " << ties << endl << "Null: " << null << endl;
			if (p_score>c_score) {
				cout << "The winner is Player!\n";
			}
			else if (p_score<c_score) {
				cout << "The winner is Computer!\n";
			}
			else {
				cout << "The game is tied!\n";
			}
			exit(1);
		}

		cout << "\n#### move n°" << count+1 << " ####\n";
		cout << "Player: ";
		cin >> user_move;
		cout << "Computer: ";

		switch (next[count]) {
		case 0:
			cout << "Rock!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++ties;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++c_score;
			}
			else if (user_move=="Paper" || user_move=="paper") {
				++p_score;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		case 1:
			cout << "Paper!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++c_score;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++p_score;
			}
			else if (user_move=="Paper" || user_move=="paper"){
				++ties;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		case 2:
			cout << "Scissors!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++p_score;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++ties;
			}
			else if (user_move=="Paper" || user_move=="paper"){
				++c_score;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		case 3:
			cout << "Rock!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++ties;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++c_score;
			}
			else if (user_move=="Paper" || user_move=="paper"){
				++p_score;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		case 4:
			cout << "Paper!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++c_score;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++p_score;
			}
			else if (user_move=="Paper" || user_move=="paper"){
				++ties;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		case 5:
			cout << "Scissors!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++p_score;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++ties;
			}
			else if (user_move=="Paper" || user_move=="paper"){
				++c_score;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		case 6:
			cout << "Rock!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++ties;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++c_score;
			}
			else if (user_move=="Paper" || user_move=="paper"){
				++p_score;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		case 7:
			cout << "Paper!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++c_score;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++p_score;
			}
			else if (user_move=="Paper" || user_move=="paper"){
				++ties;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		case 8:
			cout << "Scissors!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++p_score;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++ties;
			}
			else if (user_move=="Paper" || user_move=="paper"){
				++c_score;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		case 9:
			cout << "Rock!\n";
			if (user_move=="Rock" || user_move=="rock") {
				++ties;
			}
			else if (user_move=="Scissors" || user_move=="scissors") {
				++c_score;
			}
			else if (user_move=="Paper" || user_move=="paper"){
				++p_score;
			}
			else {
				cout << "Bad user input! ?" << user_move << "? null point.\n";
				++null;
			}
			break;
		default:
			cout << "Bad input\n";
		}
		++count;
	}
}
