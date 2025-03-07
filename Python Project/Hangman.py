import os
import random

word = random.choice(list(open('words')))
word = word.strip("\n")
letters = [*word]

found_letters = []
for x in range(len(word)):
    found_letters.append(False)

displayed_letters = []
for x in range(len(word)):
    displayed_letters.append("_")

victory_condition = False
attempts = 6

while (victory_condition == False and attempts > 0):
    print("|| HANGMAN ||")
    print("ATTEMPTS: ", attempts, "\n")
    #print("CHEATER: ", word, "\n")

    for x in range(len(word)):
        print(displayed_letters[x], " ", end='')
    
    player_input = input("\n\nPlease enter a letter: ")

    while len(player_input) != 1 or not player_input.isalpha():
        player_input = input("Please enter ONE LETTER: ")

    correct_guess = False
    for x in range(len(word)):
        if player_input == letters[x]:
            if not correct_guess:
                correct_guess = True
            found_letters[x] =  "TRUE"
            displayed_letters[x] = letters[x]

    if correct_guess == False:
        attempts -= 1
    
    os.system("cls")

    victory_condition = True
    for x in range(len(word)):
        if found_letters[x] == False:
            victory_condition = False

if victory_condition:
    print("Congratulations! You won. The word was:", word)
else:
    print("Unfortunately, you failed. The word was:", word)
input()