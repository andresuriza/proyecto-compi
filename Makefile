all:
	bison -Wnone -y -d vgraph.y

	flex vgraph.l
	gcc -c y.tab.c lex.yy.c
	gcc y.tab.o lex.yy.o ast.c -lm -o vgraph
	gcc y.tab.o lex.yy.o ast.c -lm -o ast
