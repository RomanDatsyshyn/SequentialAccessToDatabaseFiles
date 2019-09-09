#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDatabase();
void addCars();
void removeCars();
void modifyCars();
void searchCars();
void searchInt();
void searchString();
void reorderCars();
void message();
void messageAdd();
void messageRemove();
void messagePrint();
void messageToDatabase();

struct car {
    int year, price, id;
    char mark[30], model[20], town[10], fuel[20], acceleration[20], mileage[10], engine[20];
};

int main(){
remove("temp.txt");
system("cls");

int n;
printf("1 - Print Database\n2 - Add Car\n3 - Remove Car\n4 - Modify Car\n5 - Search\n6 - Message\n7 - Exit\nChoose 1..7: ");
scanf("%d", &n);
switch (n)
{
    case 1:
        system("cls");
        printDatabase();
        break;
    case 2:
        system("cls");
        addCars();
        break;
    case 3:
        system("cls");
        int id;
        printf("Enter ID: ");
        scanf("%d", &id);
        removeCars(id, 0);
        break;
    case 4:
        modifyCars();
        break;
    case 5:
        system("cls");
        searchCars();
        break;
    case 6:
        system("cls");
        message();
        break;
    case 7:
        system("cls");
        exit(0);
    default:
        
        break;
}

   return(0);
}

void printDatabase(){
    system("cls");
    FILE*fp2;
    fp2 = fopen("data.txt", "r");
    struct car a;
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("/% 3s/% 21s/% 10s/% 6s/% 10s/% 8s/% 15s/% 12s/% 11s/% 4s/\n", "ID", "Mark", "Model", "Year", "Town", "Mileage", "Engine", "Fuel", "Acceleration", "Price");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

    if (fp2) {
while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &a.id, a.mark, a.model, &a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, &a.price)!=EOF)
    {
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price
);
    }
    }
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

    fclose(fp2);
    int z = 0;
    printf("\n1 - Reload\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) printDatabase();
    else main();
}

