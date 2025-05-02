#
# 'make'        Costruisci l'eseguibile per il file "main"
# 'make clean'  Rimuovi tutti gli eseguibile e file intermedi ".o"
#

# Definisci il compilatore da usare
CXX = g++

# Definisci gli argomenti e bandiere da passare al compilatore
CXXFLAGS	:= -std=c++17 -Wall -Wextra -g

# Definisci il percorso alle librerie non presenti in /usr/lib utilizzando la bandiera -Lpath
LFLAGS =

# Definisci la cartella del risultato
OUTPUT	:= output

# Definisci la cartella del sorgente
SRC		:= src

# Definisci la cartella dei file di intestazione (file .h*)
INCLUDE	:= include

# Definisci la cartella delle librerie
LIB		:= lib

ifeq ($(OS),Windows_NT)
MAIN	:= main.exe
SOURCEDIRS	:= $(SRC)
INCLUDEDIRS	:= $(INCLUDE)
LIBDIRS		:= $(LIB)
FIXPATH = $(subst /,\,$1)
RM			:= del /q /f
MD	:= mkdir
else
MAIN	:= main
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
LIBDIRS		:= $(shell find $(LIB) -type d)
FIXPATH = $1
RM = rm -f
MD	:= mkdir -p
endif

# Definisci le cartella contenenti i file di intestazione esterni non presenti in /usr/include
INCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

# Definisci il formato delle librerie
LIBS		:= $(patsubst %,-L%, $(LIBDIRS:%/=%))

# Definisci il formato del sorgente
SOURCES		:= $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))

# Definisci il formato dei file intermedi
OBJECTS		:= $(SOURCES:.cpp=.o)

# Definisci il formato dei file di dipendenza
DEPS		:= $(OBJECTS:.o=.d)

#
# La seguente parte del makefile e' generica. Puo' essere usata per
# Costruire qualsiasi eseguibile cambiando le definizioni precedenti
# e cancellando qualsiasi dipendenza rimanente utilizzando `make depend`
#

OUTPUTMAIN	:= $(call FIXPATH,$(OUTPUT)/$(MAIN))

all: $(OUTPUT) $(MAIN)
	@echo Esecizione di 'all' completata!

$(OUTPUT):
	$(MD) $(OUTPUT)

$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

# Includi tutti i file .d
-include $(DEPS)

# Questo e' una regola di rimpiazzo del suffisso per costruire file .o e .d da file .c*.
# Utilizza le variabili automatihe $<, il nome del prerecuisito della regola (un file .c*),
# e $@, il nome dell'obiettivo della regola (un file .o)
# -MMD genera i file di dipendenza aventi lo stesso nome dei file .o
# (Per maggiori informazioni consulta il manuale dello strumento GNU Make riguardo le variabili automatiche)
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -MMD $<  -o $@

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	$(RM) $(call FIXPATH,$(DEPS))
	@echo Pulizia completata!

run: all
	./$(OUTPUTMAIN)
	@echo Esecizione di 'run: all' completata!
