# -- Compiler to be used -- #

CC = gcc

# ------------------------- #

# -- Handle to Enable Compilation & Avoid Linking -- #

COMPILE = -c

# ------------------------------------------------------- #

# -- Handle to generate Object Files -- #

OUTPUT_FILE = -o

# ------------------------------------- #



# ------------------------------------ Compilation + Linking ---------------------------------------------- #

output: main.o sorthandler.o sortingmethods.o sortingtypes.o fieldsortmethods.o utility.o input-output.o readlines.o

	$(CC) $(OUTPUT_FILE) output main.o sorthandler.o sortingmethods.o sortingtypes.o fieldsortmethods.o utility.o input-output.o readlines.o


main.o: main.c
	
	$(CC) $(COMPILE) main.c


sorthandler.o: sorting/sorthandler.c

	$(CC) $(COMPILE) sorting/sorthandler.c


sortingmethods.o: sorting/sortingmethods.c

	$(CC) $(COMPILE) sorting/sortingmethods.c


sortingtypes.o: sorting/sortingtypes.c

	$(CC) $(COMPILE) sorting/sortingtypes.c


fieldsortmethods.o: sorting/fieldsortmethods.c

	$(CC) $(COMPILE) sorting/fieldsortmethods.c


utility.o: utility.c

	$(CC) $(COMPILE) utility.c


input-output.o: io_files/input-output.c

	$(CC) $(COMPILE) io_files/input-output.c


readlines.o: io_files/readlines.c

	$(CC) $(COMPILE) io_files/readlines.c

# --------------------------------------------------------------------------------------------------------- #