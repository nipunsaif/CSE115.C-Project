#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

struct Restaurant
{
    char name[100];
    int id;
    float weight;
    float cal;
    char ingre[80];
    int quantity;
    int price;
    char man[20];
    char exp[20];
    int dis;
    int vat;
    int del;

};

void addFood()
{
    int n;
    printf("How many food item do you want to add: ");
    scanf("%d",&n);

    FILE *fp;
    fp=fopen("food.txt","a");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        struct Restaurant r[n];
        for(int i=0; i<n; i++)
        {
            printf("Food:\n");

            fflush(stdin);
            printf("\tName: ");
            gets(r[i].name);
            fprintf(fp,"%s\t",r[i].name);

            printf("\tID: ");
            scanf("%d",&r[i].id);
            fprintf(fp,"%d\t",r[i].id);

            printf("\tWeight: ");
            scanf("%f",&r[i].weight);
            fprintf(fp,"%f\t",r[i].weight);

            printf("\tCalories: ");
            scanf("%f",&r[i].cal);
            fprintf(fp,"%f\t",r[i].cal);

            fflush(stdin);
            printf("\tIngredients: ");
            scanf("%s",&r[i].ingre);
            fprintf(fp,"%s\t",r[i].ingre);

            printf("\tQuantity: ");
            scanf("%d",&r[i].quantity);
            fprintf(fp,"%d\t",r[i].quantity);

            printf("\tPrice per unit: ");
            scanf("%d",&r[i].price);
            fprintf(fp,"%d\t",r[i].price);

            fflush(stdin);
            printf("\tManufacture Date: ");
            scanf("%s",&r[i].man);
            fprintf(fp,"%s\t",r[i].man);

            fflush(stdin);
            printf("\tExpire Date: ");
            scanf("%s",&r[i].exp);
            fprintf(fp,"%s\t",r[i].exp);

            printf("\tDiscount: ");
            scanf("%d",&r[i].dis);
            fprintf(fp,"%d\t",r[i].dis);

            printf("\tVat: ");
            scanf("%d",&r[i].vat);
            fprintf(fp,"%d\t",r[i].vat);

            printf("\tDelivery charge: ");
            scanf("%d",&r[i].del);
            fprintf(fp,"%d\n",r[i].del);

            printf("\n");

        }
    }
    fclose(fp);
}

void display()
{
    struct Restaurant r[1000];
    FILE *fp;
    int count;

    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        for(int i=0; ; i++)
        {
            if(feof(fp))
            {
                break;
            }
            else
            {
                fscanf(fp,"%s %d %f %f %s %d %d %s %s %d %d %d\n",&r[i].name,&r[i].id,&r[i].weight,&r[i].cal,&r[i].ingre,&r[i].quantity,&r[i].price,&r[i].man,&r[i].exp,&r[i].dis,&r[i].vat,&r[i].del);

                printf("Food:\n");

                printf("\tName: %s\n",r[i].name);

                printf("\tID: %d\n",r[i].id);

                printf("\tWeight: %f\n",r[i].weight);

                printf("\tCalorie: %f\n",r[i].cal);

                printf("\tIngredients: %s\n",r[i].ingre);

                printf("\tQuantity: %d\n",r[i].quantity);

                printf("\tPrice: %d\n",r[i].price);

                printf("\tManufacture Date: %s\n",r[i].man);

                printf("\tExpire Date: %s\n",r[i].exp);

                printf("\tDiscount: %d\n",r[i].dis);

                printf("\tVat: %d\n",r[i].vat);

                printf("\tDelivery charge: %d\n",r[i].del);

                printf("\n");
            }
        }
    }

    fclose(fp);
}

void deleteFood()
{
    int num;
    fflush(stdin);
    printf("Enter the food id that you want to remove from menu: ");
    scanf("%d",&num);

    struct Restaurant r[1000];
    FILE *fp;
    int count;

    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        count=0;
        for(int i=0; ; i++)
        {
            if(feof(fp))
            {
                break;
            }
            else
            {
                fscanf(fp,"%s %d %f %f %s %d %d %s %s %d %d %d\n",&r[i].name,&r[i].id,&r[i].weight,&r[i].cal,&r[i].ingre,&r[i].quantity,&r[i].price,&r[i].man,&r[i].exp,&r[i].dis,&r[i].vat,&r[i].del);
                count++;
            }
        }
    }
    fclose(fp);

    fp=fopen("food.txt","w");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        int flag=0;
        for(int i=0; i<count; i++)
        {
            if(r[i].id==num)
            {
                flag++;
                continue;
            }

            fprintf(fp,"%s\t",r[i].name);
            fprintf(fp,"%d\t",r[i].id);
            fprintf(fp,"%f\t",r[i].weight);
            fprintf(fp,"%f\t",r[i].cal);
            fprintf(fp,"%s\t",r[i].ingre);
            fprintf(fp,"%d\t",r[i].quantity);
            fprintf(fp,"%d\t",r[i].price);
            fprintf(fp,"%s\t",r[i].man);
            fprintf(fp,"%s\t",r[i].exp);
            fprintf(fp,"%d\t",r[i].dis);
            fprintf(fp,"%d\t",r[i].vat);
            fprintf(fp,"%d\n",r[i].del);


        }
        if(flag==0)
        {
            Beep(610,500);
            printf("\nInvalid ID!!\n");
        }

        else
        {
            printf("\nFood Item Removed Successfully\n");
        }
    }
    fclose(fp);
}

