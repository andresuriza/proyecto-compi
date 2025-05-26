all:
	bison -t -d -v vgraph.y
	flex vgraph.lex
	gcc lex.yy.c vgraph.tab.c -lfl