OCAMLBUILD= ocamlbuild \
		-no-links -classic-display \
		-libs str,unix \
		-tags debug,annot

MAIN=msh
TARGET=native

all: $(MAIN)

$(MAIN): $(MAIN).$(TARGET)
	cp _build/$(MAIN).$(TARGET) $(MAIN)

$(MAIN).$(TARGET):
	$(OCAMLBUILD) $(MAIN).$(TARGET)


clean:
	ocamlbuild -clean
	rm -f msh

realclean: clean
	rm -f *~ $(MAIN)

cleanall: realclean
