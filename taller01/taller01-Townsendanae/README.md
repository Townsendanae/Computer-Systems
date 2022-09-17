# ProgSist-Taller01 - Contador simple de palabras

Este repositorio debe ser **CLONADO** en su máquina local.

## Ejemplo del funcionamiento del programa.

Asuma que tiene un archivo llamado _information.txt_

```
Programacion de Sistemas
Sean todo bienvenidos
Vamos a contar palabras en 
este es un archivo de pruebas
```

Se debe tener un programa que al leer un archivo, debe mostrar la siguiente informacion:

```
$./programa
Please, enter a file name: information.txt
Reading file information.txt...
The file 'information.txt' has 17 words.
```

# Compilación con Make

El archivo Makefile debe ser modificado para compilar el programa de manera eficiente, es decir:
1. El ejecutable debe llamarse **programa** y make debe ser sensible a la ausencia del ejecutable.
2. make debe ser sensible a modificaciones individuales de los archivos .c y recompilar únicamente el archivo modifcado.
3. make debe ser sensible a modificaciones de los archivos cabecera .h y recompilar todos los archivos que dependan de él.
4. make NO debe recompilar ningún archivo que no haya sido modificado


Para compilar el programa:

```
$ make
```

Para limpiar archivos temporales

```
$ make clean
```

Para probar que el _make_ funciona correctamente:

```
$ make -f Testfile Makefile
```

Para probar que el _programa_ funciona correctamente:

```
$ make -f Testfile Output
```

# Entregable

Modificar solamente los archivos:

1. Makefile
2. functions.c

Deberá realizar un commit por cada archivo modificado, es decir, deberá realizar dos commits.

Nota: Su repositorio NO debe contener archivos compilados .o, ni el archivo ejecutable.
