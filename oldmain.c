#include <stdio.h>
#include <string.h>
#include  <stdbool.h>
#include <stdlib.h>
/** csv [-frh] {[-max field] [-min field] [-mean field]} [-records field value] file **/

//first field
void commandF(char*);
void commandR(char*);
void commandH(char*);

void maxField(char*, char*, char*);
void minField(char*, char*, char*);
void meanField(char*, char*, char*);
void recordsFieldValue(char*, char*, char*);
int checkInputError(int, char*);
void initOptions(char**);

void printError();

int main(int argc, char *argv[]){

    int arguments = checkInputError(argc, argv[1]);
    if(arguments == -1){
        printError();
        return 0;
    }

    char* frh = argv[2];
    char* max = "-max";
    char* min = "-min";
    char* mean = "-mean";
    char* fieldName;
    char* file = argv[argc-1];

    if(arguments == 4 ){
        if(strcmp(frh,"-f") == 0){
            commandF(file);
        }
        else if(strcmp(frh,"-r") == 0){
            commandR(file);
        }
        else if (strcmp(frh,"h") == 0){
            commandH(file);
        }
    }
    else{
        fieldName = argv[4];
        if(strcmp(frh,"-f") == 0 || strcmp(frh,"-r") == 0 || strcmp(frh,"-h") == 0){
            // chek if its max, min, mean or record
            if(max == argv[3]){
                maxField(frh, fieldName, fieldName);
            }
            else if(min == argv[3]){
                minField(frh, fieldName, fieldName);
            }
            else if(mean == argv[3]){
                meanField(frh, fieldName, fieldName);
            }
            else recordsFieldValue(frh, fieldName, fieldName);
        }
        else printError();
    }
    return 0;
}

// implement functions
void commandF(char* fileName){
    FILE *readFile;
    bool charRead = false;
    int fieldLength = 0;
    char* field = (char*)malloc(sizeof(char*)*30);
    int amtOfFields = 0;
    //printf("reading file...\n");
    readFile = fopen(fileName, "r");

    if(readFile == NULL){
        printf("Error NULL file read");
    }
    else{
        fscanf(readFile,"%s",field);     // reads in a whole line from the file
        if(field[0] != '\0'){            // makes sure the file isn't empty
            charRead = true;             // flag that lets us know at least one field was read
            fieldLength = strlen(field); //length of the line read in
            //printf("field: %s\n",field);
            for(int i = 0; i<=fieldLength; i++){
                if(field[i] == ',' || field[i] == '\0'){
                    amtOfFields++;                          /* check for a comma or null character and increment the amount of
                                                            fields read*/
                }
            }
        }

    }
    fclose(readFile);
    if(charRead){
        printf("Number of fields: %d\n",amtOfFields);
    }
    else{
        printf("Number of fields: %d\n",0);
    }
}
void commandR(char* fileName){
    FILE *readFile;
    bool charRead = false;
    char* field = (char*)malloc(sizeof(char*)*30);
    int amtOfRecords = 0;
    readFile = fopen(fileName, "r");

    if(readFile == NULL){
        printf("Error NULL file read");
    }
    else{
        fscanf(readFile,"%s",field);
        amtOfRecords++;
        if(field[0] != '\0'){
            charRead = true;
            while(fscanf(readFile, "%c", field) == 1){
                if(*field == '\n'){
                    amtOfRecords++;
                }
            }
        }
    }

    fclose(readFile);
    if(charRead){
        printf("Number of lines: %d\n",amtOfRecords);
    }
    else{
        printf("Number of records: %d\n",0);
    }
}

void commandH(char* fileName){
    FILE *readFile;
    bool charRead = false;
    char* field = (char*)malloc(sizeof(char*)*30);
    readFile = fopen(fileName, "r");

    if(readFile == NULL){
        printf("Error NULL file read");
    }
    else{
        fscanf(readFile,"%s",field);     // reads in a whole line from the file
        if(field[0] != '\0'){            // makes sure the file isn't empty
            charRead = true;             // flag that lets us know at least one field was read

        }
    }
}

void maxField(char* frhCmd, char* field, char* fileName){}
void minField(char* frhCmd, char* field, char* fileName){}
void meanField(char* frhCmd, char* field, char* fileName){}
void recordsFieldValue(char* frhCmd, char* field, char* fileName){}

void printError(){
    printf("invalid command line arguments\n");
    printf("Use: csv [-frh] [-max field] [-min field] [-mean field] [-records field value] file\n");
}

int checkInputError(int numberOfArguments, char* argu){
    int invalidArgs = -1;
    if(numberOfArguments == 4 || numberOfArguments == 6 && strcmp(argu,"csv") == 0){
        return numberOfArguments;
    }
    else{
        return invalidArgs;
    }
}