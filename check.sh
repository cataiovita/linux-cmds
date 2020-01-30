#!/bin/bash
#//////////////////////////////////////////////////////
#	Created by Nan Mihai on 03.12.2019
#	Copyright (c) 2019 Nan Mihai. All rights reserved.
#	Checker Tema 1 - Programarea Calculatoarelor
#	Seria CC
#	Facultatea de Automatica si Calculatoare
#	Anul Universitar 2019-2020, Seria CC
#/////////////////////////////////////////////////////
print_header()
{
	header="${1}"
	header_len=${#header}
	printf "\n"
	if [ $header_len -lt 71 ]; then
		padding=$(((71 - $header_len) / 2))
		for ((i = 0; i < $padding; i++)); do
			printf " "
		done
	fi
	printf "= %s =\n\n" "${header}"
}

OUPUT="tests/out"
rm -rf "$OUPUT"
mkdir "$OUPUT"
result1=0
result2=0
result3=0
result4=0
result=0
depunctari=0
ZERO=0
VALGRIND="valgrind --leak-check=full --track-origins=yes -q --log-file=rezultat_valgrind.txt"
make all
var=10
BEST=135
print_header "Testare - Tema 1 (Programarea Calculatoarelor)"
#Cerinta 1 - Comanda grep
echo "Cerinta 1 - Comanda grep"
depunctare=0
for i in {1..20}
do
	fileIn="tests/grep/test"$i".in"
	fileOut="tests/out/test"$i".out"
	fileRef="tests/grep/test"$i".ref"
	rm rezultat_valgrind.txt
	$VALGRIND ./grep < $fileIn > $fileOut
	cat rezultat_valgrind.txt
	diff -Z $fileOut $fileRef > /dev/null
	EXIT_CODE=$?
	if (( i < 10 )); then
		idx=" $i"
	else
		idx=$i
	fi
	if [ $EXIT_CODE -eq $ZERO ] 
	then
		echo "+0.00: Cerinta 1 Test $idx ................................................. PASS"
		result=$(awk "BEGIN {print $result+1.25; exit}")
		result1=$(awk "BEGIN {print $result1+1.25; exit}")
		if [[ -z $(cat rezultat_valgrind.txt) ]]; then
			printf "\tVALGRIND ......................................................... PASS\n"
		else
			depunctare=1
			cat "rezultat_valgrind.txt"
			printf "\tVALGRIND ......................................................... FAIL\n"
		fi
	else
		echo "-1.25: Cerinta 1 Test $idx ................................................. FAIL"
	fi
done

if [ "$depunctare" -eq "0" ] && [ "$result1" -ne "0" ]; then
	result=$(awk "BEGIN {print $result+2.5; exit}")
	depunctari=$(awk "BEGIN {print $depunctari+2.5; exit}")
fi
depunctare=0

echo ""
#Cerinta 2 - Comanda cut
echo "Cerinta 2 - Comanda cut"
for i in {1..20}
do
	fileIn="tests/cut/test"$i".in"
	fileOut="tests/out/test"$i".out"
	fileRef="tests/cut/test"$i".ref"
	$VALGRIND ./cut < $fileIn > $fileOut
	diff -Z $fileOut $fileRef > /dev/null
	EXIT_CODE=$?
	if (( i < 10 )); then
		idx=" $i"
	else
		idx=$i
	fi
	if [ $EXIT_CODE -eq $ZERO ] 
	then
		echo "+0.00: Cerinta 2 Test $idx ................................................. PASS"
		result=$(awk "BEGIN {print $result+2; exit}")
		result2=$(awk "BEGIN {print $result2+2; exit}")
		if [[ -z $(cat rezultat_valgrind.txt) ]]; then
			printf "\tVALGRIND ......................................................... PASS\n"
		else
			depunctare=1
			cat "rezultat_valgrind.txt"
			printf "\tVALGRIND ......................................................... FAIL\n"
		fi
	else
		echo "-2.00: Cerinta 2 Test $idx ................................................. FAIL"
	fi
done
if [ "$depunctare" -eq "0" ] && [ "$result2" -ne "0" ]; then
	result=$(awk "BEGIN {print $result+2.5; exit}")
	depunctari=$(awk "BEGIN {print $depunctari+2.5; exit}")
fi
depunctare=0

echo ""
#Cerinta 3 - Comanda sort
echo "Cerinta 3 - Comanda sort"
for i in {1..20}
do
	fileIn="tests/sort/test"$i".in"
	fileOut="tests/out/test"$i".out"
	fileRef="tests/sort/test"$i".ref"
	$VALGRIND ./sort < $fileIn > $fileOut
	diff -Z $fileOut $fileRef > /dev/null
	EXIT_CODE=$?
	if (( i < 10 )); then
		idx=" $i"
	else
		idx=$i
	fi
	if [ $EXIT_CODE -eq $ZERO ] 
	then
		echo "+0.00: Cerinta 3 Test $idx ................................................. PASS"
		result=$(awk "BEGIN {print $result+1.25; exit}")
		result3=$(awk "BEGIN {print $result3+1.25; exit}")
		if [[ -z $(cat rezultat_valgrind.txt) ]]; then
			printf "\tVALGRIND ......................................................... PASS\n"
		else
			depunctare=1
			cat "rezultat_valgrind.txt"
			printf "\tVALGRIND ......................................................... FAIL\n"
		fi
	else
		echo "-1.25: Cerinta 3 Test $idx ................................................. FAIL"
	fi
done
if [ "$depunctare" -eq "0" ] && [ "$result3" -ne "0" ]; then
	result=$(awk "BEGIN {print $result+2.5; exit}")
	depunctari=$(awk "BEGIN {print $depunctari+2.5; exit}")
fi
depunctare=0

echo ""
#Cerinta 4 - Comanda encrypt
echo "Cerinta 4 - Comanda encrypt"
for i in {1..20}
do
	fileIn="tests/encrypt/test"$i".in"
	fileOut="tests/out/test"$i".out"
	fileRef="tests/encrypt/test"$i".ref"
	$VALGRIND ./encrypt < $fileIn > $fileOut
	diff -Z $fileOut $fileRef > /dev/null
	EXIT_CODE=$?
	if (( i < 10 )); then
		idx=" $i"
	else
		idx=$i
	fi
	if [ $EXIT_CODE -eq $ZERO ] 
	then
		echo "+0.00: Cerinta 4 Test $idx ................................................. PASS"
		result=$(awk "BEGIN {print $result+1.75; exit}")
		result4=$(awk "BEGIN {print $result4+1.75; exit}")
		if [[ -z $(cat rezultat_valgrind.txt) ]]; then
			printf "\tVALGRIND ......................................................... PASS\n"
		else
			depunctare=1
			cat "rezultat_valgrind.txt"
			printf "\tVALGRIND ......................................................... FAIL\n"
		fi
	else
		echo "-1.75: Cerinta 4 Test $idx ................................................. FAIL"
	fi
done
if [ "$depunctare" -eq "0" ] && [ "$result4" -ne "0" ]; then
	result=$(awk "BEGIN {print $result+2.5; exit}")
	depunctari=$(awk "BEGIN {print $depunctari+2.5; exit}")
fi

echo "Rezultate - Tema 1"
printf "Tema 1 - Cerinta 1 : "$result1"\n"
printf "Tema 1 - Cerinta 2 : "$result2"\n"
printf "Tema 1 - Cerinta 3 : "$result3"\n"
printf "Tema 1 - Cerinta 4 : "$result4"\n"
printf "Tema 1 - Valgrind  : "$depunctari"\n"

print_header "Rezultat final"
echo "Total     : "$result
total=${result%.*}
if (( total == BEST )); then
	echo "Felicitari! Ai punctajul maxim: "$BEST"p! :)"
else
	echo "Ai acumulat "$result"p din maxim 135p! :("
fi
make clean > /dev/null 2>&1
rm -rf "$OUPUT"
