GPP = g++ -Wall
SRC = ./src
BIN = ./bin

all: start

# La cible "deleteAll" est exécutée en tapant la commande "make deleteAll"
deleteAll :
	@echo "Suppression du contenu du répertoire $(BIN)"
	rm -f $(BIN)/*.o $(BIN)/*.bin

# La cible "compilCsv" est exécutée en tapant la commande "make compilCsv"
compilCsv :
	@echo "Compilation Util"
	$(GPP) -c $(SRC)/Csv.cpp -o $(BIN)/Csv.o

# La cible "compilMain" est exécutée en tapant la commande "make compilMain"
compilMain : deleteAll compilCsv 
	@echo "Compilation de main"
	$(GPP) main.cpp  $(BIN)/Csv.o -o $(BIN)/main.bin

# La cible "launchMain" est exécutée en tapant la commande "make launchMain"
launchMain :
	@echo "Lancement de main"
	$(BIN)/main.bin

# La cible "start" est exécutée en tapant la commande "make start"
start : compilMain launchMain