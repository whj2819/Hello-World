progs: demo.pdf table.pdf math.pdf align.pdf


all: $(progs)

demo.pdf: demo.tex
	xelatex demo.tex && xelatex demo.tex && xelatex demo.tex

table.pdf: table.tex
	xelatex table.tex && xelatex table.tex && xelatex table.tex

math.pdf: math.tex
	xelatex math.tex && xelatex math.tex && xelatex math.tex

align.pdf: align.tex
	xelatex align.tex && xelatex align.tex && xelatex align.tex


.PHONY:clean
clean:
	rm -rf *.log *.aux *.pdf