void addCars(){
system("cls");

    FILE*fp2;
    FILE*fp3;
    fp2 = fopen("data.txt", "r");
    fp3 = fopen("temp.txt", "a");

    struct car a;
    struct car b;

    system("cls");
    printf("ID: ");
    scanf("%d", &a.id);
    printf("Mark: ");
    scanf("%s", a.mark);
    printf("Model: ");
    scanf("%s", a.model);
    printf("Year: ");
    scanf("%d", &a.year);
    printf("Town: ");
    scanf("%s", a.town);
    printf("Mileage: ");
    scanf("%s", a.mileage);
    printf("Engine: ");
    scanf("%s", a.engine);
    printf("Fuel: ");
    scanf("%s", a.fuel);
    printf("Acceleration: ");
    scanf("%s", a.acceleration);
    printf("Price: ");
    scanf("%d", &a.price);

    system("cls");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("/% 3s/% 21s/% 10s/% 6s/% 10s/% 8s/% 15s/% 12s/% 11s/% 4s/\n", "ID", "Mark", "Model", "Year", "Town", "Mileage", "Engine", "Fuel", "Acceleration", "Price");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

    int z;
    printf("\nDo you want to add this Car?");
    printf("\n1 - Yes\n2 - No\n");
    scanf("%d", &z);
    if(z == 1){
        int check = 0;
        if (fp2) {
        while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &b.id, b.mark, b.model, &b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, &b.price)!=EOF)
        {   
            if(a.id == b.id){
                system("cls");
                printf("Car with ID %d already exists", a.id);
                int z1 = 0;
                printf("\n1 - Replace\n2 - Back to menu\n");
                scanf("%d", &z1);
                system("cls");
                if(z1 == 1){
                    fclose(fp2);
                    fclose(fp3);
                    removeCars(a.id, 1);

                    fp2 = fopen("data.txt", "r");
                    fp3 = fopen("temp.txt", "a");
                    if (fp2) {
                        while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &b.id, b.mark, b.model, &b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, &b.price)!=EOF)
                            {
                            if(a.id < b.id && check == 0){
                            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
                            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
                            check++;
                            }else fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
                        }
                    }
                }else{
                    fclose(fp2);
                    fclose(fp3);
                    main();
                }
                break;
            }
            if(a.id < b.id && check == 0){
                fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
                fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
                check++;
            }else fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
        

        }
        }
        if(check == 0){
        fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
        }

        
        fclose(fp2);
        fclose(fp3);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        main();
        
    }else {
        fclose(fp2);
        fclose(fp3);
        main();
    }

}
void removeCars(int id, int q){
    remove("temp.txt");
    FILE*fp2;
    FILE*fp3;
    fp2 = fopen("data.txt", "r");
    fp3 = fopen("temp.txt", "a");
    struct car ra;

        if(fp2){
        while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &ra.id, ra.mark, ra.model, &ra.year, ra.town, ra.mileage, ra.engine, ra.fuel, ra.acceleration, &ra.price)!=EOF)
        {
            if(ra.id != id){
            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", ra.id, ra.mark, ra.model, ra.year, ra.town, ra.mileage, ra.engine, ra.fuel, ra.acceleration, ra.price);
            }
        }
        }

        
    fclose(fp2);
    fclose(fp3);
    remove("data.txt");
    rename("temp.txt", "data.txt");

    if(q == 0){
    main();
    }
    
}
void modifyCars(){
    system("cls");
    FILE*fp2;
    FILE*fp3;
    fp2 = fopen("data.txt", "r");
    struct car a;
    int n;
    int count = 0;

    printf("Enter Car ID: ");
    scanf("%d", &n);

    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("/% 3s/% 21s/% 10s/% 6s/% 10s/% 8s/% 15s/% 12s/% 11s/% 4s/\n", "ID", "Mark", "Model", "Year", "Town", "Mileage", "Engine", "Fuel", "Acceleration", "Price");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

    if (fp2) {
while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &a.id, a.mark, a.model, &a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, &a.price)!=EOF)
    {
        if(a.id == n){
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price
);
        count++;
        break;
    }
    
    }
    if(count == 0){
    printf("/% 108s%d/\n", "There is no Cars with ID ", n);
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    fclose(fp2);
    int z = 0;
    printf("\n1 - Try again\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) modifyCars();
    else main();
    }
    }
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    fclose(fp2);
    int z = 0;

    printf("\nModify:\n1 - ID\n2 - Mark\n3 - Model\n4 - Year\n5 - Town\n6 - Mileage\n7 - Engine\n8 - Fuel\n9 - Acceleration\n10 - Price\n11 - Exit to menu\n");
    scanf("%d", &z);
    system ("cls");
    switch(z){
        case 1:
        printf("Old ID: %d\n", a.id);
        printf("New ID: ");
        scanf("%d", &a.id);
        break;
        case 2:
        printf("Old Mark: %s\n", a.mark);
        printf("New Mark: ");
        scanf("%s", a.mark);
        break;
        case 3:
        printf("Old Model: %s\n", a.model);
        printf("New Model: ");
        scanf("%s", a.model);
        break;
        case 4:
        printf("Old Year: %d\n", a.year);
        printf("New Year: ");
        scanf("%d", &a.year);
        break;
        case 5:
        printf("Old Town: %s\n", a.town);
        printf("New Town: ");
        scanf("%s", a.town);
        break;
        case 6:
        printf("Old Mileage: %s\n", a.mileage);
        printf("New Mileage: ");
        scanf("%s", a.mileage);
        break;
        case 7:
        printf("Old Engine: %s\n", a.engine);
        printf("New Engine: ");
        scanf("%s", a.engine);
        break;
        case 8:
        printf("Old Fuel: %s\n", a.fuel);
        printf("New Fuel: ");
        scanf("%s", a.fuel);
        break;
        case 9:
        printf("Old Acceleration: %s\n", a.acceleration);
        printf("New Acceleration: ");
        scanf("%s", a.acceleration);
        break;
        case 10:
        printf("Old Price: %d\n", a.price);
        printf("New Price: ");
        scanf("%d", &a.price);
        break;
        case 11:
        main();
        default:
        main();
    }
    system("cls");

    struct car b;
    int check = 0;

    removeCars(a.id, 1);

    fp2 = fopen("data.txt", "r");
    fp3 = fopen("temp.txt", "a");
    if (fp2) {
        while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &b.id, b.mark, b.model, &b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, &b.price)!=EOF)
        {
            if(a.id < b.id && check == 0){
            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
            check++;
            }else fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
        }
    }
    if(check == 0){
    fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
    }
                
        fclose(fp2);
        fclose(fp3);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        main();
}

