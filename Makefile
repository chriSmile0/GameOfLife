.PHONY: all clean
LIBPATH= lib/
LDLIBS += -lm -L$(LIBPATH) -lmalib -lcairo  -lX11
CFLAGS += -Wall -g
CPPFLAGS +=  -Iinclude -I/usr/include/cairo

WARNFLAGS := -Wall -Wpedantic -Wextra -Waddress -Waggressive-loop-optimizations \
  -Wcast-qual -Wcast-align -Wmissing-declarations \
  -Wdouble-promotion -Wuninitialized -Winit-self \
  -Wstrict-aliasing -Wsuggest-attribute=const -Wtrampolines -Wfloat-equal \
  -Wshadow -Wunsafe-loop-optimizations -Wlogical-op \
  -Wdisabled-optimization -Wconversion -Wunused-result






OBJPATH= obj/
BINPATH= bin/
DOCPATH= doc/

vpath %.h include/
vpath %.c src/

ifeq (TEXTE,$(MODE))



all: $(BINPATH)lavie

$(BINPATH)lavie : $(addprefix $(OBJPATH),main.o) $(LIBPATH)libmalib.a | $(BINPATH)
	gcc $(LDFLAGS)	-o $@ $^ $(LDLIBS)
	
$(LIBPATH)libmalib.a: $(addprefix $(OBJPATH), io.o jeu.o grille.o) | $(LIBPATH) 
	ar -crv $@ $^

check: lavie
	@./test/test_gol_execution.sh
	
else 
all: $(BINPATH)lavie

$(BINPATH)lavie : $(addprefix $(OBJPATH),cairo.o) $(LIBPATH)libmalib.a | $(BINPATH)
	gcc $(LDFLAGS)	-o $@ $^ $(LDLIBS)
	
$(LIBPATH)libmalib.a: $(addprefix $(OBJPATH), io.o jeu.o grille.o) | $(LIBPATH) 
	ar -crv $@ $^

check: lavie
	@./test/test_gol_execution.sh
endif
# Documentation
$(DOCPATH)doc:
	doxygen Doxyfile

#Archive
dist:
	#tar -czf $(NAME).tar.gz --transform="s,^,$(NAME)/," \
		#*.c *.h Makefile Doxyfile tests results

$(OBJPATH)cairo.o : cairo.c
$(OBJPATH)main.o : main.c 
$(OBJPATH)io.o: io.c io.h
$(OBJPATH)jeu.o : jeu.c jeu.h
$(OBJPATH)grille.o : grille.c grille.h

$(OBJPATH)%.o : %.c | $(OBJPATH)
	gcc $(CFLAGS) -o  $@ -c $<

$(OBJPATH) : 
	mkdir -p $(OBJPATH)
	
$(BINPATH) :
	mkdir -p $(BINPATH)

$(LIBPATH) :
	mkdir -p $(LIBPATH)
	
$(DOCPATH) :
	mkdir -p $(DOCPATH)


clean:
	@$(RM) -f $(BINPATH)lavie *.o
	@echo Clean!