void editFood()
{
    int num;
    fflush(stdin);
    printf("Enter the food id that you want to edit from menu: ");
    scanf("%d",&num);

    struct Restaurant r[1000];
    FILE *fp;
    int count;

    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        count=0;
        for(int i=0; ; i++)
        {
            if(feof(fp))
            {
                break;
            }
            else
            {
                fscanf(fp,"%s %d %f %f %s %d %d %s %s %d %d %d\n",&r[i].name,&r[i].id,&r[i].weight,&r[i].cal,&r[i].ingre,&r[i].quantity,&r[i].price,&r[i].man,&r[i].exp,&r[i].dis,&r[i].vat,&r[i].del);
                count++;
            }
        }
    }
    fclose(fp);

    fp=fopen("food.txt","w");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        int flag=0;
        for(int i=0; i<count; i++)
        {
            if(r[i].id==num)
            {
                flag++;
                printf("Enter new info of food id- %d:\n",r[i].id);
                fflush(stdin);
                printf("\tName: ");
                gets(r[i].name);
                fprintf(fp,"%s\t",r[i].name);

                printf("\tID: ");
                scanf("%d",&r[i].id);
                fprintf(fp,"%d\t",r[i].id);

                printf("\tWeight: ");
                scanf("%f",&r[i].weight);
                fprintf(fp,"%f\t",r[i].weight);

                printf("\tCalories: ");
                scanf("%f",&r[i].cal);
                fprintf(fp,"%f\t",r[i].cal);

                fflush(stdin);
                printf("\tIngredients: ");
                scanf("%s",&r[i].ingre);
                fprintf(fp,"%s\t",r[i].ingre);

                printf("\tQuantity: ");
                scanf("%d",&r[i].quantity);
                fprintf(fp,"%d\t",r[i].quantity);

                printf("\tPrice per unit: ");
                scanf("%d",&r[i].price);
                fprintf(fp,"%d\t",r[i].price);

                fflush(stdin);
                printf("\tManufacture Date: ");
                scanf("%s",&r[i].man);
                fprintf(fp,"%s\t",r[i].man);

                fflush(stdin);
                printf("\tExpire Date: ");
                scanf("%s",&r[i].exp);
                fprintf(fp,"%s\t",r[i].exp);

                printf("\tDiscount: ");
                scanf("%d",&r[i].dis);
                fprintf(fp,"%d\t",r[i].dis);

                printf("\tVat: ");
                scanf("%d",&r[i].vat);
                fprintf(fp,"%d\t",r[i].vat);

                printf("\tDelivery charge: ");
                scanf("%d",&r[i].del);
                fprintf(fp,"%d\n",r[i].del);
                continue;
            }

            fprintf(fp,"%s\t",r[i].name);
            fprintf(fp,"%d\t",r[i].id);
            fprintf(fp,"%f\t",r[i].weight);
            fprintf(fp,"%f\t",r[i].cal);
            fprintf(fp,"%s\t",r[i].ingre);
            fprintf(fp,"%d\t",r[i].quantity);
            fprintf(fp,"%d\t",r[i].price);
            fprintf(fp,"%s\t",r[i].man);
            fprintf(fp,"%s\t",r[i].exp);
            fprintf(fp,"%d\t",r[i].dis);
            fprintf(fp,"%d\t",r[i].vat);
            fprintf(fp,"%d\n",r[i].del);


        }
        if(flag==0)
        {
            Beep(610,500);
            printf("\nInvalid ID!!\n");
        }

        else
        {
            printf("\nFood Item Edited Successfully\n");
        }
    }
    fclose(fp);
}