void searchCars(){
system("cls");

int z2 = 0;
printf("1 - By ID\n2 - By field\n");
scanf("%d", &z2);
if(z2 == 1){

FILE*fp2;
fp2 = fopen("data.txt", "r");
int n,t = 0;
struct car a;

system("cls");
printf("Enter ID:");
scanf("%d", &n);
system("cls");

printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
printf("/% 3s/% 21s/% 10s/% 6s/% 10s/% 8s/% 15s/% 12s/% 11s/% 4s/\n", "ID", "Mark", "Model", "Year", "Town", "Mileage", "Engine", "Fuel", "Acceleration", "Price");
printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");


if (fp2) {
while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &a.id, a.mark, a.model, &a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, &a.price)!=EOF)


if(a.id == n){
printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
    t++;
}

}
fclose(fp2);

if(t == 0){
    int z = 0;
    printf("/% 108s%d/\n", "There is no Cars with ID ", n);
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n1 - Try again\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) searchCars();
    else main();
}
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    int z = 0;
    printf("\n1 - Continue searching\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) searchCars();
    else main();

}if(z2 == 2){
system("cls");
int z3;
printf("1 - Model\n2 - Year\n3 - Town\n4 - Mileage\n5 - Engine\n6 - Fuel\n7 - Acceleration\n8 - Price\n\nChoose 1..8: ");
scanf("%d", &z3);
int sint;
char schar[30];
system("cls");

switch (z3)
{
    case 1:
        printf("Enter Model: ");
        scanf("%s", schar);
        searchString(schar, 0);
        break;
    case 2:
        printf("Enter year: ");
        scanf("%d", &sint);
        searchInt(sint, 0);
        break;
    case 3:
        printf("Enter Town: ");
        scanf("%s", schar);
        searchString(schar, 1);
        break;
    case 4:
        printf("Enter Mileage: ");
        scanf("%s", schar);
        searchString(schar, 2);
        break;
    case 5:
        printf("Enter Engine: ");
        scanf("%s", schar);
        searchString(schar, 3);
        break;
    case 6:
        printf("Enter Fuel: ");
        scanf("%s", schar);
        searchString(schar, 4);
        break;
    case 7:
        printf("Enter Acceleration: ");
        scanf("%s", schar);
        searchString(schar, 5);
        break;
    case 8:
        printf("Enter price: ");
        scanf("%d", &sint);
        searchInt(sint, 1);
        break;
    default:
        main();
}
int z4 = 0;
printf("\n1 - Try again\n2 - Back to menu\n");
scanf("%d", &z4);
if(z4 == 1) searchCars();
else main();

}

}

void searchInt(int f, int sw){
FILE*fp2;
fp2 = fopen("data.txt", "r");
struct car s;
int t = 0;

system("cls");
printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
printf("/% 3s/% 21s/% 10s/% 6s/% 10s/% 8s/% 15s/% 12s/% 11s/% 4s/\n", "ID", "Mark", "Model", "Year", "Town", "Mileage", "Engine", "Fuel", "acceleration", "Price");
printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

if(sw == 0){
        if (fp2) {
            while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &s.id, s.mark, s.model, &s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, &s.price)!=EOF)
            {   
            if(s.year == f){
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", s.id, s.mark, s.model, s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, s.price);
            t++;
            }
            }
        }
}if(sw == 1){
        if (fp2) {
            while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &s.id, s.mark, s.model, &s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, &s.price)!=EOF)
            {   
            if(s.price == f){
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", s.id, s.mark, s.model, s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, s.price);
            t++;
            }
            }
        }
}
    fclose(fp2);
    if (t == 0) printf("/% 109s/\n", "No matches found");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

}

