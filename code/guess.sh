# Author: 	Christian Hall
# Date:		October 2, 2015
# E-mail: 	hallbasics@yahoo.com
# Purpose:	"Guess my number" game.

#!/bin/bash



gamenumber=$(((RANDOM % 100) +1))

echo The number is between 1 and 100, can you guess it?

#
echo My number is $gamenumber


guess=1

echo "Please enter a number: " 
read guess


flag=false

while [ "$flag" = false ]; do
	again=" "	

	if [ $gamenumber -eq $guess ]
		then
			flag=true
			echo Congratulations, you\'ve guessed correctly!
	elif [ $gamenumber -lt $guess ]
		then
			echo Sorry, my number is lower than that.
	elif [ $gamenumber -gt $guess ]
		then
			echo Sorry, my number is higher than that.
	else #[ $gamenumber -lt 0] || [ $gamenumber -gt 0 ]
		echo "Error"
	fi
	
	
	if [ "$flag" = false ]
		then	
			printf "\n"
			echo Your last guess was $guess
			echo What would you like your new guess to be?: 
			read guess
	else
		echo Nice, you win!
		echo "Would you like to play again (y\\n)?"
		read again
		if [ $again = 'y' ] ; then
			flag=false	
		else
			echo "Bye!"
		fi
	fi

done
