#include <stdio.h>
#include <string.h>
/** csv [-frh] [-max field] [-min field] [-mean field] [-records field value] file **/

//first field
void commandF(char*);
void commandR(char*);
void commandH(char*);

void maxField(char*);// not sure for parameters
void minField(char*);
void meanField(char*);
void recordsFieldValue(char*);

int main(int argc, char *argv[]){
    if(argc  <= 3){
        printf("invalid command line arguments\n");
        printf("Use: csv [-frh] [-max field] [-min field] [-mean field] [-records field value] file\n");
    }
    else if(strcmp(argv[1],"csv") != 0){
        //check arguments and types
        printf("invalid command line arguments\n");
        printf("Use: csv [-frh] [-max field] [-min field] [-mean field] [-records field value] file\n");
    }
    else{
        // parse command line arguments
    }
    return 0;
}

// implement functions
void commandF(char* fileName){}
void commandR(char* fileName){}
void commandH(char* fileName){}
void maxField(char* fileName){}// not sure for parameters
void minField(char* fileName){}
void meanField(char* fileName){}
void recordsFieldValue(char* fileName){}