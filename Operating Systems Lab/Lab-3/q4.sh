#!/bin/bash

echo "Q4: Calculate Gross Salary"
echo "Gross = Basics + TA + 10% of Basics"
echo "Enter Basics:"
read basics
echo "Enter TA"
read TA
echo `bc <<< "scale=4; $basics*1.1000 + $TA"`  
