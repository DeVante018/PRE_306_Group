#include <stdio.h>
#include <string.h>
#include  <stdbool.h>
#include <stdlib.h>
/** csv [-frh] {[-max field] [-min field] [-mean field]} [-records field value] file **/

//first field
void commandF(char*);
void commandR(char*);
int commandRHelper(char* fileName);
void maxField(char*, char*);
void minField(char*, char*);
void meanField(char*, char*);
void recordsFieldValue(char*, char*);
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
    if(arguments >= 4 ){
        if(strcmp(frh,"-f") == 0 && arguments == 4){
            commandF(file);
        }
        else if(strcmp(frh,"-r") == 0 && arguments == 4){
            commandR(file);
        }
        else if (strcmp(frh,"-h") == 0){
            fieldName = argv[4];
            if(strcmp(max,argv[3]) == 0){
                maxField(fieldName, file);
            }
            else if(strcmp(max,argv[3]) == 0){
                minField(fieldName, file);
            }
            else if(strcmp(max,argv[3]) == 0){
                meanField(fieldName, file);
            }else{
                printf("why the fuck am i here");
            }
        }
        else{
            printError();
        }
    }
    else{
     printError();
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
int commandRHelper(char* fileName){
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
    return amtOfRecords;
}

void maxField(char* field, char* fileName){
FILE *readFile;
readFile = fopen(fileName, "r");
int numberOflines = commandRHelper(fileName);
char line[1024] = {0};
char (*lines)[numberOflines] = malloc(sizeof(char [numberOflines][2048]));
//char lines[1024][1024] = {0};
int index = 0;
int index2 = 0; 
while(fgets(line, sizeof(line), readFile)){
    while(index2 < 2048){
        lines[index][index2] = line[index2];
        index2 = index2 + 1; 
    }
    index = index + 1; 
    index2 = 0;
}
index = 0; 
int relativeIndex = 0;
char storeString [2048] = {0};
char cmpString [2048] = {0};
for (int i = 0; i < strlen(field); i++){
cmpString[i] = field[i];
}
//strcpy(storeString, lines[0]);
//char *ptr = strchr(storeString, ',\0');
//char checkFor [] = ",\0"
//strcspn()
int storeIndex = 0;
while(index < 2048 ){

 if(lines[0][index] == '\0'){
     int replaceBytes = 2048 - storeIndex - 2;
     int addition = storeIndex - 2;
     memset(storeString + addition, 0, replaceBytes);
     memset(cmpString + addition, 0, replaceBytes);
     for(int i = 0; i < 2048; i++){
         if(cmpString[i] != storeString[i]){
            printf("%d", i);
         }
     }
     printf("\n");
     printf("\n");
     if(strcmp(storeString, cmpString) == 0){
         printf("hello Kyle");
         break;
     }else{
         relativeIndex = -1;
         break;
     }
    
 }else if(lines[0][index] == ','){
     if(strcmp(storeString, cmpString) == 0){
         break;
     }
    memset(storeString, 0, 2048);
    storeIndex = 0;
    relativeIndex += 1;
 }else{
     storeString[storeIndex] = lines[0][index];
     storeIndex = storeIndex + 1;
 }
 index = index + 1; 
}
index = 1;
if(relativeIndex != -1){
while(index < numberOflines){
    
    index += 1; 
}
}
printf("%d", relativeIndex);
printf("%s",lines[1]);


index = 0; 
if
while()
fclose(readFile);
}
void minField(char* field, char* fileName){}
void meanField(char* field, char* fileName){}
void recordsFieldValue(char* field, char* fileName){}

void printError(){
    printf("invalid command line arguments\n");
    printf("Use: csv [-frh] [-max field] [-min field] [-mean field] [-records field value] file\n");
}

int checkInputError(int numberOfArguments, char* argu){
    int invalidArgs = -1;
    if((numberOfArguments == 4 || numberOfArguments == 6) && strcmp(argu,"csv") == 0){
        return numberOfArguments;
    }
    else{
        return invalidArgs;
    }
}
