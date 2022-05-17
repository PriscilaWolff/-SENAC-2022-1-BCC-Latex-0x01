#include <stdio.h>
#include <stdlib.h>

void gerar_tabuada(int);

int main(int argc, char *argv[]) {
    int base;

    if (argc == 2)
        base = atoi(argv[1]);
    else 
        base = 2;
  
    gerar_tabuada(base);

    exit(EXIT_SUCCESS);
}

/* Recebe um inteiro x indicando a base da tabuada
 * e gera um arquivo texto, tabela.tex, contendo 
 * codigo LaTeX de uma tabela com a tabuada de x.
 */ 
void gerar_tabuada(int x) {
    const char *arquivo = "tabela.tex";

    FILE * fp = fopen(arquivo,"wt");
    if (fp == NULL)
        return;

    fprintf(fp,"\\begin{table}[h]\n");
    fprintf(fp,"\\caption{Tabuada do %d}", x);
    fprintf(fp,"\\centering");
    fprintf(fp,"\\begin{tabular}{|rcrcr|}\n");
    fprintf(fp,"\\hline\n");
    fprintf(fp,"\\hline\n");

    for (int i=0; i<=10; i++) {
        fprintf(fp, "%3d & $\\times$ & %3d & $=$ & %3d\\\\\n", i, x, i*x);
    }

    fprintf(fp,"\\hline\n");

    fprintf(fp,"\\end{tabular}\n");
    fprintf(fp,"\\end{table}\n");

    fclose(fp);
}

