#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
A struct teclado zoeiro mapeia quais teclas foram trocadas de posição
*/
struct teclado_zoeiro {
	char original;
	char trocado;
};

void deszoeirador(char txt[], teclado_zoeiro* t, int n) {
	/* loop de busca */
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < strlen(txt); i++) {
			if(txt[i] == t[j].trocado || txt[i] == t[j].original) // verifica se algum caracter é igual a tecla original ou trocada
			if (txt[i] == t[j].trocado) {
				txt[i] = t[j].original; // se for igual a tecla trocada o caracter é trocado para tecla original
			}else{
				txt[i] = t[j].trocado; // se for igual a tecla original o caracter é trocada para tecla trocada
			}
		}
	}
	printf("%s", txt);
	printf("\n");
}

int main() {
	teclado_zoeiro* t = nullptr; // ponteiro para array de teclado zoeiro
	char txt[50]; // buffer de entrada
	int n = 0, m = 0; // n -> número de caracteres trocados; m -> quantidade de textos a serem lidos

	memset(txt, '\0', (sizeof(txt) / sizeof(txt[0]))); // inicializa o buffer de memoria com caracteres nulos

	scanf_s("%d %d", &n, &m); // ler a quantidade de n e m 
	getchar();

	t = (teclado_zoeiro*)malloc(sizeof(teclado_zoeiro) * n); // cria um array de n teclas trocadas
	for (int i = 0; i < n; i++) {
		t[i].trocado = getchar(); // ler a tecla que foi trocada
		getchar();
		t[i].original = getchar(); // ler a tecla original
		getchar();
	}

	for (int i = 0; i < m; i++) {
		fgets(txt, sizeof(txt), stdin); // input do texto
		deszoeirador(txt, t, n); // função que imprimi o texto correto
		memset(txt, '\0', (sizeof(txt) / sizeof(txt[0]))); // reinicializa o buffer de entrada
	}

	return 0;
}