void searchString(char f[30], int sw){

FILE*fp2;
fp2 = fopen("data.txt", "r");
struct car s;
int t = 0;
char *strcheck;

system("cls");
printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
printf("/% 3s/% 21s/% 10s/% 6s/% 10s/% 8s/% 15s/% 12s/% 11s/% 4s/\n", "ID", "Mark", "Model", "Year", "Town", "Mileage", "Engine", "Fuel", "Acceleration", "Price");
printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

if(sw == 0){
        if (fp2) {
            while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &s.id, s.mark, s.model, &s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, &s.price)!=EOF)
            {
            strcheck = strstr(s.model, f);
            if(strcheck != 0){
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", s.id, s.mark, s.model, s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, s.price);
            t++;
            }
            }
        }
}if(sw == 1){
        if (fp2) {
            while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &s.id, s.mark, s.model, &s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, &s.price)!=EOF)
            {   
            strcheck = strstr(s.town, f);
            if(strcheck != 0){
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", s.id, s.mark, s.model, s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, s.price);
            t++;
            }
            }
        }
}if(sw == 2){
        if (fp2) {
            while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &s.id, s.mark, s.model, &s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, &s.price)!=EOF)
            {   
            strcheck = strstr(s.mileage, f);
            if(strcheck != 0){
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", s.id, s.mark, s.model, s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, s.price);
            t++;
            }
            }
        }
}if(sw == 3){
        if (fp2) {
            while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &s.id, s.mark, s.model, &s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, &s.price)!=EOF)
            {   
            strcheck = strstr(s.engine, f);
            if(strcheck != 0){
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", s.id, s.mark, s.model, s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, s.price);
            t++;
            }
            }
        }
}if(sw == 4){
        if (fp2) {
            while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &s.id, s.mark, s.model, &s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, &s.price)!=EOF)
            {   
            strcheck = strstr(s.fuel, f);
            if(strcheck != 0){
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", s.id, s.mark, s.model, s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, s.price);
            t++;
            }
            }
        }
}if(sw == 5){
        if (fp2) {
            while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &s.id, s.mark, s.model, &s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, &s.price)!=EOF)
            {   
            strcheck = strstr(s.acceleration, f);
            if(strcheck != 0){
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", s.id, s.mark, s.model, s.year, s.town, s.mileage, s.engine, s.fuel, s.acceleration, s.price);
            t++;
            }
            }
        }
}


fclose(fp2);
if (t == 0) printf("/% 109s/\n", "No matches found");
printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
}

void message(){
system("cls");
int n;
printf("1 - Add\n2 - Remove\n3 - Print\n4 - Add to DataBase\n5 - Back\n\nChoose 1..5: ");
scanf("%d", &n);
switch (n)
{
    case 1:
        messageAdd();
        break;
    case 2:
        system("cls");
        int id;
        printf("Enter ID: ");
        scanf("%d", &id);
        messageRemove(id, 0);
        break;
    case 3:
        messagePrint();
        break;
    case 4:
        messageToDatabase();
        break;
    case 5:
        system("cls");
        main();
        break;
    default:    
        break;
}
}

void messageAdd(){
    
    FILE*fp2;
    FILE*fp3;
    fp2 = fopen("message.txt", "r");
    fp3 = fopen("temp.txt", "a");

    struct car a;
    struct car b;

    system("cls");
    printf("ID: ");
    scanf("%d", &a.id);
    printf("Mark: ");
    scanf("%s", a.mark);
    printf("Model: ");
    scanf("%s", a.model);
    printf("Year: ");
    scanf("%d", &a.year);
    printf("Town: ");
    scanf("%s", a.town);
    printf("Mileage: ");
    scanf("%s", a.mileage);
    printf("Engine: ");
    scanf("%s", a.engine);
    printf("Fuel: ");
    scanf("%s", a.fuel);
    printf("Acceleration: ");
    scanf("%s", a.acceleration);
    printf("Price: ");
    scanf("%d", &a.price);

    system("cls");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("/% 3s/% 21s/% 10s/% 6s/% 10s/% 8s/% 15s/% 12s/% 11s/% 4s/\n", "ID", "Mark", "Model", "Year", "Town", "Mileage", "Engine", "Fuel", "Acceleration", "Price");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

    int z;
    printf("\nDo you want to add this Car?");
    printf("\n1 - Yes\n2 - No\n");
    scanf("%d", &z);
    if(z == 1){
        int check = 0;
        if (fp2) {
        while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &b.id, b.mark, b.model, &b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, &b.price)!=EOF)
        {   
            if(a.id == b.id){
                system("cls");
                printf("Car with ID %d already exists", a.id);
                int z1 = 0;
                printf("\n1 - Replace\n2 - Back to menu\n");
                scanf("%d", &z1);
                system("cls");
                if(z1 == 1){
                    fclose(fp2);
                    fclose(fp3);
                    messageRemove(a.id, 1);

                    fp2 = fopen("message.txt", "r");
                    fp3 = fopen("temp.txt", "a");
                    if (fp2) {
                        while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &b.id, b.mark, b.model, &b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, &b.price)!=EOF)
                            {
                            if(a.id < b.id && check == 0){
                            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
                            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
                            check++;
                            }else fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
                        }
                    }
                }else{
                    fclose(fp2);
                    fclose(fp3);
                    message();
                }
                break;
            }
            if(a.id < b.id && check == 0){
                fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
                fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
                check++;
            }else fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", b.id, b.mark, b.model, b.year, b.town, b.mileage, b.engine, b.fuel, b.acceleration, b.price);
    
        }
        }
        if(check == 0){
        fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price);
        }

        fclose(fp2);
        fclose(fp3);
        remove("message.txt");
        rename("temp.txt", "message.txt");
        message();
        
    }else {
        fclose(fp2);
        fclose(fp3);
        message();
    }
}

