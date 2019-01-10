all: teaching.pdf
	ls *.pdf
	
teaching.pdf: teaching.tex
	xelatex -shell-escape -8bit teaching.tex  
	
clear:
	rm *.pdf *.aux *.log *.toc *.snm *.nav *.out