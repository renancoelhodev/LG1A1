/* Bibliotecas  */

#include	<stdio.h>	/* Para usar printf e scanf */
#include	<conio.h>	/* Para usar getch */
#include	<stdlib.h>	/* Para usar exit */
#include	<locale.h>	/* Para acentos */
#include	<math.h>	/* Para c�lculos matem�ticos */

/* Vari�veis de mem�ria */
/* tipo_de_dado (natureza: inteiro, real, alfanum�rico    nome_da_vari�vel */

float	F , C , K;

/* CORPO DO PROGRAMA */

int main()
{
	setlocale	(LC_ALL,	"");
	printf	("\n\nEx. 8");
	
	printf	("\n\nDigite o valor de temperatura em �C:");
	scanf	("%f" , &C);
	
	F = (9*C/5)+32;
	K = C + 273;
	
	printf	("\n\nIsso corresponde a %.2f�F", F);
	printf	("\n\nOu a %.2fK", K);
	getch	();
}

