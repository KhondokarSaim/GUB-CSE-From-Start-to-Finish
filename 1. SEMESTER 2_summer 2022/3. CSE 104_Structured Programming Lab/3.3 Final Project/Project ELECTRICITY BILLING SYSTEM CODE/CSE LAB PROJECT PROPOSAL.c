#include <stdio.h>
#include <string.h>
#include <conio.h>
void main()
{
    int conu, category;
    //int category;
    double pos_inf = 'INFINITY';
    float chg, surchg=0, gramt,netamt;
    char username[30], password[20];

    printf("\n\t\t\t\t---------ELECTRICITY BILLING SYSTEM---------");

    printf("\n\n\t\t\t\t\tEnter your username: ");
    scanf("%s",&username);

    printf("\t\t\t\t\tEnter your password: ");
    scanf("%s",&password);

    if(strcmp(username,"saim")==0){
        if(strcmp(password,"221902353")==0){

        printf("\nWelcome.Login Success!\n");


        }else{
    printf("\nwrong password");
}
    }else{
    printf("\nUser doesn't exist");
}

    //printf("Input Customer ID :");
    //scanf("%d",&custid);
    //printf("Input the name of the customer :");
    //scanf("%s",connm);

    printf("\n\t--------------------------------");
    printf("\n\t\tConsumers Category");
    printf("\n\t---------------------------------\n");
    printf("[1]> House Holds.\n");
    printf("[2]> General Consumers.\n");
    printf("[3]> Agriculture.\n");
    printf("[4]> Construction.\n");
    printf("[5]> Education and Charity.\n");
    printf("[6]> Small Industries.\n");
    printf("[7]> Commercial Buildings.\n");

    printf("\nSelect a particular category = ");
    scanf("%d",&category);

    switch(category)
    {

    case 1: //House holds

        printf("\nInput the unit consumed by the customer : ");
        scanf("%d",&conu);

        if (conu<=50)
            chg = 3.57;
        else
            printf("ERROR! YOU ARE OUT OF LIMIT!");
        break;

    case 2: //General Consumers

        printf("\nInput the unit consumed by the customer : ");
        scanf("%d",&conu);

        if (conu<=75)
            chg = 4.19;

        else if (conu>=76 && conu<200)
            chg = 5.72;

        else if (conu>=201 && conu<300)
            chg = 6.00;

        else if (conu>=301 && conu<400)
            chg = 6.34;

        else if (conu>=401 && conu<600)
            chg = 9.94;

        else if (conu<pos_inf)
            chg = 11.46;

        break;


    case 3: //Agriculture

        printf("\nInput the unit consumed by the customer : ");
        scanf("%d",&conu);

        if (conu<pos_inf)
            chg = 4.19;
        break;


    case 4: //Construction

        printf("\nInput the unit consumed by the customer : ");
        scanf("%d",&conu);

        if (conu<pos_inf)
            chg = 12.00;
        break;


    case 5: //Education & Charity

        printf("\nInput the unit consumed by the customer : ");
        scanf("%d",&conu);

        if (conu<pos_inf)
            chg = 6.02;
        break;


    case 6: //Small Industries

        printf("\nInput the unit consumed by the customer : ");
        scanf("%d",&conu);

        if (conu<pos_inf)
            chg = 10.24;
        break;

    case 7: //Commercial Building

        printf("\nInput the unit consumed by the customer : ");
        scanf("%d",&conu);

        if (conu<pos_inf)
            chg = 12.36;
        break;

}

gramt = conu*chg;
if (gramt>=1000)
        surchg = gramt*15/100.0;
    netamt = gramt+surchg;
    //if (netamt  < 100)
        //netamt =100;
    //printf("\nElectricity Bill\n");
    //printf("Customer IDNO                       :%d\n",password);
    printf("\n------------------------------------------------------\n");
    printf("Customer Name                       :%s\n",username);
    printf("------------------------------------------------------\n");
    printf("Unit Consumed                       :%d\n",conu);
    printf("------------------------------------------------------\n");
    printf("Amount Charges TK. %4.2f  per unit  :%8.2f\n",chg,gramt);
    printf("------------------------------------------------------\n");
    printf("Surcharge Amount                    :%8.2f\n",surchg);
    printf("------------------------------------------------------\n");
    printf("Net Amount Paid By the Customer     :%8.2f\n",netamt);

}
