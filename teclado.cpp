#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct teclado_zoeiro {
	char original;
	char trocado;
};

void deszoeirador(char txt[], teclado_zoeiro* t, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < strlen(txt); i++) {
			if(txt[i] == t[j].trocado || txt[i] == t[j].original)
			if (txt[i] == t[j].trocado) {
				txt[i] = t[j].original;
			}else{
				txt[i] = t[j].trocado;
			}
		}
	}
	printf("%s", txt);
	printf("\n");
}

int main() {
	teclado_zoeiro* t;
	char txt[50];
	int n = 0, m = 0;

	memset(txt, '\0', (sizeof(txt) / sizeof(txt[0])));

	scanf_s("%d %d", &n, &m);
	getchar();

	t = (teclado_zoeiro*)malloc(sizeof(teclado_zoeiro) * n);
	for (int i = 0; i < n; i++) {
		t[i].trocado = getchar();
		getchar();
		t[i].original = getchar();
		getchar();
	}

	for (int i = 0; i < m; i++) {
		fgets(txt, sizeof(txt), stdin);
		deszoeirador(txt, t, n);
		memset(txt, '\0', (sizeof(txt) / sizeof(txt[0])));
	}

	return 0;
}