void searchFood()
{
    char nam[100];
    fflush(stdin);
    printf("Enter a food name that you want to search: ");
    gets(nam);

    struct Restaurant res[1000];
    FILE *fp;
    int count;

    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        int flag=0;
        for(int i=0; ; i++)
        {
            if(feof(fp))
            {
                break;
            }
            else
            {
                fscanf(fp,"%s %d %f %f %s %d %d %s %s %d %d %d\n",&res[i].name,&res[i].id,&res[i].weight,&res[i].cal,&res[i].ingre,&res[i].quantity,&res[i].price,&res[i].man,&res[i].exp,&res[i].dis,&res[i].vat,&res[i].del);

                if(strcmp(nam,res[i].name)==0)
                {
                    flag++;
                    printf("Food:\n");

                    printf("\tName: %s\n",res[i].name);

                    printf("\tID: %d\n",res[i].id);

                    printf("\tWeight: %f\n",res[i].weight);

                    printf("\tCalories: %f\n",res[i].cal);

                    printf("\tIngredients: %s\n",res[i].ingre);

                    printf("\tQuantity: %d\n",res[i].quantity);

                    printf("\tPrice: %d\n",res[i].price);

                    printf("\tManufacture Date: %s\n",res[i].man);

                    printf("\tExpire Date: %s\n",res[i].exp);

                    printf("\tDiscount: %d\n",res[i].dis);

                    printf("\tVat: %d\n",res[i].vat);

                    printf("\tDelivery charge: %d\n",res[i].del);

                    printf("\n\n");
                }
            }
        }

        if(flag==0)
        {
            Beep(610,500);
            printf("There no food item by this name");
        }
    }

    fclose(fp);
}
void orderFood()
{
    int num;
    struct Restaurant r[1000];
    FILE *fp;
    int count;

    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        count=0;
        for(int i=0; ; i++)
        {
            if(feof(fp))
            {
                break;
            }
            else
            {
                fscanf(fp,"%s %d %f %f %s %d %d %s %s %d %d %d\n",&r[i].name,&r[i].id,&r[i].weight,&r[i].cal,&r[i].ingre,&r[i].quantity,&r[i].price,&r[i].man,&r[i].exp,&r[i].dis,&r[i].vat,&r[i].del);
                count++;
            }
        }
    }
    fclose(fp);
    float result=0;
    while(1)
    {
        printf("\nEnter food id that your want to order: ");
        scanf("%d",&num);

        for(int i=0; i<count; i++)
        {
            if(num==r[i].id)
            {
                printf("\nOrdered food:\n");
                printf("\tName: %s\n",r[i].name);
                printf("\tID: %d\n",r[i].id);
                printf("\tPrice: %d\n",r[i].price);
                printf("\tDiscount: %d\n",r[i].dis);
                printf("\tVat: %d\n",r[i].vat);

                result=result+r[i].price+(r[i].vat/100.0)-r[i].dis;
            }
        }
        int x;

        printf("Do you want to order anything else?\n1. Yes.\n2. No\n");
        printf("Enter your choice: ");
        scanf("%d",&x);

        if(x==1)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    printf("\nOrder completed successfully\nYou have to pay %f tk\n",result);
}

int login()
{
    char admin[20],pass[20];
    fflush(stdin);
    printf("\n\nAdmin: ");
    gets(admin);

    fflush(stdin);
    printf("\nPassword: ");
    gets(pass);

    if((strcmp(admin,"humayra")==0&&strcmp(pass,"humayra123")==0)||(strcmp(admin,"abrar")==0&&strcmp(pass,"abrar123")==0)||(strcmp(admin,"muntasirul")==0&&strcmp(pass,"muntasirul123")==0)||(strcmp(admin,"saif")==0&&strcmp(pass,"saif123")==0))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
int main()
{
    system("color 3F");
    int a,b;
    while(1)
    {
        time_t now;
        time(&now);
        printf("\n\t\t\t\t\t\t%s",ctime(&now));

        printf("                                   *************************************************\n");
        printf("                                   WELCOME TO CHAR-PHORON\n");
        printf("                                                     -WE CARE ABOUT YOUR TASTE\n");
        printf("                                   *************************************************\n\n");
        printf("1.Admin\n2.Customer\n0.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&a);

        switch(a)
        {
        case 1:
        {
            int re=login();
            if(re==1)
            {
                system("cls");
                int x;
                printf("                                   ************************\n");
                printf("                                   WELCOME TO ADMIN WINDOW\n");
                printf("                                   ************************\n\n");
                printf("1. Add food item.\n2. Display info of all food.\n3. delete food item.\n4. Edit food info.\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d",&x);

                switch(x)
                {
                case 1:
                {
                    system("cls");
                    addFood();
                    break;
                }
                case 2:
                {
                    system("cls");
                    display();
                    break;

                }
                case 3:
                {
                    system("cls");
                    deleteFood();
                    break;

                }
                case 4:
                {
                    system("cls");
                    editFood();
                    break;

                }
                case 0:
                {
                    system("cls");
                    return 0;
                    break;
                }
                }
            }

            else
            {
                Beep(610,500);
                printf("\n\nWrong Input!!");
            }
            break;
        }
        case 2:
        {
            printf("                                   *************************\n");
            printf("                                   WELCOME TO CUSTOMER WINDOW\n");
            printf("                                   *************************\n\n");
            printf("1. Display all food item.\n2. Search food.\n3. Order food.\n0. Exit");
            int flag;
            printf("\n\nEnter your choice: ");
            scanf("%d",&flag);

            switch(flag)
            {
            case 1:
            {
                system("cls");
                display();
                break;
            }
            case 2:
            {
                system("cls");
                searchFood();
                break;
            }
            case 3:
            {
                system("cls");
                orderFood();
                break;
            }
            case 0:
            {
                system("cls");
                return 0;
            }
            }
            break;
        }
        case 0:
        {
            system("cls");
            return 0;
        }
        }

    }
    return 0;
}
