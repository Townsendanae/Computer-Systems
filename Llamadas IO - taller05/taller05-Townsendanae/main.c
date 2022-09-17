#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>

#include "blowfish.h"

bool dflag = false; //Decrypt/Encrypt flag

void print_help(char *command)
{
	printf("secret encripta o desincripta un archivo usando el algoritmo Blowfish.\n");
	printf("uso:\n %s [-d] -k <key> <nombre_archivo>\n", command);
	printf(" %s -h\n", command);
	printf("Opciones:\n");
	printf(" -h\t\t\tAyuda, muestra este mensaje\n");
	printf(" -d\t\t\tDesincripta el archivo en lugar de encriptarlo.\n");
	printf(" -k <key>\t\tEspecífica la clave (key) de encriptación, 8 bytes en hex.\n");
}

int main(int argc, char **argv)
{
	struct stat mi_stat;
	char *input_file = NULL;
	char *key_arg_str = NULL;

	int opt, index;
	
	while ((opt = getopt (argc, argv, "dhk:")) != -1){
		switch(opt)
		{
			case 'd':
				dflag = true;
				break;
			case 'h':
				print_help(argv[0]);
				return 0;
			case 'k':
				key_arg_str = optarg;
        		break;
			case '?':
			default:
				fprintf(stderr, "uso: %s [-d] -k <key> <nombre_archivo>\n", argv[0]);
				fprintf(stderr, "     %s -h\n", argv[0]);
				return 1;
		}
	}

	/* Aquí recoge argumentos que no son opción, por ejemplo el nombre del input file */
	for (index = optind; index < argc; index++)
		input_file = argv[index];

	if(!input_file){
		fprintf(stderr, "Especifique el nombre del archivo.\n");
		fprintf(stderr, "uso: %s [-d] -k <key> <nombre_archivo>\n", argv[0]);
		fprintf(stderr, "     %s -h\n", argv[0]);
		return 1;
	}else{
		/* Ejemplo como verificar existencia y tamaño de un archivo */
		if(stat(input_file, &mi_stat) < 0){
			fprintf(stderr, "Archivo %s no existe!\n", input_file);
			return 1;
		}else
			printf("Leyendo el archivo %s (%ld bytes)...\n", input_file, mi_stat.st_size);
	}

	/* Valida la clave de encriptación */
	if(key_arg_str){
		if(strlen(key_arg_str) != 16){
			fprintf(stderr, "Error en tamaño de la clave de encriptación.\n");
			return 1;
		}
	}else{
		fprintf(stderr, "Error al especificar la clave de encriptación.\n");
		fprintf(stderr, "uso: %s [-d] -k <key> <nombre_archivo>\n", argv[0]);
		fprintf(stderr, "     %s -h\n", argv[0]);
		return 1;
	}
	
	
	
	/*TODO: Encriptar o desencriptar archivo input_file usando Blowfish */
	/*TIP: Revisar https://github.com/B-Con/crypto-algorithms/blob/master/blowfish_test.c */
	
	
	/* RETO1 - Extraer valor númerico de la clave en ASCII hex. (ver readme) */
	// sscanf()

	BYTE key_arg[8];
	unsigned short byte, i;

	for(i=0;i<8;i++){
		sscanf(key_arg_str + 2*i,"%2hx", &byte);
		key_arg[i] = (BYTE) byte;
	}

	/* RETO2 - Crear archivo con nuevo nombre .enc o .dec. (validar con variable dflag. Usar calloc, strcpy, strcat) */
	// output_file
	// strcpy
	// strcat
	
	int n;
	char *file;

	file = (char*)calloc(n,sizeof(input_file));
	strcpy(file, input_file);

	// d para desencriptar
	if (dflag) {
		strcat(file,".dec");	
	 }else {
		strcat(file, ".enc");
	 }
	
	/* RETO3 - encriptar o desencriptar (ver blowfish_test.c) */
	
	
	// crear archivo (tipo: O_CREAT, O_TRUNC, y O_WRONLY,   y con modo: S_IRUSR y S_IWUSR):
	// int fd_output = open()

	int fd_output = open(file, O_CREAT| O_TRUNC| O_WRONLY, S_IRUSR| S_IWUSR);
	
	
	// configuracion del blowfish_key:
	// BYTE key1[8]  = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08}; // para probar desencriptado
	// ouput_buf
	BYTE output_buf[BLOWFISH_BLOCK_SIZE];
	// input_buf
	BYTE input_buf[BLOWFISH_BLOCK_SIZE];
	// Blowfish key
	BLOWFISH_KEY key;
	
	// leer archivo 
	// int fd_input = open();
	int fd_input = open(input_file, O_RDONLY,0);
	
	// recorrer archivo, encriptar o desencriptar, y guardar:
	// while read()

	if(dflag){
		while(read(fd_input, input_buf, BLOWFISH_BLOCK_SIZE)>0){
			blowfish_key_setup(key_arg, &key, BLOWFISH_BLOCK_SIZE);
			blowfish_decrypt(input_buf, output_buf, &key);
			write(fd_output, output_buf, BLOWFISH_BLOCK_SIZE);
			memset(input_buf, 0, BLOWFISH_BLOCK_SIZE);
		}
	printf("Archivo %s desencriptado exitosamente en %s ...\n", input_file, file);
	}else{
		while(read(fd_input, input_buf, BLOWFISH_BLOCK_SIZE)>0){
			blowfish_key_setup(key_arg, &key, BLOWFISH_BLOCK_SIZE);
			blowfish_encrypt(input_buf, output_buf, &key);
			write(fd_output, output_buf, BLOWFISH_BLOCK_SIZE);
			memset(input_buf, 0, BLOWFISH_BLOCK_SIZE);	
		}
	printf("Archivo %s encriptado exitosamente en %s ...\n", input_file, file);
	}
	//// blowfish_decrypt();
	//// blowfish_encrypt();
		
	//// write();
	//// memset(input_buf, 0, sizeof input_buf);
	// printf mensaje exito
	// closes and free calloc

	close(fd_output);
	close(fd_input);

	free(file);
}
