clear
echo '1) Ejecute push_swap con parámetros no numéricos. El programa debe mostrar "Error".'
echo './push_swap 1 2 a 26 0'
./push_swap 1 2 a 26 0
echo './push_swap "3 ; 0"'
./push_swap "3 ; 0"
​#
echo '\n2) Ejecute push_swap con un parámetro numérico duplicado. El programa debe mostrar "Error".'
echo './push_swap 21 73 89 -23 44 90 -3 21 0'
./push_swap 21 73 89 -23 44 90 -3 21 0
echo './push_swap "-121 731 -89 203 -44 90 -44 21 0"'
./push_swap "-121 731 -89 203 -44 90 -44 21 0"
​#
echo '\n3) Ejecute push_swap sólo con parámetros numéricos, incluyendo uno mayor que MAXINT. El programa debe mostrar "Error".'
echo './push_swap -4 11 2147483650 -8 9 3'
./push_swap -4 11 2147483650 -8 9 3
echo './push_swap "4 -11 2147483650 -8 9 3"'
./push_swap "4 -11 2147483650 76 45 54 61"
​#
echo '\n4) Ejecute push_swap sin ningún parámetro. El programa no debe mostrar nada y devolver el prompt.'
echo './push_swap'
./push_swap
echo '\n./push_swap ""'
./push_swap ""
echo '\n./push_swap " "'
./push_swap " "
​#
echo '\n 5) Ejecute /push_swap 42. El programa no debería mostrar nada.'
echo './push_swap 42'
./push_swap 42
​#
echo '\n 6) Ejecute el siguiente comando "$>./push_swap 0 1 2 3". El programa programa no debería mostrar nada.'
echo './push_swap 0 1 2 3'
./push_swap 0 1 2 3
​#
echo '\n 7) Ejecute el siguiente comando "$>./push_swap 0 1 2 3 4 5 6 7 8 9". El  programa no debería mostrar nada.'
./push_swap '0 1 2 3 4 5 6 7 8 9'
./push_swap 0 1 2 3 4 5 6 7 8 9
​#
echo '\n 8) Ejecute "$>ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG. Repita con otras combinaciones.'
echo 'ARG="2 1 0"'
echo './push_swap $ARG'
ARG="2 1 0"
./push_swap $ARG
echo 'ARG="2 1 0"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
echo 'ARG="2 0 1"'
echo './push_swap $ARG'
ARG="2 0 1"
./push_swap $ARG
echo 'ARG="2 0 1"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
echo 'ARG="1 0 2"'
echo './push_swap $ARG'
ARG="1 0 2"
./push_swap $ARG
echo 'ARG="0 2 1"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
echo './push_swap $ARG'
ARG="1 2 0"
./push_swap $ARG
echo 'ARG="1 2 0"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
​#
echo '\n9) Ejecute "$>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG. Repita con otras combinaciones.'
echo './push_swap $ARG'
ARG="1 5 2 4 3"
./push_swap $ARG
echo 'ARG="1 5 2 4 3"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
echo './push_swap $ARG'
ARG="4 2 3 1 5"
./push_swap $ARG
echo 'ARG="4 2 3 1 5"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
echo './push_swap $ARG'
ARG="2 3 5 4 1"
./push_swap $ARG
echo 'ARG="2 3 5 4 1"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
echo './push_swap $ARG'
./push_swap $ARG
echo 'ARG="1 5 4 2 3"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
echo './push_swap $ARG'
ARG="4 5 2 1 3"
./push_swap $ARG
echo 'ARG="4 5 2 1 3"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
echo './push_swap $ARG'
ARG="1 2 3 5 4"
./push_swap $ARG
echo 'ARG="1 2 3 5 4"\n./push_swap $ARG | ./checker_Mac $ARG'
./push_swap $ARG | ./checker_Mac $ARG
​#
echo '\n10) Ejecute "$>ARG="<100 valores aleatorios>"; ./push_swap $ARG |./checker_OS $ARG" y sustituya el marcador de posición por 100 valores aleatorios'
i=0
suma=0
media=0
for i in {1..5}
do
    ARG=$(seq -500 500 | sort -R | tail -n 100 | tr '\n' ' ')
    value=$(./push_swap $ARG | wc -l)
	echo "Instrucciones: " $value
    echo "\n./push_swap $ARG | ./checker_Mac $ARG"
	./push_swap $ARG | ./checker_Mac $ARG
​
    suma=`expr $suma + $value`
done
media=`expr $suma / 5`
echo "Media: " $media;
​
echo '\n11) Ejecute "$>ARG="<500 valores aleatorios>"; ./push_swap $ARG |./checker_OS $ARG" y sustituya el marcador de posición por 500 valores aleatorios'
i=0
suma=0
media=0
for i in {1..5}
do
    ARG=$(seq -500 500 | sort -R | tail -n 500 | tr '\n' ' ')
    value=$(./push_swap $ARG | wc -l)
    echo "Instrucciones: " $value
    echo "\n./push_swap $ARG | ./checker_Mac $ARG"
    ./push_swap $ARG | ./checker_Mac $ARG
​
    suma=`expr $suma + $value`
done
media=`expr $suma / 5`
echo "Media: " $media;



##ARG=$(seq -10 10 | sort -R | tail -n 6 | tr '\n' ' '); ./push_swap $ARG