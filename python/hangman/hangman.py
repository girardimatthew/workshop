#!/usr/bin/env python
# write a function that picks a random word from a list of words from the

import random

# return a random integer: 0 <= X <= len
def iRand(len):
	# x = random.random()
	# x = int(x * len)
	x = random.randint(0, len)
	return x

# get a random word from dictionary
def getWord():
	dict = []
	with open("sowpods.txt", 'rU') as f:
		line = f.readline()
		while line:
			line = line.strip()		# gets rid of all whitespaces (including the \n character)
			dict.append(line)
			line = f.readline()

	dict_length = len(dict)
	N = iRand(dict_length)
	return dict[N]

def printWord(word):
	for i in range(len(word)):
		print word[i],
	print

def game_loop(hidden, word):
	# Number of guesses left
	nGuess = 6

	while nGuess >= 1:
		print "You have %d guesses left." % (nGuess)
		guess = raw_input(">>> Guess a letter: ")
		guess = guess.upper()
		hit = False
		for n in range(len(hidden)):
			if hidden[n] == guess:
				word[n] = guess
				hit = True
		if hit!=True:
			print "Incorrect!"
		else:
			printWord(word)

		nGuess -= 1

	# ask the user to guess the hidden word
	x = raw_input(">>> Guess the hidden word: ")
	x = x.upper()
	if hidden == x:
		print "You won!"
	else:
		print "You lost! The hidden word is: " + hidden

def main():
	print ">>> Welcome to Hangman!"
	hidden = getWord()
	# print hidden
	hlen = len(hidden)

	# word to be guessed
	word = []
	for i in range(hlen):
		word.append("_")
	
	# print word to be guessed
	printWord(word)

	# game
	game_loop(hidden,word)

if __name__ == '__main__':
	main()
