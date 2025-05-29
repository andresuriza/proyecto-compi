vgraph: lex.yy.c vgraph.tab.c
	gcc -g lex.yy.c vgraph.tab.c -o vgraph

lex.yy.c: y.tab.c vgraph.l
	flex vgraph.l

y.tab.c: vgraph.y
	bison -d vgraph.y

clean: 
	rm -rf lex.yy.c vgraph.tab.c vgraph.tab.h vgraph vgraph.dSYM