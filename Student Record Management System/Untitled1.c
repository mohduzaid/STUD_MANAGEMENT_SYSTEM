#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Student{
    int id;
    char name[20];
    int age;
    float score;
} Student;

void addStudent(){
    FILE* fp = fopen("Studentrec.txt","a");
    Student s;
    printf("Enter the details of the student\n");
    printf("Student ID: ");
    scanf("%d", &s.id);
    printf("Student Name: ");
    getchar();
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    printf("Student Age: ");
    scanf("%d", &s.age);
    printf("Student Score: ");
    scanf("%f", &s.score);
    fprintf(fp, "%d %s %d %.2f\n", s.id, s.name, s.age, s.score);
    fclose(fp);
}

void displayStudent(){
    FILE* fp = fopen("Studentrec.txt","r");
    Student s;
    printf("---DATA OF ALL THE STUDENTS---\n");
    printf("\n");

    while(fscanf(fp,"%d %s %d %f",&s.id, s.name, &s.age, &s.score)!=EOF){
        printf("Student ID: %d\n",s.id);
        printf("Name: %s\n",s.name);
        printf("Age: %d\n",s.age);
        printf("Score: %.2f\n",s.score);
        printf("\n");
    }
    fclose(fp);
}

void searchStudent(){

    FILE* fp = fopen("Studentrec.txt","r");
    Student s;
    int num; int found = 0;
    printf("Enter the ID to be searched\nID: ");
    scanf("%d", &num);
    while(fscanf(fp,"%d %s %d %f",&s.id, s.name, &s.age, &s.score)!=EOF){

        if(num==s.id){
            printf("---FOUNDED---\n");
            printf("Student ID: %d\n",s.id);
            printf("Name: %s\n",s.name);
            printf("Age: %d\n",s.age);
            printf("Score: %f\n",s.score);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("NOT FOUND\n");
    }
    fclose(fp);
}

void editStudent(){
    int num; int found = 0;
    printf("Enter the ID to edit\nID: ");
    scanf("%d", &num);
    FILE* fp = fopen("Studentrec.txt","r");
    FILE* temp = fopen("temp.txt","w");
    Student s;
    while(fscanf(fp,"%d %s %d %f",&s.id, s.name, &s.age, &s.score)!=EOF){

        if(s.id==num){
            printf("Enter new Details\n");
            printf("ID: ");
            scanf("%d", &s.id);
            printf("Name: ");
            getchar();
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0;
            printf("Age: ");
            scanf("%d", &s.age);
            printf("Score: ");
            scanf("%f", &s.score);
            found = 1;
        }
        fprintf(temp,"%d %s %d %.2f\n",s.id, s.name, s.age, s.score);
    }
    fclose(fp);
    fclose(temp);
    remove("Studentrec.txt");
    rename("temp.txt", "Studentrec.txt");
    if(!found){
        printf("STUDENT NOT FOUND\n");
    }
    else{
        printf("UPDATED SUCCESFSULLY");
    }

}


void deleteStudent(){
    int num; int found = 0;
    printf("Enter the ID to delete\nID: ");
    scanf("%d", &num);
    FILE* fp = fopen("Studentrec.txt","r");
    FILE* temp = fopen("temp.txt","w");
    Student s;

    while(fscanf(fp,"%d %s %d %f",&s.id, s.name, &s.age, &s.score)!= EOF){
        if(s.id!=num){
            fprintf(temp,"%d %s %d %f\n", s.id, s.name, s.age, s.score);
        }
        else{
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("Studentrec.txt");
    rename("temp.txt", "Studentrec.txt");
    if(!found){
         printf("STUDENT NOT FOUND\n");
    }
    else{
        printf("DELETED SUCCESSFULLY");
    }

}
int main(){
    int n;
    do{
        printf("---STUDENT RECORD MANAGEMENT SYSTEM---\n");
        printf("Press 1 to Add Student\n");
        printf("Press 2 to Display details of Students\n");
        printf("Press 3 to Delete Student\n");
        printf("Press 4 to Edit Student details\n");
        printf("Press 5 to Search Student\n");
        printf("Press 0 to Exit\n");
        scanf("%d", &n);

        switch(n){
            case 1: addStudent(); break;
            case 2: displayStudent(); break;
            case 3: deleteStudent(); break;
            case 4: editStudent(); break;
            case 5: searchStudent(); break;
            case 0: printf("Exiting..."); break;
            default: printf("INVALID CHOICE");
        }
    }while(n!=0);
    return 0;
}