void messageRemove(int id, int q){
    remove("temp.txt");
    FILE*fp2;
    FILE*fp3;
    fp2 = fopen("message.txt", "r");
    fp3 = fopen("temp.txt", "a");
    struct car ra;

        if(fp2){
        while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &ra.id, ra.mark, ra.model, &ra.year, ra.town, ra.mileage, ra.engine, ra.fuel, ra.acceleration, &ra.price)!=EOF)
        {
            if(ra.id != id){
            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", ra.id, ra.mark, ra.model, ra.year, ra.town, ra.mileage, ra.engine, ra.fuel, ra.acceleration, ra.price);
            }
        }
        }
    fclose(fp2);
    fclose(fp3);
    remove("message.txt");
    rename("temp.txt", "message.txt");

    if(q == 0){
    message();
    }
}

void messagePrint(){
    system("cls");
    int check = 0;
    FILE*fp2;
    fp2 = fopen("message.txt", "r");
    struct car a;
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("/% 3s/% 21s/% 10s/% 6s/% 10s/% 8s/% 15s/% 12s/% 11s/% 4s/\n", "ID", "Mark", "Model", "Year", "Town", "Mileage", "Engine", "Fuel", "Acceleration", "Price");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

    if (fp2) {
while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &a.id, a.mark, a.model, &a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, &a.price)!=EOF)
    {
            printf("/% 3d/% 21s/% 10s/% 6d/% 10s/% 8s/% 15s/% 12s/% 11s/% 5d/\n", a.id, a.mark, a.model, a.year, a.town, a.mileage, a.engine, a.fuel, a.acceleration, a.price
);
            check++;
    }
    }

    if(check == 0){
        printf("/% 110s/\n", "There is no Cars");
        printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    }else printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

    fclose(fp2);
    int z = 0;
    printf("\n1 - Reload\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) messagePrint();
    else message();
}

void messageToDatabase(){

    FILE*fp1;
    FILE*fp2;
    FILE*fp3;
    fp1 = fopen("message.txt", "r");

    int count = 0;



    struct car d;
    struct car m;

    if (fp1) {
        while (fscanf(fp1, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &m.id, m.mark, m.model, &m.year, m.town, m.mileage, m.engine, m.fuel, m.acceleration, &m.price)!=EOF)
        {       
                count++;
                fp2 = fopen("data.txt", "r");
                fp3 = fopen("temp.txt", "a");
            removeCars(m.id, 1);
                fclose(fp2);
                fclose(fp3);
                remove("data.txt");
                rename("temp.txt", "data.txt");
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    for (int i = 0; i < count; i++){
        printf("////////////");
    fp1 = fopen("message.txt", "r");
    fp2 = fopen("data.txt", "r");
    fp3 = fopen("temp.txt", "a");

    int check1 = 0;
    int check2 = 0;

        fscanf(fp1, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &m.id, m.mark, m.model, &m.year, m.town, m.mileage, m.engine, m.fuel, m.acceleration, &m.price);
        if(fp2){
                while (fscanf(fp2, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &d.id, d.mark, d.model, &d.year, d.town, d.mileage, d.engine, d.fuel, d.acceleration, &d.price)!=EOF)
                {
                        if(m.id < d.id && check1 == 0){
                            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", m.id, m.mark, m.model, m.year, m.town, m.mileage, m.engine, m.fuel, m.acceleration, m.price);
                            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", d.id, d.mark, d.model, d.year, d.town, d.mileage, d.engine, d.fuel, d.acceleration, d.price);
                            check1++;
                        }else{
                            fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", d.id, d.mark, d.model, d.year, d.town, d.mileage, d.engine, d.fuel, d.acceleration, d.price);
                    }
                }
        }

        if(check1 == 0){
        fprintf(fp3, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", m.id, m.mark, m.model, m.year, m.town, m.mileage, m.engine, m.fuel, m.acceleration, m.price);
        }

        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        remove("data.txt");
        rename("temp.txt", "data.txt");

        messageRemove(m.id, 1);

    }
    message();
    }





