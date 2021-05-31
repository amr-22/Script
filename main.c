#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listFiles(){
    int x;
    do{
        char path[100], com2[200];
        strcpy(com2, "ls ");
        printf("Enter Path: ");
        scanf("%s",path);
        printf("1- list all files including hidden files\n2- Format list with hidden files\n3-Sorting the Formatted listing by time\n4-list all directory\n5- sort by file size\n6- list in reverse order\n7-Exit\n-> ");
        scanf("%d ", &x);
        if (x == 7){
            break;
        }
        switch (x){
            case 1:
                strcat(com2, "-a ");
                break;
            case 2:
                strcat(com2, "-la ");
                break;
            case 3:
                strcat(com2,"-lt ");
                break;
            case 4:
                strcat(com2, " ");
                break;
            case 5:
                strcat(com2, "-S ");
                break;
            case 6:
                strcat(com2, "-r ");
                break;
            default:
                printf("wrong input");
                break;
        }
        strcat(com2, path);
        system(com2);
    }
    while(1);
}

void changePermissions(){
    char x[]="y";
    do{
        char path[100],command[200],nameOfFile[100],currentPath[100],Permission[100],location[100];
        strcpy(command,"\nchmod ");
        printf("enter your path:");
        scanf("%s",path);
        strcpy(currentPath,"cd ");
        strcat(currentPath,path);
        strcpy(location, currentPath);
        strcat(currentPath,"\nls -l");
        system(currentPath);
        printf("enter your Permission:");
        scanf("%s",Permission);
        printf("enter name of file:");
        scanf("%s",nameOfFile);
        strcat(command,Permission);
        strcat(command," ");
        strcat(command,nameOfFile);
        printf("\nstring:%s\n",command);
        strcat(location,command);
        system(location);
        printf("You want to Exit (y/n)");
        scanf("%s",x);
    }while (strcmp(x,"n") == 0);
}

void makeDeleteFD(){
    int c;
    while(1){
        char path[100],dest[100],com[100],name[100];
        printf("1-Make file/Directory.\n2-Delete file/Directory.\n3-Exit\n-> ");

        scanf("%d",&c);
        if (c == 3)
            break;

        char t[100];
        int z = 0;


        switch (c){
            case 1:

                printf("\n1-Make a file\n2-Make a Directory\n->");
                scanf("%d",&z);
                if(z == 1){
                    strcpy(com,"touch ");
                    printf("Enter file name: ");
                }
                else{
                    strcpy(com,"mkdir ");
                    printf("Enter directory name: ");
                }
                scanf("%s",name);
                printf("Enter it's Path: ");
                scanf("%s",path);



                strcat(com,path);//add the path to the command
                strcat(com,"/");
                strcat(com,name);//add the File name

                system(com);

                break;

            case 2:
                strcpy(com,"rm ");
                printf("1-Delete a file\n2-Delete a Directory\n->");
                scanf("%d",&z);
                if(z == 1)
                    printf("Enter file path");

                else{
                    strcat(com," -r ");
                    printf("Enter Directory path:");
                }
                scanf("%s",path);
                strcat(com,path);//total path will be added to the command EX: rm -r ~/Downloads/ahmed
                system(com);
                break;

            default:
                printf("invalid input");
                break;
        }
    }
}

void symbolicLink(){
    char x[] = "y";
    do{
        char path[100],dest[100],com[200];
        strcpy(com,"ln -s ");
        printf("Enter The path of the file: ");
        scanf("%s",path);
        strcat(com,path);
        printf("Enter The destination  of the file: ");
        scanf("%s",dest);
        strcat(com," ");
        strcat(com,dest);
        system(com);
        printf("You want to Exit (y/n)");
        scanf("%s",x);
    }while (strcmp(x,"n") == 0);
}

void renameFD(){

}

int main(int argc,char *argv[]){
    if(argc>1) {
        if (strcmp(argv[1], "--help") == 0)
            printf("File Manager\n");
        printf("1       (list files by many sort constraints\n");
    }
    else {
        int x = 0;
        while (1) {
            printf("Menu:\n1-List files/directories\n2-Change permissions of files\n3-Make/delete files/directories\n4-Create symbolic link files\n5-Rename files/directories\n6-Exit\n->");
            scanf("%d", &x);
            switch (x) {
                case 1:
                    listFiles();
                    break;

                case 2:
                    changePermissions();
                    break;

                case 3:
                    makeDeleteFD();
                    break;

                case 4:
                    symbolicLink();
                    break;

                case 5:
                    renameFD();
                    break;
                case 6:
                    exit(0);

                default:
                    break;
            }
        }
    }
    return 0;
}
