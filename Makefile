.PHONY: help
help:
	@echo 'make [BASE=n] pdf'
	@echo '      n: base da tabuada (2 por padrão)'
	@echo

.PHONY: pdf
pdf: clear main doc

main: main.c
	gcc main.c -o main -std=c11 -W -Wall -pedantic

tabela.tex: main
	./main $(BASE)

.PHONY: doc
doc: tabela.tex
	tectonic main.tex 

.PHONY: clear
clear:
	rm -f tabela.tex main
